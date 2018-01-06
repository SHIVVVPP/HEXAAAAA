#include "stdafx.h"
#include "boss.h"


boss::boss()
{
}


boss::~boss()
{
}

HRESULT boss::init(MONSTER_INDEX mon_index, POINT leftX_topY)
{
	enemy::init(mon_index, leftX_topY);
	return S_OK;
}

void boss::frameMove()
{
	frameCounter++;

	if (frameCounter % 10 == 0)
	{
		if (_monsterDirection == rightStand)
		{
			_currentFrameY = 1;

			if (_currentFrameX >= 1)_currentFrameX = -1;
			_currentFrameX++;

			frameCounter = 0;
		}

		if (_monsterDirection == rightMove)
		{
			_currentFrameY = 11;

			if (_currentFrameX <= 5)_currentFrameX = -1;
			_currentFrameX++;

			frameCounter = 0;
		}

		if (_monsterDirection == rightJump)
		{
			_currentFrameY = 2;

			_currentFrameX = 0;

			frameCounter = 0;

			centerX += 3;
			centerY -= (_jumpPower - _gravity);
			_gravity += 0.1f;
		}

		if (_monsterDirection == rightJumpAttack)
		{
			_currentFrameY = 5;

			_currentFrameX = 0;

			centerY += (_gravity);

			_gravity += 0.2f;

			_attackRc = RectMake(_rc.left, centerY, 80, 70);

			frameCounter = 0;

		}

		if (_monsterDirection == rightRangeAttack)
		{
			_currentFrameY = 6;

			if (_currentFrameX <= 3)_currentFrameX = -1;
			_currentFrameX++;

			frameCounter = 0;
		}

		if (_monsterDirection == rightAttack)
		{
			_currentFrameY = 8;

			if (_currentFrameX < 3)
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

		if (_monsterDirection == rightDamaged)
		{
			_currentFrameY = 20;

			_currentFrameX = 0;

			frameCounter = 0;
		}

		if (_monsterDirection == rightDead)
		{
			_currentFrameY = 17;

			if (_currentFrameX >= 4) _currentFrameX = -1;
			_currentFrameX++;

			frameCounter = 0;
		}
		////////////////////////////////////////////////////// 방향전환

		if (_monsterDirection == leftStand)
		{
			_currentFrameY = 25;

			if (_currentFrameX <= 5)_currentFrameX = 6;
			_currentFrameX--;

			frameCounter = 0;
		}

		if (_monsterDirection == leftMove)
		{
			_currentFrameY = 35;

			if (_currentFrameX <= 0)_currentFrameX = 6;
			_currentFrameX--;

			frameCounter = 0;
		}

		if (_monsterDirection == leftJump)
		{
			_currentFrameY = 26;

			_currentFrameX = 6;

			frameCounter = 0;

			centerX -= 3;
			centerY -= (_jumpPower - _gravity);
			_gravity += 0.1f;
		}

		if (_monsterDirection == leftJumpAttack)
		{
			_currentFrameY = 29;

			_currentFrameX = 6;

			centerY += _gravity;
			_gravity += 0.2f;

			_attackRc = RectMake(_rc.left, centerY, 80, 70);

			frameCounter = 0;
		}

		if (_monsterDirection == leftRangeAttack)
		{
			_currentFrameY = 30;


			if (_currentFrameX <= 3)_currentFrameX = 6;
			_currentFrameX--;

			frameCounter = 0;
		}

		if (_monsterDirection == leftAttack)
		{
			_currentFrameY = 36;


			if (_currentFrameX <= 3)_currentFrameX = 6;
			_currentFrameX--;

			frameCounter = 0;
		}

		if (_monsterDirection == leftDead)
		{
			_currentFrameY = 41;


			if (_currentFrameX <= 2)_currentFrameX = 6;
			_currentFrameX--;

			frameCounter = 0;
		}

		if (_monsterDirection == leftDamaged)
		{
			_currentFrameY = 44;


			_currentFrameX = 6;

			frameCounter = 0;
		}




	}




	_imageName->setFrameX(_currentFrameX);
	_imageName->setFrameY(_currentFrameY);

}
