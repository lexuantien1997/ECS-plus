#ifndef GAMETIME_H_
#define GAMETIME_H_

#include "../High perfomance ECS/Singleton.h"
#include <Windows.h>

class GameTime:public ECS::Singleton<GameTime>
{
private:
	LARGE_INTEGER mStartTime, mEndTime, mDelta, mClockRate;
public:

	void StartCounter();

	float GetCouter();

	GameTime();

	~GameTime();
};

#endif
