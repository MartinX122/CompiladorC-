#include "EditorPanel.h"

using namespace Compilador;
using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;

EditorPanel::EditorPanel()
{
	this->InitializeComponent();
	
	this->Timer->Start();
}

EditorPanel::~EditorPanel()
{
	this->Timer->Stop();

	//delete(this);
}

System::Void EditorPanel::InitializeComponent() 
{
	this->SuspendLayout();

	/*Definicion*/
	this->Editor = gcnew RichTextBox();
	this->Numerador = gcnew PictureBox();
	this->Panel_Editor_Texto = gcnew Panel();
	this->Panel_Editor_Numerador = gcnew Panel();
	this->Timer = gcnew System::Windows::Forms::Timer();

	(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Numerador))->BeginInit();

	/*Editor*/
	this->Editor->BorderStyle = Windows::Forms::BorderStyle::None;
	this->Editor->Font = gcnew Drawing::Font(L"Microsoft Sans Serif", 11.25F, FontStyle::Regular, GraphicsUnit::Point,static_cast<System::Byte>(0));
	this->Editor->Location = Point(0, 0);
	this->Editor->Name = L"Editor";
	this->Editor->Size = Drawing::Size(749, 361);
	this->Editor->TabIndex = 3;
	this->Editor->Text = L"";
	this->Editor->Dock = DockStyle::Fill;

	/*Numerador*/
	this->Numerador->Dock = DockStyle::Fill;
	this->Numerador->Location = Drawing::Point(0, 0);
	this->Numerador->Name = L"Numerador";
	this->Numerador->Size = Drawing::Size(55, 361);
	this->Numerador->TabIndex = 4;
	this->Numerador->TabStop = false;
	this->Numerador->BackColor = Color::Gray;
	this->Numerador->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &EditorPanel::Numerador_Paint);

	/*Timer*/
	this->Timer->Interval = 10;
	this->Timer->Tick += gcnew System::EventHandler(this, &EditorPanel::Timer_Tick);

	/*Panel Editor*/
	this->Panel_Editor_Texto->SuspendLayout();
	this->Panel_Editor_Texto->Controls->Add(this->Editor);
	this->Panel_Editor_Texto->Dock = DockStyle::Fill;
	this->Panel_Editor_Texto->Location = Drawing::Point(55, 0);
	this->Panel_Editor_Texto->Name = L"Panel_Editor_Texto";
	this->Panel_Editor_Texto->Size = Drawing::Size(749, 361);
	this->Panel_Editor_Texto->TabIndex = 3;

	/*Panel Numerador*/
	this->Panel_Editor_Numerador->SuspendLayout();
	this->Panel_Editor_Numerador->Controls->Add(this->Numerador);
	this->Panel_Editor_Numerador->Dock = DockStyle::Left;
	this->Panel_Editor_Numerador->Location = Drawing::Point(0, 0);
	this->Panel_Editor_Numerador->Name = L"Panel_Editor_Numerador";
	this->Panel_Editor_Numerador->Size = Drawing::Size(55, 361);
	this->Panel_Editor_Numerador->TabIndex = 2;

	/*Panel Actual*/
	this->Controls->Add(this->Panel_Editor_Texto);
	this->Controls->Add(this->Panel_Editor_Numerador);
	this->Dock = DockStyle::Fill;
	this->Location = System::Drawing::Point(168, 24);
	this->Name = L"EditorPanel";
	this->Size = Drawing::Size(804, 361);
	this->TabIndex = 1;
	this->Click += gcnew System::EventHandler(this, &EditorPanel::EditorPanel_Click);

	this->ResumeLayout(false);
	this->Panel_Editor_Texto->ResumeLayout(false);
	this->Panel_Editor_Numerador->ResumeLayout(false);
	(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Numerador))->EndInit();



}

Void EditorPanel::EditorPanel_Click(System::Object^ sender, System::EventArgs^ e) 
{
	//this->Timer->Start();
}

System::Void EditorPanel::Timer_Tick(System::Object^ sender, System::EventArgs^ e)
{
	this->Numerador->Refresh();
}

System::Void EditorPanel::Numerador_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e)
{
	this->CARACTER = 0;

	int ALTURA = 0;

	if (Editor->Lines->Length > 0)
	{
		for (int i = 0; i <= Editor->Lines->Length - 1; i++)
		{
			System::Int32^ Index = gcnew System::Int32(i + 1);
			System::String ^ Text = Index->ToString();

			float Longitud = Numerador->Width - (e->Graphics->MeasureString(Text, Editor->Font).Width + 10);

			System::Drawing::Font ^ font = gcnew System::Drawing::Font(Editor->Font, FontStyle::Bold);

			e->Graphics->DrawString(Text, font, Brushes::Black, Longitud, (float)ALTURA);

			CARACTER += Editor->Lines[i]->Length + 1;
			ALTURA = Editor->GetPositionFromCharIndex(CARACTER).Y;

		}
	}
	else
	{

		float Longitud = Editor->Width - (e->Graphics->MeasureString("1", Editor->Font).Width + 10);

		System::Drawing::Font ^ font = gcnew System::Drawing::Font(Editor->Font, FontStyle::Bold);

		e->Graphics->DrawString("1", font, Brushes::Black, Longitud, (float)ALTURA);

	}


}

System::Void EditorPanel::DefineText(System::String^ text) 
{
	Editor->Text = text;
}

System::String^ Compilador::EditorPanel::GetText()
{
	return Editor->Text;
}
