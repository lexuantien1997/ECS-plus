#include "DirectSound\audio.h"



Audio::Audio(HWND hwnd)
{
	DirectSound_Init(hwnd);
}

Audio::~Audio()
{
	DirectSound_Shutdown();
}

bool Audio::DirectSound_Init(HWND hwnd)
{
	//create DirectSound manager object
	dsound = new CSoundManager();

	//initialize DirectSound
	HRESULT result;
	result = dsound->Initialize(hwnd, DSSCL_PRIORITY);
	if (result != DS_OK) return false;

	//set the primary buffer format
	result = dsound->SetPrimaryBufferFormat(2, 22050, 16);
	if (result != DS_OK) return false;

	//return success
	return true;
}

void Audio::DirectSound_Shutdown()
{
	if (dsound) delete dsound;
}

CSound *Audio::LoadSound(string filename)
{
	HRESULT result;

	//create local reference to wave data
	CSound *wave = NULL;

#if UNICODE // string filename
	wstring str = wstring(filename.begin(), filename.end());

#else
	string str = filename;

#endif // UNICOE
	result = dsound->Create(&wave, (LPTSTR)str.c_str()); //(LPTSTR)
	if (result != DS_OK) wave = NULL;

	//return the wave
	return wave;
}

void Audio::PlaySound(CSound *sound)
{
	sound->Play();
}

void Audio::LoopSound(CSound *sound)
{
	sound->Play(0, DSBPLAY_LOOPING);
}

void Audio::StopSound(CSound *sound)
{
	sound->Stop();
}
