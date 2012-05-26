#ifndef _CLAYER_H_
#define _CLAYER_H_

#include <vector>

#include "HVSTMTH.h"
#include "CBaseHitBox.h"
#include "CBasePlayer.h"
#include "CBaseBush.h"
#include "CBaseWater.h"
#include "LinkedList.h"


class CLayer
{

public:

	CLayer(){containsPlayer = false;}
	~CLayer();

	inline int getLayerNum(){return layerNum;}
	inline int getTileNum(int tileID){return tiles[tileID];}
	inline int getHBCount(){return hitBoxCount;}
	inline int getEntCount(){return entCount;}
	inline void setLayerNum(int val){layerNum = val;}
	inline void setHBCount(int val){hitBoxCount = val;}
	inline void setTile(int tile, int ID){tiles[tile] = ID;}
	inline void initialize(CLayer data);
	inline void setEntCount(int val){entCount = val;}
	void determineEnt(int ID, float x, float y, int layerNum);
	std::vector<CBaseHitBox> hitBoxes;
	bool containsPlayer;

	//entities X_X 
	//OLD DO NOT USE
	std::vector<CBasePlayer *> player;
	std::vector<CBaseBush *> bush;
	std::vector<CBaseWater *> water;
	LinkedList entities;
	LinkedList entityID;
	int playerCount;
	int bushCount;
	int waterCount;
	std::map<int, List<void *>> entityMap;
	

	int hitBoxCount;
	void clear();
	int entCount;

	

private:
	int layerNum;
	int tiles[2500];
	
	
	
	
};

#endif