#pragma once
#include "GameState.h"
#include "GameMap.h"
#include "BorderInitializer.h"
#include "Player.h"
#include "Vector2.h"

class GameStateGame : GameState
{
private:
	GameMap gameMap;
	Player player;

public:
	virtual ~GameStateGame(void);

	// Used to initialize the state
	void virtual init(Window* wind);

	// Update the game logic
	void virtual update();

	// Process the input
	bool virtual processInput(void);

	// Called when the state is set to active
	void virtual onEnter(void);

	// Called when the state is set to inactive
	void virtual onExit(void);

private:
	void inputPlayer(Event *e);
};