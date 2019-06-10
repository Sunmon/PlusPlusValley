#include "GUI_Main.h"
#include "startingPage.h"
#include "gamePage.h"

using namespace System;
using namespace System::Windows::Forms;

//Project 속성 - Linker- 고급 - 진입점 - "GUI_MAIN"로 설정

[STAThreadAttribute]

void GUI_MAIN() {

	Application::EnableVisualStyles();

	Application::SetCompatibleTextRenderingDefault(false);

	CLRFInal::startingPage startForm;
	CLRFInal::gamePage gameForm;

	Application::Run(% startForm);

	if (startForm.isCharacterSet) Application::Run(% gameForm);
}