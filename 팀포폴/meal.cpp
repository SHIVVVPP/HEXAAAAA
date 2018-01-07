#include "stdafx.h"
#include "meal.h"


meal::meal()
{
	_type = TYPE_MEAL;
}


meal::~meal()
{
}

HRESULT meal::init(int x, int y)
{
	_leftX = x;
	_topY = y;
	_helathValue = 5;
	_rc = RectMake(_leftX, _topY, IMAGEMANAGER->findImage("food")->getWidth(), IMAGEMANAGER->findImage("food")->getHeight());
	return S_OK;
}

void meal::update()
{
}

void meal::render()
{
	if (KEYMANAGER->isToggleKey(VK_F1))
	{
		RectangleMake(getMemDC(), CAMERAMANAGER->CameraRelativePointX(_rc.left), CAMERAMANAGER->CameraRelativePointY(_rc.top), IMAGEMANAGER->findImage("food")->getWidth(), IMAGEMANAGER->findImage("food")->getHeight());
	}

	IMAGEMANAGER->findImage("food")->render(getMemDC(), CAMERAMANAGER->CameraRelativePointX(_rc.left), CAMERAMANAGER->CameraRelativePointY(_rc.top));
}

