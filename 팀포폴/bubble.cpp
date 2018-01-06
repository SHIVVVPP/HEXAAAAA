#include "stdafx.h"
#include "bubble.h"


bubble::bubble()
{
	_imageName = IMAGEMANAGER->findImage("레드비틀");
	slowFrameCounter = 0;
	frameCounter = 0;
	_speed = 3.0f;
	_rcPlaceX = 0;
	_rcPlaceY = 0;
	_rcX = 60;
	_rcY = 35;
	_hitCounter = 1;
	_jumpPower = _gravity = 0;

	_attackChance = false;
}


bubble::~bubble()
{
}

HRESULT bubble::init(MONSTER_INDEX mon_index, POINT leftX_topY)
{
	enemy::init( mon_index,  leftX_topY);
	
	return S_OK;
}

void bubble::frameMove()
{
		frameCounter++;

		if (frameCounter % 5 == 0)
		{
			if (_monsterDirection == leftMove)
			{
				if (frameCounter >= 3)frameCounter = -1;
				frameCounter++;
				frameCounter = 0;
			}
		}
}

void bubble::Move()
{
	if (_monsterDirection == leftMove)
	{
		centerX -= _speed;

		_speed += 0.2f;
	}
}
