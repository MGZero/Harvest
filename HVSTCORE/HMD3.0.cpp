#include "HMD3.0.h"

CHMD3_0::CHMD3_0(CFileData * data)
{
	int intReader = 0;
	double doubleReader = 0;
	std::string stringReader = "";
	__int64 position = 3;

	doubleReader = data->toDouble(position);
	position += 8;

	if (doubleReader != 3.0)
	{
		throw "Incorrect map format!";
		return;
	}

	//map ID
	stringReader = data->getDataRange(position, 5);
	position += 5;
	intReader = data->toInt(position);
	position += 4;

	//create the data stream
	_dataStream = new CDataStream(data);

}

CHMD3_0::CHMD3_0(std::string fileName)
{
	int intReader = 0;
	double doubleReader = 0;
	std::string stringReader = "";
	FILE * mapFile = fopen(fileName.c_str(), "rb");
	//read header
	
	//first, the HMD Version
	fread(&stringReader, 3, 1, mapFile);
	fread(&doubleReader, sizeof(doubleReader), 1, mapFile);

	if (doubleReader != 3.0)
	{
		throw "Incorrect map format!";
		fclose(mapFile);
		return;
	}

	//read in mapID
	fread(&stringReader, 5,1,mapFile);
	fread(&intReader, sizeof(intReader),1,mapFile);

	//create datastream, which also creates the content stream
	_dataStream = new CDataStream(mapFile);

	//close the stream
	fclose(mapFile);
}

CHMD3_0::~CHMD3_0()
{
	delete _dataStream;
}

void CHMD3_0::_setUpTileCoords()
{
	//float x = -2.5f, y = -3.375f; 
	float x = -(SCALEX_1*400.0), y = -(SCALEY_1*400.0);
	//set up tile coordinates
	for (int i = 0; i < 2500; i++)
	{
		static int counter = 0;
		_tileCoords[i].X = x;
		_tileCoords[i].Y = y;

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

void CHMD3_0::createMap()
{
	/*for (int i = 0; i < _dataStream->layers.count(); i++)
	{
		CLayer3_0 * tempLayer = _dataStream->layers[i];

		//process stuff
		for (int entities = 0; entities < tempLayer->entities.size(); entities++)
			tempLayer->entities[entities]->live();

		//draw!!
		for (int tiles = 0; tiles < 2500; tiles++)
		{
			//HVSTGFX::createTile(tempLayer->tiles[tiles], _tileCoords[tiles].magnitudeX, _tileCoords[tiles].magntidueY, 
		}
	}*/
}