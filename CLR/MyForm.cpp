#include "MyForm1.h"
#include "MyForm.h"
#include "MyForm2.h"
#include "Controller.h"

#include <Windows.h>

using namespace CLRFInal; // This is your project name

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)

	{
	

	Application::EnableVisualStyles();

	Application::SetCompatibleTextRenderingDefault(false);
	Controller* c = Controller::getInstance();
	Application::Run(gcnew MyForm(c));
	
	Application::Run(gcnew MyForm1(c));

	Application::Run(gcnew MyForm2(c));
	
	Application::Run(gcnew MyForm1(c));
	
	return 0;

	}