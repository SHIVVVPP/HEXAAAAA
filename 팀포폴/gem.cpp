#include "stdafx.h"
#include "gem.h"


gem::gem()
{
	_type = TYPE_GEM;
	_move = false;
	_hang = false;
	_picked = false;
	_canHit = false;
}

gem::~gem()
{
}

HRESULT gem::init(int range , int x, int y, int startX, int startY, float speed, float angle)
{
	_imageName = "smalljew";
	_image = IMAGEMANAGER->findImage(_imageName);
	_range = range;

	_leftX = x;
	_topY = y;

	_startX = startX;
	_startY = startY;

	_speedX = speed;
	_angle = angle;
	
	_shuf = RND->getFromIntTo(1,6);
	return S_OK;
}


void gem::update()
{
	move();
	switch (_shuf)
	{
	case 1:
		_imageName = "reddia";
		_image = IMAGEMANAGER->findImage(_imageName);
		_goldValue = 50;
		_gemType = REDDIA;
		break;
	case 2:
		_imageName = "yellowgem";
		_image = IMAGEMANAGER->findImage(_imageName);
		_goldValue = 30;
		_range = 40;
		_gemType = YELLOWGEM;
		break;
	case 3:
		_imageName = "greengem";
		_image = IMAGEMANAGER->findImage(_imageName);
		_goldValue = 20;
		_gemType = GREENGEM;
		break;
	case 4:
		_imageName = "bluegem";
		_image = IMAGEMANAGER->findImage(_imageName);
		_goldValue = 40;
		_startY = _topY + 6;
		_gemType = BLUEGEM;
		break;
	case 5:
		_imageName = "smalljew";
		_image = IMAGEMANAGER->findImage(_imageName);
		_goldValue = 5;
		_range = 50;
		_gemType = SMALLGEM;
		break;
	case 6:
		_imageName = "bluedia";
		_image = IMAGEMANAGER->findImage(_imageName);
		_goldValue = 100;
		_startY = _topY - 25;
		_gemType = BLUEDIA;
	}
}

void gem::render()
{
	if(KEYMANAGER->isToggleKey(VK_F1))
	RectangleMake(getMemDC(), CAMERAMANAGER->CameraRelativePointX(_rc.left), CAMERAMANAGER->CameraRelativePointY(_rc.top), IMAGEMANAGER->findImage(_imageName)->getWidth(), IMAGEMANAGER->findImage(_imageName)->getHeight());

	//_image = IMAGEMANAGER->findImage(_imageName)->alphaRender(getMemDC(), CAMERAMANAGER->CameraRelativePointX(_leftX), CAMERAMANAGER->CameraRelativePointY(_topY), _alphaValue);
	_image->alphaRender(getMemDC(), CAMERAMANAGER->CameraRelativePointX(_leftX), CAMERAMANAGER->CameraRelativePointY(_topY), _alphaValue);
	//IMAGEMANAGER->findImage(_imageName)->alphaRender(getMemDC(), CAMERAMANAGER->CameraRelativePointX(_leftX), CAMERAMANAGER->CameraRelativePointY(_topY),_alphaValue);
}

void gem::move()
{
	_rc = RectMake(_leftX, _topY,IMAGEMANAGER->findImage(_imageName)->getWidth(), IMAGEMANAGER->findImage(_imageName)->getHeight());

	if (_range >= getDistance(_leftX, _topY, _startX, _startY))
	{
		_leftX += cosf(_angle) * _speedX;
		_topY += -sinf(_angle) * (5) * _speedX;
	}
	_angle += 0.04;
}



