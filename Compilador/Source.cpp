/*

PROYECTO FINAL
COMPILADORES

*/


#include "PantallaPrincipal.h"

[System::STAThreadAttribute]
void Main(array<System::String^>^ args)
{

	System::Windows::Forms::Application::EnableVisualStyles();
	System::Windows::Forms::Application::SetCompatibleTextRenderingDefault(false);

	Compilador::PantallaPrincipal Dialog;

	System::Windows::Forms::Application::Run(% Dialog);
}

