#ifndef _CSPRITEX_H_
#define _CSPRITEX_H_

#include "glew.h"
#include "wglew.h"
#include "FreeImage.h"
#include "CFileData.h"

//sprite scales

#define SCALEX_1      .063500000000000000000000000000000000000000000000000000000000000000000f
#define SCALEX_2      SCALEX_1 * 2.0f
#define SCALEX_4      SCALEX_1 * 4.0f
#define SCALEX_8      SCALEX_1 * 8.0f
#define SCALEX_16     SCALEX_1 * 16.0f
#define SCALEX_32     SCALEX_1 * 32.0f
#define SCALEX_64     SCALEX_1 * 64.0f
#define SCALEX_128    SCALEX_1 * 128.0f
#define SCALEX_256    SCALEX_1 * 256.0f
#define SCALEX_512    SCALEX_1 * 512.0f

#define SCALEY_1      .008333333333333333333333333333333333333333333333333333333333333333333f
#define SCALEY_2      SCALEY_1 * 2.0f
#define SCALEY_4      SCALEY_1 * 4.0f
#define SCALEY_8      SCALEY_1 * 8.0f
#define SCALEY_16     SCALEY_1 * 16.0f
#define SCALEY_32     SCALEY_1 * 32.0f
#define SCALEY_64     SCALEY_1 * 64.0f
#define SCALEY_128    SCALEY_1 * 128.0f
#define SCALEY_256    SCALEY_1 * 256.0f
#define SCALEY_512    SCALEY_1 * 512.0f

#define WIDTHSCALE .012500000000000000000000000000000000f
#define HEIGHTSCALE .016875000000000000000000000000000000f

typedef struct
{
	int width;
	int height;
	DWORD size;
	FIBITMAP * dib; //this is only used temporarily.  It should be cleaned up immediately after its use.
} IMAGEFILE;

class CSpriteX
{
public:
		CSpriteX(char * fileName, bool image);
		CSpriteX(CFileData * file);
		CSpriteX(){}
		virtual ~CSpriteX();

		static unsigned char * loadImageFile(char *fileName, IMAGEFILE *imgFile, GLuint &texture);
		static unsigned char * loadImageFile(CFileData *image, IMAGEFILE *imgFile, GLuint &texture);
		//void createSprite(float width, float height, float x, float y, CSprite & sprite); //createSprite
		virtual void createImage(float x, float y); //createSprite

private:
		bool _error;

		unsigned char * _sprite;
		bool _loaded;
		float _animCount; //used for animation

protected:
	IMAGEFILE _imgFile;
	GLuint _texture;

};

#endif