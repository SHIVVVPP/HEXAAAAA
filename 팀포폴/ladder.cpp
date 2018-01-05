#include "stdafx.h"
#include "ladder.h"


ladder::ladder()
{
	_type = TYPE_LADDER;
	
	_move = false;
	_hang = true;

	_picked = false;
	//_isHit = false;
}


ladder::~ladder()
{
}

HRESULT ladder::init(int x, int y, float length)
{
	_height = length;
	_leftX = x;
	_topY = y;
	_rc = RectMake(_leftX, _topY, IMAGEMANAGER->findImage("ladder")->getWidth(), _height);
	return S_OK;
}

void ladder::render()
{
	int tempY = _rc.bottom;

	if (KEYMANAGER->isToggleKey(VK_F1))Rectangle(getMemDC(),_rc.left, _rc.top, _rc.right, _rc.bottom);

	for (; tempY >= _rc.top + IMAGEMANAGER->findImage("ladder")->getHeight();)
	{
		tempY -= IMAGEMANAGER->findImage("ladder")->getHeight();
		IMAGEMANAGER->findImage("ladder")->render(getMemDC(), _leftX, tempY);
	}
	_rc.top = tempY;
	_rc.right = _rc.left + IMAGEMANAGER->findImage("ladder")->getWidth();
	IMAGEMANAGER->findImage("ladder")->render(getMemDC(),_rc.left,_height);
}
