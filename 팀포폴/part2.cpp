#include "stdafx.h"
#include "part2.h"

part2::part2()
{
}


part2::~part2()
{
}

HRESULT part2::init(int x, int y)
{
	_leftX = x;
	_topY = y;
	_angle = PI2;
	_rc = RectMake(_leftX, _topY, IMAGEMANAGER->findImage("halfedplatter2")->getWidth(), IMAGEMANAGER->findImage("halfedplatter2")->getHeight());
	return S_OK;
}

void part2::update()
{
}

void part2::render()
{
	if (KEYMANAGER->isToggleKey(VK_F1))
	{
		RectangleMake(getMemDC(), CAMERAMANAGER->CameraRelativePointX(_rc.left), CAMERAMANAGER->CameraRelativePointY(_rc.top), IMAGEMANAGER->findImage("halfedplatter2")->getWidth(), IMAGEMANAGER->findImage("halfedplatter2")->getHeight());
	}

	IMAGEMANAGER->findImage("halfedplatter2")->render(getMemDC(), CAMERAMANAGER->CameraRelativePointX(_rc.left), CAMERAMANAGER->CameraRelativePointY(_rc.top));
}

void part2::move()
{
	_rc = RectMake(_leftX, _topY, IMAGEMANAGER->findImage("halfedplatter")->getWidth(), IMAGEMANAGER->findImage("halfedplatter")->getHeight());

	_leftX += cosf(_angle) * _speedX;
	_topY += -sinf(_angle) * (5) * _speedX;

	_angle += 0.05;
}

