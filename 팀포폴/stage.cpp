#include "stdafx.h"
#include "stage.h"


stage::stage()
{
}


stage::~stage()
{
}

HRESULT stage::init()
{

	IMAGEMANAGER->addImage("���", "���� ���.bmp", WINSIZEX, WINSIZEY, true, RGB(255, 0, 255));

	return S_OK;
}

void stage::release()
{
}

void stage::update()
{
}

void stage::render()
{
}
