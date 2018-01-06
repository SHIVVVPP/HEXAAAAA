#include "stdafx.h"
#include "smalldirtblock.h"


smalldirtblock::smalldirtblock()
{
	_type = TYPE_SMALL_BLOCK;
}


smalldirtblock::~smalldirtblock()
{
}

HRESULT smalldirtblock::init(int x, int y)
{
	_leftX = x;
	_topY = y;

	_rc = RectMake(_leftX, _topY, IMAGEMANAGER->findImage("dirtblocksmall")->getWidth(), IMAGEMANAGER->findImage("dirtblocksmall")->getHeight());

	return S_OK;
}

void smalldirtblock::update()
{
}

void smalldirtblock::render()
{
	IMAGEMANAGER->findImage("dirtblocksmall")->render(getMemDC(), CAMERAMANAGER->CameraRelativePointX(_rc.left), CAMERAMANAGER->CameraRelativePointY(_rc.top));

	if (KEYMANAGER->isToggleKey(VK_F1))
	{
		RectangleMake(getMemDC(), CAMERAMANAGER->CameraRelativePointX(_rc.left), CAMERAMANAGER->CameraRelativePointY(_rc.top), IMAGEMANAGER->findImage("dirtblocksmall")->getWidth(), IMAGEMANAGER->findImage("dirtblocksmall")->getHeight());
	}
}