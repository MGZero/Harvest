#ifndef _GLMAIN_H_
#define _GLMAIN_H_

#include <windows.h>
#include <tchar.h>
//#include <gl/gl.h>
//#include <gl/glu.h>
#include "glew.h"
#include "wglew.h"
#include "FreeImage.h"
#include "stdio.h"
#include "stdlib.h"
#include <iostream>
#include <fstream>
#include <istream>
#include "global_Objects.h"


//sprite scales

#define SCALEX_1      (2.0f/320.0f)
#define SCALEX_2      SCALEX_1 * 2.0f
#define SCALEX_4      SCALEX_1 * 4.0f
#define SCALEX_8      SCALEX_1 * 8.0f
#define SCALEX_16     SCALEX_1 * 16.0f
#define SCALEX_32     SCALEX_1 * 32.0f
#define SCALEX_64     SCALEX_1 * 64.0f
#define SCALEX_128    SCALEX_1 * 128.0f
#define SCALEX_256    SCALEX_1 * 256.0f
#define SCALEX_512    SCALEX_1 * 512.0f

#define SCALEY_1      (2.0f/240.0f)
#define SCALEY_2      SCALEY_1 * 2.0f
#define SCALEY_4      SCALEY_1 * 4.0f
#define SCALEY_8      SCALEY_1 * 8.0f
#define SCALEY_16     SCALEY_1 * 16.0f
#define SCALEY_32     SCALEY_1 * 32.0f
#define SCALEY_64     SCALEY_1 * 64.0f
#define SCALEY_128    SCALEY_1 * 128.0f
#define SCALEY_256    SCALEY_1 * 256.0f
#define SCALEY_512    SCALEY_1 * 512.0f



#define BITMAP_ID 0x4D42
#define WIDTHSCALE .0125
#define HEIGHTSCALE .016875

namespace HVSTGFX
{
	class CSprite;
	class CAnimation;
	class CTile;
	class CXTileSheet;
	static int tempWidth, tempHeight;
	
	enum directions
	{
		UP = 0,
		RIGHT,
		DOWN,
		LEFT,
		DLeft,
		DRight,
		ULeft,
		URight
	};

	typedef struct
	{
		 int width;
		 int height;
		 DWORD size;
		 FIBITMAP * dib;
	} IMAGEFILE;

	unsigned char * loadImageFile(char *fileName, IMAGEFILE *imgFile, GLuint &texture);
	unsigned char * loadImageFile(CFileData *image, IMAGEFILE *imgFile, GLuint &texture);

	void createSprite(float width, float height, float x, float y, CSprite & sprite); //createSprite
	void createSpriteX(float width, float height, float x, float y, CSprite sprite); //createSpriteX

	void loadTiles(char *fileName, CXTileSheet &tileDump, int pixWidth, int pixHeight);  //loadTilesPNG
	void createTile(int tileID, float x, float y, CXTileSheet tileSht); //createTile

	bool animateX(HVSTGFX::CAnimation *frames, float x, float y); //animteX

	void adjustCoords(float& x, float& y); //needed for readHMD()
	void initGL();
	void SetupPixelFormat(HDC hDC);


	class CSprite
	{
	public:
		CSprite(){loaded = false; error = false;}
		CSprite(char * fileName);
		CSprite(char * fileName, bool image);
		CSprite(CFileData * data);
		~CSprite();

		
		unsigned char * sprite;
		GLuint texture;
		bool loaded;

		IMAGEFILE imgFile;

		int width, height;
		float animCount; //used for animation

		bool error;
		//float x, y; //used for the map file
	};

	class CXTileSheet
	{
	public:
		CXTileSheet(){}
		CXTileSheet(char * fileName, int pixWidth, int pixHeight);
		CXTileSheet(char * fileName, int pixWidth, int pixHeight, bool image);

		unsigned char * sheet;
		IMAGEFILE imgFile;
		int totalx, totaly, total;
		bool loaded;
		float *xCoords, *yCoords;
		float width, height;
		float glWidth, glHeight;
		int counter;
		GLuint texture;
			
		void calcCoordinates(int tileID);
		void initialize(char *fileName, int pixWidth, int pixHeight, bool image);

	};
	
	class CAnimation
	{
	public:
		CAnimation(CSprite * frames, int count, float speed, int width, int height);
		CAnimation(int count, float speed, int width, int height);
		~CAnimation(){}

		float frameCount;
		CSprite *sprites;
		List<CSprite*> mySprites;
		CSprite * currentFrame;
		int prevFrame;

		inline int getNumofFrames(){return numOfFrames;}
		void addSprite(CSprite *sprite);
		inline CSprite * getFrames(){return sprites;}
		inline CSprite getFrame(int index){return sprites[index];}
		CSprite getFrameX(int index); //getFrameX
		inline float getSpeed(){return speed;}
		inline float getWidth(){return width;}
		inline float getHeight(){return height;}
		void clearAnimation();

	private:
		
		int numOfFrames;
		float speed;
		float width, height;
		int frameTracker; //for the animationTrigger
		
		
	};

	class CAnimationTrigger : public CBaseEventTrigger
	{
	public:
		~CAnimationTrigger();
		CAnimationTrigger();
		void update(CAnimation * frames);
	};

	

};

#endif
