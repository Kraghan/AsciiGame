#pragma once

#include <windows.h>

class Timer
{
private : 
	LARGE_INTEGER lastUpdateTime;
	LONGLONG freq;

public:
	static const double SECONDS_PER_UPDATE;
	explicit Timer(void);
	void start(void);
	float getElapsedSeconds(bool restart = false);
	double getElapsedMs(bool restart = false);

};