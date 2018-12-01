#include "TelephoneForm.h"

using namespace Telephone;

int main(array<String^>^ args) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	Application::Run(gcnew TelephoneForm());
	return 0;
}