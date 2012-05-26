#include <stdio.h>
#include <stdlib.h>
#include "glMain.h"
#include <windows.h>

HVSTGFX::CAnimationTrigger::CAnimationTrigger()
{
	CBaseEvent * animEnd = new CBaseEvent("Animation End");
	CBaseEvent * animBegin = new CBaseEvent("Animation Begin");
	CBaseEvent * animFrame = new CBaseEvent("Animation Frame");

	_addEvent(animEnd);
	_addEvent(animBegin);
	_addEvent(animFrame);
}

HVSTGFX::CAnimationTrigger::~CAnimationTrigger()
{
}

void HVSTGFX::CAnimationTrigger::update(CAnimation * frames)
{
	//check animationEnd
	if (frames->frameCount == frames->getNumofFrames())
		signalHandler(_events[0]);
	else if (frames->frameCount == 0)
		signalHandler(_events[1]);
}

unsigned char * HVSTGFX::loadImageFile(CFileData *image, HVSTGFX::IMAGEFILE *imgFile, GLuint &texture)
{
	FREE_IMAGE_FORMAT fif = FreeImage_GetFIFFromFilename(image->getName().c_str());
	FIMEMORY * stream = 0;
	unsigned char tempRGB;
	GLuint tempTex = 0;
	GLenum errCode;
	bool error = false;

	stream = FreeImage_OpenMemory(image->getData());

	if(FreeImage_FIFSupportsReading(fif))
	imgFile->dib = FreeImage_LoadFromMemory(fif, stream);

	if(!imgFile->dib)
	{
		glbl->debugger->writeString("failed to open sprite " + image->getName());
		return NULL;
	}

	//pointer to image data
	unsigned char* bits;

	bits = FreeImage_GetBits(imgFile->dib);
	imgFile->width = FreeImage_GetWidth(imgFile->dib); imgFile->height = FreeImage_GetHeight(imgFile->dib);
	imgFile->size = sizeof(bits);
	int size = imgFile->width*imgFile->height;//(FreeImage_GetWidth(dib) * FreeImage_GetHeight(dib));

	for (int imageIDx = 0; imageIDx < size * 4; imageIDx += 4)
	{
		tempRGB = bits[imageIDx];
		bits[imageIDx] = bits[imageIDx + 2];
		bits[imageIDx + 2] = tempRGB;
	}
	
	glGenTextures(1, &tempTex);
	texture = tempTex;
	
	errCode = glGetError();
	if (errCode != GL_NO_ERROR)
	{
		MessageBox(NULL, _T("Unable to detect OpenGL support. Check if you have your graphics driver installed, or if your graphics card supports OpenGL."), NULL, NULL);
	}
	glBindTexture(GL_TEXTURE_2D, texture);
	
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, imgFile->width, imgFile->height, 0, GL_RGBA, GL_UNSIGNED_BYTE, bits);
	
	//FreeImage_Unload(dib);
	
#ifdef _DEBUG
	if (!error)
		glbl->debugger->writeString("successfully loaded sprite " + image->getName() + "\n");
#endif
	return bits;

}

unsigned char * HVSTGFX::loadImageFile(char *fileName, HVSTGFX::IMAGEFILE * imgFile,  GLuint &texture)
{
	//FREE_IMAGE_FORMAT fif = FIF_PNG;

	FREE_IMAGE_FORMAT fif = FreeImage_GetFIFFromFilename(fileName);

	//pointer to the image data
	unsigned char* bits;
	unsigned char tempRGB;
	GLuint tempTex = 0;
	GLenum errCode;
	const unsigned char *errString;
	bool error = false;
	std::string file(fileName);
	
	if(FreeImage_FIFSupportsReading(fif))
		imgFile->dib = FreeImage_Load(fif, fileName);
	

	if(!imgFile->dib)
	{
		glbl->debugger->writeString("failed to open sprite " + *fileName);
		return NULL;
	}

	bits = FreeImage_GetBits(imgFile->dib);
	imgFile->width = FreeImage_GetWidth(imgFile->dib); imgFile->height = FreeImage_GetHeight(imgFile->dib);
	imgFile->size = sizeof(bits);
	int size = imgFile->width*imgFile->height;//(FreeImage_GetWidth(dib) * FreeImage_GetHeight(dib));

	for (int imageIDx = 0; imageIDx < size * 4; imageIDx += 4)
	{
		tempRGB = bits[imageIDx];
		bits[imageIDx] = bits[imageIDx + 2];
		bits[imageIDx + 2] = tempRGB;
	}
	
	glGenTextures(1, &tempTex);
	texture = tempTex;
	
	errCode = glGetError();
	if (errCode != GL_NO_ERROR)
	{
		MessageBox(NULL, _T("Unable to detect OpenGL support. Check if you have your graphics driver installed, or if your graphics card supports OpenGL."), NULL, NULL);
	}
	glBindTexture(GL_TEXTURE_2D, texture);
	
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, imgFile->width, imgFile->height, 0, GL_RGBA, GL_UNSIGNED_BYTE, bits);
	
	//FreeImage_Unload(dib);
	
#ifdef _DEBUG
	if (!error)
		glbl->debugger->writeString("successfully loaded sprite " + file + "\n");
#endif
	return bits;
}

HVSTGFX::CSprite::~CSprite()
{
	//sprite = 0;
	//FreeImage_Unload(imgFile.dib);
}

HVSTGFX::CSprite::CSprite(char *fileName, bool image)
{
	loaded = false;
	sprite = loadImageFile(fileName, &imgFile, texture);
	FreeImage_Unload(imgFile.dib);
	width = tempWidth; height = tempHeight;
}

//remove this and update the references
void HVSTGFX::createSprite(float width, float height, float x, float y, CSprite & sprite)
{
	glBindTexture(GL_TEXTURE_2D, sprite.texture);
	glColor4f(1.0f,1.0f,1.0f, 1.0f );
		
		glBegin(GL_QUADS);
			glTexCoord2f(0.0f, 0.0f); glVertex3f(x, y, 0.0f);
			glTexCoord2f(1.0f, 0.0f); glVertex3f(x + width, y, 0.0f);
			glTexCoord2f(1.0f, 1.0f); glVertex3f(x + width, y + height, 0.0f);
			glTexCoord2f(0.0f, 1.0f); glVertex3f(x, y + height, 0.0f);
		glEnd();
}

void HVSTGFX::loadTiles(char *fileName, HVSTGFX::CXTileSheet &tileDump, int pixWidth, int pixHeight)
{

	static int texCount = 2;
	tileDump.counter = 0;
	tileDump.sheet = HVSTGFX::loadImageFile(fileName, &tileDump.imgFile, tileDump.texture);
	tileDump.loaded = false;
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, tileDump.imgFile.width, tileDump.imgFile.height, 0, GL_RGBA, GL_UNSIGNED_BYTE, tileDump.sheet);

	tileDump.width = pixWidth; tileDump.height = pixHeight;
	tileDump.glWidth = tileDump.width/tileDump.imgFile.width;
	tileDump.glHeight = tileDump.height/tileDump.imgFile.height;
	tileDump.totalx = (tileDump.imgFile.width/pixWidth);
	tileDump.totaly = (tileDump.imgFile.height/pixHeight);
	tileDump.total = tileDump.totalx*tileDump.totaly;

	tileDump.xCoords = new float[tileDump.total]; tileDump.yCoords = new float[tileDump.total];

	for (int i = 0; i < tileDump.total; i++, tileDump.counter++)
		tileDump.calcCoordinates(i);
}

void HVSTGFX::createTile(int tileID, float x, float y, HVSTGFX::CXTileSheet tileSht)
{
	float widthAdd = (tileSht.width/2)*WIDTHSCALE;
	float heightAdd = (tileSht.height/2)*HEIGHTSCALE;

		glBindTexture(GL_TEXTURE_2D, tileSht.texture);
		glColor4f(1.0f,1.0f,1.0f, 1.0f );
		
		glBegin(GL_QUADS);
			glTexCoord2f(tileSht.xCoords[tileID], tileSht.yCoords[tileID]);                                                  glVertex3f(x, y, 0.0f);
			glTexCoord2f(tileSht.xCoords[tileID] + tileSht.glWidth, tileSht.yCoords[tileID]);									 glVertex3f(x + widthAdd, y, 0.0f);
			glTexCoord2f(tileSht.xCoords[tileID] + tileSht.glWidth, tileSht.yCoords[tileID] + tileSht.glHeight);				 glVertex3f(x + widthAdd, y + heightAdd, 0.0f);
			glTexCoord2f(tileSht.xCoords[tileID], tileSht.yCoords[tileID] + tileSht.glHeight);									 glVertex3f(x, y + heightAdd, 0.0f);
		glEnd();
}

bool HVSTGFX::animateX(HVSTGFX::CAnimation *frames, float x, float y)
{
    HVSTGFX::createSprite(frames->getWidth(), frames->getHeight(),
							  x, y, *frames->mySprites[(int)frames->frameCount]);

		
	frames->frameCount += frames->getSpeed();
	if (frames->frameCount >= frames->getNumofFrames())
	{
		frames->frameCount = 0;
		return true;
	}
	else
		return false;

}

HVSTGFX::CAnimation::CAnimation(HVSTGFX::CSprite * frames, int count, float speed, int width, int height)
{
	sprites = new HVSTGFX::CSprite[count];

	for (int i = 0; i < count; i++)
	{
		sprites[i].animCount = frames[i].animCount;
		sprites[i].error = frames[i].error;
		sprites[i].height = frames[i].error;
		sprites[i].loaded = frames[i].loaded;
		sprites[i].imgFile = frames[i].imgFile;
		sprites[i].sprite = frames[i].sprite;
		sprites[i].texture = frames[i].texture;
		sprites[i].width = frames[i].width;
		
	}

	numOfFrames = count;
	this->speed = speed;
	this->width = (float)width * SCALEX_1;
	this->height = (float)height * SCALEY_1;
	frameCount = 0;
}

HVSTGFX::CAnimation::CAnimation(int count, float speed, int width, int height)
{
	numOfFrames = count;
	this->speed = speed;
	frameCount = 0;
	prevFrame = 0;
	currentFrame = 0;
	this->width = (float)width * SCALEX_1;
	this->height = (float)height * SCALEY_1;
}

void HVSTGFX::CAnimation::addSprite(HVSTGFX::CSprite *sprite)
{
	mySprites.add(sprite);

	if (mySprites.count() == 1)
		currentFrame = mySprites[0];
}

HVSTGFX::CSprite HVSTGFX::CAnimation::getFrameX(int index)
{
	void * address = 0;
	HVSTGFX::CSprite *data = 0;

	//address = mySprites.retrieveSequential(index);
	data = (HVSTGFX::CSprite*)address;

	return *data;
}


void HVSTGFX::CXTileSheet::calcCoordinates(int tileID)
{
	static int xcount = 0, ycount = 0;
	//calculate the GL coordinates
	xCoords[tileID] = (xcount++) * glWidth;
	yCoords[tileID] = (ycount)* glHeight;

	
	if (xcount >= totalx)
	{
		xcount = 0;
		ycount++;
	}

	if (counter == total - 1)
	{
		xcount = 0;
		ycount = 0;
	}
}

void HVSTGFX::SetupPixelFormat(HDC hDC)
{
	 /*      Pixel format index
        */
        int nPixelFormat;

        static PIXELFORMATDESCRIPTOR pfd = {
                sizeof(PIXELFORMATDESCRIPTOR),          //size of structure
                1,                                      //default version
                PFD_DRAW_TO_WINDOW |                    //window drawing support
                PFD_SUPPORT_OPENGL |                    //opengl support
                PFD_DOUBLEBUFFER,                       //double buffering support
                PFD_TYPE_RGBA,                          //RGBA color mode
                32,                                     //32 bit color mode
                0, 0, 0, 0, 0, 0,                       //ignore color bits
                0,                                      //no alpha buffer
                0,                                      //ignore shift bit
                0,                                      //no accumulation buffer
                0, 0, 0, 0,                             //ignore accumulation bits
                16,                                     //16 bit z-buffer size
                0,                                      //no stencil buffer
                0,                                      //no aux buffer
                PFD_MAIN_PLANE,                         //main drawing plane
                0,                                      //reserved
                0, 0, 0 };                              //layer masks ignored

                /*      Choose best matching format*/
                nPixelFormat = ChoosePixelFormat(hDC, &pfd);

                /*      Set the pixel format to the device context*/
                SetPixelFormat(hDC, nPixelFormat, &pfd);
}

void HVSTGFX::initGL()
{
	//glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);
	glFrontFace(GL_CCW);
	glEnable(GL_TEXTURE_2D);
	glEnable(GL_BLEND);
	glEnable(GL_ALPHA_TEST);
	
}

void HVSTGFX::CAnimation::clearAnimation()
{
	mySprites.clear();
}


void HVSTGFX::adjustCoords(float& x, float& y)
{
	x -= 400.0f; //adjust to a pos/neg value
	x *= .00625f; //adjust to the GL coordinate

	y -= (400.0f - 16.0f); //adjust to a pos/neg value
	y *= .0084375f; //adjust to the GL coordinate
	y *= -1;
}