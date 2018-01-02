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

	IMAGEMANAGER->addImage("배경", "원본 배경.bmp", WINSIZEX, WINSIZEY, true, RGB(255, 0, 255));

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
