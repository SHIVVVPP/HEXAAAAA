#pragma once
#include "targetver.h"

#define WIN32_LEAN_AND_MEAN             

#include <windows.h>

#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>
#include <iostream>



#include "commonMacroFunction.h"
#include "randomFunction.h"
#include "keyManager.h"
#include "utils.h"
#include "imageManager.h"
#include "timeManager.h"
#include "soundManager.h"
#include "txtData.h"
#include "effectManager.h"
#include "iniDataManager.h"
#include "cameraManager.h"

using namespace std;
using namespace HEXA_UTIL;

//=====================================
// ## ������ ## 17.09.29 ##
//=====================================

#define WINNAME		(LPTSTR)(TEXT("Hexa API"))
#define WINSTARTX	50
#define WINSTARTY	50
#define WINSIZEX	1280	
#define WINSIZEY	720

#define WINSTYLE	WS_CAPTION | WS_SYSMENU

#define RND randomFunction::getSingleton()
#define KEYMANAGER keyManager::getSingleton()
#define IMAGEMANAGER imageManager::getSingleton()
#define TIMEMANAGER timeManager::getSingleton()
#define SOUNDMANAGER soundManager::getSingleton()
#define EFFECTMANAGER effectManager::getSingleton()
#define TXTDATA txtData::getSingleton()
#define INIDATA iniDataManager::getSingleton()
#define CAMERAMANAGER cameraManager::getSingleton()

//=============================================================
// ## 17.10.18 ## Macro ##
//=============================================================

#define SAFE_DELETE(p) {if(p) {delete(p); (p) = NULL;}}
#define SAFE_RELEASE(p) {if(p) {(p)->release(); (p)=NULL;}}


//=====================================
// ## extern ## 17.10.12 ##
//=====================================

extern HINSTANCE _hInstance;	
extern HWND	_hWnd;			
extern POINT _ptMouse;



