#include "stdafx.h"
#include "fakedirt.h"


fakedirt::fakedirt()
{
}


fakedirt::~fakedirt()
{
}


HRESULT fakedirt::init(int x, int y, int width)
{
	_leftX = x;
	_topY = y;
	_width = width;
	//_rc = RectMake(_leftX, _topY, IMAGEMANAGER->findImage("leftfakehead")->getWidth(), IMAGEMANAGER->findImage("leftfakehead")->getHeight());

	_rc = RectMake(_leftX, _topY, _width, IMAGEMANAGER->findImage("leftfakehead")->getHeight());
	return S_OK;
}

void fakedirt::update()
{
}

void fakedirt::render()
{

	int tempX = _leftX;
	int tempY = _rc.bottom;
	tempX = _rc.left;
	IMAGEMANAGER->findImage("leftfakehead")->render(getMemDC(), CAMERAMANAGER->CameraRelativePointX(tempX), CAMERAMANAGER->CameraRelativePointY(_rc.top));
	tempX += IMAGEMANAGER->findImage("leftfakehead")->getWidth();
	for (; tempX < _rc.right - IMAGEMANAGER->findImage("leftfakehead")->getWidth();)
	{
		IMAGEMANAGER->findImage("leftfakehead")->render(getMemDC(), CAMERAMANAGER->CameraRelativePointX(tempX), CAMERAMANAGER->CameraRelativePointY(_rc.top));
		tempX += IMAGEMANAGER->findImage("leftfakehead")->getWidth();
	}
	IMAGEMANAGER->findImage("leftfakehead")->render(getMemDC(), CAMERAMANAGER->CameraRelativePointX(tempX), CAMERAMANAGER->CameraRelativePointY(_rc.top));
	tempX += IMAGEMANAGER->findImage("leftfakehead")->getWidth();
	_rc.right = tempX;
	
	if (KEYMANAGER->isToggleKey(VK_F1))
	{
		//RectangleMake(getMemDC(), CAMERAMANAGER->CameraRelativePointX(_leftX), CAMERAMANAGER->CameraRelativePointY(_topY), IMAGEMANAGER->findImage("leftfakehead")->getWidth(), IMAGEMANAGER->findImage("leftfakehead")->getHeight());
		RectangleMake(getMemDC(), CAMERAMANAGER->CameraRelativePointX(_leftX), CAMERAMANAGER->CameraRelativePointY(_topY), getWidth(_rc), getHeight(_rc));
	}
}
