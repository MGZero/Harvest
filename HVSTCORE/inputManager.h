#ifndef _INPUTMANAGER_H_
#define _INPUTMANAGER_H_

#include "CBaseEventTrigger.h"
#include <windows.h>
#include <iostream>
#include <algorithm>

namespace HVSTInput
{
	class CKey
	{
	public:
		CKey(){};
		CKey(int keyCode);
		~CKey(){};

		int getKeyState();
		int getPrevState();
		int getKey();
		void setKeyState();

	private:
		int _key;
		int _currentState;
		int _previousState;
	};

	class CkeyboardTrigger : public CBaseEventTrigger
	{
	public:
		

		void update();
		CkeyboardTrigger * initialize();
		void deinitialize();
		

	private:
		//constructor for singleton implementation
		CkeyboardTrigger();
		~CkeyboardTrigger();

		static CkeyboardTrigger * _singleton;
		CKey* _keyboard[256];
		void _pollKeys();
	};

	class CMouseTrigger : public CBaseEventTrigger
	{
	public:
		~CMouseTrigger();

		void update();
		CMouseTrigger * initialize();
		void pollButtons();

	private:
		CMouseTrigger();

		CKey* _mouse[3];
		static CMouseTrigger * _singleton;
		float _x,_y;

	};
};


#endif