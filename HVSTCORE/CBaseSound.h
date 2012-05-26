#ifndef _CBASESOUND_H_
#define _CBASESOUND_H_

#include "theoreticalEnt.h"
#include "fmodMain.h"
#include "CFileData.h"

class CBaseSound : public CBaseTheoryEnt
{
public:
	CBaseSound(){};
	CBaseSound( char * fileName, bool stream);
	CBaseSound( CFileData * sound, bool stream);
	~CBaseSound();

	
	char *mySoundFile;
	FMOD::Sound *mySound;
	FMOD::Channel *myChannel;
	bool active;
	int playCount;

	void emitSound();
	void reset();
	void playSfx(); //used when you want to play a sound effect once
	void stopSound();
	
};

#endif