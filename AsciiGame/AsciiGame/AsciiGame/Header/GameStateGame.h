#pragma once
#include "GameState.h"
#include "GameMap.h"
#include "Initializer.h"
#include "Player.h"
#include "Vector2.h"
#include "Bullet.h"
#include "AlphabetDrawer.h"
#include "IA.h"
#include "Shotgun.h"
#include "BombThrower.h"
#include "Laser.h"

#include <vector>
#include <thread>

class GameStateGame : GameState
{
private:
	GameMap gameMap;
	Player player;
	
	vector<Bullet> bullet;
	bool needRedrawUi;
	double timeElapsed;
	vector<IA> ia;

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

	void setPlayerWeapon(Weapon* weapon);

	static void loadingScreen(Window* window, GameStateGame* state);
	static bool loadingScreenOn;

private:
	void inputPlayer(Event *e);
	void displayUI();
	bool collision(Vector2 positionBox1, Vector2 dimensionBox1, Vector2 positionBox2, Vector2 dimensionBox2);
	void resetTimer();
};