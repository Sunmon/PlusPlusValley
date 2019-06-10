#include "startingPage.h"

using namespace System;
using namespace System::Windows::Forms;

//Project 속성 - Linker- 고급 - 진입점 - "Start"로 설정

[STAThreadAttribute]

void Start() {

	Application::EnableVisualStyles();

	Application::SetCompatibleTextRenderingDefault(false);

	CLRFInal::startingPage form;

	Application::Run(% form);

}