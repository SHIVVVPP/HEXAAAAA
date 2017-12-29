#include "stdafx.h"
#include "player.h"


player::player()
{
}


player::~player()
{
}


HRESULT player::init()
{
	//IMAGEMANAGER->addFrameImage("playerIdle", "character//playerIdle.bmp", 250, 500, 1, 2, true, RGB(255, 0, 255));
	//IMAGEMANAGER->addFrameImage("playerAttack", "character//playerAtk.bmp", 1000, 500, 4, 2, true, RGB(255, 0, 255));
	//IMAGEMANAGER->addFrameImage("playerDownAttack", "character//playerDownAtk.bmp", 250, 500, 1, 2, true, RGB(255, 0, 255));
	//IMAGEMANAGER->addFrameImage("playerWalk", "character//playerWalk.bmp", 1500, 500, 6, 2, true, RGB(255, 0, 255));
	//IMAGEMANAGER->addFrameImage("playerHitted", "character//playerHitted.bmp", 250, 500, 1, 2, true, RGB(255, 0, 255));
	//IMAGEMANAGER->addFrameImage("playerClimb", "character//playerLadder.bmp", 250, 750, 1, 3, true, RGB(255, 0, 255));

	_playerMainCondition = PLAYER_RIGHT_IDLE;
	_playerSubCondition = PLAYER_NOTHING;
	
	
	
	_x = WINSIZEX / 2;
	_y = WINSIZEY / 2;

	_playerRC = RectMakeCenter(_x, _y, 150, 160);
	_imageRC = RectMakeCenter(_x, _y, 250, 250);

	//플레이어 기본값 초기화
	_currentHP = _maxHP = 8;
	_currentMP = _maxMP = 30;
	_playerGold = 0;
	_equipmentRelic = NULL;
	_speed = 5.0f;
	_jumpPower = 5.0f;
	_gravity = 0.2f;
	//_probeY = 0;
	_repulsivePower = 3.0f;     // 타격 시 플레이어를 뒤로 자연스럽게 밀어내기 위한 반발력
	_frictionalPower = 0.2f;	// 반발력을 서서히 삭감시키기 위한 마찰력
	_isJump = false;


	int rightIdle[] = { 0 };
	KEYANIMANAGER->addArrayFrameAnimation("playerRightIdle", "playerIdle", rightIdle, 1, 6, true);
	int leftIdle[] = { 1 };
	KEYANIMANAGER->addArrayFrameAnimation("playerLeftIdle", "playerIdle", leftIdle, 1, 6, true);
	int rightMove[] = { 0,1,2,3,4,5 };
	KEYANIMANAGER->addArrayFrameAnimation("playerRightMove", "playerWalk", rightMove, 6, 8, true);
	int leftMove[] = { 6,7,8,9,10,11 };
	KEYANIMANAGER->addArrayFrameAnimation("playerLeftMove", "playerWalk", leftMove, 6, 8, true);
	int rightJump[] = { 0 };
	KEYANIMANAGER->addArrayFrameAnimation("playerRightJump", "playerJump", rightJump, 1, 8, true);
	int leftJump[] = { 1 };
	KEYANIMANAGER->addArrayFrameAnimation("playerLefttJump", "playerJump", leftJump, 1, 8, true);
	int rightAttack[] = { 0,1,2,3 };
	KEYANIMANAGER->addArrayFrameAnimation("playerRightAttack", "playerAtk", rightAttack, 4, 8, true);
	int leftAttack[] = { 4,5,6,7 };
	KEYANIMANAGER->addArrayFrameAnimation("playerLeftAttack", "playerAtk", leftAttack, 4, 8, true);
	int leftDownAttack[] = { 0 };
	KEYANIMANAGER->addArrayFrameAnimation("playerLeftDownAttack", "playerDownAtk", leftDownAttack, 1, 8, true);
	int rightDownAttack[] = { 1 };
	KEYANIMANAGER->addArrayFrameAnimation("playerRightDownAttack", "playerDownAtk", rightDownAttack, 1, 8, true);
	int rightHitted[] = { 0 };
	KEYANIMANAGER->addArrayFrameAnimation("playerRightHitted", "playerHitted", rightHitted, 1, 8, true);
	int leftHitted[] = { 1 };
	KEYANIMANAGER->addArrayFrameAnimation("playerLeftHitted", "playerHitted", leftHitted, 1, 8, true);
	int leftClimb[] = { 0 };
	KEYANIMANAGER->addArrayFrameAnimation("playerLeftClimb", "playerClimb", leftClimb, 1, 8, true);
	int rightClimb[] = { 1 };
	KEYANIMANAGER->addArrayFrameAnimation("playerRightClimb", "playerClimb", rightClimb, 1, 8, true);
	int edgeClimb[] = { 2 };
	KEYANIMANAGER->addArrayFrameAnimation("playerEdgeClimb", "playerClimb", rightClimb, 1, 8, true);
	
	
	_image = IMAGEMANAGER->findImage("playerIdle");
	_ani = KEYANIMANAGER->findAnimation("playerRightIdle");
	//_image = IMAGEMANAGER->findImage()
	return S_OK;
}
void player::release()
{
}
void player::update()
{
	if (KEYMANAGER->isOnceKeyDown(VK_RIGHT))
	{
		_playerMainCondition = PLAYER_RIGHT_MOVE;
		
		_image = IMAGEMANAGER->findImage("playerWalk");
		_ani = KEYANIMANAGER->findAnimation("playerRightMove");
		_ani->start();
	}
	else if (KEYMANAGER->isOnceKeyUp(VK_RIGHT))
	{
		_ani->stop();
		_playerMainCondition = PLAYER_RIGHT_IDLE;
		_image = IMAGEMANAGER->findImage("playerIdle");
		_ani = KEYANIMANAGER->findAnimation("playerRightIdle");
		_ani->start();
	}

	if (KEYMANAGER->isOnceKeyDown(VK_LEFT))
	{
		_playerMainCondition = PLAYER_LEFT_MOVE;
		_image = IMAGEMANAGER->findImage("playerWalk");
		_ani = KEYANIMANAGER->findAnimation("playerLeftMove");
		_ani->start();
	}
	else if (KEYMANAGER->isOnceKeyUp(VK_LEFT))
	{
		_ani->stop();
		_playerMainCondition = PLAYER_LEFT_IDLE;
		_image = IMAGEMANAGER->findImage("playerIdle");
		_ani = KEYANIMANAGER->findAnimation("playerLeftIdle");
		_ani->start();
	}
	if (KEYMANAGER->isOnceKeyDown(VK_UP) && _playerSubCondition == PLAYER_LADDER)
	{
		_playerMainCondition = PLAYER_LEFT_CLIMB;
		_image = IMAGEMANAGER->findImage("playerClimb");
		_ani = KEYANIMANAGER->findAnimation("playerLeftClimb");
		_ani->start();
	}
	if (KEYMANAGER->isOnceKeyUp(VK_UP) && _playerSubCondition == PLAYER_LADDER)
	{
		_ani->stop();
	}

	if (KEYMANAGER->isOnceKeyDown(VK_SPACE) && _isJump == false)
	{
		if (_playerMainCondition == PLAYER_RIGHT_IDLE || _playerMainCondition == PLAYER_RIGHT_MOVE)
		{
			_playerMainCondition = PLAYER_RIGHT_JUMP;
			_image = IMAGEMANAGER->findImage("playerJump");
			_ani = KEYANIMANAGER->findAnimation("playerRightJump");
			_ani->start();
		}
		if (_playerMainCondition == PLAYER_LEFT_IDLE || _playerMainCondition == PLAYER_LEFT_MOVE)	_playerMainCondition = PLAYER_LEFT_JUMP;
		_isJump = true;
	}

	

	switch (_playerMainCondition)
	{
	case PLAYER_RIGHT_IDLE:
		break;
	case PLAYER_LEFT_IDLE:
		break;
	case PLAYER_IDLE_JUMP:
		_y -= _jumpPower;
		_jumpPower -= _gravity;
		break;
	case PLAYER_RIGHT_JUMP:
		_x += _speed;
		_y -= _jumpPower;
		_jumpPower -= _gravity;
		break;
	case PLAYER_LEFT_JUMP:
		_x -= _speed;
		_y -= _jumpPower;
		_jumpPower -= _gravity;
		break;
	case PLAYER_RIGHT_MOVE:
		_x += _speed;
		break;
	case PLAYER_LEFT_MOVE:
		_x -= _speed;
		break;
	case PLAYER_RIGHT_CLIMB:
		if (KEYMANAGER->isStayKeyDown(VK_UP))
		{
			_y -= _speed;
			_playerMainCondition = PLAYER_LEFT_CLIMB;
		}
		if (KEYMANAGER->isStayKeyDown(VK_DOWN))
		{
			_y += _speed;
			_playerMainCondition = PLAYER_LEFT_CLIMB;
		}
		break;
	case PLAYER_LEFT_CLIMB:
		if (KEYMANAGER->isStayKeyDown(VK_UP))
		{
			_y -= _speed;
			_playerMainCondition = PLAYER_RIGHT_CLIMB;
		}
		if (KEYMANAGER->isStayKeyDown(VK_DOWN))
		{
			_y += _speed;
			_playerMainCondition = PLAYER_RIGHT_CLIMB;
		}
		break;
	case PLAYER_CLIMB_EDGE:
		if (KEYMANAGER->isStayKeyDown(VK_UP))
		{
			_y -= _speed;
			_playerMainCondition = PLAYER_RIGHT_CLIMB;
		}
		if (KEYMANAGER->isStayKeyDown(VK_DOWN))
		{
			_y += _speed;
			_playerMainCondition = PLAYER_RIGHT_CLIMB;
		}
		break;
	case PLAYER_RIGHT_ATTACK:
		_attackRC = RectMakeCenter(_x + 150, _y, 50, 30);
		break;
	case PLAYER_RIGHT_JUMP_ATTACK:
		_attackRC = RectMakeCenter(_x + 150, _y, 50, 30);
		break;
	case PLAYER_LEFT_ATTACK:
		_attackRC = RectMakeCenter(_x - 150, _y, 50, 30);
		break;
	case PLAYER_LEFT_JUMP_ATTACK:
		_attackRC = RectMakeCenter(_x - 150, _y, 50, 30);
		break;
	case PLAYER_DOWN_ATTACK:
		_attackRC = RectMakeCenter(_x, _y+160, 50, 30);
		break;
	case PLAYER_RIGHT_HITTED:
		_x -= _repulsivePower;
		_repulsivePower -= _frictionalPower;	
		break;
	case PLAYER_LEFT_HITTED:
		_x += _repulsivePower;
		_repulsivePower -= _frictionalPower;
		break;
	case PLAYER_DEAD:
		break;
	}

	_playerRC = RectMakeCenter(_x, _y, 150, 160);
	_imageRC = RectMakeCenter(_x, _y, 250, 250);
	KEYANIMANAGER->update();
}


void player::render()
{
	_image->aniRender(getMemDC(), _imageRC.left, _imageRC.top, _ani);

	if (KEYMANAGER->isToggleKey(VK_F1))
	{
		Rectangle(getMemDC(), _imageRC.left, _imageRC.top, _imageRC.right, _imageRC.bottom);
		Rectangle(getMemDC(), _playerRC.left, _playerRC.top, _playerRC.right, _playerRC.bottom);
	}
}
