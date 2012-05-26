#ifndef _CBASENTCOM_H_
#define _CBASENTCOM_H_

#include "restrictedent.h"

class CBaseEntCom : public CBaseRestrictedEnt
{
public:
	CBaseEntCom(){}
	~CBaseEntCom(){}

	void loadIdentity(CBaseEventTrigger &trigger, std::string name);
	void clearIdentity();
	void triggerIdentity();

private:
	CBaseEvent * _eventIdentity;

	void runNewFrame();
	void runLoadIdentity(void * trigger, std::string name);


protected:
};


#endif