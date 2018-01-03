#include "stdafx.h"
#include "gem.h"


gem::gem()
{
	_type = TYPE_GEM;
	_move = false;
	_hang = false;
	_picked = false;
}

gem::~gem()
{
}

HRESULT gem::init(int x, int y , const char* imageName, int goldup)
{
	_x = x;
	_y = y;
	_imageName = imageName;
	_goldValue = goldup;
	_rc = RectMake(_x, _y, IMAGEMANAGER->findImage(imageName)->getWidth(), IMAGEMANAGER->findImage(imageName)->getHeight());
	return S_OK;
}

void gem::update()
{
}

void gem::render()
{
	if(KEYMANAGER->isToggleKey(VK_F1))
	Rectangle(getMemDC(),_rc.left, _rc.top, _rc.right, _rc.bottom);
	IMAGEMANAGER->findImage(_imageName)->render(getMemDC(),_rc.left,_rc.top);
}

void gem::respawn(int x, int y, bool fire, float angle)
{
}


