#ifndef _LOGIC_H_
#define _LOGIC_H_
#include <windows.h>
#include "glMain.h"
#include "theoreticalEnt.h"
#include "CBaseSound.h"
#include "CBaseText.h"


namespace HVSTLOG
{

	class CBaseHeart : public CBaseTheoryEnt
	{
	public:	
		CBaseHeart(float xS, float yS);
		CBaseHeart(){}
		~CBaseHeart(){};

		float x, y;
		HVSTGFX::CSprite hearts[5];
		//HVSTGFX::CSprite hearts[5];
		int heartGone;
		bool active;

	
	};

	class CBaseHudButton : public CBaseTheoryEnt
	{
	public:
		CBaseHudButton();
		CBaseHudButton(int ID, std::string name, List<std::string> params);
		virtual ~CBaseHudButton();

		void live();
	private:
		unsigned char _button; //read from parameters

		void runKeyDown(List<char> keyStrokes);
		void runKeyRelease(List<char> keyStrokes);

		HVSTGFX::CAnimation * _buttonPressed;//HVSTGFX::CAnimation * _buttonPressed;
		HVSTGFX::CAnimation * _buttonReleased;//HVSTGFX::CAnimation * _buttonReleased;


	};

	class CBaseHUD
	{
	public:
		CBaseHUD();
		~CBaseHUD(){};
		void drawHUD();
		float getX(){return x;}
		float getY(){return y;}
		bool getActiveHeart(int heartCount){return heart[heartCount]->active;}
		void moveHUD(float x1, float y1);
		void setHeartX(int heartCount, float x1);
		void setHeartY(int heartCount, float y1);
		void damage();
		void heal();
		void MPDown();
		void MPUp();

		float mouseX, mouseY;
		float x, y; //the position of the HUD
		int heartCount;
		int currentHeart;
		int MP;
		friend void setUpHeart(float x, float y, HVSTLOG::CBaseHUD * HUD, int index);
		CBaseHeart * heart[20];

		
		

	private:
		HVSTGFX::CSprite EHud[2], RHud[2];//HVSTGFX::CSprite EHud[2], RHud[2];
		HVSTGFX::CSprite cursor;//HVSTGFX::CSprite cursor;
		HVSTGFX::CSprite magMeter[47];//HVSTGFX::CSprite magMeter[47];

		//sprites
		/*HVSTGFX::CAnimation * _HUDEOpen;
		HVSTGFX::CAnimation * _HUDEPressed;
		HVSTGFX::CAnimation * _HUDROpen;
		HVSTGFX::CAnimation * _HUDRPressed;
		HVSTGFX::CAnimation * _HUDMagMeter;
		/*HVSTGFX::CAnimation * _HUDHeartEmp;
		HVSTGFX::CAnimation * _HUDHeart14;
		HVSTGFX::CAnimation * _HUDHeart12;
		HVSTGFX::CAnimation * _HUDHeart34;
		HVSTGFX::CAnimation * _HUDHeartFull;*/
		
		

		
		
	};
	
};



#endif