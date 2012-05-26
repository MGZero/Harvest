#ifndef _CENTRELATION_H_
#define _CENTRELATION_H_


class CEntRelation
{
public:
	CEntRelation( void * entActedOn, int eventToFire, int firingEvent );
	~CEntRelation(){};

	bool checkFiringEvent(int evCheck);
		
private:
	void * entActedOn;
	int eventToFire; //which event to fire
	int firingEvent; //the event that fires the above
};

#endif