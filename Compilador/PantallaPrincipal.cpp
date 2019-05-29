#include "PantallaPrincipal.h"

#include "AcercaDeDialog.h"
#include "Compilador.h"

using namespace Compilador;

#pragma region navbar

System::Void PantallaPrincipal::MenuAcercaDe_Click(System::Object^ sender, System::EventArgs^ e)
{
	AcercaDeDialog^ dialog = gcnew AcercaDeDialog();
	dialog->ShowDialog(this);

}

System::Void PantallaPrincipal::CompilarArchivoToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{

	ListaResultadosCompilacion->Items->Clear();

	TabPage^ selected = this->Editor_Tabs->SelectedTab;

	EditorPanel^ editorSelect = (EditorPanel^)(selected->Controls->Find("Editor", true)[0]);

	//MessageBox::Show(editorSelect->GetText());

	try {

		Codigo::CodigoIntermedio = "";

		LabelEstado->Text = "Compilando";
		AnalizadorLexico::AnalizadorLexico^ lex = gcnew AnalizadorLexico::AnalizadorLexico();
		lex->SetCadenaLectura(editorSelect->GetText());
		Analizador::Analizador^ analizador = gcnew Analizador::Analizador(lex);
		analizador->Programa();

		LabelEstado->Text = "Exito";

		MessageBox::Show(Codigo::CodigoIntermedio);

	}
	catch (AnalizadorLexico::LexicoException^ ex) 
	{
		ListViewItem^ nuevoError = gcnew ListViewItem();

		nuevoError->Text = ex->GetLinea().ToString();
		nuevoError->SubItems->Add(ex->Message);

		ListaResultadosCompilacion->Items->Add(nuevoError);
		LabelEstado->Text = "Hay Errores";

	}
	catch (System::Exception^ ex) {

		MessageBox::Show(ex->Message, "Error Faltal",  MessageBoxButtons::OK, MessageBoxIcon::Error);

	}
		
	ProgressBarEstado->Value = 100;

}


System::Void PantallaPrincipal::CompilarExternamenteToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {



	

	if (CompildorExecute->ShowDialog(this) == System::Windows::Forms::DialogResult::OK)
	{
		
		ListaResultadosCompilacion->Items->Clear();

		TabPage^ selected = this->Editor_Tabs->SelectedTab;

		EditorPanel^ editorSelect = (EditorPanel^)(selected->Controls->Find("Editor", true)[0]);

		System::String^ CompuladorRuta = CompildorExecute->FileName;

		MessageBox::Show(CompuladorRuta);

		System::Diagnostics::Process::Start("CMD.exe", "/K "+CompuladorRuta+" /b "+editorSelect->GetText());

	}


	
	
}
#pragma endregion


int PantallaPrincipal::NewPage() 
{
	TabPage^ newPage = gcnew TabPage();
	EditorPanel^ newEditor = gcnew EditorPanel();

	newPage->Location = System::Drawing::Point(4, 22);
	newPage->Name = L"Archivo " + this->PAGE;
	newPage->Text = L"Archivo " + this->PAGE;
	newPage->Padding = System::Windows::Forms::Padding(3);
	newPage->Size = Drawing::Size(796, 335);
	newPage->TabIndex = 1;

	newPage->UseVisualStyleBackColor = true;

	newEditor->Location = System::Drawing::Point(50, 58);
	newEditor->Name = L"Editor";
	newEditor->Size = System::Drawing::Size(200, 100);
	newEditor->TabIndex = 0;

	newPage->Controls->Add(newEditor);

	this->Editor_Tabs->Controls->Add(newPage);

	PAGE++;

	return Editor_Tabs->TabPages->IndexOf(newPage);

}

int PantallaPrincipal::NewPage(System::String^ Text, System::String^ Title)
{
	TabPage^ newPage = gcnew TabPage();
	EditorPanel^ newEditor = gcnew EditorPanel();

	newPage->Location = System::Drawing::Point(4, 22);
	newPage->Name = Title;
	newPage->Text = Title;
	newPage->Padding = System::Windows::Forms::Padding(3);
	newPage->Size = Drawing::Size(796, 335);
	newPage->TabIndex = 1;

	newPage->UseVisualStyleBackColor = true;

	newEditor->Location = System::Drawing::Point(50, 58);
	newEditor->Name = L"panelx";
	newEditor->Size = System::Drawing::Size(200, 100);
	newEditor->TabIndex = 0;
	newEditor->DefineText(Text);

	newPage->Controls->Add(newEditor);

	this->Editor_Tabs->Controls->Add(newPage);

	return Editor_Tabs->TabPages->IndexOf(newPage);
}
System::Void PantallaPrincipal::Editor_Tabs_DrawItem(System::Object^ sender, System::Windows::Forms::DrawItemEventArgs^ e) 
{
	try 
	{
		System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(PantallaPrincipal::typeid));

		TabPage^ tabPage = this->Editor_Tabs->TabPages[e->Index];
		Rectangle^ tabRect = this->Editor_Tabs->GetTabRect(e->Index);

		tabRect->Inflate(-2, -2);
		Image^ closeImage = (cli::safe_cast<Image^>(resources->GetObject(L"PictureBoxHide.Image")));


		e->Graphics->DrawImage(closeImage, (tabRect->Right - closeImage->Width), tabRect->Top + (tabRect->Height - closeImage->Height) / 2);
		
		TextRenderer::DrawText(e->Graphics, tabPage->Text, tabPage->Font, *tabRect, tabPage->ForeColor, TextFormatFlags::Left);

	}
	catch (Exception^ ex) 
	{
		MessageBox::Show(ex->ToString());
	}
	
}

System::Void PantallaPrincipal::Editor_Tabs_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) 
{
	Rectangle^ r = Editor_Tabs->GetTabRect(this->Editor_Tabs->SelectedIndex);
	Rectangle^ closeButton = gcnew Rectangle(r->Right - 15, r->Top + 4, 9, 7);
	if (closeButton->Contains(e->Location))
	{
		this->Editor_Tabs->TabPages->Remove(this->Editor_Tabs->SelectedTab);
	}
}

System::Void PantallaPrincipal::NuevoToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) 
{
	Editor_Tabs->SelectTab(this->NewPage());

}

System::Void PantallaPrincipal::AbrirToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) 
{
	
	if (AbrirArchivoDialog->ShowDialog(this) == System::Windows::Forms::DialogResult::OK)
	{


		System::String^ TituloArchivo = System::IO::Path::GetFileName(AbrirArchivoDialog->FileName);
		System::String^ ContenidoArchivo = "";



		for (int i = 0; i <= System::IO::File::ReadAllLines(AbrirArchivoDialog->FileName)->Length -1; i++) 
		{
			ContenidoArchivo += System::IO::File::ReadAllLines(AbrirArchivoDialog->FileName)[i]+"\n";
		}


		Editor_Tabs->SelectTab(this->NewPage(ContenidoArchivo, TituloArchivo));
		
	}
	


	//this->NewPage();
}