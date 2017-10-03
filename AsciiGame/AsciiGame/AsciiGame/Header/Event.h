#pragma once
class Event
{
public:
	//enum des input
	enum INPUT
	{
		KB_ESCAPE = 27,
		KB_A = 65,
	};
	//enum des types d'événements
	enum TYPE_INPUT_EVENT
	{
		TI_PRESSED = 0,
		TI_HOLDING = 1,
		TI_RELEASED = 2,
	};

public:
	Event();
	~Event();
};

