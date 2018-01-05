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

HRESULT gem::init(const char* imageName, int goldup, int range)
{
	_imageName = imageName;

	_goldValue = goldup;
	_range = range;
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

	IMAGEMANAGER->findImage(_imageName)->alphaRender(getMemDC(), _x, _y,_alphaValue);
}

void gem::fire(int x, int y,int startX, int startY, float speed, float angle)
{
	_x = _startX = x;
	_y = _startY = y;
	_angle = angle;
	_speedX = speed;
	//파이어하지말고 생성ㄷ되자마자 무브로 옮기게;
	//_rc = RectMake(_x, _y, IMAGEMANAGER->findImage(_imageName)->getWidth(), IMAGEMANAGER->findImage(_imageName)->getHeight());
}

void gem::move()
{
	_rc = RectMake(_x, _y,IMAGEMANAGER->findImage(_imageName)->getWidth(), IMAGEMANAGER->findImage(_imageName)->getHeight());

	if (_range >= getDistance(_x, _y, _startX, _startY))
	{
		_x += cosf(_angle) * _speedX;
		_y += -sinf(_angle) * (5) * _speedX;
	}

	_angle += 0.04;
}



