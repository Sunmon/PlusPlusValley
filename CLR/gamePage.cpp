#include "gamePage.h"

using namespace System;
using namespace System::Windows::Forms;

void Game() {

	Application::EnableVisualStyles();

	Application::SetCompatibleTextRenderingDefault(false);

	CLRFInal::gamePage form;

	Application::Run(% form);

}