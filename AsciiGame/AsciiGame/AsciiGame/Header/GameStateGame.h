#pragma once
#include "GameState.h"
#include "GameMap.h"
#include "BorderInitializer.h"
#include "CaveSeedInitializer.h"
#include "Player.h"
#include "Vector2.h"
#include "Bullet.h"
#include "AlphabetDrawer.h"

#include <vector>

class GameStateGame : GameState
{
private:
	GameMap gameMap;
	Player player;
	
	vector<Bullet> bullet;
	bool needRedrawUi;
	double timeElapsed;

public:
	virtual ~GameStateGame(void);

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

private:
	void inputPlayer(Event *e);
	void displayBullet(Bullet &bullet);
	void displayUI();
};