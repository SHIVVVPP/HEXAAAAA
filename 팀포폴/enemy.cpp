#include "stdafx.h"
#include "enemy.h"




enemy::enemy()
{

}

enemy::~enemy()
{

}

HRESULT enemy::init(MONSTER_INDEX mon_index, POINT leftX_topY)
{
	return S_OK;
}
void enemy::release()
{

}

void enemy::update()
{

}

void enemy::render()
{

}


void enemy::pixelCollisionReact(image * collisionImage, POINT ptReal)
{
	int probeY = _collisionRc.bottom - ptReal.y;
	int probeX = (_collisionRc.left + _collisionRc.right) / 2 - ptReal.x;
	int r, g, b;
	
	int offsetY = 0;

	//¹Ù´ÚÃæµ¹
	bool e = false;
	for (int i = probeY + 10; i > probeY - 10; i--)
	{
		COLORREF color = GetPixel(collisionImage->getMemDC(), probeX, i);
		r = GetRValue(color);
		g = GetGValue(color);
		b = GetBValue(color);

		if (r == 0 && g == 255 & b == 0)
		{
			offsetY++;
			e = true;
		}
		else break;
	}
	if (e)
	{
		if (_subCondition != LAND)
		{
			this->setSubCondition(LAND);
			_cy -= offsetY-10;
		}
	}
	else 
	{
		this->setSubCondition(FALL);
	}
	
	//¿·Ãæµ¹
	probeX = _collisionRc.left - ptReal.x;
	COLORREF color = GetPixel(collisionImage->getMemDC(),probeX, _collisionRc.bottom-10);
	r = GetRValue(color);
	g = GetGValue(color);
	b = GetBValue(color);
	if (r == 0 && g == 255 & b == 0)
	{
		int offsetX = 0;
		for (int i = probeX; i < probeX + _width / 2; i++)
		{
			color = GetPixel(collisionImage->getMemDC(), i, _collisionRc.bottom - 10);
			r = GetRValue(color);
			g = GetGValue(color);
			b = GetBValue(color);
			if (r == 0 && g == 255 && b == 0)
			{
				offsetX++;
			}
		}
		_cx += offsetX;
		changeDirection();
	}
	
	probeX = _collisionRc.right - ptReal.x;
	color = GetPixel(collisionImage->getMemDC(), probeX, _collisionRc.bottom - 10);
	r = GetRValue(color);
	g = GetGValue(color);
	b = GetBValue(color);
	if (r == 0 && g == 255 & b == 0)
	{
		int offsetX = 0;
		for (int i = probeX; i > probeX - _width / 2; i--)
		{
			color = GetPixel(collisionImage->getMemDC(), i, _collisionRc.bottom - 10);
			r = GetRValue(color);
			g = GetGValue(color);
			b = GetBValue(color);
			if (r == 0 && g == 255 && b == 0)
			{
				offsetX++;
			}
		}
		_cx -= offsetX;
		changeDirection();
	}

}

void enemy::changeDirection()
{
	if (_isRight) _isRight = false;
	else _isRight = true;

	this->setCondition();
}
