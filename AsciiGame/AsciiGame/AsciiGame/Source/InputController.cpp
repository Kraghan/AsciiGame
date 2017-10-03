#include "..\Header\InputController.h"

///constructeur
/// https://www.amibroker.com/guide/afl/getasynckeystate.html
///
InputController::InputController(std::stack<Event> * event)
	: event(event)
{
	stateKey[Event::INPUT::KB_ESCAPE] = 0;					//echape
	stateKey[Event::INPUT::KB_UP] = 0;						//UP
	stateKey[Event::INPUT::KB_DOWN] = 0;					//DOWN
	stateKey[Event::INPUT::KB_RIGHT] = 0;					//RIGHT
	stateKey[Event::INPUT::KB_LEFT] = 0;					//LEFT
	stateKey[Event::INPUT::KB_Z] = 0;						//Z
	stateKey[Event::INPUT::KB_S] = 0;						//S
	stateKey[Event::INPUT::KB_Q] = 0;						//Q
	stateKey[Event::INPUT::KB_D] = 0;						//D
	stateKey[Event::INPUT::KB_SPACE] = 0;					//SPACE
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
///
void InputController::update()
{
	for (auto const& x : stateKey)
	{
		if (GetKeyState(x.first) & 0x8000 && stateKey[x.first] == 0)
		{
			//Your code
			//cout << x.first << " pressed" << endl;

			stateKey[x.first] = 1;
			event->push(Event((Event::INPUT)x.first, Event::TYPE_INPUT_EVENT::TI_PRESSED));
		}
		if (GetKeyState(x.first) & 0x8000 && stateKey[x.first] == 1)
		{
			//holding
			//cout << x.first << " holdinng" << endl;
			event->push(Event((Event::INPUT)x.first, Event::TYPE_INPUT_EVENT::TI_HOLDING));
		}
		else if (!(GetKeyState(x.first) & 0x8000) && stateKey[x.first] == 1)
		{
			//s'il �tant en holding avant...
			//cout << x.first << " released" << endl;
			stateKey[x.first] = 0;
			event->push(Event((Event::INPUT)x.first, Event::TYPE_INPUT_EVENT::TI_RELEASED));
		}

		/*std::cout << x.first  // string (key)
			<< ':'
			<< x.second // string's value 
			<< std::endl;*/
	}
}
