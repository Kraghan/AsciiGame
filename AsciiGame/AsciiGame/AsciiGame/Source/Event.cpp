#include "..\Header\Event.h"

Event::Event()
	: input(Event::INPUT::KB_VOID)
	, typeInput(Event::TYPE_INPUT_EVENT::TI_VOID)
{

}

Event::Event(INPUT input, TYPE_INPUT_EVENT typeInput)
	: input(input), typeInput(typeInput)
{

}


Event::~Event()
{

}
