#pragma once

#include <windows.h>

class Timer
{
private : 
	LARGE_INTEGER lastUpdateTime;
	LONGLONG freq;

public:
	explicit Timer(void);
	void start(void);
	float getElapsedSeconds(bool restart = false);
	double getElapsedMs(bool restart = false);

};
