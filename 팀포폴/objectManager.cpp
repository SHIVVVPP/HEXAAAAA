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
	IMAGEMANAGER->addImage("���", "���� ���.bmp", WINSIZEX, WINSIZEY, false, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("������1", "_dirtpile1.bmp", WINSIZEX, WINSIZEY, false, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("������2", "_dirtpile2.bmp", WINSIZEX, WINSIZEY, false, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("������3", "_dirtpile3.bmp", WINSIZEX, WINSIZEY, false, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("������4", "_dirtpile4.bmp", WINSIZEX, WINSIZEY, false, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("������5", "_dirtpile5.bmp", WINSIZEX, WINSIZEY, false, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("��������", "_digClod.bmp", WINSIZEX, WINSIZEY, false, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("�����", "_digClod.bmp", WINSIZEX, WINSIZEY, false, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("���̺�����Ʈ", "_challengeGoal.bmp", WINSIZEX, WINSIZEY, false, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("ū��", "_dirtblock.bmp", WINSIZEX, WINSIZEY, false, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("������", "_dirtblock_small.bmp", WINSIZEX, WINSIZEY, false, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("��¥��1", "_fakeblack1.bmp", WINSIZEX, WINSIZEY, false, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("��¥��2", "_fakeblack2.bmp", WINSIZEX, WINSIZEY, false, RGB(255, 0, 255));
	//IMAGEMANAGER->addImage("���", "_bubble.bmp", 0, 0, 84, 21, 4, false, RGB(255, 0, 255));

	IMAGEMANAGER->addImage("�Ķ�����", "���� ���.bmp", WINSIZEX, WINSIZEY, false, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("�������", "���� ���.bmp", WINSIZEX, WINSIZEY, false, RGB(255, 0, 255));
	IMAGEMANAGER->addImage("��������", "���� ���.bmp", WINSIZEX, WINSIZEY, false, RGB(255, 0, 255));
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
