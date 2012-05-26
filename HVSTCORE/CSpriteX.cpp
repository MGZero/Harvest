#include "CSpriteX.h"
#include <vector>
#include <iostream>

CSpriteX::CSpriteX(char *fileName, bool image)
{
	_loaded = false;
	_sprite = loadImageFile(fileName, &_imgFile, _texture);
	FreeImage_Unload(_imgFile.dib);
}

CSpriteX::CSpriteX(CFileData * file)
{
	_sprite = CSpriteX::loadImageFile(file, &_imgFile, _texture);
	//FreeImage_Unload(_imgFile.dib);
}

CSpriteX::~CSpriteX()
{
	/*delete [] _sprite;
	_sprite = 0;*/
	//FreeImage_Unload(_imgFile.dib);
}

unsigned char * CSpriteX::loadImageFile(CFileData *image, IMAGEFILE *imgFile, GLuint &texture)
{
	FREE_IMAGE_FORMAT fif = FreeImage_GetFIFFromFilename(image->getName().c_str());
	FIMEMORY * stream = 0;
	unsigned char tempRGB;
	GLuint tempTex = 0;
	GLenum errCode;
	bool error = false;

	stream = FreeImage_OpenMemory(image->getData(), image->getSize());

	//if(FreeImage_FIFSupportsReading(fif))
	imgFile->dib = FreeImage_LoadFromMemory(fif, stream);

	if(!imgFile->dib)
		return NULL;

	//pointer to image data
	unsigned char* bits;

	bits = FreeImage_GetBits(imgFile->dib);
	imgFile->width = FreeImage_GetWidth(imgFile->dib); imgFile->height = FreeImage_GetHeight(imgFile->dib);
	imgFile->size = sizeof(bits);
	int size = imgFile->width*imgFile->height;//(FreeImage_GetWidth(dib) * FreeImage_GetHeight(dib));

	if (size % 4 == 0)
		for (int imageIDx = 0; imageIDx < size * 4; imageIDx += 4)
		{
			tempRGB = bits[imageIDx];
			bits[imageIDx] = bits[imageIDx + 2];
			bits[imageIDx + 2] = tempRGB;
		}
	else
		for (int imageIDx = 0; imageIDx < size * 3; imageIDx += 3)
		{
			tempRGB = bits[imageIDx];
			bits[imageIDx] = bits[imageIDx + 2];
			bits[imageIDx + 2] = tempRGB;
		}
	
	glGenTextures(1, &tempTex);
	texture = tempTex;
	
	errCode = glGetError();

	glBindTexture(GL_TEXTURE_2D, texture);

	errCode = glGetError();
	
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, imgFile->width, imgFile->height, 0, GL_RGBA, GL_UNSIGNED_BYTE, bits);

	errCode = glGetError();
	
	return bits;	

}

unsigned char * CSpriteX::loadImageFile(char *fileName, IMAGEFILE *imgFile, GLuint &texture)
{
//FREE_IMAGE_FORMAT fif = FIF_PNG;

	FREE_IMAGE_FORMAT fif = FreeImage_GetFIFFromFilename(fileName);

	//pointer to the image data
	unsigned char* bits;
	unsigned char tempRGB;
	GLuint tempTex = 0;
	GLenum errCode;
	bool error = false;
	std::string file(fileName);
	
	if(FreeImage_FIFSupportsReading(fif))
		imgFile->dib = FreeImage_Load(fif, fileName);
	

	if(!imgFile->dib)
		return NULL;

	bits = FreeImage_GetBits(imgFile->dib);
	imgFile->width = FreeImage_GetWidth(imgFile->dib); imgFile->height = FreeImage_GetHeight(imgFile->dib);
	imgFile->size = sizeof(bits);
	int size = imgFile->width*imgFile->height;//(FreeImage_GetWidth(dib) * FreeImage_GetHeight(dib));

	if (size % 4 == 0)
		for (int imageIDx = 0; imageIDx < size * 4; imageIDx += 4)
		{
			tempRGB = bits[imageIDx];
			bits[imageIDx] = bits[imageIDx + 2];
			bits[imageIDx + 2] = tempRGB;
		}
	else
		for (int imageIDx = 0; imageIDx < size * 3; imageIDx += 3)
		{
			tempRGB = bits[imageIDx];
			bits[imageIDx] = bits[imageIDx + 2];
			bits[imageIDx + 2] = tempRGB;
		}
	
	glGenTextures(1, &tempTex);
	texture = tempTex;
	
	errCode = glGetError();
	if (errCode != GL_NO_ERROR)
		return NULL;
	
	glBindTexture(GL_TEXTURE_2D, texture);
	
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, imgFile->width, imgFile->height, 0, GL_RGBA, GL_UNSIGNED_BYTE, bits);
	
	return bits;
}

void CSpriteX::createImage(float x, float y)
{
	glBindTexture(GL_TEXTURE_2D, _texture);
	glColor4f(1.0f,1.0f,1.0f, 1.0f );
	static float width = _imgFile.width * SCALEX_1, height = _imgFile.height * SCALEY_1;


		glBegin(GL_QUADS);
			glTexCoord2f(0.0f, 0.0f); glVertex3f(x, y, 0.0f);
			glTexCoord2f(1.0f, 0.0f); glVertex3f(x + width, y, 0.0f);
			glTexCoord2f(1.0f, 1.0f); glVertex3f(x + width, y + height, 0.0f);
			glTexCoord2f(0.0f, 1.0f); glVertex3f(x, y + height, 0.0f);
		glEnd();
}