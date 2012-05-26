#ifndef _CTITLESCREEN_H_
#define _CTITLESCREEN_H_

#include "theoreticalEnt.h"
#include "glmain.h"
#include "CBaseSound.h"

class CTitleScreen : public CBaseTheoryEnt
{
public:
	CTitleScreen();
	~CTitleScreen();

	HVSTGFX::CSprite getSprite();
	void render();
	void live();

private:
	HVSTGFX::CSprite title;

	void runKeyDown(List<char> keyStrokes);
	void runNewFrame();
	bool _onTitle;
	CSpriteStateX  _spriteStates;
	CBaseSound * _BGM;
	


};

#endif