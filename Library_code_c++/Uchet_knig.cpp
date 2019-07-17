#include "Uchet_knig.h"

using namespace::System;
using namespace::System::Windows::Forms;

[STAThread]
void main(array<String^>^ arg)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Biblio::Uchet_knig form;
	Application::Run(% form);
}
