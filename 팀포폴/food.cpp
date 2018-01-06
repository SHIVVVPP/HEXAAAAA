#include "stdafx.h"
#include "food.h"

food::food()
{
	_type = TYPE_FOOD;
}


food::~food()
{
}


HRESULT food::init(int x, int y)
{
	_leftX = x;
	_topY = y;
	_helathValue = 5;
	_rc = RectMake(_leftX, _topY, IMAGEMANAGER->findImage("chicken")->getWidth(), IMAGEMANAGER->findImage("chicken")->getHeight());
	return S_OK;
}

void food::update()
{
}

void food::render()
{
	if (KEYMANAGER->isToggleKey(VK_F1))
	{
		RectangleMake(getMemDC(), CAMERAMANAGER->CameraRelativePointX(_rc.left), CAMERAMANAGER->CameraRelativePointY(_rc.top), IMAGEMANAGER->findImage("chicken")->getWidth(), IMAGEMANAGER->findImage("chicken")->getHeight());
	}

	IMAGEMANAGER->findImage("chicken")->render(getMemDC(), CAMERAMANAGER->CameraRelativePointX(_rc.left), CAMERAMANAGER->CameraRelativePointY(_rc.top));
}
