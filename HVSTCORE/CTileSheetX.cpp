#include "CTileSheetX.h"

CTileSheetX::CTileSheetX(char * fileName, bool image, int tileWidth, int tileHeight) :
CSpriteX(fileName, image)
{
	_counter = 0;

	_glWidth = (float)tileWidth/_imgFile.width;
	_glHeight = (float)tileHeight/_imgFile.height;
	_totalx = (_imgFile.width/tileWidth);
	_totaly = (_imgFile.height/tileHeight);
	_total = _totalx * _totaly;

	_xCoords = new float[_total]; _yCoords = new float[_total];

	for (int i = 0; i < _total; i++, _counter++)
		_calcCoordinates(i);
}

CTileSheetX::CTileSheetX(CFileData * data, int tileWidth, int tileHeight) :
CSpriteX(data)
{
	_counter = 0;

	_glWidth = (float)tileWidth/_imgFile.width;
	_glHeight = (float)tileHeight/_imgFile.height;
	_totalx = (_imgFile.width/tileWidth);
	_totaly = (_imgFile.height/tileHeight);
	_total = _totalx * _totaly;

	_xCoords = new float[_total]; _yCoords = new float[_total];

	for (int i = 0; i < _total; i++, _counter++)
		_calcCoordinates(i);
}


CTileSheetX::~CTileSheetX()
{
	delete [] _xCoords;
	delete [] _yCoords;
	_xCoords = 0;
	_yCoords = 0;
}

void CTileSheetX::_calcCoordinates(int tileID)
{
	static int xcount = 0, ycount = 0;

	//calculate the GL coordinates
	_xCoords[tileID] = (xcount++) * _glWidth;
	_yCoords[tileID] = (ycount)* _glHeight;

	
	if (xcount >= _totalx)
	{
		xcount = 0;
		ycount++;
	}

	if (_counter == _total - 1)
	{
		xcount = 0;
		ycount = 0;
	}
}

void CTileSheetX::createTile(int tileID, float x, float y)
{
	float widthAdd = (_imgFile.width/2)*WIDTHSCALE;
	float heightAdd = (_imgFile.height/2)*HEIGHTSCALE;

		glBindTexture(GL_TEXTURE_2D, _texture);
		glColor4f(1.0f,1.0f,1.0f, 1.0f );
		
		glBegin(GL_QUADS);
			glTexCoord2f(_xCoords[tileID], _yCoords[tileID]);                                                  glVertex3f(x, y, 0.0f);
			glTexCoord2f(_xCoords[tileID] + _glWidth, _yCoords[tileID]);									 glVertex3f(x + widthAdd, y, 0.0f);
			glTexCoord2f(_xCoords[tileID] + _glWidth, _yCoords[tileID] + _glHeight);				 glVertex3f(x + widthAdd, y + heightAdd, 0.0f);
			glTexCoord2f(_xCoords[tileID], _yCoords[tileID] + _glHeight);									 glVertex3f(x, y + heightAdd, 0.0f);
		glEnd();
}