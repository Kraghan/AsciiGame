#pragma once
#include "GameState.h"
#include "GameStateGame.h"
#include "AlphabetDrawer.h"
#include "Timer.h"
#include "Weapon.h"
#include "BombThrower.h"
#include "Laser.h"
#include "Shotgun.h"
#include "GameMap.h"
#include "Initializer.h"
#include "Player.h"
#include <vector>

class GameStateGamePreparation : GameState
{
private:
	int borderColor = 0x05;
	int borderVisualizationColor = 0x03;
	int arrowColor = 0x06;
	int arrowColorPressed = 0x0E;
	int weaponIndex;
	unsigned int playerYLimitTop = 30;
	unsigned int playerYLimitBottom = 90;

	bool nextWeapon;
	bool previousWeapon;
	bool weaponChanged;
	bool playerUp;

	double timeElapsed;
	double timeBeforeReset = 0.05;
	double timeElapsedBeforeCompleteReset;
	double timeBeforeCompleteReset = 10.0;

	std::vector<Weapon*> weapons;
	GameMap gameMap;
	Player player;
	vector<Bullet> bullet;

	bool collision(Vector2 positionBox1, Vector2 dimensionBox1, Vector2 positionBox2, Vector2 dimensionBox2);

public:
	virtual ~GameStateGamePreparation(void);

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