//#include "CBaseTxt.h"

//void CBaseTXTBox::addBox(std::string text)
//{
//	word.insert(word.end(), text);
//}
//
//CBaseTXTBox::CBaseTXTBox(int boxCount, std::string * textBoxes)
//{
//	box.sprite = HVSTGFX::loadImageFile("resource/sprites/text/txtBox.png", &box.imgFile, box.texture);
//	blockCount = boxCount;
//	box.loaded = false;
//
//	for (int i = 0; i < boxCount; i++)
//	{
//		addBox(textBoxes[i]);
//	}
//	myEvents.onWait = false;
//	draw = true;
//	countDown = 0;
//	reset = false;
//	scrollCount = 0;
//
//}
//
//void CBaseTXTBox::parseString(int block, float x, float y)
//{
//	std::string str = "";
//	int length = 0;
//
//
//	text.x = x; text.y = y; //-.9f, -.6f
//	privX = -.9f; privY = -0.6f;
//	str = word.at(block);
//	length = str.length();
//	
//	for (int i = 0; i < length; i++)
//	{
//		//glBindTexture(GL_TEXTURE_2D, text.charSheet.texture);
//		HVSTGFX::createTile( ((int)str.at(i)) - 32, text.x, text.y, text.charSheet);
//		privX += .045f;
//		text.x += .045f;
//
//		if (privX >= .7f)
//		{
//			text.y -= .137f;
//			privY -= .137f;
//			privX = -.9f;
//			text.x = x;
//		}
//	}
//}
//
//void CBaseTXTBox::parseStringX(int block, float x, float y)
//{
//	std::string str = "";
//	int length = 0;
//
//
//	text.x = x; text.y = y; //-.9f, -.6f
//	privX = -.9f; privY = -0.6f;
//	str = word.at(block);
//	length = str.length();
//	static int lengthDec = length;
//
//	if (reset)
//	{
//		lengthDec = length;
//		reset = false;
//	}
//	
//	if (lengthDec >= 0)
//	{
//		for (int i = 0; i < length - lengthDec; i++)
//		{
//		
//			HVSTGFX::createTile( ((int)str.at(i)) - 32, text.x, text.y, text.charSheet);
//			privX += .045f;
//			text.x += .045f;
//	
//			if (privX >= .7f)
//			{
//				text.y -= .137f;
//				privY -= .137f;
//				privX = -.9f;
//				text.x = x;
//			}
//		}
//		lengthDec--;
//	}
//	else
//	{
//		for (int i = 0; i < length; i++)
//		{
//		
//			HVSTGFX::createTile( ((int)str.at(i)) - 32, text.x, text.y, text.charSheet);
//			privX += .045f;
//			text.x += .045f;
//	
//			if (privX >= .7f)
//			{
//				text.y -= .137f;
//				privY -= .137f;
//				privX = -.9f;
//				text.x = x;
//			}
//		}
//	}
//}
//
//void CBaseTXTBox::drawTextBoxX(float x, float y, bool drawBox)
//{
//	static int counter = 0;
//	static bool trigger = false;
//
//
//	if (draw)
//	{
//		if (counter <= blockCount)
//		{
//			if (drawBox)
//				HVSTGFX::createSprite(3.2f, 1.08f, x, y, box); //-1.6f, -1.1f
//			parseStringX(counter, x + .69f, y + .5f);
//			
//
//			if (GetAsyncKeyState(VK_RETURN))
//			{
//				trigger = true;
//			}
//
//			if (trigger)
//			{
//				myEvents.ev_wait(myEvents.waitCount(12.5, countDown)); //50
//			}
//
//			if (myEvents.onWait)
//			{
//				counter++;
//				scrollCount++;
//				trigger = false;
//				reset = true;
//				myEvents.onWait = false;
//				
//				if (counter == blockCount)
//				{
//					counter = 0;
//					draw = false;
//				}
//		
//			}
//
//		}
//	}
//}
//
//void CBaseTXTBox::drawText(float x, float y)
//{
//	static int counter = 0;
//	static bool trigger = false;
//	if (draw)
//	{
//		if (counter <= blockCount)
//		{
//			parseString(counter, x + .69f, y + .5f);
//			//HVSTGFX::createSprite(3.2f, 1.08f, x, y, box); //-1.6f, -1.1f
//
//			if (GetAsyncKeyState(VK_RETURN))
//			{
//				trigger = true;
//			}
//
//			if (trigger)
//			{
//				myEvents.ev_wait(myEvents.waitCount(12.5, countDown)); //50
//			}
//
//			if (myEvents.onWait)
//			{
//				counter++;
//				trigger = false;
//				myEvents.onWait = false;
//				
//				if (counter == blockCount)
//				{
//					counter = 0;
//					draw = false;
//				}
//		
//			}
//
//		}
//	}
//}
//
//void CBaseTXTBox::drawTextBox(float x, float y)
//{
//	static int counter = 0;
//	static bool trigger = false;
//
//	if (draw)
//	{
//		if (counter <= blockCount)
//		{
//			parseString(counter, x + .69f, y + .5f);
//			HVSTGFX::createSprite(3.2f, 1.08f, x, y, box); //-1.6f, -1.1f
//
//			if (GetAsyncKeyState(VK_RETURN))
//			{
//				trigger = true;
//			}
//
//			if (trigger)
//			{
//				myEvents.ev_wait(myEvents.waitCount(12.5, countDown)); //50
//			}
//
//			if (myEvents.onWait)
//			{
//				counter++;
//				trigger = false;
//				myEvents.onWait = false;
//				
//				if (counter == blockCount)
//				{
//					counter = 0;
//					draw = false;
//				}
//		
//			}
//
//		}
//	}
//}
//
//
//CBaseTXT::CBaseTXT()
//{
//	HVSTGFX::loadTiles("resource/sprites/text/txtWhite.png", charSheet, 16, 16);
//	HVSTGFX::loadTiles("resource/sprites/text/txtGreen.png", charSheetG, 16, 16);
//}
//
//CBaseTXT::~CBaseTXT()
//{
//	charSheet.sheet = NULL;
//}