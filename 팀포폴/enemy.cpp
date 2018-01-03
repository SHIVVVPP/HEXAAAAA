#include "stdafx.h"
#include "enemy.h"


enemy::enemy()
{

}

enemy::~enemy()
{

}


HRESULT enemy::init()
{
	

	return S_OK;
}

HRESULT enemy::init(const char * imageName, POINT position, int hitCounter, int rcX, int rcY, int rcPlaceX, int rcPlaceY)
{
	_currentFrameX = _currentFrameY = 0;

	_imageName = IMAGEMANAGER->findImage(imageName);

	slowFrameCounter = 0;
	frameCounter = 0;
	_index = 0;

	_rcX = rcX;				//충돌렉트 x
	_rcY = rcY;				//충돌렉트 Y

	_rcPlaceX = rcPlaceX;	//충돌렉트 X좌표 설정
	_rcPlaceY = rcPlaceY;	//충돌렉트 Y좌표 설정

	_monsterDirection = leftMove;	//초기 상태

	
	
	_attackChance = false;

	centerX = position.x;			//개체 x좌표
	centerY = position.y;			//개체 Y좌표

	_rc = RectMakeCenter(centerX, centerY, _imageName->getFrameWidth(), _imageName->getFrameHeight());  //이미지 기준 렉트

	_collisionRc = RectMakeCenter((centerX + _rcPlaceX), (centerY + _rcPlaceY), _rcX, _rcY);			//충돌렉트		

	_detectRc = RectMakeCenter(centerX, centerY, 150, 500);
																										
	_attackRc = RectMake(centerX, centerY, 0, 0);
																							

	reflectJumpPower = 5.0f;   //플레이어에게 넘겨줄 점프 파워 정보

	_hitCounter = hitCounter;

	_probeX  = centerX;

	_probeY = (centerY + _rc.bottom - _rc.top ) / 2;

	return S_OK;
}

HRESULT enemy::init(const char * imageName, POINT position, int hitCounter, int rcX, int rcY, int rcPlaceX, int rcPlaceY
	, int subRcX, int subRcY, int subRcPlaceX, int subRcPlaceY)
{
	_currentFrameX = _currentFrameY = 0;

	_imageName = IMAGEMANAGER->findImage(imageName);

	_rcX = rcX;						 //충돌렉트 x
	_rcY = rcY;						 //충돌렉트 Y

	_rcPlaceX = rcPlaceX;			//충돌렉트 X좌표 설정
	_rcPlaceY = rcPlaceY;			//충돌렉트 Y좌표 설정

	_subRcX = subRcX;				//서브충돌렉트 X 크기
	_subRcY = subRcY;				//서브충돌렉트 Y 크기

	_subRcPlaceX = subRcPlaceX;		// 서브충돌렉트 X좌표 설정
	_subRcPlaceY = subRcPlaceY;		// 서브충돌랙트 Y좌표 설정

	_monsterDirection = leftStand;

	centerX = position.x;			//몬스터 X좌표
	centerY = position.y;			//몬스터 Y좌표

	_rc = RectMakeCenter(centerX, centerY, _imageName->getFrameWidth(), _imageName->getFrameHeight()); //이미지 렉트 

	_collisionRc = RectMakeCenter(centerX + _rcPlaceX, centerY + _rcPlaceY, _rcX, _rcY);				//충돌렉트 

	_subCollisionRc = RectMakeCenter(centerX + _subRcPlaceX, centerY + _subRcPlaceY, _subRcX, _subRcY);	//서브충돌렉트

	reflectJumpPower = 5.0f;	//플레이어에게 넘겨줄 점프 파워 정보

	_hitCounter = hitCounter;

	return S_OK;
}

void enemy::release()
{

}

void enemy::update()
{
	_collisionRc = RectMakeCenter(centerX + _rcPlaceX, centerY + _rcPlaceY, _rcX, _rcY);				//충돌렉트 움직여주기

	_subCollisionRc = RectMakeCenter(centerX + _subRcPlaceX, centerY + _subRcPlaceY, _subRcX, _subRcY);//서브충돌렉트 움직여주기

	_rc = RectMakeCenter(centerX, centerY, _imageName->getFrameWidth(), _imageName->getFrameHeight());

	_detectRc = RectMakeCenter(centerX, centerY, 150, 500);												//감지범위 렉트 업데이트

	_probeX = centerX ;
	_probeY = (centerY + _rc.bottom - _rc.top) / 2;

}

void enemy::render()
{
	_imageName->frameRender(getMemDC(), _rc.left, _rc.top, _currentFrameX, _currentFrameY);
	//_imageName->aniRender(getMemDC(), _rc.left, _rc.right , _monsterMotion );

	//Rectangle(getMemDC(), _collisionRc.left, _collisionRc.top, _collisionRc.right, _collisionRc.bottom);
	//
	//Rectangle(getMemDC(), _subCollisionRc.left, _subCollisionRc.top, _subCollisionRc.right, _subCollisionRc.bottom);

	if (KEYMANAGER->isToggleKey(VK_F1))
	{
		Rectangle(getMemDC(), _collisionRc.left, _collisionRc.top, _collisionRc.right, _collisionRc.bottom);			//메인렉트

		Rectangle(getMemDC(), _subCollisionRc.left, _subCollisionRc.top, _subCollisionRc.right, _subCollisionRc.bottom);	//서브렉트

		Rectangle(getMemDC(), _attackRc.left, _attackRc.top, _attackRc.right, _attackRc.bottom);			//공격렉트
	}


}




void enemy::slimeFameMove()
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

void enemy::redbeetleFrameMove()
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

void enemy::greenDragonFrameMove()
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

void enemy::yellowDragonFrameMove()
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

void enemy::skeletonFrameMove()
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
				_attackRc = RectMake(centerX, centerY, 0 , 0);
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

void enemy::bossFrameMove()
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
		}

		if (_monsterDirection == rightJumpAttack)
		{
			_currentFrameY = 5;

			_currentFrameX = 0;

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

			if (_currentFrameX <= 3)_currentFrameX = -1;
			_currentFrameX++;

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
		}

		if (_monsterDirection == leftJumpAttack)
		{
			_currentFrameY = 29;

			_currentFrameX = 6;

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



void enemy::generalMove()
{
	for (int i = _probeY - 10; i < _probeY + 20; ++i)
	{
		COLORREF color = GetPixel(IMAGEMANAGER->findImage("임시배경")->getMemDC(), centerX, i);

		int r = GetRValue(color);
		int g = GetGValue(color);
		int b = GetBValue(color);

		if ((r == 0 && g == 255 && b == 0))
		{
			centerY = i - (_rc.bottom - _rc.top) / 2;
			break;
		}
	}
	///////
	if (_monsterDirection == leftMove)
	{

		COLORREF color = GetPixel(IMAGEMANAGER->findImage("임시배경")->getMemDC(), _rc.left, centerY + (_rc.bottom - _rc.top) / 2 + 1);

		int r = GetRValue(color);
		int g = GetGValue(color);
		int b = GetBValue(color);

		if (!(r == 0 && g == 255 && b == 0))
		{
			//exit(0);
			if (_monsterDirection == leftMove)
			{
				//exit(0);
				_monsterDirection = rightMove;
			}

		}

	}

	if (_monsterDirection == rightMove)
	{
		//exit(0);

		COLORREF color = GetPixel(IMAGEMANAGER->findImage("임시배경")->getMemDC(), _rc.right, centerY + (_rc.bottom - _rc.top) / 2 + 1);

		int r = GetRValue(color);
		int g = GetGValue(color);
		int b = GetBValue(color);

		if (!(r == 0 && g == 255 && b == 0))
		{
			//exit(0);
			if (_monsterDirection == rightMove)
			{
				//exit(0);
				_monsterDirection = leftMove;
			}

		}

	}

	if (_monsterDirection == rightMove)
	{
		centerX += 5;
	}

	if (_monsterDirection == leftMove)
	{
		centerX -= 5;
	}
}

void enemy::damaged()
{
	_hitCounter--;
}


