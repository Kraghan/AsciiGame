#include "..\Header\InputController.h"

///constructeur
InputController::InputController()
{

}


InputController::~InputController()
{

}

bool InputController::inputController()
{
	if (GetAsyncKeyState(VK_ESCAPE))
	{
		return (false);
	}
	return (true);
}