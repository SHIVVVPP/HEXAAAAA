#include "stdafx.h"
#include "moveblock.h"


moveblock::moveblock()
{
	_type = TYPE_MOVING_BLOCK;
	_move = true;
	_canLand = true;
	_hang = false;
	_picked = false;
	_isRight = false;
	_isUp = false;
	_direction = false;
	//_isHit = false;
}


moveblock::~moveblock()
{
}

HRESULT moveblock::init(int x, int y,int range,bool isRight,bool isUp , bool type)
{
	_width = IMAGEMANAGER->findImage("movingrock")->getWidth();
	_height = IMAGEMANAGER->findImage("movingrock")->getHeight();

	_leftX = x;
	_topY = y;
	_startX = x;
	_startY = y;
	_range = range;
	_speedX = 2;
	_speedY = 2;
	_isRight = isRight;
	_isUp = isUp;
	_direction = type;
	_rc = RectMake(_leftX, _topY, IMAGEMANAGER->findImage("movingrock")->getWidth(), IMAGEMANAGER->findImage("movingrock")->getHeight());
	return S_OK;
}

void moveblock::update()
{
	
	
	_rc = RectMake(_leftX, _topY, _width, _height);

	if (!_direction)
	{
		_leftX += _speedX;
		if (_range <= getDistance(_leftX, _topY, _startX, _startY))
		{
			_speedX = -2;
			_isRight = false;
		}
		if (_leftX <= _startX)
		{
			_speedX = 2;
			_isRight = true;
		}
	}
	else if(_direction)
	{
		_topY += _speedY;
		if (_range <= getDistance(_leftX, _topY, _startX, _startY))
		{
			_speedY = -2;
			_isUp = false;
		}
		if (_topY <= _startY)
		{
			_speedY = 2;
			_isUp = true;
		}
	}
}

void moveblock::render()
{
	if (KEYMANAGER->isToggleKey(VK_F1))
	{
		RectangleMake(getMemDC(), CAMERAMANAGER->CameraRelativePointX(_rc.left), CAMERAMANAGER->CameraRelativePointY(_rc.top), IMAGEMANAGER->findImage("movingrock")->getWidth(), IMAGEMANAGER->findImage("movingrock")->getHeight());
	}
	
	IMAGEMANAGER->findImage("movingrock")->render(getMemDC(), CAMERAMANAGER->CameraRelativePointX(_leftX), CAMERAMANAGER->CameraRelativePointY(_topY));
}
