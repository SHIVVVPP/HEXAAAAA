#include "stdafx.h"
#include "redBeetle.h"


redBeetle::redBeetle()
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


redBeetle::~redBeetle()
{
}

HRESULT redBeetle::init(MONSTER_INDEX mon_index, POINT leftX_topY)
{
	enemy::init(mon_index, leftX_topY);

	return S_OK;
}

void redBeetle::frameMove()
{
	frameCounter++;

	if (frameCounter % 10 == 0)
	{
		if (_monsterDirection == rightMove)
		{
			_currentFrameY = 0;

			if (_currentFrameX >= 3)_currentFrameX = -1;
			_currentFrameX++;

			frameCounter = 0;
		}
		if (_monsterDirection == leftMove)
		{
			_currentFrameY = 2;
			if (_currentFrameX <= 0)_currentFrameX = 4;
			_currentFrameX--;

			frameCounter = 0;
		}

		if (_monsterDirection == rightDead)
		{
			if (_currentFrameX >= 1)_currentFrameX = -1;
			_currentFrameX++;

			frameCounter = 0;
		}
		if (_monsterDirection == leftDead)
		{
			if (_currentFrameX <= 0)_currentFrameX = 2;
			_currentFrameX--;

			frameCounter = 0;
		}
		_imageName->setFrameX(_currentFrameX);
	}
}

