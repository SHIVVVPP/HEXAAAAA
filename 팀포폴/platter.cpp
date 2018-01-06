#include "stdafx.h"
#include "platter.h"


platter::platter()
{
	_type = TYPE_PLATTER;
}


platter::~platter()
{
}

HRESULT platter::init(int x, int y , float length)
{
	_leftX = x;
	_topY = y;
	_rc = RectMake(_leftX, _topY, IMAGEMANAGER->findImage("platter")->getWidth(), IMAGEMANAGER->findImage("platter")->getHeight());

	return S_OK;
}

void platter::update()
{
}

void platter::render()
{
	if (KEYMANAGER->isToggleKey(VK_F1))
	{
		RectangleMake(getMemDC(), CAMERAMANAGER->CameraRelativePointX(_rc.left), CAMERAMANAGER->CameraRelativePointY(_rc.top), IMAGEMANAGER->findImage("platter")->getWidth(), IMAGEMANAGER->findImage("platter")->getHeight());
	}

	IMAGEMANAGER->findImage("platter")->render(getMemDC(), CAMERAMANAGER->CameraRelativePointX(_rc.left), CAMERAMANAGER->CameraRelativePointY(_rc.top));
}
