#include "stdafx.h"
#include "musicsheet.h"

musicsheet::musicsheet()
{
	_gainValue = 0;
}


musicsheet::~musicsheet()
{
}

HRESULT musicsheet::init(int x, int y)
{
	_leftX = x;
	_topY = y;

	_rc = RectMakeCenter(_leftX, _topY, IMAGEMANAGER->findImage("bgmusicsheet")->getWidth(), IMAGEMANAGER->findImage("bgmusicsheet")->getHeight());

	return S_OK;
}

void musicsheet::update()
{
}

void musicsheet::render()
{
	if (KEYMANAGER->isToggleKey(VK_F1))
	{
		RectangleMake(getMemDC(), CAMERAMANAGER->CameraRelativePointX(_leftX), CAMERAMANAGER->CameraRelativePointY(_topY), IMAGEMANAGER->findImage("bgmusicsheet")->getWidth(), IMAGEMANAGER->findImage("bgmusicsheet")->getHeight());
	}

	IMAGEMANAGER->findImage("bgmusicsheet")->render(getMemDC(), CAMERAMANAGER->CameraRelativePointX(_leftX), CAMERAMANAGER->CameraRelativePointY(_topY));
}
