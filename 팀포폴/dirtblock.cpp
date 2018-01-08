#include "stdafx.h"
#include "dirtblock.h"

dirtblock::dirtblock()
{
	_type = TYPE_BLOCK;
}


dirtblock::~dirtblock()
{
}

HRESULT dirtblock::init(int x, int y)
{
	_leftX = x;
	_topY = y;

	_speedX = 0;
	_speedY = 0;
	_rc = RectMake(_leftX, _topY, IMAGEMANAGER->findImage("dirtblock")->getWidth(), IMAGEMANAGER->findImage("dirtblock")->getHeight());

	return S_OK;
}

void dirtblock::update()
{
}

void dirtblock::render()
{	
	IMAGEMANAGER->findImage("dirtblock")->render(getMemDC(), CAMERAMANAGER->CameraRelativePointX(_rc.left), CAMERAMANAGER->CameraRelativePointY(_rc.top));

	if (KEYMANAGER->isToggleKey(VK_F1))
	{
		RectangleMake(getMemDC(), CAMERAMANAGER->CameraRelativePointX(_rc.left), CAMERAMANAGER->CameraRelativePointY(_rc.top), IMAGEMANAGER->findImage("dirtblock")->getWidth(), IMAGEMANAGER->findImage("dirtblock")->getHeight());
	}

}
