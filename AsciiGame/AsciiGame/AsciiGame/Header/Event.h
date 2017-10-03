#pragma once
class Event
{
public:
	//enum des input
	enum INPUT
	{
		KB_ESCAPE = 27,
		KB_A = 65,
		KB_UP = 38,
		KB_DOWN = 40,
		KB_RIGHT = 39,
		KB_LEFT = 37,
		KB_Z = 90,
		KB_S = 83,
		KB_Q = 81,
		KB_D = 68,
		KB_SPACE = 32,
	};
	//enum des types d'événements
	enum TYPE_INPUT_EVENT
	{
		TI_PRESSED = 0,
		TI_HOLDING = 1,
		TI_RELEASED = 2,
	};

	INPUT input;
	TYPE_INPUT_EVENT typeInput;

public:
	Event(INPUT input, TYPE_INPUT_EVENT typeInput);
	~Event();
};

