#pragma once
#include "GameState.h"
#include "GameStateGame.h"
#include "Player.h"
#include "Weapon.h"
#include <vector>

class GameStateGamePreparation : GameState
{
private:
	GameMap map;
	Player player;
	std::vector<Weapon*> weapons;
	std::vector<Bullet> bullet;
	int borderColor = 0x05;
	int borderVisualizationColor = 0x03;
	int arrowColor = 0x06;
	int arrowColorPressed = 0x0E;

	bool nextWeapon;
	bool previousWeapon;
	bool weaponChanged;
	bool playerUp;

	int weaponIndex;

	float timeElapsed;
	float timeElapsedBeforeCompleteReset;
	float timeBeforeReset = 0.05f;
	float timeBeforeCompleteReset = 10.0f;

public:
	virtual ~GameStateGamePreparation(void);

	// Used to initialize the state
	void virtual init(void);

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