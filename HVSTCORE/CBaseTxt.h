//#ifndef _CBASETXT_H_
//#define _CBASETXT_H_
//
//#include "theoreticalEnt.h"
//#include "glmain.h"
//#include "HVSTDATMAIN.h"
//#include <vector>
//#include "CBaseSound.h"
//
//
//class CBaseTXT
//{
//public:
//	CBaseTXT();
//	~CBaseTXT();
//	HVSTGFX::CXTileSheet charSheet, charSheetB, charSheetR, charSheetG, charSheetW;
//	float x, y;
//};
//
//
//class CBaseTXTBox : public CBaseTheoryEnt
//{
//	
//	
//public:
//	CBaseTXTBox(){box.sprite = HVSTGFX::loadImageFile("resource/sprites/text/txtBox.png", &box.imgFile, box.texture);}
//	CBaseTXTBox(int boxCount, std::string * textBoxes);
//	~CBaseTXTBox(){};
//
//	void addBox(std::string text);
//	void drawTextBox(float x, float y);
//	void drawText(float x, float y);
//	void drawTextBoxX(float x, float y, bool drawBox);
//	void parseString(int block, float x, float y); //block: which data chunk to read
//	void parseStringX(int block, float x, float y);
//	int getScroll(){return scrollCount;}
//
//	HVSTGFX::CSprite box;
//	HVSTDAT<std::string> words;
//	std::vector<std::string> word;
//	CBaseTXT text;
//	int blockCount;
//	bool draw;
//	int countDown;
//
//	
//	
//
//private:
//	
//	
//	
//	float privX, privY;
//	bool reset;
//	int scrollCount;
//
//
//
//};
//
//
//#endif
