#include "../Header/Timer.h"
const double Timer::SECONDS_PER_UPDATE = 1.0 / 60.0;

/*explicit*/ Timer::Timer(void)
{
	QueryPerformanceCounter(&lastUpdateTime);
	LARGE_INTEGER li_freq;
	QueryPerformanceFrequency(&li_freq);
	freq = li_freq.QuadPart;
	freq /= 1000;
}

void Timer::start(void)
{
	QueryPerformanceCounter(&lastUpdateTime);
}

float Timer::getElapsedSeconds(bool restart)
{
	LARGE_INTEGER timeNow;
	QueryPerformanceCounter(&timeNow);
	LONGLONG elapsedLong = timeNow.QuadPart - lastUpdateTime.QuadPart;

	float elapsed = (float)((float)elapsedLong / (float)freq);
	elapsed /= 1000.0f;

	if (restart)
		lastUpdateTime = timeNow;

	return elapsed;
}

double Timer::getElapsedMs(bool restart)
{
	LARGE_INTEGER timeNow;
	QueryPerformanceCounter(&timeNow);
	LONGLONG elapsedLong = timeNow.QuadPart - lastUpdateTime.QuadPart;

	return (double)((float)elapsedLong / (float)freq);
}