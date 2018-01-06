#include "stdafx.h"
#include "blueSlime.h"


blueSlime::blueSlime()
{
	_imageName = IMAGEMANAGER->findImage("ΩΩ∂Û¿”");
	slowFrameCounter = 0;
	frameCounter = 0;
	_speed = 3.0f;
	_rcPlaceX = 0;
	_rcPlaceY = 10;
	_rcX = 50;
	_rcY = 50;
	_hitCounter = 2;
	_jumpPower = _gravity = 0;

	_attackChance = false;
}


blueSlime::~blueSlime()
{
}
HRESULT blueSlime::init(MONSTER_INDEX mon_index, POINT leftX_topY)
{
	enemy::init(mon_index, leftX_topY);

	return S_OK;
}

void blueSlime::frameMove()
{
	frameCounter++;

	if (frameCounter % 10 == 0)
	{
		if (_monsterDirection == leftMove)
		{
			_currentFrameY = 3;
			if (_currentFrameX <= 0)_currentFrameX = 4;
			_currentFrameX--;

			frameCounter = 0;
		}
		if (_monsterDirection == rightMove)
		{
			_currentFrameY = 1;

			if (_currentFrameX >= 3)_currentFrameX = -1;
			_currentFrameX++;

			frameCounter = 0;
		}
		_imageName->setFrameX(_currentFrameX);
	}
}
