#include "start_programu.h"
#include "zaloguj.h"
#include "zarejestruj.h"

using namespace System;
using namespace System::Windows::Forms;


void main() 
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	projopr::start_programu form;
	Application::Run(% form);

}
