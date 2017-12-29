#pragma once
#include "GameState.h"
#include "Timer.h"
#include "GameMap.h"
#include "Initializer.h"
#include "Player.h"

#include <vector>
#include <thread>

class GameStateGame : GameState
{
private:
	Timer timer;
	float timeElapsed;
	GameMap map;
	Vector2f cameraPosition;
	Player player;
	std::vector<Bullet> bullets;
	int level;

	static void loadingScreen();
	static bool loadingScreenOn;
	void nextLevel();

	float timeBeforeNextLevel = 3;
	float timeElapsedBeforeNextLevel;
	bool animationUpdatedDecreaseScore;

public:
	virtual ~GameStateGame(void);

	// Used to initialize the state
	void virtual init(void);

	// Update the game logic
	void virtual update(void);

	// Process the input
	bool virtual processInput(void);

	// Called just before update in the gameloop
	void virtual display(void);

	void displayUI(void);

	// Called when the state is set to active
	void virtual onEnter(void);

	// Called when the state is set to inactive
	void virtual onExit(void);

	void setPlayerWeapon(Weapon* weapon);
};