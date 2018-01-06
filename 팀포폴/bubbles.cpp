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

	_objAni = new animation;
	_objAni->init(IMAGEMANAGER->findImage("bubbles")->getWidth(), IMAGEMANAGER->findImage("bubbles")->getHeight(), IMAGEMANAGER->findImage("bubbles")->getFrameWidth(), IMAGEMANAGER->findImage("bubbles")->getFrameHeight());
	_objAni->setFPS(1);
	_objAni->setDefPlayFrame(false, true);
	_objAni->start();
	_rc = RectMake(_leftX, _topY, IMAGEMANAGER->findImage("bubbles")->getFrameWidth(), IMAGEMANAGER->findImage("bubbles")->getFrameHeight());
	return S_OK;
}

void bubbles::update()
{
	_objAni->frameUpdate(TIMEMANAGER->getElapsedTime() * 6);
	move();
}

void bubbles::render()
{
	if (KEYMANAGER->isToggleKey(VK_F1))
	{
		RectangleMake(getMemDC(), CAMERAMANAGER->CameraRelativePointX(_leftX), CAMERAMANAGER->CameraRelativePointY(_topY), IMAGEMANAGER->findImage("bubbles")->getFrameWidth(), IMAGEMANAGER->findImage("bubbles")->getFrameHeight());
	}

	IMAGEMANAGER->findImage("bubbles")->aniRender(getMemDC(), CAMERAMANAGER->CameraRelativePointX(_leftX), CAMERAMANAGER->CameraRelativePointY(_topY),_objAni);
}

void bubbles::move()
{
	_rc = RectMake(_leftX, _topY, IMAGEMANAGER->findImage("bubbles")->getFrameWidth(), IMAGEMANAGER->findImage("bubbles")->getFrameHeight());

	_topY -= _speedX;
	if (_range <= getDistance(_leftX, _topY, _startX, _startY))
	{
		_speedX = 0;
	}
}