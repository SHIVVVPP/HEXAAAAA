#include "stdafx.h"
#include "yellowDragon.h"


yellowDragon::yellowDragon()
{
	_imageName = IMAGEMANAGER->findImage("노란용");
	slowFrameCounter = 0;
	frameCounter = 0;
	_speed = 3.0f;
	_rcPlaceX = 0;
	_rcPlaceY = 0;
	
	_rcX = 50;
	_rcY = 50;

	_subRcX = 50;
	_subRcY = 50;

	_subRcPlaceX = 0;
	_subRcPlaceY = 0;

	_hitCounter = 7;
	_jumpPower = _gravity = 0;

	_attackChance = false;
}


yellowDragon::~yellowDragon()
{
}

HRESULT yellowDragon::init(MONSTER_INDEX mon_index, POINT leftX_topY)
{
	enemy::init(mon_index, leftX_topY);
	_monsterDirection = leftStand;
	_subCollisionRc = RectMakeCenter(centerX + _subRcPlaceX, centerY + _subRcPlaceY, _subRcX, _subRcY);	//서브충돌렉트

	return S_OK;
}

void yellowDragon::frameMove()
{
	frameCounter++;
	if (frameCounter % 10 == 0)
	{

		if (_monsterDirection == leftStand)
		{
			_currentFrameY = 0;

			if (_currentFrameX >= 11)_currentFrameX = -1;
			_currentFrameX++;

			frameCounter = 0;
		}


		if (_monsterDirection == leftMove)
		{
			_currentFrameY = 1;

			if (_currentFrameX >= 5)_currentFrameX = -1;
			_currentFrameX++;

			frameCounter = 0;
		}
		if (_monsterDirection == leftAttack)
		{
			_currentFrameY = 2;

			if (_currentFrameX < 2)_currentFrameX++;

			frameCounter = 0;
		}

		if (_monsterDirection == rightMove)
		{
			_currentFrameY = 3;

			if (_currentFrameX >= 5)_currentFrameX = -1;
			_currentFrameX++;

			frameCounter = 0;
		}

	}


	_imageName->setFrameX(_currentFrameX);
	_imageName->setFrameY(_currentFrameY);
}
