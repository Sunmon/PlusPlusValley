#include "startingPage.h"

using namespace System;
using namespace System::Windows::Forms;

//Project �Ӽ� - Linker- ��� - ������ - "Start"�� ����

[STAThreadAttribute]

void Start() {

	Application::EnableVisualStyles();

	Application::SetCompatibleTextRenderingDefault(false);

	CLRFInal::startingPage form;

	Application::Run(% form);

}