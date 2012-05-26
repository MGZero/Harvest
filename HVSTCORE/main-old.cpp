#include "glMain.h"
#include "CBasePlayer.h"
#include "CBaseSound.h"
#include "NPCTest.h"
#include "HMD.h"
#include "CBaseTime.h"
#include "logic.h"
#include "CBaseTxt.h"
#include "HED.h"
#include "CNPCDemo.h"
#include "CBaseWater.h"
#include "CTitleScreen.h"
#include "CBaseCamera.h"
#include "DBG.h"
#include "global_Objects.h"
#include <windows.h>

HWND hwndMain;	//Main window handle
HDC g_hdc; //global device context
bool done = false;
bool zeldaTalk = false;

CNPCDemo * zelda;
HVSTMTH::matrix mat1(2,4);
HVSTMTH::matrix mat2(4,3);

HVSTGFX::CSprite newTest;
HVSTGFX::CSprite newTest2;
HVSTGFX::CSprite newSprite;

CBaseHitBox htbxTst(.43f, .5f, .17f, .27f);
CBaseHitBox treeBox1(-.985f, .4f, .4f, .495f);
CBaseHitBox treeBox2(-.185f, .1f, .4f, .495f);
CBaseHMD HMDTest;

CBasePlayer *player;
CBaseTXTBox *txtChair;
CBaseTXTBox *stupid;
CBaseCamera *camera;
bool chairTalk = false;
FMOD::System * tempSys;
HVSTEVENT glblEv;
int timerRef;
GLOBALS * glbl;

//CNPCTest *npc = new CNPCTest(); //create this guy
HVSTLOG::CBaseHUD *HUD;
CBaseTheoryEnt * eventTest;

PBYTE key;


const int FRAMES_PER_SECOND = 60; //default: 200
const int SKIP_TICKS = 1000 / FRAMES_PER_SECOND;

DWORD next_game_tick = clock();

// Callback function
LRESULT CALLBACK MainWndProc(HWND hwnd,UINT msg,WPARAM wParam,LPARAM lParam);
// Windows entry point
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, INT nCmdShow)
{
MSG msg; // MSG structure to store messages
WNDCLASSEX wcx; // WINDOW class information


//================create game stuff=======================//

bool test = true;
bool playOnce = true;
try{
	HEDFunc::populateList("resource/harvest.hed");}
catch(std::string str){
	glbl->debugger->writeString(str);
	done = true;}

float j, k;
const clock_t min = 9;
int sleep_time = 0;
glbl = new GLOBALS();

// Initialize the struct to zero
ZeroMemory(&wcx,sizeof(WNDCLASSEX));
	wcx.cbSize = sizeof(WNDCLASSEX); // Must always be sizeof(WNDCLASSEX)
	wcx.style = CS_HREDRAW|CS_VREDRAW |CS_DBLCLKS ; // Class styles
	wcx.lpfnWndProc = (WNDPROC)MainWndProc; // Pointer to the callback procedure
	wcx.cbClsExtra = 0; // Extra byte to allocate following the wndclassex structure
	wcx.cbWndExtra = 0; // Extra byte to allocate following an instance of the structure
	wcx.hInstance = hInstance; // Instance of the application
	wcx.hIcon = NULL; // Class Icon
	wcx.hCursor = LoadCursor(NULL, IDC_ARROW); // Class Cursor
	wcx.hbrBackground = (HBRUSH)(COLOR_WINDOW); // Background brush
	wcx.lpszMenuName = NULL; // Menu resource
	wcx.lpszClassName = _T("HVST"); // Name of this class
	wcx.hIconSm = NULL; // Small icon for this class

	// Register this window class with MS-Windows
	if (!RegisterClassEx(&wcx))
		return 0;

	// Create the window
	hwndMain = CreateWindowEx(0, //Extended window style
			_T("HVST"), // Window class name
			_T("Harvest Engine Core Build 7.5"), // Window title
			(WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU | WS_MINIMIZEBOX | WS_MAXIMIZEBOX) , // Window style
			0,0, // (x,y) pos of the window
			322,264,//264,272, // Width and height of the window
			HWND_DESKTOP, // HWND of the parent window (can be null also)
			NULL, // Handle to menu
			hInstance, // Handle to application instance
			NULL); // Pointer to window creation data

	// Check if window creation was successful
	if (!hwndMain)
		return 0;

	// Make the window visible
	ShowWindow(hwndMain,SW_SHOW);

	
//	npc->AIHealth0 = true;
//	npc->AINone = false;
	float heartX = 1.45f, heartY = -.1f;
	HMDFunc::setUpTileCoords();
	CTitleScreen * title = new CTitleScreen();
	//HMDFunc::readMap("resource/maps/SoDLinkHouse.hmd", HMDTest);
	HMDFunc::readMapX("resource/sprites/tiles/hyrule/seedlinggrove/SoDSG01.HMD", HMDTest);
	// Process messages coming to this window
	bool onTitle = true;
	bool onIntro = false;
	//intro dialog
	CBaseTXTBox * intro = 0;
	std::string introText[25];

	glbl->resources->addResource(new HVSTGFX::CSprite("resource/sprites/player/walkUp/walkUp0.png",true), "sprite", "PlwalkUp0");
	glbl->resources->addResource(new HVSTGFX::CSprite("resource/sprites/player/walkUp/walkUp1.png",true), "sprite", "PlwalkUp1");
	glbl->resources->addResource(new HVSTGFX::CSprite("resource/sprites/player/walkUp/walkUp2.png",true), "sprite", "PlwalkUp2");
	glbl->resources->addResource(new HVSTGFX::CSprite("resource/sprites/player/walkUp/walkUp3.png",true), "sprite", "PlwalkUp3");
	glbl->resources->addResource(new HVSTGFX::CSprite("resource/sprites/player/walkUp/walkUp4.png",true), "sprite", "PlwalkUp4");
	glbl->resources->addResource(new HVSTGFX::CSprite("resource/sprites/player/walkUp/walkUp5.png",true), "sprite", "PlwalkUp5");
	glbl->resources->addResource(new HVSTGFX::CSprite("resource/sprites/player/walkUp/walkUp6.png",true), "sprite", "PlwalkUp6");
	glbl->resources->addResource(new HVSTGFX::CSprite("resource/sprites/player/walkUp/walkUp7.png",true), "sprite", "PlwalkUp7");
	glbl->resources->addResource(new HVSTGFX::CSprite("resource/sprites/player/walkUp/walkUp8.png",true), "sprite", "PlwalkUp8");
	glbl->resources->addResource(new HVSTGFX::CSprite("resource/sprites/player/walkUp/walkUp9.png",true), "sprite", "PlwalkUp9");

	glbl->resources->addResource(new HVSTGFX::CSprite("resource/sprites/player/walkDown/walkDown0.png",true), "sprite", "PlwalkDown0");
	glbl->resources->addResource(new HVSTGFX::CSprite("resource/sprites/player/walkDown/walkDown1.png",true), "sprite", "PlwalkDown1");
	glbl->resources->addResource(new HVSTGFX::CSprite("resource/sprites/player/walkDown/walkDown2.png",true), "sprite", "PlwalkDown2");
	glbl->resources->addResource(new HVSTGFX::CSprite("resource/sprites/player/walkDown/walkDown3.png",true), "sprite", "PlwalkDown3");
	glbl->resources->addResource(new HVSTGFX::CSprite("resource/sprites/player/walkDown/walkDown4.png",true), "sprite", "PlwalkDown4");
	glbl->resources->addResource(new HVSTGFX::CSprite("resource/sprites/player/walkDown/walkDown5.png",true), "sprite", "PlwalkDown5");
	glbl->resources->addResource(new HVSTGFX::CSprite("resource/sprites/player/walkDown/walkDown6.png",true), "sprite", "PlwalkDown6");
	glbl->resources->addResource(new HVSTGFX::CSprite("resource/sprites/player/walkDown/walkDown7.png",true), "sprite", "PlwalkDown7");
	glbl->resources->addResource(new HVSTGFX::CSprite("resource/sprites/player/walkDown/walkDown8.png",true), "sprite", "PlwalkDown8");
	glbl->resources->addResource(new HVSTGFX::CSprite("resource/sprites/player/walkDown/walkDown9.png",true), "sprite", "PlwalkDown9");

	glbl->resources->addResource(new HVSTGFX::CSprite("resource/sprites/player/walkLeft/walkLeft0.png",true), "sprite", "PlwalkLeft0");
	glbl->resources->addResource(new HVSTGFX::CSprite("resource/sprites/player/walkLeft/walkLeft1.png",true), "sprite", "PlwalkLeft1");
	glbl->resources->addResource(new HVSTGFX::CSprite("resource/sprites/player/walkLeft/walkLeft2.png",true), "sprite", "PlwalkLeft2");
	glbl->resources->addResource(new HVSTGFX::CSprite("resource/sprites/player/walkLeft/walkLeft3.png",true), "sprite", "PlwalkLeft3");
	glbl->resources->addResource(new HVSTGFX::CSprite("resource/sprites/player/walkLeft/walkLeft4.png",true), "sprite", "PlwalkLeft4");
	glbl->resources->addResource(new HVSTGFX::CSprite("resource/sprites/player/walkLeft/walkLeft5.png",true), "sprite", "PlwalkLeft5");
	glbl->resources->addResource(new HVSTGFX::CSprite("resource/sprites/player/walkLeft/walkLeft6.png",true), "sprite", "PlwalkLeft6");
	glbl->resources->addResource(new HVSTGFX::CSprite("resource/sprites/player/walkLeft/walkLeft7.png",true), "sprite", "PlwalkLeft7");
	glbl->resources->addResource(new HVSTGFX::CSprite("resource/sprites/player/walkLeft/walkLeft8.png",true), "sprite", "PlwalkLeft8");
	glbl->resources->addResource(new HVSTGFX::CSprite("resource/sprites/player/walkLeft/walkLeft9.png",true), "sprite", "PlwalkLeft9");

	glbl->resources->addResource(new HVSTGFX::CSprite("resource/sprites/player/walkRight/walkRight0.png",true), "sprite", "PlwalkRight0");
	glbl->resources->addResource(new HVSTGFX::CSprite("resource/sprites/player/walkRight/walkRight1.png",true), "sprite", "PlwalkRight2");
	glbl->resources->addResource(new HVSTGFX::CSprite("resource/sprites/player/walkRight/walkRight2.png",true), "sprite", "PlwalkRight1");
	glbl->resources->addResource(new HVSTGFX::CSprite("resource/sprites/player/walkRight/walkRight3.png",true), "sprite", "PlwalkRight3");
	glbl->resources->addResource(new HVSTGFX::CSprite("resource/sprites/player/walkRight/walkRight4.png",true), "sprite", "PlwalkRight4");
	glbl->resources->addResource(new HVSTGFX::CSprite("resource/sprites/player/walkRight/walkRight5.png",true), "sprite", "PlwalkRight5");
	glbl->resources->addResource(new HVSTGFX::CSprite("resource/sprites/player/walkRight/walkRight6.png",true), "sprite", "PlwalkRight6");
	glbl->resources->addResource(new HVSTGFX::CSprite("resource/sprites/player/walkRight/walkRight7.png",true), "sprite", "PlwalkRight7");
	glbl->resources->addResource(new HVSTGFX::CSprite("resource/sprites/player/walkRight/walkRight8.png",true), "sprite", "PlwalkRight8");
	glbl->resources->addResource(new HVSTGFX::CSprite("resource/sprites/player/walkRight/walkRight9.png",true), "sprite", "PlwalkRight9");

	glbl->resources->addResource(new HVSTGFX::CSprite("resource/sprites/player/arrowLeft/arrowShotL0.png",true), "sprite", "PlShootL0");
	glbl->resources->addResource(new HVSTGFX::CSprite("resource/sprites/player/arrowLeft/arrowShotL1.png",true), "sprite", "PlShootL1");
	glbl->resources->addResource(new HVSTGFX::CSprite("resource/sprites/player/arrowLeft/arrowShotL2.png",true), "sprite", "PlShootL2");
	glbl->resources->addResource(new HVSTGFX::CSprite("resource/sprites/player/arrowLeft/arrowShotL3.png",true), "sprite", "PlShootL3");
	glbl->resources->addResource(new HVSTGFX::CSprite("resource/sprites/player/arrowLeft/arrowShotL4.png",true), "sprite", "PlShootL4");
	glbl->resources->addResource(new HVSTGFX::CSprite("resource/sprites/player/arrowLeft/arrowShotL5.png",true), "sprite", "PlShootL5");
	glbl->resources->addResource(new HVSTGFX::CSprite("resource/sprites/player/arrowLeft/arrowShotL6.png",true), "sprite", "PlShootL6");
	glbl->resources->addResource(new HVSTGFX::CSprite("resource/sprites/player/arrowLeft/arrowShotL7.png",true), "sprite", "PlShootL7");
	glbl->resources->addResource(new HVSTGFX::CSprite("resource/sprites/player/arrowLeft/arrowShotL8.png",true), "sprite", "PlShootL8");
	glbl->resources->addResource(new HVSTGFX::CSprite("resource/sprites/player/arrowLeft/arrowShotL9.png",true), "sprite", "PlShootL9");
	glbl->resources->addResource(new HVSTGFX::CSprite("resource/sprites/player/arrowLeft/arrowShotL10.png",true), "sprite", "PlShootL10");
	glbl->resources->addResource(new HVSTGFX::CSprite("resource/sprites/player/arrowLeft/arrowShotL11.png",true), "sprite", "PlShootL11");
	glbl->resources->addResource(new HVSTGFX::CSprite("resource/sprites/player/arrowLeft/arrowShotL12.png",true), "sprite", "PlShootL12");
	glbl->resources->addResource(new HVSTGFX::CSprite("resource/sprites/player/arrowLeft/arrowShotL13.png",true), "sprite", "PlShootL13");
	glbl->resources->addResource(new HVSTGFX::CSprite("resource/sprites/player/arrowLeft/arrowShotL14.png",true), "sprite", "PlShootL14");

	glbl->resources->addResource(new HVSTGFX::CSprite("resource/sprites/player/arrowRight/arrowShotR0.png",true), "sprite", "PlShootR0");
	glbl->resources->addResource(new HVSTGFX::CSprite("resource/sprites/player/arrowRight/arrowShotR1.png",true), "sprite", "PlShootR1");
	glbl->resources->addResource(new HVSTGFX::CSprite("resource/sprites/player/arrowRight/arrowShotR2.png",true), "sprite", "PlShootR2");
	glbl->resources->addResource(new HVSTGFX::CSprite("resource/sprites/player/arrowRight/arrowShotR3.png",true), "sprite", "PlShootR3");
	glbl->resources->addResource(new HVSTGFX::CSprite("resource/sprites/player/arrowRight/arrowShotR4.png",true), "sprite", "PlShootR4");
	glbl->resources->addResource(new HVSTGFX::CSprite("resource/sprites/player/arrowRight/arrowShotR5.png",true), "sprite", "PlShootR5");
	glbl->resources->addResource(new HVSTGFX::CSprite("resource/sprites/player/arrowRight/arrowShotR6.png",true), "sprite", "PlShootR6");
	glbl->resources->addResource(new HVSTGFX::CSprite("resource/sprites/player/arrowRight/arrowShotR7.png",true), "sprite", "PlShootR7");
	glbl->resources->addResource(new HVSTGFX::CSprite("resource/sprites/player/arrowRight/arrowShotR8.png",true), "sprite", "PlShootR8");
	glbl->resources->addResource(new HVSTGFX::CSprite("resource/sprites/player/arrowRight/arrowShotR9.png",true), "sprite", "PlShootR9");
	glbl->resources->addResource(new HVSTGFX::CSprite("resource/sprites/player/arrowRight/arrowShotR10.png",true), "sprite", "PlShootR10");
	glbl->resources->addResource(new HVSTGFX::CSprite("resource/sprites/player/arrowRight/arrowShotR11.png",true), "sprite", "PlShootR11");
	glbl->resources->addResource(new HVSTGFX::CSprite("resource/sprites/player/arrowRight/arrowShotR12.png",true), "sprite", "PlShootR12");
	glbl->resources->addResource(new HVSTGFX::CSprite("resource/sprites/player/arrowRight/arrowShotR13.png",true), "sprite", "PlShootR13");
	glbl->resources->addResource(new HVSTGFX::CSprite("resource/sprites/player/arrowRight/arrowShotR14.png",true), "sprite", "PlShootR14");
	player = new CBasePlayer();

	//initialize the intro stuff
	bool trigger = false;
	int countDown = 0;
	introText[0] = "Legends speak of a world created by             the Gods..";
	introText[1] = "The home of the Hylians, the Master       Sword, and the Triforce.";
	introText[2] = "  This is where the Gods rested     after descending upon the World of                Chaos.";
	introText[3] = "Not far from here, their power also       reached to another world.";
	introText[4] = "  This world became inhabited by    dragons, who banded together over                 time..";
	introText[5] = "and created the country as it is               known today.";
	introText[6] = "This is the world called Doragon.";
	introText[7] = "Not long after, these clans began       fighting with one another.";
	introText[8] = "    Fighting for land, or for                    dominance.";
	introText[9] = "Soon after, others began to appear. Not dragons, but humans. It was by              their hands";
	introText[10]= "that the most sacred tool known to          this world was created -";
	introText[11]= "      The Blade of Golden Light";
	introText[12]= "Soon after, Doragon had been filled  with a wide variety of creatures.          The Kingdom of Doragon";
	introText[13]= "  was established and traders from      the land of Hyrule had begun                travelling here.";
	introText[14]= "  The land became as prosperous as        its' neighboring country.";
	introText[15]= "         Until one day...";
	introText[16]= "  When the smell of ash was in the                air..";
	introText[17]= "  When the moon shined red in the            light of Twilight..";
	introText[18]= "  And when the gale of the desert            reached the plains..";
	introText[19]= "   That was the day Doragon fell    into the shadows, never to be heard                from again.";
	introText[20]= "    What happened to this world?    None who venture into it survive to              tell the tale.";
	introText[21]= "     These are the four legends                of Doragon.";
	introText[22]= "    The source of its' demise is      still lurking in our world today.";
	introText[23]= "   And it's soon to be revealed to         the rest of the world...";
	introText[24]= "   On the land of a wealthy family        is where our story begins.";

	intro = new CBaseTXTBox(25, introText);
	CBaseSound * introTheme = new CBaseSound("resource/sounds/music/introTheme.ogg",true);
	
	HUD = new HVSTLOG::CBaseHUD(); //create the HUD object
	//HVSTGFX::CXTileSheet tileTest2("resource/sprites/tiles/sample.png", 16, 16, true);
//	HVSTGFX::loadPNGTiles("resource/sprites/tiles/sample2.png", tiles3, 16, 16);
//	HVSTGFX::loadPNGTiles("resource/sprites/tiles/grassTile.png", newTile, 16, 16);
	zelda = new CNPCDemo();
	
	//take the player data from the map file
	
	
	CBaseVector blah;
	blah.magnitudeX = SCALEX_1;
	blah.magnitudeY = SCALEY_1;
	//initialize the camera
	camera = new CBaseCamera(2.0f, 2.0f, 0, 0, .5f, .5f,blah , player, true);

	try
	{
		glbl->initInput();
	}
	catch (char * str)
	{
		done = true;
	}
	glbl->debugger->writeString("Beginning main game loop....\n\n");
	while (!done)
	{

		

		while(PeekMessage(&msg, hwndMain, NULL, NULL, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		

		if (GetFocus())
		{

	
			//render the scene
			
					
			
			glClearColor(.0f, .0f, .0f, .0f);
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
			glAlphaFunc(GL_GREATER, 0.0f);
			glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
			
			
			//check events
			glbl->GKeyboardTrigger->update();
			glbl->GFrameTrigger->update();
			
			if (onTitle)
			{
				title->live();
				title->render();
				if (!title->BGM->active)
				{
					title->BGM->emitSound();
					title->BGM->active = true;
				}
				if (GetAsyncKeyState(VK_RETURN))
				{
					trigger = true;
					
					
				}
				if (trigger)
				{
					title->myEvents.ev_wait(title->myEvents.waitCount(25.0f, countDown));
					
					if (title->myEvents.onWait)
					{
						onTitle = false;
						onIntro = true;
						//glTranslatef(-player->getxCoord(), -player->getyCoord(), 0.0f);
						title->BGM->stopSound();
#ifdef DEBUG
						glbl->debugger->writeString("Leaving title screen, moving to main game logic...\n");
#endif
						//introTheme->emitSound();
						
					}
				}
			}
			else
			{
				if (camera)
					camera->live();
#ifdef DEBUG
				else
					glbl->debugger->writeString("Camera is broken! FIX IT YOU SHIT!!\n");
#endif
				
				HMDFunc::createMapX(HMDTest);
				player->live();

				
				//HVSTGFX::createSpritePNGX(SCALEX_32, SCALEY_32, zelda->getxCoord(), zelda->getyCoord(), zelda->spriteMain);

				/*if (!player->inAction)
					player->walk();
				player->slash();
				player->arrowShoot();
				player->plantBomb();
				player->tossBoomerang();*/

				/*if (zeldaTalk)
					zelda->speak(HUD->x - 2.1f, HUD->y - 1.8f);

				if (chairTalk)
				{
					txtChair->drawTextBox(HUD->x - 2.1f, HUD->y - 1.8f);
				}*/

				

				//HUD->drawHUD();
				camera->HUD->drawHUD();

				}

				

				

				/*if (GetAsyncKeyState(VK_RETURN))
				{
					npc->AIHealth0 = false;
					npc->AINone = true;
				}

				temp = npc->checkCondition();
				npc->executeSchedule(temp);*/

		
				
				//standing code was here
				

				SwapBuffers(g_hdc);
				
				tempSys->update();

				//switch off global events
				glbl->GFrameTrigger->getEvent(0)->triggered = false;

				next_game_tick += SKIP_TICKS;
				sleep_time = next_game_tick - clock();
				if( sleep_time >= 0 ) {
					Sleep( sleep_time );
				}
				else 
				{
					// Shit, we are running behind!
				}
			

		}
		else
		{
			Sleep(1);

		}

	
	}


	// return value to the system
	return msg.wParam;
	
 }

 LRESULT CALLBACK MainWndProc(HWND hwnd,UINT msg,WPARAM wParam,LPARAM lParam)
 {
	HDC hdc = NULL;
	HGLRC hrc = NULL;
	int width, height;

	switch (msg)
	{
		case WM_CREATE:
#ifdef DEBUG
			glbl->debugger->writeString("Beginning window creation..\n\n");
#endif
			hdc = GetDC(hwnd);
			
#ifdef DEBUG
			if (!hdc)
				glbl->debugger->writeString("Failed to create HDC\n");
#endif
			//g_hdc = hdc;
			HVSTGFX::SetupPixelFormat(hdc);
			hrc = wglCreateContext(hdc);
#ifdef DEBUG
			if (!hrc)
				glbl->debugger->writeString("Failed to create HRC\n");
#endif
			wglMakeCurrent(hdc, hrc);
			g_hdc = hdc;
			HVSTGFX::initGL();
			FreeImage_Initialise(TRUE);
			FMOD::System_Create(&tempSys);		// Create the main system object.
			tempSys->init(100, FMOD_INIT_NORMAL, 0);	// Initialize FMOD.
			
			//tempSys->playSound(FMOD_CHANNEL_FREE, player->sound, 0, NULL);
			
			
			break;

		case WM_DESTROY:
			// User closed the window
			done = true;
			wglMakeCurrent(hdc, hrc);
			wglDeleteContext(hrc);
			tempSys->release();
			delete glbl->resources;
			delete player;
			delete HUD;
			delete zelda;
			//delete title;
			PostQuitMessage(0);
			break;

		case WM_SIZE:
			height = HIWORD(lParam);
			width = LOWORD(lParam);

			if (height == 0)
				height = 1;

			glViewport(0,0, width, height);
			
			glMatrixMode(GL_PROJECTION);
			glLoadIdentity();

			gluPerspective(45.0f, (GLfloat)width/(GLfloat)height,1.0f,1000.0f);
			glLoadIdentity();
			break;

		case WM_KEYUP:
			if (!GetKeyboardState(key))
			{
				
			}
			
			break;

		case WM_KEYDOWN:
			
			break;

		case WM_MOUSEMOVE:
			HUD->mouseX = (HUD->x + ((float)LOWORD(lParam)/(326.0f/2.0f)) - 1.0f) - .5f;
			HUD->mouseY = (HUD->y + (((float)HIWORD(lParam)/(215.0f/2.0f)) * -1.0f) + 1.0f) - .7f;
			break;

		case WM_SETCURSOR:
			SetCursor(NULL);
			break;

		case WM_SETFOCUS:
			//glTranslatef(player->getxCoord() - player->relX, player->getyCoord() + player->relY, 0.0f);
			break;
			
		default:
			// Call the default window handler
			return DefWindowProc(hwnd,msg,wParam,lParam);
	}
	return 0;
 }

