#include "GUI_Main.h"
#include "startingPage.h"
#include "gamePage.h"

using namespace System;
using namespace System::Windows::Forms;

//Project �Ӽ� - Linker- ��� - ������ - "GUI_MAIN"�� ����

[STAThreadAttribute]

void GUI_MAIN() {

	Application::EnableVisualStyles();

	Application::SetCompatibleTextRenderingDefault(false);

	CLRFInal::startingPage startForm;
	CLRFInal::gamePage gameForm;

	Application::Run(% startForm);

	if (startForm.isCharacterSet) Application::Run(% gameForm);
}