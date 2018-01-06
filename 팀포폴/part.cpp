#include "stdafx.h"
#include "part.h"



part::part()
{
}


part::~part()
{
}

HRESULT part::init(int x, int y)
{
	_leftX = x;
	_topY = y;
	_angle = PI;
	_rc = RectMake(_leftX, _topY, IMAGEMANAGER->findImage("halfedplatter")->getWidth(), IMAGEMANAGER->findImage("halfedplatter")->getHeight());

	return S_OK;
}

void part::update()
{
}

void part::render()
{
	if (KEYMANAGER->isToggleKey(VK_F1))
	{
		RectangleMake(getMemDC(), CAMERAMANAGER->CameraRelativePointX(_rc.left), CAMERAMANAGER->CameraRelativePointY(_rc.top), IMAGEMANAGER->findImage("halfedplatter2")->getWidth(), IMAGEMANAGER->findImage("halfedplatter2")->getHeight());
	}

	IMAGEMANAGER->findImage("halfedplatter2")->render(getMemDC(), CAMERAMANAGER->CameraRelativePointX(_rc.left), CAMERAMANAGER->CameraRelativePointY(_rc.top));
}

void part::move()
{
	_rc = RectMake(_leftX, _topY, IMAGEMANAGER->findImage("halfedplatter")->getWidth(), IMAGEMANAGER->findImage("halfedplatter")->getHeight());

	_leftX += cosf(_angle) * _speedX;
	_topY += -sinf(_angle) * (5) * _speedX;

	_angle += 0.05;
}
