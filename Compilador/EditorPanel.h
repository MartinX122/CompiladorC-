#pragma once

namespace Compilador {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	
	public ref class EditorPanel : public Panel
	{
	public:
		EditorPanel(void);
		~EditorPanel(void);

		System::Void DefineText(System::String^ text);
		System::String^ GetText();
	
	private:

		Void InitializeComponent();

		RichTextBox^ Editor;
		PictureBox^ Numerador;

		Panel^ Panel_Editor_Texto;
		Panel^ Panel_Editor_Numerador;

		Timer^ Timer;

		Void EditorPanel_Click(System::Object^ sender, System::EventArgs^ e);
		Void Timer_Tick(System::Object^ sender, System::EventArgs^ e);
		Void Numerador_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e);

		int CARACTER;
	};

}