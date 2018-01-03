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
	_speed = 3.0f;

	_rcX = rcX;				//�浹��Ʈ x
	_rcY = rcY;				//�浹��Ʈ Y

	_rcPlaceX = rcPlaceX;	//�浹��Ʈ X��ǥ ����
	_rcPlaceY = rcPlaceY;	//�浹��Ʈ Y��ǥ ����

	_monsterDirection = leftMove;	//�ʱ� ����

	_jumpPower = _gravity = 0;

	
	
	_attackChance = false;

	centerX = position.x;			//��ü x��ǥ
	centerY = position.y;			//��ü Y��ǥ

	_rc = RectMakeCenter(centerX, centerY, _imageName->getFrameWidth(), _imageName->getFrameHeight());  //�̹��� ���� ��Ʈ

	_collisionRc = RectMakeCenter((centerX + _rcPlaceX), (centerY + _rcPlaceY), _rcX, _rcY);			//�浹��Ʈ		

	_detectRc = RectMakeCenter(centerX, centerY, 150, 500);
																										
	_attackRc = RectMake(centerX, centerY, 0, 0);
																							

	reflectJumpPower = 5.0f;   //�÷��̾�� �Ѱ��� ���� �Ŀ� ����

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

	_rcX = rcX;						 //�浹��Ʈ x
	_rcY = rcY;						 //�浹��Ʈ Y

	_rcPlaceX = rcPlaceX;			//�浹��Ʈ X��ǥ ����
	_rcPlaceY = rcPlaceY;			//�浹��Ʈ Y��ǥ ����

	_subRcX = subRcX;				//�����浹��Ʈ X ũ��
	_subRcY = subRcY;				//�����浹��Ʈ Y ũ��

	_subRcPlaceX = subRcPlaceX;		// �����浹��Ʈ X��ǥ ����
	_subRcPlaceY = subRcPlaceY;		// �����浹��Ʈ Y��ǥ ����

	_monsterDirection = leftStand;

	centerX = position.x;			//���� X��ǥ
	centerY = position.y;			//���� Y��ǥ

	_rc = RectMakeCenter(centerX, centerY, _imageName->getFrameWidth(), _imageName->getFrameHeight()); //�̹��� ��Ʈ 

	_collisionRc = RectMakeCenter(centerX + _rcPlaceX, centerY + _rcPlaceY, _rcX, _rcY);				//�浹��Ʈ 

	_subCollisionRc = RectMakeCenter(centerX + _subRcPlaceX, centerY + _subRcPlaceY, _subRcX, _subRcY);	//�����浹��Ʈ

	reflectJumpPower = 5.0f;	//�÷��̾�� �Ѱ��� ���� �Ŀ� ����

	_hitCounter = hitCounter;

	return S_OK;
}

void enemy::release()
{

}

void enemy::update()
{
	_collisionRc = RectMakeCenter(centerX + _rcPlaceX, centerY + _rcPlaceY, _rcX, _rcY);				//�浹��Ʈ �������ֱ�

	_subCollisionRc = RectMakeCenter(centerX + _subRcPlaceX, centerY + _subRcPlaceY, _subRcX, _subRcY);//�����浹��Ʈ �������ֱ�

	_rc = RectMakeCenter(centerX, centerY, _imageName->getFrameWidth(), _imageName->getFrameHeight());

	_detectRc = RectMakeCenter(centerX, centerY, 150, 500);												//�������� ��Ʈ ������Ʈ

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
		Rectangle(getMemDC(), _collisionRc.left, _collisionRc.top, _collisionRc.right, _collisionRc.bottom);			//���η�Ʈ

		Rectangle(getMemDC(), _subCollisionRc.left, _subCollisionRc.top, _subCollisionRc.right, _subCollisionRc.bottom);	//���귺Ʈ

		Rectangle(getMemDC(), _attackRc.left, _attackRc.top, _attackRc.right, _attackRc.bottom);			//���ݷ�Ʈ
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

////////////////////////////////////////////////////////////������ ���ư��� ������
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
		////////////////////////////////////////////////////// ������ȯ

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

void enemy::bubbleFrameMove()
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

void enemy::bubbleMove()
{
	if (_monsterDirection == leftMove)
	{
		centerX -= _speed;

		_speed += 0.2f;
	}
}



void enemy::generalMove()
{
	for (int i = _probeY - 10; i < _probeY + 20; ++i)
	{
		COLORREF color = GetPixel(IMAGEMANAGER->findImage("�ӽù��")->getMemDC(), centerX, i);

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

		COLORREF color = GetPixel(IMAGEMANAGER->findImage("�ӽù��")->getMemDC(), _rc.left, centerY + (_rc.bottom - _rc.top) / 2 + 1);

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

		COLORREF color = GetPixel(IMAGEMANAGER->findImage("�ӽù��")->getMemDC(), _rc.right, centerY + (_rc.bottom - _rc.top) / 2 + 1);

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


