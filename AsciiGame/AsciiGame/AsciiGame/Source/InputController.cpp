#include "..\Header\InputController.h"

///constructeur
InputController::InputController()
{

}


InputController::~InputController()
{

}

///
/// input de la console
/// keycode:
/// https://www.amibroker.com/guide/afl/getasynckeystate.html
///
void InputController::update()
{
	if (GetAsyncKeyState(VK_ESCAPE))
	{
		exit(EXIT_SUCCESS);
	}
	if (GetAsyncKeyState(65))
	{
		//A
		exit(EXIT_SUCCESS);
	}
}