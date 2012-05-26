#include "HMD.h"
#include "HED.h"
#include <stdio.h>
#include "stdlib.h"
#include <iostream>
#include <fstream>
#include <istream>
#include "global_Objects.h"

void HMDFunc::entCreation(int index, CLayer &layer, float x, float y)
{
/*	int *z = 0;
	for (int i = 0; i < layer.getEntCount(); i++)
	{
		z = (int*)entClassID.retrieveSequential(i);
		if (*z == index)
			break;
		else
			*z = -1;
	}*/

	
}

void * HMDFunc::entCreation(int ID, std::string entName, List<std::string> params, float x, float y)
{
	std::string name = "";
	name = entInfo.entLookUp(ID);
	return createEnt(ID, name, entName, params, x, y);
}

void * HMDFunc::createEnt(int entID, std::string name, std::string entName, List<std::string> params, float x, float y)
{
	DETERMINE_ENT();
}

void HMDFunc::readMapX(const char * fileName, CBaseHMD &HMD)
{
	CBaseHMD tempHMD;
	CBaseHitBox *tempHB;
	FILE *mapFile = fopen(fileName, "rb");
	int length = 0;
	char temp;
	std::string tempSTR = "";
	std::string HEDURL = "";
	//layer stuff
	CLayer tempLayer; //remove
	CLayerX * tempLayerX;
	int ID = 0;
	int x = 0;
	int y = 0;
	int x2 = 0;
	int y2 = 0;
	bool errors = false;
	std::string file(fileName);

	glbl->debugger->writeString("Opening map " + file + "\n\n");
	
	tempLayer.playerCount = 0;
	tempLayer.bushCount = 0;
	tempLayer.waterCount = 0;

	if (!mapFile)
	{
		glbl->debugger->writeString("Failed to load map\n");
		return;
	}

	//read in tileSet URL
	length = ReadCompressed(mapFile);
	for (int i = 0; i < length; i++)
	{
		fread(&temp, 1, 1, mapFile);
		if (temp == '\\')
			temp = '/';
		tempSTR = temp;
		HEDURL.append(tempSTR);
	}
	char* tileURL = new char[HEDURL.size()];
	tileURL[HEDURL.size()] = 0;
	memcpy(tileURL, HEDURL.c_str(), HEDURL.size());	
	HVSTGFX::loadTiles(tileURL, tempHMD.tileSet, 16, 16);

	//HED URL
	//length = ReadCompressed(mapFile);
	//fseek(mapFile, length, SEEK_CUR);
	
	//read in layer count
	fread(&tempHMD.layerCount, sizeof(tempHMD.layerCount), 1, mapFile);

	//read in layers
	for (int i = 0; i < tempHMD.layerCount; i++)
	{
		tempLayerX = new CLayerX(i);
		//read in the name and throw it away
		length = ReadCompressed(mapFile);
		for (int j = 0; j < length; j++)
			fread(&temp, 1,1, mapFile);

		//read in tile IDs
		for (int j = 0; j < 2500; j++)
		{
			fread(&length, sizeof(length), 1, mapFile);
			tempLayer.setTile(j, length);
			tempLayerX->tiles[j] = length;
		}

		//read in the number of entities
		fread(&length, sizeof(length), 1,mapFile);
		tempLayer.entCount = length;
		tempLayerX->entCount = length;
		//read in the entity ID and their coordinates
		for (int j = 0; j < length; j++)
		{
			fread(&ID, sizeof(ID), 1, mapFile);
			fread(&x, sizeof(x), 1, mapFile);
			fread(&y, sizeof(y), 1, mapFile);

			tempLayer.determineEnt(ID, x, y, i);
			//tempLayerX->entityMap.
			entCreation(ID, tempLayer, x,y);

		}

		//read in the hitboxes
		fread(&length, sizeof(length), 1, mapFile);
		for(int j = 0; j < length; j++)
		{
			fread(&x, sizeof(x), 1, mapFile);
			fread(&y, sizeof(y), 1, mapFile);
			fread(&x2, sizeof(x2), 1, mapFile);
			fread(&y2, sizeof(y2), 1, mapFile);

			tempHB->x = x;
			tempHB->y = y + 14;
			tempHB->x2 = x2;
			tempHB->y2 = y2 + 14;

			//tempHB.y = 800 - y - 32;//flip the axis
			//tempHB.y2 = 800 - y2 - 32;
			HVSTGFX::adjustCoords(tempHB->x, tempHB->y);
			HVSTGFX::adjustCoords(tempHB->x2, tempHB->y2);
			tempLayer.hitBoxes.push_back(*tempHB);
			tempLayer.hitBoxCount++;
			
		}
		tempHMD.layers.push_back(tempLayer);
		tempLayer.clear();
	}
	//read in bgm url
	HEDURL = "";
	length = ReadCompressed(mapFile);
	for (int i = 0; i < length; i++)
	{
		fread(&temp, 1, 1, mapFile);
		if (temp == '\\')
			temp = '/';
		tempSTR = temp;
		HEDURL.append(tempSTR);
	}

	//first, check if the ogg exists
	HEDURL[length - 3] = 'o';
	HEDURL[length - 2] = 'g';
	HEDURL[length - 1] = 'g';

	FILE * oggTest = fopen(HEDURL.c_str(), "rb");
	
	if (!oggTest)
	{
		HEDURL[length - 3] = 'm';
		HEDURL[length - 2] = 'i';
		HEDURL[length - 1] = 'd';
	}
	else
		fclose(oggTest);

	char* BGMURL = new char[HEDURL.size()];
	BGMURL[HEDURL.size()] = 0;
	memcpy(BGMURL, HEDURL.c_str(), HEDURL.size());

	tempHMD.BGM = new CBaseSound(BGMURL, true);
	HMD = tempHMD;
}

void HMDFunc::createMapX(CBaseHMD HMD)
{

	static int counter = 0;
	void * entAddress[4];

	if (!HMD.BGM->active)
	{
		HMD.BGM->emitSound();
		HMD.BGM->active = true;
	}
	for (int i = 0; i < HMD.layerCount; i++)
	{
		
		for (int j = 0; j < HMD.layers[i].getEntCount(); j++)
		{
			int *ID = (int*)HMD.layers[i].entityID.retrieveSequential(j);
			void *entAddress = HMD.layers[i].entities.retrieveSequential(j);
			
		}
	}

	//call draw functions here
	for (int i = 0; i < HMD.layerCount; i++)
	{
		for (int j = 0; j < 2500; j++)
			if (HMD.layers[i].getTileNum(j) != -1)
			{
				HVSTGFX::createTile(HMD.layers[i].getTileNum(j), tileCoordX[j], tileCoordY[j], HMD.tileSet);
			}

		//if (HMD.layers[i].playerCount > 0)
		//	HMD.layers[i].player[0]->Draw();

		for (int j = 0; j < HMD.layers[i].getEntCount(); j++)
		{
			int *ID = (int*)HMD.layers[i].entityID.retrieveSequential(j);
			void *entAddress = HMD.layers[i].entities.retrieveSequential(j);
		}
	}
}

void HMDFunc::setUpTileCoords()
{
	//float x = -2.5f, y = -3.375f; 
	float x = -(SCALEX_1*400.0), y = -(SCALEY_1*400.0);
	//set up tile coordinates
	for (int i = 0; i < 2500; i++)
	{
		static int counter = 0;
		tileCoordX[i] = x;
		tileCoordY[i] = y;

		counter++;

		x += 16*SCALEX_1;//.1f;
		if (counter == 50)
		{
			counter = 0;
			x = -(SCALEX_1*400.0);
			y += 16*SCALEY_1;//.135f;
		}
	}
}

unsigned int HMDFunc::ReadCompressed(FILE * fileStream)
{
    unsigned int value = 0;  // Swap out for highest type of read data.
    unsigned char byte = 0;

    // Do while there are bits to read.
    do
    {
        value <<= 7;

        // Get byte's value.
        fread(&byte, sizeof(char), 1, fileStream);

        // Calculate value.
        value |= byte & 0x7F;

    } while (byte & 0x80);

    // Return value.
    return value;
}

void HMDFunc::createHMD(CBaseHMD & HMD)
{
	int ID = 0;
	List<void*> * tempList;
	std::string name = "";
	if (!HMD.BGM->active)
	{
		HMD.BGM->emitSound();
		HMD.BGM->active = true;
	}


	for (int i = 0; i < HMD.layersX.count(); i++)
	{
		//process live() calls
		for (int j = 0; j < HMD.layersX[i]->entityMap.count(); j++)
		{
			//retrieve ID of the key and then cycle through each list
			ID = HMD.layersX[i]->entityMap.Keys()[j];
			for(int k = 0; k < HMD.layersX[i]->entityMap[ID]->count(); k++)
			{
				name = entInfo.entLookUp(ID);
				tempList = HMD.layersX[i]->entityMap[ID];
				LIVE_ENT();
				
			}
		}

		//DRAW THAT SHIT!!!!!!!!!

		for (int j = 0; j < 2500; j++)
			if (HMD.layers[i].getTileNum(j) != -1)
			{
				HVSTGFX::createTile(HMD.layers[i].getTileNum(j), tileCoordX[j], tileCoordY[j], HMD.tileSet);
			}


		for (int j = 0; j < HMD.layersX[i]->entityMap.count(); j++)
		{
			ID = HMD.layersX[i]->entityMap.Keys()[j];

			for(int k = 0; k < HMD.layersX[i]->entityMap[ID]->count(); k++)
			{
				name = entInfo.entLookUp(ID);
				tempList = HMD.layersX[i]->entityMap[ID];
				DRAW_ENT();
				
			}
			
		}
	}

}

void HMDFunc::readHMD(std::string fileName, CBaseHMD &HMD)
{
	FILE * HMDFile = fopen(fileName.c_str(), "rb");
	std::string FID = "", FOD = "", BGM = "", BGI = "", tileSht = "";
	std::string entName = "";
	List<std::string> params;
	std::string strGarbage = "";
	int intGarbage = 0;
	int mEventCount = 0;
	int sEventCount = 0;
	int paramCount = 0;
	int strLengths = 0;
	int entX = 0, entY = 0;
	int entID = 0;
	char charGarbage;
	CBaseVector topLeft, bottomRight;
	void * entAddress = 0;

	fread(&intGarbage, sizeof(intGarbage), 1, HMDFile);
	for (int i = 0; i < intGarbage; i++)
	{
		fread(&charGarbage, 1,1,HMDFile);
		BGM += charGarbage;
	}

	fread(&intGarbage, sizeof(intGarbage), 1, HMDFile);
	for (int i = 0; i < intGarbage; i++)
	{
		fread(&charGarbage, 1,1,HMDFile);
		FID += charGarbage;
	}

	fread(&intGarbage, sizeof(intGarbage), 1, HMDFile);
	for (int i = 0; i < intGarbage; i++)
	{
		fread(&charGarbage, 1,1,HMDFile);
		FOD += charGarbage;
	}

	fread(&intGarbage, sizeof(intGarbage), 1, HMDFile);
	for (int i = 0; i < intGarbage; i++)
	{
		fread(&charGarbage, 1,1,HMDFile);
		BGI += charGarbage;
	}
	
	fread(&intGarbage, sizeof(intGarbage), 1, HMDFile);
	for (int i = 0; i < intGarbage; i++)
	{
		fread(&charGarbage, 1,1,HMDFile);
		tileSht += charGarbage;
	}

	//create the map properties here

	//and now do the layer stuff
	fread(&intGarbage, sizeof(intGarbage), 1, HMDFile);
	HMD.layerCount = intGarbage;

	for (int i = 0; i < HMD.layerCount; i++)
	{
		HMD.layersX.add(new CLayerX(i));
		//read the layer name
		fread(&intGarbage, sizeof(intGarbage),1,HMDFile);
		for (int j = 0; j < intGarbage; j++)
			fread(&charGarbage, 1,1,HMDFile);
		
		//read the tiles
		for (int j = 0; j < 2500; j++)
		{
			fread(&intGarbage, sizeof(intGarbage),1,HMDFile);
			//HMD.layersX[i]->setTile(intGarbage, j);
			HMD.layersX[i]->tiles[j] = intGarbage;
		}
		
		//read the entities - this is where the torture is
		fread(&HMD.layersX[i]->entCount,sizeof(HMD.layersX[i]->entCount),1,HMDFile);
		for (int j = 0; j < HMD.layersX[i]->entCount; j++)
		{
			//read in the ID and name
			fread(&entID, sizeof(entID),1,HMDFile);
			fread(&intGarbage, sizeof(intGarbage),1,HMDFile);
			for (int k = 0; k < intGarbage; k++)
			{
				fread(&charGarbage, 1,1,HMDFile);
				entName += charGarbage;
			}
			fread(&entX,sizeof(entX),1,HMDFile);
			fread(&entY, sizeof(entY),1,HMDFile);
			
			//read the parameter values
			fread(&paramCount, sizeof(paramCount),1,HMDFile);
			for (int k = 0; k < intGarbage; k++)
			{
				strGarbage = "";
				fread(&intGarbage, sizeof(intGarbage),1,HMDFile);
				for(int l = 0; l < intGarbage; l++)
				{
					fread(&charGarbage, 1,1,HMDFile);
					strGarbage += charGarbage;
				}
				params.add(strGarbage);
			}
			strGarbage = "";
			entAddress = entCreation(entID, entName, params, entX, entY);
			HMD.layersX[i]->addEntity(entID, entAddress);

			//this happens last after all the data has been read for this entity
			//the entity constructor will handle any needed parameters
			
			HMD.layersX[i]->entCount++;
		}

		//hitboxes
		fread(&intGarbage, sizeof(intGarbage),1,HMDFile);
		for (int j = 0; j < intGarbage; j++)
		{
			fread(&topLeft.X, 4,1,HMDFile);
			fread(&topLeft.Y, 4,1,HMDFile);
			fread(&bottomRight.X, 4,1,HMDFile);
			fread(&bottomRight.Y, 4,1,HMDFile);

			HMD.layersX[i]->hitboxes.add(new CBaseHitBox(topLeft.X,topLeft.Y,bottomRight.X,bottomRight.Y));
		}
	}
	
}

