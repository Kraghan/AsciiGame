#pragma once
#include "GameState.h"
#include "AlphabetDrawer.h"

class GameStatePause : GameState
{
private:
	// Enum used to know which button is focused
	enum FocusButton
	{
		FB_RESUME,
		FB_NEWGAME,
		FB_QUIT
	};

	// 
	FocusButton focus;

	// 
	Vector2 position;

	void drawContour();

public:
	virtual ~GameStatePause(void);

	// Used to initialize the state
	void virtual init(Window* wind);

	// Update the game logic
	void virtual update();

	// Process the input
	bool virtual processInput(void);

	// Called just before update in the gameloop
	void virtual display();

	// Called when the state is set to active
	void virtual onEnter(void);

	// Called when the state is set to inactive
	void virtual onExit(void);
};