#include "stdafx.h"
#include "greenDragon.h"


greenDragon::greenDragon()
{
	_imageName = IMAGEMANAGER->findImage("ÃÊ·Ï¿ë");
	slowFrameCounter = 0;
	frameCounter = 0;
	_speed = 3.0f;
	_rcPlaceX = 0;
	_rcPlaceY = 0;
	_rcX = 50;
	_rcY = 50;
	_hitCounter = 3;
	_jumpPower = _gravity = 0;

	_attackChance = false;
}


greenDragon::~greenDragon()
{
}

HRESULT greenDragon::init(MONSTER_INDEX mon_index, POINT leftX_topY)
{
	enemy::init(mon_index, leftX_topY);

	return S_OK;
}

void greenDragon::frameMove()
{
	frameCounter++;
	if (frameCounter % 10 == 0)
	{
		if (_monsterDirection == rightMove)
		{
			_currentFrameY = 0;

			if (_currentFrameX >= 2)_currentFrameX = -1;
			_currentFrameX++;

			frameCounter = 0;
		}
		if (_monsterDirection == leftMove)
		{
			_currentFrameY = 4;

			if (_currentFrameX <= 0)_currentFrameX = 3;
			_currentFrameX--;

			frameCounter = 0;
		}

	}


	_imageName->setFrameX(_currentFrameX);
	_imageName->setFrameY(_currentFrameY);
}

