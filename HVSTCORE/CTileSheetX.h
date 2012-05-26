#ifndef _CTILESHEETX_H_
#define _CTILESHEETX_H_

#include "CSpriteX.h"

class CTileSheetX : public CSpriteX
{
public:
	CTileSheetX(char * fileName, bool image, int tileWidth, int tileHeight);
	CTileSheetX(CFileData * data, int tileWidth, int tileHeight);
	~CTileSheetX();

	void createTile(int tileID, float x, float y);
	inline float getXCoord(int i){return _xCoords[i];}
	inline float getYCoord(int i){return _yCoords[i];}

private:

	int _totalx, _totaly, _total;
	float * _xCoords, * _yCoords;
	float _glWidth, _glHeight;
	int _counter;
	GLuint _texture;
			
	void _calcCoordinates(int tileID);
};

#endif