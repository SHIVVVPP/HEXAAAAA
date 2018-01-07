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
	COLORREF color;
	int probeY = _collisionRc.bottom - ptReal.y;
	int probeX = (_collisionRc.left + _collisionRc.right) / 2 - ptReal.x;
	int r, g, b;
	
	int offsetY = 0;

	//¹Ù´ÚÃæµ¹
	bool e = false;
	for (int i = probeY + 10; i > probeY - 10; --i)
	{
		color = GetPixel(collisionImage->getMemDC(), probeX, i);
		r = GetRValue(color);
		g = GetGValue(color);
		b = GetBValue(color);

		if (r == 0 && g == 255 & b == 0)
		{
			e = true;
			offsetY++;
		}
		else break;
	}
	if (e)
	{
			if (_subCondition == FALL)
			{
				this->setSubCondition(LAND);
				_topY = _collisionRc.bottom + 10 - offsetY - _height;
			}
	}
	else 
	{
		color = GetPixel(collisionImage->getMemDC(), probeX + _width / 2, probeY + 1);
		r = GetRValue(color);
		g = GetGValue(color);
		b = GetBValue(color);

		color = GetPixel(collisionImage->getMemDC(), probeX - _width / 2, probeY + 1);
		int r1 = GetRValue(color);
		int g1 = GetGValue(color);
		int b1 = GetBValue(color);

		if (!(r == 0 && g == 255 & b == 0) && !(r1 == 0 && g1 == 255 & b1 == 0))
		{
			this->setSubCondition(FALL);
		}
	}
	
	//¿·Ãæµ¹
	probeX = _collisionRc.left - ptReal.x;
	probeY = _collisionRc.bottom - 10 - ptReal.y;
	color = GetPixel(collisionImage->getMemDC(),probeX, probeY);
	r = GetRValue(color);
	g = GetGValue(color);
	b = GetBValue(color);
	if (r == 0 && g == 255 && b == 0)
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
		_leftX += offsetX;
		changeDirection();
	}
	
	probeX = _collisionRc.right - ptReal.x;
	color = GetPixel(collisionImage->getMemDC(), probeX, probeY);
	r = GetRValue(color);
	g = GetGValue(color);
	b = GetBValue(color);
	if (r == 0 && g == 255 && b == 0)
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
		_leftX -= offsetX;
		changeDirection();
	}

}

void enemy::changeDirection()
{
	if (_isRight) _isRight = false;
	else _isRight = true;

	this->setCondition();
}

void enemy::changeDirection(bool state)
{
	_isRight = state;
	this->setCondition();
}
