#include "stdafx.h"
#include "bubbles.h"

bubbles::bubbles()
{
}


bubbles::~bubbles()
{
}

HRESULT bubbles::init(int x, int y, int startX, int startY, int range)
{
	_leftX = x;
	_topY = y;
	_startX = startX;
	_startY = startY;
	_range = range;
	_speedX = 2;
	_rc = RectMake(_leftX, _topY, IMAGEMANAGER->findImage("bubble")->getWidth(), IMAGEMANAGER->findImage("bubble")->getHeight());
	return S_OK;
}

void bubbles::update()
{
	move();
}

void bubbles::render()
{
	if (KEYMANAGER->isToggleKey(VK_F1))
	{
		RectangleMake(getMemDC(), CAMERAMANAGER->CameraRelativePointX(_leftX), CAMERAMANAGER->CameraRelativePointY(_topY), IMAGEMANAGER->findImage("bubble")->getWidth(), IMAGEMANAGER->findImage("bubble")->getHeight());
	}

	IMAGEMANAGER->findImage("bubble")->render(getMemDC(), CAMERAMANAGER->CameraRelativePointX(_leftX), CAMERAMANAGER->CameraRelativePointY(_topY));
}

void bubbles::move()
{
	_rc = RectMake(_leftX, _topY, IMAGEMANAGER->findImage("bubble")->getWidth(), IMAGEMANAGER->findImage("bubble")->getHeight());

	_topY -= _speedX;
	if (_range <= getDistance(_leftX, _topY, _startX, _startY))
	{
		_speedX = 0;
	}
}