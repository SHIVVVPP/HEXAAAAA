#include "stdafx.h"
#include "player.h"

void player::usage()
{
	switch (_dir)
	{
	case 1:
		_bulletAngle = PI * 2;
		break;
	case -1:
		_bulletAngle = PI;
		break;
	}

	switch (_currentRelic)
	{
	case FIRELOD:
		if (KEYMANAGER->isOnceKeyDown('B'))
		{
			if (_dir == 1)
			{
				_ani->stop();
				_playerMainCondition = PLAYER_RIGHT_ATTACK;
				_image = IMAGEMANAGER->findImage("playerAtk");
				_ani = KEYANIMANAGER->findAnimation("playerRightAttack");
				_Relic->fire(_x + (_attackRC.right - _attackRC.left), _y + (_attackRC.bottom - _attackRC.top) /4, _bulletAngle, 5.0f);
				_ani->start();
			}
			else if (_dir == -1)
			{
				_ani->stop();
				_playerMainCondition = PLAYER_LEFT_ATTACK;
				_image = IMAGEMANAGER->findImage("playerAtk");
				_ani = KEYANIMANAGER->findAnimation("playerLeftAttack");
				_Relic->fire(_x - (_attackRC.right - _attackRC.left), _y + (_attackRC.bottom - _attackRC.top) / 4, _bulletAngle, 5.0f);
				_ani->start();
			}
		}
		break;
	case ORB:
		if (_dir == 1)
		{
			_ani->stop();
			_playerMainCondition = PLAYER_RIGHT_ATTACK;
			_image = IMAGEMANAGER->findImage("playerAtk");
			_ani = KEYANIMANAGER->findAnimation("playerRightAttack");
			
			_ani->start();
		}
		else if (_dir == -1)
		{
			_ani->stop();
			_playerMainCondition = PLAYER_LEFT_ATTACK;
			_image = IMAGEMANAGER->findImage("playerAtk");
			_ani = KEYANIMANAGER->findAnimation("playerLeftAttack");
			
			_ani->start();
		}
		break;
	case FISHINGROD:
		break;
	}
}