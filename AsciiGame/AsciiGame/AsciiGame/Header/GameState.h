#pragma once
class GameState
{
private :


public :
	explicit GameState(void);
	virtual ~GameState(void) = 0;

	void virtual init() = 0;
	void virtual update(double dt) = 0;
	bool virtual processInput(void) = 0;
	void virtual onEnter(void) = 0;
	void virtual onExit(void) = 0;
};