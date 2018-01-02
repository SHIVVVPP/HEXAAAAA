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

	frameCounter = 0;
	_index = 0;

	_rcX = rcX;				//�浹��Ʈ x
	_rcY = rcY;				//�浹��Ʈ Y

	_rcPlaceX = rcPlaceX;	//�浹��Ʈ X��ǥ ����
	_rcPlaceY = rcPlaceY;	//�浹��Ʈ Y��ǥ ����

	_monsterDirection = leftMove;	//�ʱ� ����

	
	
	

	centerX = position.x;			//��ü x��ǥ
	centerY = position.y;			//��ü Y��ǥ

	_rc = RectMakeCenter(centerX, centerY, _imageName->getFrameWidth(), _imageName->getFrameHeight());  //�̹��� ���� ��Ʈ

	_collisionRc = RectMakeCenter((centerX + _rcPlaceX), (centerY + _rcPlaceY), _rcX, _rcY);			//�浹��Ʈ									//�浹 ��Ʈ

																							

	reflectJumpPower = 5.0f;   //�÷��̾�� �Ѱ��� ���� �Ŀ� ����

	_hitCounter = hitCounter;

	_probeX  = centerX;
	_probeY = (centerY + _rc.bottom - _rc.top )/ 2;

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
		Rectangle(getMemDC(), _collisionRc.left, _collisionRc.top, _collisionRc.right, _collisionRc.bottom);

		Rectangle(getMemDC(), _subCollisionRc.left, _subCollisionRc.top, _subCollisionRc.right, _subCollisionRc.bottom);
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
	if (frameCounter % 30 == 0)
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

		if (_monsterDirection = rightJumpAttack)
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
		////////////////////////////////////////////////////// ������ȯ

		if (_monsterDirection == leftStand)
		{
			_currentFrameY = 25;

			if (_currentFrameX <= 5)_currentFrameX = 7;
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


			if (_currentFrameX <= 3)_currentFrameX = 7;
			_currentFrameX--;

			frameCounter = 0;
		}



		
	}

	


	_imageName->setFrameX(_currentFrameX);
	_imageName->setFrameY(_currentFrameY);
}

void enemy::generalMove()
{
	for (int i = _probeY - 50; i < _probeY + 50; ++i)
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
		for (int i = _probeX - 50; i < _probeX; ++i)
		{
			COLORREF color = GetPixel(IMAGEMANAGER->findImage("�ӽù��")->getMemDC(), i, centerY + (_rc.bottom - _rc.top) / 2 + 50);

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
				break;
			}
		}
	}

	if (_monsterDirection == rightMove)
	{
		//exit(0);
		for (int i = _probeX ; i < _probeX + 50; ++i)
		{
			COLORREF color = GetPixel(IMAGEMANAGER->findImage("�ӽù��")->getMemDC(), i, centerY + (_rc.bottom - _rc.top) / 2 + 50);

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
				break;
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


