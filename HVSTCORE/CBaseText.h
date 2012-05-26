#ifndef _CBASETEXT_H_
#define _CBASETEXT_H_

#include "theoreticalent.h"
#include "CMessage.h"

class CBaseText : public CBaseTheoryEnt
{
public:
	CBaseText * init();
	void destroy();
	virtual void live();

private:
	CBaseText(){}
	CBaseText(int ID, std::string name, List<std::string> params);
	~CBaseText();

	static CBaseText * _singleton;
	List<std::string> _text;
	bool _display;

	void runOnTextShow(CMessage * message);
	void checkEvents();
	void _showText();

	CMessage * _currentMsg;
	HVSTGFX::CSprite _letters[256];
};

#endif