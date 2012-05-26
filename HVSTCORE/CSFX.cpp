#include "CSFX.h"

CSFX::CSFX(CFileData *fileData)
{
	FMOD_RESULT result;
	FMOD_CREATESOUNDEXINFO * settings;
	
	_mySound = 0;
	std::string temp = "";

	for (int i = 0; i < fileData->getSize(); i++)
		temp += fileData->getData()[i];
	settings = new FMOD_CREATESOUNDEXINFO();
	settings->cbsize = sizeof(FMOD_CREATESOUNDEXINFO);
	settings->length = fileData->getSize();

	result = tempSys->createSound(temp.c_str(), FMOD_HARDWARE | FMOD_OPENMEMORY, settings, &_mySound);
	delete settings;
	settings = 0;
}

CSFX::~CSFX()
{
	/*if (_mySound)
		_mySound->release();*/
}

void CSFX::playSound()
{
	tempSys->playSound(FMOD_CHANNEL_FREE, _mySound, 0, &_myChannel);
}

void CSFX::stopSound()
{
	
}