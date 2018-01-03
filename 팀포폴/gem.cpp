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

HRESULT gem::init(const char* imageName, int goldup)
{
	_imageName = imageName;
	_goldValue = goldup;
	
	return S_OK;
}

void gem::update()
{
	move();
	
}

void gem::render()
{
	if(KEYMANAGER->isToggleKey(VK_F1))
	Rectangle(getMemDC(),_rc.left, _rc.top, _rc.right, _rc.bottom);

	IMAGEMANAGER->findImage(_imageName)->render(getMemDC(), _x, _y);
}

void gem::fire(int x, int y,int startX, int startY, float speed, float angle)
{
	_x = _startX = x;
	_y = _startY = y;
	_angle = angle;
	_speedX = speed;

	//_rc = RectMake(_x, _y, IMAGEMANAGER->findImage(_imageName)->getWidth(), IMAGEMANAGER->findImage(_imageName)->getHeight());
}

void gem::move()
{
	_rc = RectMake(_x, _y,IMAGEMANAGER->findImage(_imageName)->getWidth(), IMAGEMANAGER->findImage(_imageName)->getHeight());

	_x += cosf(_angle) * _speedX;
	_y += -sinf(_angle) * (10) * _speedX;
}



