#include "stdafx.h"
#include "platter.h"


platters::platters()
{
	_type = TYPE_PLATTER;
	
}


platters::~platters()
{
}

HRESULT platters::init(int x, int y)
{
	_leftX = x;
	_topY = y;
	_rc = RectMake(_leftX, _topY, IMAGEMANAGER->findImage("platter")->getWidth(), IMAGEMANAGER->findImage("platter")->getHeight());

	return S_OK;
}

void platters::update()
{
}

void platters::render()
{
	if (KEYMANAGER->isToggleKey(VK_F1))
	{
		RectangleMake(getMemDC(), CAMERAMANAGER->CameraRelativePointX(_rc.left), CAMERAMANAGER->CameraRelativePointY(_rc.top), IMAGEMANAGER->findImage("platter")->getWidth(), IMAGEMANAGER->findImage("platter")->getHeight());
	}

	IMAGEMANAGER->findImage("platter")->render(getMemDC(), CAMERAMANAGER->CameraRelativePointX(_rc.left), CAMERAMANAGER->CameraRelativePointY(_rc.top));
}
