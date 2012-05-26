#ifndef _HMD_H_
#define _HMD_H_
//===================provides the map file format=======================//
//Essentially, it's a list of databases of things.======================//
#include "entInfo.h"
#include "CLayer.h"
#include "glMain.h"
#include "dictionary.h"
#include "CLayerX.h"
#include "HED.h"

//HMD Macros go here. DO IT RIGHT THIS TIME GODDAMNIT, FOLLOW THE FUCKING ALGORITHM
#define BASE_DETERMINE_ENT(ENTITY)									\
	if (name == #ENTITY)											\
		if (name == "CBasePlayer")									\
			return new ENTITY();									\
		else														\
			return new ENTITY(entID, entName, params);				\

//Add a call to BASE_DETERMINE_ENT() to this macro for each entity
#define DETERMINE_ENT()												\
	   BASE_DETERMINE_ENT(CBasePlayer);								\

//live calls
#define BASE_LIVE_ENT(ENTITY)										\
	if (name == #ENTITY)											\
	{																\
		ENTITY temp = (ENTITY&)tempList[k];							\
		temp.live();												\
	}																\

#define LIVE_ENT()													\
	BASE_LIVE_ENT(CBasePlayer);										\

//draw calls
#define BASE_DRAW_ENT(ENTITY)										\
	if (name == #ENTITY)											\
	{																\
		ENTITY temp = (ENTITY&)tempList[k];							\
		temp.Draw();												\
	}																\

#define DRAW_ENT()													\
	BASE_DRAW_ENT(CBasePlayer);										\


class CBaseHMD
{
public:
	CBaseHMD(){};
	int layerCount;
	std::string tileSetName;
	HVSTGFX::CXTileSheet tileSet;
	CSprite_State mapStates;
	HVSTGFX::CSprite BGImage;
	std::vector<CLayer> layers;
	List<CLayerX*> layersX;
	std::string BGMURL;
	CBaseSound *BGM;
};

namespace HMDFunc
{
	void readMapX(const char * fileName, CBaseHMD &HMD);
	void readHMD(std::string fileName, CBaseHMD &HMD); //most up to date version of the HMD reader
	void createHMD(CBaseHMD & HMD); //This is the end of the road; this is the end of the line. This is the end of your life; this is the.....ENDGAME.
	void entCreation(int index, CLayer &layer, float x, float y);
	void * entCreation(int ID, std::string entName, List<std::string> params, float x, float y);
	void * createEnt(int entID, std::string name, std::string entName, List<std::string> params, float x, float y);
	void entLive(int index, CLayer &layer);
	void entDraw(int index, CLayer &layer);
	unsigned int ReadCompressed(FILE * fileStream);
	void setUpTileCoords();
	void createMapX(CBaseHMD HMD);
	void createHMD(CBaseHMD HMD); //most up to date version of the map generator
	static float tileCoordX[2500];
	static float tileCoordY[2500];
	static LinkedList entClassID; //container for the entity IDs
	static LinkedList entClasses; //container for the instantiation classes
	static int entClassCount = 0;
	static CEntInfo entInfo;
	//a databse for entities that interact with each other, i.e. a button opens a door
	

	/*template< class T > 
	class entClassContainer
	{
	public:
		entClassContainer(){}

		entClassContainer(int index)
		{
			entClassID.append(&index);
			entClasses.append(this);
			entClassCount++;
		}
		~entClassContainer(){}

		void * createEntity(int *m, float x, float y)
		{
			T* temp = new T();
			//set up map information
			HVSTGFX::adjustCoords(x, y);
			temp->x = x; temp->y = y;
			temp->x2 = temp->x + SCALEX_32; temp->y2 = temp->y - SCALEY_32;
			*m = temp->getID();
			return (temp);
		}

		void drawEnt(void * address)
		{
			T * temp = (T*)address;
			temp->Draw();
		}
		
		void liveEnt(void * address)
		{
			T * temp = (T*)address;
			temp->live();
		}
	};*/

	
};



#endif