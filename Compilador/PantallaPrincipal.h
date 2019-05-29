#pragma once

#include "EditorPanel.h"

namespace Compilador {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de PantallaPrincipal
	/// </summary>
	public ref class PantallaPrincipal : public System::Windows::Forms::Form
	{
	public:
		PantallaPrincipal(void)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//

			PAGE = 1;

			this->NewPage();
			
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~PantallaPrincipal()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^ Panel_Inferior;
	private: System::Windows::Forms::MenuStrip^ BarraMenus;

	private: System::Windows::Forms::ToolStripMenuItem^ MenuArchivo;
	private: System::Windows::Forms::ToolStripMenuItem^ MenuEditar;
	private: System::Windows::Forms::ToolStripMenuItem^ MenuVer;
	private: System::Windows::Forms::ToolStripMenuItem^ MenuCompilar;
	private: System::Windows::Forms::ToolStripMenuItem^ MenuAyuda;
	private: System::Windows::Forms::ToolStripMenuItem^ MenuAcercaDe;
	private: System::Windows::Forms::Panel^ Panel_Lateral;
	private: System::Windows::Forms::Panel^ Panel_Principal;

	private: System::Windows::Forms::StatusStrip^ BarraEstado;
	private: System::Windows::Forms::ToolStripStatusLabel^ LabelEstado;
	private: System::Windows::Forms::ToolStripProgressBar^ ProgressBarEstado;


	private:

	internal:

	private: System::Windows::Forms::ListView^ ListaResultadosCompilacion;
	internal:
	private: System::Windows::Forms::ColumnHeader^ ListaResultadosCompilacion_Linea;
	private: System::Windows::Forms::ColumnHeader^ ListaResultadosCompilacion_Descripcion;


	private: System::Windows::Forms::ToolStripMenuItem^ nuevoToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ abrirToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ cortarToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ copiarToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ pegarToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ eliminarToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ compilarArchivoToolStripMenuItem;
	private: System::Windows::Forms::TabControl^ Editor_Tabs;



	private: System::Windows::Forms::PictureBox^ PictureBoxHide;
	private: System::Windows::Forms::TreeView^ Archivos_Viewer;
	private: System::Windows::Forms::OpenFileDialog^ AbrirArchivoDialog;
	private: System::Windows::Forms::ToolStripMenuItem^ abrirCarpetaToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ compilarExternamenteToolStripMenuItem;
	private: System::Windows::Forms::OpenFileDialog^ CompildorExecute;


	private: System::ComponentModel::IContainer^ components;
	private:




	protected:










	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(PantallaPrincipal::typeid));
			this->Panel_Inferior = (gcnew System::Windows::Forms::Panel());
			this->ListaResultadosCompilacion = (gcnew System::Windows::Forms::ListView());
			this->ListaResultadosCompilacion_Linea = (gcnew System::Windows::Forms::ColumnHeader());
			this->ListaResultadosCompilacion_Descripcion = (gcnew System::Windows::Forms::ColumnHeader());
			this->BarraEstado = (gcnew System::Windows::Forms::StatusStrip());
			this->LabelEstado = (gcnew System::Windows::Forms::ToolStripStatusLabel());
			this->ProgressBarEstado = (gcnew System::Windows::Forms::ToolStripProgressBar());
			this->BarraMenus = (gcnew System::Windows::Forms::MenuStrip());
			this->MenuArchivo = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->nuevoToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->abrirToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->abrirCarpetaToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->MenuEditar = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->cortarToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->copiarToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->pegarToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->eliminarToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->MenuVer = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->MenuCompilar = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->compilarArchivoToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->compilarExternamenteToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->MenuAyuda = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->MenuAcercaDe = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->Panel_Lateral = (gcnew System::Windows::Forms::Panel());
			this->Archivos_Viewer = (gcnew System::Windows::Forms::TreeView());
			this->Panel_Principal = (gcnew System::Windows::Forms::Panel());
			this->Editor_Tabs = (gcnew System::Windows::Forms::TabControl());
			this->PictureBoxHide = (gcnew System::Windows::Forms::PictureBox());
			this->AbrirArchivoDialog = (gcnew System::Windows::Forms::OpenFileDialog());
			this->CompildorExecute = (gcnew System::Windows::Forms::OpenFileDialog());
			this->Panel_Inferior->SuspendLayout();
			this->BarraEstado->SuspendLayout();
			this->BarraMenus->SuspendLayout();
			this->Panel_Lateral->SuspendLayout();
			this->Panel_Principal->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->PictureBoxHide))->BeginInit();
			this->SuspendLayout();
			// 
			// Panel_Inferior
			// 
			this->Panel_Inferior->Controls->Add(this->ListaResultadosCompilacion);
			this->Panel_Inferior->Controls->Add(this->BarraEstado);
			this->Panel_Inferior->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->Panel_Inferior->Location = System::Drawing::Point(0, 385);
			this->Panel_Inferior->Name = L"Panel_Inferior";
			this->Panel_Inferior->Size = System::Drawing::Size(972, 161);
			this->Panel_Inferior->TabIndex = 7;
			// 
			// ListaResultadosCompilacion
			// 
			this->ListaResultadosCompilacion->Columns->AddRange(gcnew cli::array< System::Windows::Forms::ColumnHeader^  >(2) {
				this->ListaResultadosCompilacion_Linea,
					this->ListaResultadosCompilacion_Descripcion
			});
			this->ListaResultadosCompilacion->Dock = System::Windows::Forms::DockStyle::Fill;
			this->ListaResultadosCompilacion->Location = System::Drawing::Point(0, 0);
			this->ListaResultadosCompilacion->Name = L"ListaResultadosCompilacion";
			this->ListaResultadosCompilacion->Size = System::Drawing::Size(972, 139);
			this->ListaResultadosCompilacion->TabIndex = 2;
			this->ListaResultadosCompilacion->UseCompatibleStateImageBehavior = false;
			this->ListaResultadosCompilacion->View = System::Windows::Forms::View::Details;
			// 
			// ListaResultadosCompilacion_Linea
			// 
			this->ListaResultadosCompilacion_Linea->Text = L"Linea";
			this->ListaResultadosCompilacion_Linea->Width = 99;
			// 
			// ListaResultadosCompilacion_Descripcion
			// 
			this->ListaResultadosCompilacion_Descripcion->Text = L"Descripción";
			this->ListaResultadosCompilacion_Descripcion->Width = 300;
			// 
			// BarraEstado
			// 
			this->BarraEstado->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) { this->LabelEstado, this->ProgressBarEstado });
			this->BarraEstado->Location = System::Drawing::Point(0, 139);
			this->BarraEstado->Name = L"BarraEstado";
			this->BarraEstado->Size = System::Drawing::Size(972, 22);
			this->BarraEstado->TabIndex = 1;
			this->BarraEstado->Text = L"statusStrip1";
			// 
			// LabelEstado
			// 
			this->LabelEstado->Name = L"LabelEstado";
			this->LabelEstado->Size = System::Drawing::Size(32, 17);
			this->LabelEstado->Text = L"Exito";
			// 
			// ProgressBarEstado
			// 
			this->ProgressBarEstado->Name = L"ProgressBarEstado";
			this->ProgressBarEstado->Size = System::Drawing::Size(100, 16);
			// 
			// BarraMenus
			// 
			this->BarraMenus->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(5) {
				this->MenuArchivo, this->MenuEditar,
					this->MenuVer, this->MenuCompilar, this->MenuAyuda
			});
			this->BarraMenus->Location = System::Drawing::Point(0, 0);
			this->BarraMenus->Name = L"BarraMenus";
			this->BarraMenus->Size = System::Drawing::Size(972, 24);
			this->BarraMenus->TabIndex = 8;
			this->BarraMenus->Text = L"menuStrip1";
			// 
			// MenuArchivo
			// 
			this->MenuArchivo->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				this->nuevoToolStripMenuItem,
					this->abrirToolStripMenuItem, this->abrirCarpetaToolStripMenuItem
			});
			this->MenuArchivo->Name = L"MenuArchivo";
			this->MenuArchivo->Size = System::Drawing::Size(60, 20);
			this->MenuArchivo->Text = L"Archivo";
			// 
			// nuevoToolStripMenuItem
			// 
			this->nuevoToolStripMenuItem->Name = L"nuevoToolStripMenuItem";
			this->nuevoToolStripMenuItem->Size = System::Drawing::Size(144, 22);
			this->nuevoToolStripMenuItem->Text = L"Nuevo";
			this->nuevoToolStripMenuItem->Click += gcnew System::EventHandler(this, &PantallaPrincipal::NuevoToolStripMenuItem_Click);
			// 
			// abrirToolStripMenuItem
			// 
			this->abrirToolStripMenuItem->Name = L"abrirToolStripMenuItem";
			this->abrirToolStripMenuItem->Size = System::Drawing::Size(144, 22);
			this->abrirToolStripMenuItem->Text = L"Abrir";
			this->abrirToolStripMenuItem->Click += gcnew System::EventHandler(this, &PantallaPrincipal::AbrirToolStripMenuItem_Click);
			// 
			// abrirCarpetaToolStripMenuItem
			// 
			this->abrirCarpetaToolStripMenuItem->Name = L"abrirCarpetaToolStripMenuItem";
			this->abrirCarpetaToolStripMenuItem->Size = System::Drawing::Size(144, 22);
			this->abrirCarpetaToolStripMenuItem->Text = L"Abrir Carpeta";
			this->abrirCarpetaToolStripMenuItem->Click += gcnew System::EventHandler(this, &PantallaPrincipal::AbrirCarpetaToolStripMenuItem_Click);
			// 
			// MenuEditar
			// 
			this->MenuEditar->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(4) {
				this->cortarToolStripMenuItem,
					this->copiarToolStripMenuItem, this->pegarToolStripMenuItem, this->eliminarToolStripMenuItem
			});
			this->MenuEditar->Name = L"MenuEditar";
			this->MenuEditar->Size = System::Drawing::Size(49, 20);
			this->MenuEditar->Text = L"Editar";
			// 
			// cortarToolStripMenuItem
			// 
			this->cortarToolStripMenuItem->Name = L"cortarToolStripMenuItem";
			this->cortarToolStripMenuItem->Size = System::Drawing::Size(117, 22);
			this->cortarToolStripMenuItem->Text = L"Cortar";
			// 
			// copiarToolStripMenuItem
			// 
			this->copiarToolStripMenuItem->Name = L"copiarToolStripMenuItem";
			this->copiarToolStripMenuItem->Size = System::Drawing::Size(117, 22);
			this->copiarToolStripMenuItem->Text = L"Copiar";
			// 
			// pegarToolStripMenuItem
			// 
			this->pegarToolStripMenuItem->Name = L"pegarToolStripMenuItem";
			this->pegarToolStripMenuItem->Size = System::Drawing::Size(117, 22);
			this->pegarToolStripMenuItem->Text = L"Pegar";
			// 
			// eliminarToolStripMenuItem
			// 
			this->eliminarToolStripMenuItem->Name = L"eliminarToolStripMenuItem";
			this->eliminarToolStripMenuItem->Size = System::Drawing::Size(117, 22);
			this->eliminarToolStripMenuItem->Text = L"Eliminar";
			// 
			// MenuVer
			// 
			this->MenuVer->Name = L"MenuVer";
			this->MenuVer->Size = System::Drawing::Size(35, 20);
			this->MenuVer->Text = L"Ver";
			// 
			// MenuCompilar
			// 
			this->MenuCompilar->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {
				this->compilarArchivoToolStripMenuItem,
					this->compilarExternamenteToolStripMenuItem
			});
			this->MenuCompilar->Name = L"MenuCompilar";
			this->MenuCompilar->Size = System::Drawing::Size(68, 20);
			this->MenuCompilar->Text = L"Compilar";
			// 
			// compilarArchivoToolStripMenuItem
			// 
			this->compilarArchivoToolStripMenuItem->Name = L"compilarArchivoToolStripMenuItem";
			this->compilarArchivoToolStripMenuItem->Size = System::Drawing::Size(198, 22);
			this->compilarArchivoToolStripMenuItem->Text = L"Compilar Archivo";
			this->compilarArchivoToolStripMenuItem->Click += gcnew System::EventHandler(this, &PantallaPrincipal::CompilarArchivoToolStripMenuItem_Click);
			// 
			// compilarExternamenteToolStripMenuItem
			// 
			this->compilarExternamenteToolStripMenuItem->Name = L"compilarExternamenteToolStripMenuItem";
			this->compilarExternamenteToolStripMenuItem->Size = System::Drawing::Size(198, 22);
			this->compilarExternamenteToolStripMenuItem->Text = L"Compilar Externamente";
			this->compilarExternamenteToolStripMenuItem->Click += gcnew System::EventHandler(this, &PantallaPrincipal::CompilarExternamenteToolStripMenuItem_Click);
			// 
			// MenuAyuda
			// 
			this->MenuAyuda->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->MenuAcercaDe });
			this->MenuAyuda->Name = L"MenuAyuda";
			this->MenuAyuda->Size = System::Drawing::Size(53, 20);
			this->MenuAyuda->Text = L"Ayuda";
			// 
			// MenuAcercaDe
			// 
			this->MenuAcercaDe->Name = L"MenuAcercaDe";
			this->MenuAcercaDe->Size = System::Drawing::Size(126, 22);
			this->MenuAcercaDe->Text = L"Acerca de";
			this->MenuAcercaDe->Click += gcnew System::EventHandler(this, &PantallaPrincipal::MenuAcercaDe_Click);
			// 
			// Panel_Lateral
			// 
			this->Panel_Lateral->Controls->Add(this->Archivos_Viewer);
			this->Panel_Lateral->Dock = System::Windows::Forms::DockStyle::Left;
			this->Panel_Lateral->Location = System::Drawing::Point(0, 24);
			this->Panel_Lateral->Name = L"Panel_Lateral";
			this->Panel_Lateral->Size = System::Drawing::Size(168, 361);
			this->Panel_Lateral->TabIndex = 9;
			// 
			// Archivos_Viewer
			// 
			this->Archivos_Viewer->Dock = System::Windows::Forms::DockStyle::Fill;
			this->Archivos_Viewer->Location = System::Drawing::Point(0, 0);
			this->Archivos_Viewer->Name = L"Archivos_Viewer";
			this->Archivos_Viewer->Size = System::Drawing::Size(168, 361);
			this->Archivos_Viewer->TabIndex = 0;
			// 
			// Panel_Principal
			// 
			this->Panel_Principal->Controls->Add(this->Editor_Tabs);
			this->Panel_Principal->Dock = System::Windows::Forms::DockStyle::Fill;
			this->Panel_Principal->Location = System::Drawing::Point(168, 24);
			this->Panel_Principal->Name = L"Panel_Principal";
			this->Panel_Principal->Size = System::Drawing::Size(804, 361);
			this->Panel_Principal->TabIndex = 10;
			// 
			// Editor_Tabs
			// 
			this->Editor_Tabs->Dock = System::Windows::Forms::DockStyle::Fill;
			this->Editor_Tabs->DrawMode = System::Windows::Forms::TabDrawMode::OwnerDrawFixed;
			this->Editor_Tabs->Location = System::Drawing::Point(0, 0);
			this->Editor_Tabs->Name = L"Editor_Tabs";
			this->Editor_Tabs->SelectedIndex = 0;
			this->Editor_Tabs->Size = System::Drawing::Size(804, 361);
			this->Editor_Tabs->SizeMode = System::Windows::Forms::TabSizeMode::Fixed;
			this->Editor_Tabs->TabIndex = 0;
			this->Editor_Tabs->DrawItem += gcnew System::Windows::Forms::DrawItemEventHandler(this, &PantallaPrincipal::Editor_Tabs_DrawItem);
			this->Editor_Tabs->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &PantallaPrincipal::Editor_Tabs_MouseDown);
			// 
			// PictureBoxHide
			// 
			this->PictureBoxHide->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"PictureBoxHide.Image")));
			this->PictureBoxHide->Location = System::Drawing::Point(947, 0);
			this->PictureBoxHide->Name = L"PictureBoxHide";
			this->PictureBoxHide->Size = System::Drawing::Size(25, 24);
			this->PictureBoxHide->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->PictureBoxHide->TabIndex = 0;
			this->PictureBoxHide->TabStop = false;
			this->PictureBoxHide->Visible = false;
			// 
			// PantallaPrincipal
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(972, 546);
			this->Controls->Add(this->PictureBoxHide);
			this->Controls->Add(this->Panel_Principal);
			this->Controls->Add(this->Panel_Lateral);
			this->Controls->Add(this->BarraMenus);
			this->Controls->Add(this->Panel_Inferior);
			this->Name = L"PantallaPrincipal";
			this->Text = L"Compilador";
			this->Panel_Inferior->ResumeLayout(false);
			this->Panel_Inferior->PerformLayout();
			this->BarraEstado->ResumeLayout(false);
			this->BarraEstado->PerformLayout();
			this->BarraMenus->ResumeLayout(false);
			this->BarraMenus->PerformLayout();
			this->Panel_Lateral->ResumeLayout(false);
			this->Panel_Principal->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->PictureBoxHide))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	
	private: 
		int NewPage();
		int NewPage(System::String^ Text, System::String^ Title);

		System::Void MenuAcercaDe_Click(System::Object^ sender, System::EventArgs^ e);
		System::Void CompilarArchivoToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
		System::Void Editor_Tabs_DrawItem(System::Object^ sender, System::Windows::Forms::DrawItemEventArgs^ e);
		System::Void Editor_Tabs_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e);
		System::Void NuevoToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
		System::Void AbrirToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
		System::Void CompilarExternamenteToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e);
		System::Void AbrirCarpetaToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {}
		
		int PAGE;

};
}
