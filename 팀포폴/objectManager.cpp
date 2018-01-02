#include "stdafx.h"
#include "objectManager.h"


objectManager::objectManager()
{
}


objectManager::~objectManager()
{
}

HRESULT objectManager::init()
{
	IMAGEMANAGER->addImage("배경", "원본 배경.bmp", WINSIZEX, WINSIZEY, false, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("무더기1", "_dirtpile1.bmp", WINSIZEX, WINSIZEY, false, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("무더기2", "_dirtpile2.bmp", WINSIZEX, WINSIZEY, false, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("무더기3", "_dirtpile3.bmp", WINSIZEX, WINSIZEY, false, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("무더기4", "_dirtpile4.bmp", WINSIZEX, WINSIZEY, false, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("무더기5", "_dirtpile5.bmp", WINSIZEX, WINSIZEY, false, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("벽무더기", "_digClod.bmp", WINSIZEX, WINSIZEY, false, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("돌덩이", "_digClod.bmp", WINSIZEX, WINSIZEY, false, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("세이브포인트", "_challengeGoal.bmp", WINSIZEX, WINSIZEY, false, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("큰모래", "_dirtblock.bmp", WINSIZEX, WINSIZEY, false, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("작은모래", "_dirtblock_small.bmp", WINSIZEX, WINSIZEY, false, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("가짜벽1", "_fakeblack1.bmp", WINSIZEX, WINSIZEY, false, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("가짜벽2", "_fakeblack2.bmp", WINSIZEX, WINSIZEY, false, RGB(255, 0, 255));
	//IMAGEMANAGER->addImage("방울", "_bubble.bmp", 0, 0, 84, 21, 4, false, RGB(255, 0, 255));

	IMAGEMANAGER->addImage("파랑범프", "원본 배경.bmp", WINSIZEX, WINSIZEY, false, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("초록범프", "원본 배경.bmp", WINSIZEX, WINSIZEY, false, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("빨강범프", "원본 배경.bmp", WINSIZEX, WINSIZEY, false, RGB(255, 0, 255));
	return S_OK;
}

void objectManager::release()
{
}

void objectManager::update()
{
}

void objectManager::render()
{
}
