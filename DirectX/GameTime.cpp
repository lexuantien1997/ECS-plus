#include "GameTime.h"



void GameTime::StartCounter()
{
	if (!QueryPerformanceFrequency(&mClockRate))
	{
		return;
	}

	QueryPerformanceCounter(&mStartTime);
}

float GameTime::GetCouter()
{
	QueryPerformanceCounter(&mEndTime);
	mDelta.QuadPart = mEndTime.QuadPart - mStartTime.QuadPart;

	return ((float)mDelta.QuadPart / mClockRate.QuadPart);
}

GameTime::GameTime()
{
}


GameTime::~GameTime()
{
}
