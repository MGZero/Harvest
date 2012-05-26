#ifndef _CSFX_H_
#define _CSFX_H_

#include "fmodMain.h"
#include "CFileData.h"
#include <unordered_map>

typedef std::tr1::unordered_map<FMOD::Sound*, FMOD::Channel*> soundGetHelper;

class CSFX
{
public:
	CSFX(CFileData * fileData);
	CSFX(){}
	~CSFX();

	void playSound();
	void stopSound();
	void pauseSound();

protected:
	FMOD::Sound * _mySound;
	FMOD::Channel * _myChannel;
};

#endif