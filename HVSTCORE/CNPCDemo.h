#ifndef _CNPCDEMO_H_
#define _CNPCDEMO_H_
#include "CBaseNPC.h"
#include "CBaseTXT.h"

class CNPCDemo : public CBaseNPC
{
public:
	CNPCDemo();
	virtual ~CNPCDemo();

	void speak(float x, float y);

private:
	//CBaseTXTBox * dialog1;

protected:
	virtual void initialize();

};


#endif