#pragma once
#include "GameState.h"
#include "AlphabetDrawer.h"
#include "AudioHelper.h"

class GameStateMenu : GameState
{
private:
	// Enum used to know which button is focused
	enum FocusButton
	{
		FB_PLAY,
		FB_QUIT
	};

	// True if the focus has change. Use to redraw only when needed
	bool hasChange;

	// Current button focused
	FocusButton focus;

	// Draw the border
	void drawContour(void);

	// Draw the title
	void drawTitle(void);

	// Draw play button
	void drawPlay(void);

	// Draw focused play button
	void drawPlayFocused(void);

	// Draw quit button
	void drawQuit(void);

	// Draw focused quit button
	void drawQuitFocused(void);
public:
	// Destructor
	virtual ~GameStateMenu(void);

	// Used to initialize the state
	void virtual init(Window* wind);

	// Update the game logic
	void virtual update(void);

	// Process the input
	bool virtual processInput(void);

	// Called just before update in the gameloop
	void virtual display(void);

	// Called when the state is set to active
	void virtual onEnter(void);

	// Called when the state is set to inactive
	void virtual onExit(void);
};