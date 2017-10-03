#include "..\Header\InputController.h"

///constructeur
InputController::InputController(std::stack<Event> * event)
	: event(event)
{

}

///constructeur
InputController::InputController()
	: event(NULL)
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

		event->push(Event(Event::INPUT::KB_A, Event::TYPE_INPUT_EVENT::TI_PRESSED));
	}
}