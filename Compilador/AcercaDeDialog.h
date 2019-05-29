#pragma once

namespace Compilador {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de AcercaDeDialog
	/// </summary>
	public ref class AcercaDeDialog : public System::Windows::Forms::Form
	{
	public:
		AcercaDeDialog(void)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~AcercaDeDialog()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ Aceptarbutton;
	private: System::Windows::Forms::PictureBox^ Logo;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label5;

	private: System::Windows::Forms::Label^ label7;
	private: System::Windows::Forms::Label^ label8;
	private: System::Windows::Forms::Label^ label9;

	protected:

	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(AcercaDeDialog::typeid));
			this->Aceptarbutton = (gcnew System::Windows::Forms::Button());
			this->Logo = (gcnew System::Windows::Forms::PictureBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Logo))->BeginInit();
			this->SuspendLayout();
			// 
			// Aceptarbutton
			// 
			this->Aceptarbutton->Location = System::Drawing::Point(444, 392);
			this->Aceptarbutton->Name = L"Aceptarbutton";
			this->Aceptarbutton->Size = System::Drawing::Size(75, 23);
			this->Aceptarbutton->TabIndex = 0;
			this->Aceptarbutton->Text = L"Aceptar";
			this->Aceptarbutton->UseVisualStyleBackColor = true;
			this->Aceptarbutton->Click += gcnew System::EventHandler(this, &AcercaDeDialog::Aceptarbutton_Click);
			// 
			// Logo
			// 
			this->Logo->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"Logo.Image")));
			this->Logo->Location = System::Drawing::Point(149, 100);
			this->Logo->Name = L"Logo";
			this->Logo->Size = System::Drawing::Size(212, 107);
			this->Logo->SizeMode = System::Windows::Forms::PictureBoxSizeMode::Zoom;
			this->Logo->TabIndex = 1;
			this->Logo->TabStop = false;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Segoe UI Semilight", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::SystemColors::ControlDarkDark;
			this->label1->Location = System::Drawing::Point(219, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(75, 20);
			this->label1->TabIndex = 2;
			this->label1->Text = L"Acerca de";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Segoe UI Light", 21.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->ForeColor = System::Drawing::SystemColors::MenuHighlight;
			this->label2->Location = System::Drawing::Point(142, 45);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(234, 40);
			this->label2->TabIndex = 3;
			this->label2->Text = L"PROYECTO FINAL";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Segoe UI Semilight", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->ForeColor = System::Drawing::SystemColors::Desktop;
			this->label3->Location = System::Drawing::Point(101, 233);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(62, 13);
			this->label3->TabIndex = 4;
			this->label3->Text = L"Integrantes:";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Segoe UI Semilight", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->ForeColor = System::Drawing::SystemColors::Desktop;
			this->label4->Location = System::Drawing::Point(162, 350);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(90, 13);
			this->label4->TabIndex = 5;
			this->label4->Text = L"Arantxa Guerrero";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Segoe UI Semilight", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label5->ForeColor = System::Drawing::SystemColors::Desktop;
			this->label5->Location = System::Drawing::Point(162, 255);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(124, 13);
			this->label5->TabIndex = 5;
			this->label5->Text = L"Hector Martin Ruiz Rosas";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"Segoe UI Semilight", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label7->ForeColor = System::Drawing::SystemColors::Desktop;
			this->label7->Location = System::Drawing::Point(162, 279);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(185, 13);
			this->label7->TabIndex = 7;
			this->label7->Text = L"Carlos Ernesto Campuzano de la Rosa";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Font = (gcnew System::Drawing::Font(L"Segoe UI Semilight", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label8->ForeColor = System::Drawing::SystemColors::Desktop;
			this->label8->Location = System::Drawing::Point(162, 327);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(148, 13);
			this->label8->TabIndex = 9;
			this->label8->Text = L"Carlos Eduardo Briano Aguilar";
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Font = (gcnew System::Drawing::Font(L"Segoe UI Semilight", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label9->ForeColor = System::Drawing::SystemColors::Desktop;
			this->label9->Location = System::Drawing::Point(162, 303);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(153, 13);
			this->label9->TabIndex = 8;
			this->label9->Text = L"Cruz Esthela Salazar Melendez";
			// 
			// AcercaDeDialog
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ControlLightLight;
			this->ClientSize = System::Drawing::Size(531, 418);
			this->Controls->Add(this->label8);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->Logo);
			this->Controls->Add(this->Aceptarbutton);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"AcercaDeDialog";
			this->ShowIcon = false;
			this->ShowInTaskbar = false;
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			this->Text = L"Acerca  de";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Logo))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: 
		System::Void Aceptarbutton_Click(System::Object^ sender, System::EventArgs^ e);

	};
}
