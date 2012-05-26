#include "CBaseSound.h"

CBaseSound::CBaseSound(char *fileName, bool stream)
{

	if (!tempSys)
		throw "FMod Sound System did not initialize properly!";

	std::string file(fileName);
		if (stream)
			tempSys->createStream(fileName, FMOD_DEFAULT, 0, &mySound);
		else
			tempSys->createSound(fileName, FMOD_DEFAULT, 0, &mySound);

#ifdef _DEBUG
		if (mySound)
			glbl->debugger->writeString("successfully loaded sound " + file + "\n");
		else
			glbl->debugger->writeString("failed to load sound " + file + "\n");
#endif
		
		active = false;
		playCount = 0;
}

CBaseSound::CBaseSound(CFileData * sound, bool stream)
{

	const char * fileData = (const char*)sound->getData();
	
	if (!tempSys)
		throw "FMod Sound System did not initialize properly!";

		if (stream)
			tempSys->createStream(fileData, FMOD_DEFAULT, 0, &mySound);
		else
			tempSys->createSound(fileData, FMOD_DEFAULT, 0, &mySound);

#ifdef _DEBUG
		if (mySound)
			glbl->debugger->writeString("successfully loaded sound " + sound->getName() + "\n");
		else
			glbl->debugger->writeString("failed to load sound " + sound->getName() + "\n");
#endif
		
		active = false;
		playCount = 0;
}

void CBaseSound::reset()
{
	active = false;
	playCount = 0;
}


void CBaseSound::playSfx()
{
	if (!active)
			active = true;
		else
		{
			if (playCount == 0)
			{
				emitSound();
				playCount++;
			}
		}
}

void CBaseSound::emitSound()
{
	tempSys->playSound(FMOD_CHANNEL_FREE, mySound, 0, &myChannel);
}

void CBaseSound::stopSound()
{
	myChannel->stop();
}

CBaseSound::~CBaseSound()
{
	stopSound();
	mySound->release();
}





