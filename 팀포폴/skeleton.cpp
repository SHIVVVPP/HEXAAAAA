#include "stdafx.h"
#include "skeleton.h"


skeleton::skeleton()
{
	_imageName = IMAGEMANAGER->findImage("해골");
	slowFrameCounter = 0;
	frameCounter = 0;
	_speed = 3.0f;
	_rcPlaceX = 0;
	_rcPlaceY = 0;
	_rcX = 50;
	_rcY = 70;
	_hitCounter = 3;
	_jumpPower = _gravity = 0;

	_attackChance = false;
}


skeleton::~skeleton()
{
}

HRESULT skeleton::init(MONSTER_INDEX mon_index, POINT leftX_topY)
{
	enemy::init(mon_index, leftX_topY);

	return S_OK;
}

void skeleton::frameMove()
{
	frameCounter++;
	slowFrameCounter++;

	if (frameCounter % 10 == 0)
	{
		if (_monsterDirection == rightStand)
		{
			_currentFrameY = 0;
			_currentFrameX = 0;

			frameCounter = 0;
		}

		if (_monsterDirection == rightMove)
		{
			_currentFrameY = 1;
			if (_currentFrameX >= 3)_currentFrameX = -1;
			_currentFrameX++;

			frameCounter = 0;
		}


		if (_monsterDirection == rightAttack)
		{
			_currentFrameY = 5;
			if (_currentFrameX < 1)
			{
				_currentFrameX++;

				_attackRc = RectMake(centerX, _rc.top + 30, 80, 70);
			}
			else
			{
				_attackRc = RectMake(centerX, centerY, 0, 0);
			}
			frameCounter = 0;
		}


		if (_monsterDirection == rightSpawn)
		{
			_currentFrameY = 10;
			if (_currentFrameX < 3)_currentFrameX++;

			frameCounter = 0;
		}

		if (_monsterDirection == leftStand)
		{
			_currentFrameY = 12;
			_currentFrameX = 3;

			frameCounter = 0;
		}

		if (_monsterDirection == leftMove)
		{
			_currentFrameY = 13;

			if (_currentFrameX <= 0) _currentFrameX = 4;

			_currentFrameX--;

			frameCounter = 0;
		}

		if (_monsterDirection == leftAttack)
		{
			_currentFrameY = 16;
			if (_currentFrameX > 2)
			{
				_currentFrameX--;

				_attackRc = RectMake(centerX - 80, _rc.top + 30, 80, 70);
			}
			else
			{

				_attackRc = RectMake(centerX, centerY, 0, 0);

				_monsterDirection = leftStand;
			}


			frameCounter = 0;
		}

		if (_monsterDirection == leftSpawn)
		{
			_currentFrameY = 21;
			if (_currentFrameX > 0) _currentFrameX--;
			frameCounter = 0;
		}
	}

	////////////////////////////////////////////////////////////느리게 돌아가는 프레임
	if (slowFrameCounter % 30 == 0)
	{
		if (_monsterDirection == rightBackStep)
		{
			_currentFrameY = 3;
			if (_currentFrameX < 1)_currentFrameX++;

			slowFrameCounter = 0;
		}

		if (_monsterDirection == leftBackStep)
		{
			_currentFrameY = 14;

			if (_currentFrameX > 2) _currentFrameX--;


			slowFrameCounter = 0;
		}


	}


	_imageName->setFrameX(_currentFrameX);
	_imageName->setFrameY(_currentFrameY);

}
