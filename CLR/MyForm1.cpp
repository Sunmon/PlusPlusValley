#include "MyForm1.h"
#include "MyForm.h"
#include "MyForm2.h"
#include "Controller.h"

#include <Windows.h>

using namespace CLRFInal; // This is your project name

int WINAPI WinMain1(HINSTANCE, HINSTANCE, LPSTR, int)
{

	Application::EnableVisualStyles();

	Application::SetCompatibleTextRenderingDefault(false);
	Controller* c;

	Application::Run(gcnew MyForm1(c));
	//Application::Run(gcnew MyForm2(c));
	Application::Run(gcnew MyForm2());

	return 0;

}

