#include "stdafx.h"
#include "moveblock.h"


moveblock::moveblock()
{
	_type = TYPE_MOVING_BLOCK;
	_move = true;
	_canLand = true;
	_hang = false;
	_picked = false;
}


moveblock::~moveblock()
{
}

HRESULT moveblock::init(int x, int y,int range,bool isRight)
{
	_width = IMAGEMANAGER->findImage("movingrock")->getWidth();
	_height = IMAGEMANAGER->findImage("movingrock")->getHeight();

	_x = x;
	_y = y;
	_startX = x;
	_startY = y;
	_range = range;
	_speedX = 2;
	_rc = RectMake(_x, _y, IMAGEMANAGER->findImage("movingrock")->getWidth(), IMAGEMANAGER->findImage("movingrock")->getHeight());
	return S_OK;
}

void moveblock::update()
{
	_x += _speedX;
	_rc = RectMake(_x, _y, _width, _height);

	if (_range <= getDistance(_x, _y, _startX, _startY)) _speedX = -2;
	if (_x <= _startX) _speedX = +2;
}

void moveblock::render()
{
	if (KEYMANAGER->isToggleKey(VK_F1))
	{
		Rectangle(getMemDC(), _rc.left, _rc.top, _rc.right, _rc.bottom);
	}
	
	IMAGEMANAGER->findImage("movingrock")->render(getMemDC(),_x,_y);
}
