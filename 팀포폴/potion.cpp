#include "stdafx.h"
#include "potion.h"


potion::potion()
{
	_type = TYPE_POTION;
}


potion::~potion()
{
}

HRESULT potion::init(int x, int y)
{
	_leftX = x;
	_topY = y;
	_manaValue = 6;

	_rc = RectMake(_leftX, _topY, IMAGEMANAGER->findImage("potion")->getWidth(), IMAGEMANAGER->findImage("potion")->getHeight());
	return S_OK;
}

void potion::update()
{
}

void potion::render()
{
	if (KEYMANAGER->isOnceKeyDown(VK_F1))
	{
		RectangleMake(getMemDC(), CAMERAMANAGER->CameraRelativePointX(_rc.left), CAMERAMANAGER->CameraRelativePointY(_rc.top), IMAGEMANAGER->findImage("potion")->getWidth(), IMAGEMANAGER->findImage("potion")->getHeight());
	}

	IMAGEMANAGER->findImage("potion")->render(getMemDC(), CAMERAMANAGER->CameraRelativePointX(_rc.left), CAMERAMANAGER->CameraRelativePointY(_rc.top));
}
