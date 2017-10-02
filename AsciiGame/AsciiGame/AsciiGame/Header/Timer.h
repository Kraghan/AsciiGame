#pragma once

#include <windows.h>

class Timer
{
public:
	LARGE_INTEGER lastUpdateTime;
	LONGLONG freq;

	explicit Timer(void);
	void start(void);
	float getElapsedSeconds(bool restart = false);
	unsigned long getElapsedMs(bool restart = false);

};
