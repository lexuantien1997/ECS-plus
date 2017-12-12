#ifndef _AUDIO_H_
#define _AUDIO_H_

#include "DirectSound\DirectSound.h"

class Audio
{
	CSoundManager *dsound;
public:
	Audio(HWND hwnd);
	~Audio();

	bool DirectSound_Init(HWND hwnd);
	void DirectSound_Shutdown();
	CSound *LoadSound(string filename);
	void PlaySound(CSound *sound);
	void LoopSound(CSound *sound);
	void StopSound(CSound *sound);
};

#endif 
