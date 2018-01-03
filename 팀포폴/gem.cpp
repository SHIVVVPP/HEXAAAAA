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

	IMAGEMANAGER->findImage(_imageName)->render(getMemDC(),_rc.left,_rc.top);
}

void gem::fire(int x, int y, float speed, float angle)
{
	_x = x;
	_y = y;
	_angle = angle;
	_speedX = speed;

	//_rc = RectMake(_x, _y, IMAGEMANAGER->findImage(_imageName)->getWidth(), IMAGEMANAGER->findImage(_imageName)->getHeight());
}

void gem::move()
{
	_x += _speedX;
	_y += -sinf(_angle) * (10) * _speedX;
	_rc = RectMake(_x, _y, IMAGEMANAGER->findImage(_imageName)->getWidth(), IMAGEMANAGER->findImage(_imageName)->getHeight());
}


