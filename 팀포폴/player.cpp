#include "stdafx.h"
#include "player.h"
#include "NPC.h"
#include "enemy.h"
#include "objects.h"


player::player()
{
}


player::~player()
{
}


HRESULT player::init()
{
	//IMAGEMANAGER->addFrameImage("playerWalk", "./image/character/playerWalk.bmp", 1500, 500, 6, 2, true, RGB(255, 0, 255));
	//IMAGEMANAGER->addFrameImage("playerClimb", "./image/character/playerLadder.bmp", 250, 750, 1, 3, true, RGB(255, 0, 255));
	//IMAGEMANAGER->addFrameImage("playerIdle", "./image/character/playerIdle.bmp", 250, 500, 1, 2, true, RGB(255, 0, 255));
	//IMAGEMANAGER->addFrameImage("playerHitted", "./image/character/playerHitted.bmp", 250, 500, 1, 2, true, RGB(255, 0, 255));
	//IMAGEMANAGER->addFrameImage("playerDownAtk", "./image/character/playerDownAtk.bmp", 250, 500, 1, 2, true, RGB(255, 0, 255));
	//IMAGEMANAGER->addFrameImage("playerAtk", "./image/character/playerAtk.bmp", 1000, 500, 4, 2, true, RGB(255, 0, 255));
	//IMAGEMANAGER->addFrameImage("playerJump", "./image/character/playerJump.bmp", 500, 500, 2, 2, true, RGB(255, 0, 255));
	/*_Relic = new bullet;
	_Relic->init("파볼", 100, 800);*/
	_currentRelic = FIRELOD;
	_bulletAngle = PI;
	_playerMainCondition = PLAYER_RIGHT_IDLE;
	_playerSubCondition = PLAYER_NOTHING;
	
	LadderRC = RectMakeCenter(600, 450, 200, 600);

	enemyRC = RectMakeCenter(900, WINSIZEY / 2, 100, 100);
	
	
	_x = 2800;
	_y = 3800;

	_playerRC = RectMakeCenter(_x, _y, 150, 160);
	_imageRC = RectMakeCenter(_x, _y, 250, 250);
	_attackRC = RectMakeCenter(-100, -100, 150, 160);
	//플레이어 기본값 초기화
	_currentHP = _maxHP = 8;
	_currentMP = _maxMP = 30;
	_playerGold = 0;
	_equipmentRelic = NULL;
	_speed = 5.0f;
	_jumpPower = 11.0f;
	_gravity = 0.35f;
	_dir = 1;
	_probeY = 0;
	_repulsivePower = 3.0f;     // 타격 시 플레이어를 뒤로 자연스럽게 밀어내기 위한 반발력
	_frictionalPower = 0.2f;	// 반발력을 서서히 삭감시키기 위한 마찰력
	_isLadder = false;
	_isLand = false;
	_isJump = true;
	_canAtk = true;


	int rightIdle[] = { 0 };
	KEYANIMANAGER->addArrayFrameAnimation("playerRightIdle", "playerIdle", rightIdle, 1, 6, true);
	int leftIdle[] = { 1 };
	KEYANIMANAGER->addArrayFrameAnimation("playerLeftIdle", "playerIdle", leftIdle, 1, 6, true);
	int rightMove[] = { 0,1,2,3,4,5 };
	KEYANIMANAGER->addArrayFrameAnimation("playerRightMove", "playerWalk", rightMove, 6, 8, true);
	int leftMove[] = {11,10,9,8,7,6 };
	KEYANIMANAGER->addArrayFrameAnimation("playerLeftMove", "playerWalk", leftMove, 6, 8, true);
	int rightJumpUp[] = { 0 };
	KEYANIMANAGER->addArrayFrameAnimation("playerRightJumpUp", "playerJump", rightJumpUp, 1, 8, true);
	int rightJumpDown[] = { 1 };
	KEYANIMANAGER->addArrayFrameAnimation("playerRightJumpDown", "playerJump", rightJumpDown, 1, 8, true);
	int leftJumpUp[] = { 2 };
	KEYANIMANAGER->addArrayFrameAnimation("playerLeftJumpUp", "playerJump", leftJumpUp, 1, 8, true);
	int leftJumpDown[] = { 3 };
	KEYANIMANAGER->addArrayFrameAnimation("playerLeftJumpDown", "playerJump", leftJumpDown, 1, 8, true);
	int rightAttackarr[] = { 0,1,2,3 };
	KEYANIMANAGER->addArrayFrameAnimation("playerRightAttack", "playerAtk", rightAttackarr, 4, 15, false ,rightAttack, this);
	int leftAttackarr[] = {7,6,5,4 };
	KEYANIMANAGER->addArrayFrameAnimation("playerLeftAttack", "playerAtk", leftAttackarr, 4, 15, false ,leftAttack, this);
	int leftDownAttack[] = { 0 };
	KEYANIMANAGER->addArrayFrameAnimation("playerLeftDownAttack", "playerDownAtk", leftDownAttack, 1, 8, true);
	int rightDownAttack[] = { 1 };
	KEYANIMANAGER->addArrayFrameAnimation("playerRightDownAttack", "playerDownAtk", rightDownAttack, 1, 8, true);
	int rightHitted[] = { 0 };
	KEYANIMANAGER->addArrayFrameAnimation("playerRightHitted", "playerHitted", rightHitted, 1, 8, true);
	int leftHitted[] = { 1 };
	KEYANIMANAGER->addArrayFrameAnimation("playerLeftHitted", "playerHitted", leftHitted, 1, 8, true);
	int climb[] = { 0,1 };
	KEYANIMANAGER->addArrayFrameAnimation("playerClimb", "playerClimb", climb, 2, 4, true);
	int edgeClimb[] = { 2 };
	KEYANIMANAGER->addArrayFrameAnimation("playerEdgeClimb", "playerClimb", edgeClimb, 1, 8, true);
	
	
	_image = IMAGEMANAGER->findImage("playerIdle");
	_ani = KEYANIMANAGER->findAnimation("playerRightIdle");

	DATABASE->setPlayer_currentInfo(_currentHP, _maxHP, _currentMP, _playerGold);
	return S_OK;
}
void player::release()
{
}
void player::update()
{
	
	///// 상태에 따른 중력 작용 여부 //////
	if (_isJump)
	{
		_y -= _jumpPower;
		_jumpPower -= _gravity;
	}
	if (_isLand)
	{
		_jumpPower = 0.0f;
	}
	
	
	

	////////////////////// 땅 위에서의 기본 동작 ///////////////////////////////

	if (_isLand && !_isJump && !_isLadder)
	{
		if (KEYMANAGER->isOnceKeyDown(VK_RIGHT))
		{
			_dir = 1;
			_playerMainCondition = PLAYER_RIGHT_MOVE;
			setPlayerCondition();
		}
		if (KEYMANAGER->isOnceKeyUp(VK_RIGHT))
		{
			_playerMainCondition = PLAYER_RIGHT_IDLE;
			setPlayerCondition();
		}
		if (KEYMANAGER->isOnceKeyDown(VK_LEFT))
		{
			_dir = -1;
			_playerMainCondition = PLAYER_LEFT_MOVE;
			setPlayerCondition();
		}
		if (KEYMANAGER->isOnceKeyUp(VK_LEFT))
		{
			_playerMainCondition = PLAYER_LEFT_IDLE;
			setPlayerCondition();
		}
		if (KEYMANAGER->isOnceKeyDown(VK_SPACE))
		{
			_isJump = true;
			_jumpPower = 11.0f;
			_gravity = 0.35f;
			switch (_playerMainCondition)
			{
			case PLAYER_RIGHT_IDLE:
				_playerMainCondition = PLAYER_IDLE_JUMP;
				break;
			case PLAYER_LEFT_IDLE:
				_playerMainCondition = PLAYER_IDLE_JUMP;
				break;
			case PLAYER_IDLE_JUMP:
				_playerMainCondition = PLAYER_IDLE_JUMP;
				break;
			case PLAYER_RIGHT_MOVE:
				_playerMainCondition = PLAYER_RIGHT_JUMP;
				break;
			case PLAYER_LEFT_MOVE:
				_playerMainCondition = PLAYER_LEFT_JUMP;
				break;
			case PLAYER_UP_CLIMB:
				_playerMainCondition = PLAYER_IDLE_JUMP;
				break;
			case PLAYER_DOWN_CLIMB:
				_playerMainCondition = PLAYER_IDLE_JUMP;
				break;
			case PLAYER_EDGE_CLIMB:
				_playerMainCondition = PLAYER_IDLE_JUMP;
				break;
			}
			setPlayerCondition();
		
		}
		if (KEYMANAGER->isOnceKeyDown('A'))
		{
			switch (_dir)
			{
			case 1:
				_playerMainCondition = PLAYER_RIGHT_ATTACK;
				setPlayerCondition();
				break;

			case -1:
				_playerMainCondition = PLAYER_LEFT_ATTACK;
				setPlayerCondition();
				break;

			}
		
		}
		
	}
	/////////// 사다리 렉트와 충돌 시 ////////////////////
	if (_playerSubCondition == PLAYER_LADDER)
	{
		if (KEYMANAGER->isOnceKeyDown(VK_UP))
		{
			_isLadder = true;
			_playerMainCondition = PLAYER_UP_CLIMB;
			setPlayerCondition();
		}
		if (KEYMANAGER->isOnceKeyUp(VK_UP))
		{
			_ani->stop();
		}

		if (KEYMANAGER->isOnceKeyDown(VK_DOWN))
		{
			_isLadder = true;
			_playerMainCondition = PLAYER_DOWN_CLIMB;
			setPlayerCondition();
		}
		if (KEYMANAGER->isOnceKeyUp(VK_DOWN))
		{
			_ani->stop();
		}
	}
	/////////////////////  점프 상태에서 동작 ///////////////////////
	if (_isJump && _playerMainCondition != 14 && _playerMainCondition != 15 && _playerMainCondition != 16)
	{
		if (KEYMANAGER->isOnceKeyDown(VK_RIGHT))
		{
			_playerMainCondition = PLAYER_RIGHT_JUMP;
			_dir = 1;
			setPlayerCondition();
		}
		if (KEYMANAGER->isOnceKeyUp(VK_RIGHT))
		{
			_playerMainCondition = PLAYER_IDLE_JUMP;
			setPlayerCondition();
		}
		if (KEYMANAGER->isOnceKeyDown(VK_LEFT))
		{
			_playerMainCondition = PLAYER_LEFT_JUMP;
			_dir = -1;
			setPlayerCondition();
		}
		if (KEYMANAGER->isOnceKeyUp(VK_LEFT))
		{
			_playerMainCondition = PLAYER_IDLE_JUMP;
			setPlayerCondition();
		}
		if (KEYMANAGER->isOnceKeyDown(VK_DOWN))
		{
			_playerMainCondition = PLAYER_DOWN_ATTACK;
			setPlayerCondition();
		}
	}
	else if (_playerMainCondition == PLAYER_DOWN_ATTACK
		|| _playerMainCondition == PLAYER_RIGHT_DOWN_ATTACK
		|| _playerMainCondition == PLAYER_LEFT_DOWN_ATTACK)
	{
		if (KEYMANAGER->isOnceKeyDown(VK_RIGHT))
		{
			_dir = 1;
			_playerMainCondition = PLAYER_RIGHT_DOWN_ATTACK;
			setPlayerCondition();
		}
		if (KEYMANAGER->isOnceKeyUp(VK_RIGHT))
		{
			_playerMainCondition = PLAYER_DOWN_ATTACK;
			setPlayerCondition();
		}
		if (KEYMANAGER->isOnceKeyDown(VK_LEFT))
		{
			_dir = -1;
			_playerMainCondition = PLAYER_LEFT_DOWN_ATTACK;
			setPlayerCondition();
		}
		if (KEYMANAGER->isOnceKeyUp(VK_LEFT))
		{
			_playerMainCondition = PLAYER_DOWN_ATTACK;
			setPlayerCondition();
		}

	}

	///////////////////////////// 플레이어 상태에 따른 이동 조작  /////////////////////////////////////

	switch (_playerMainCondition)
	{
	case PLAYER_RIGHT_IDLE:
	
		break;
	case PLAYER_LEFT_IDLE:
	
		break;
	case PLAYER_IDLE_JUMP:
		break;
	case PLAYER_RIGHT_JUMP:
		_x += _speed;
		break;
	case PLAYER_LEFT_JUMP:
		_x -= _speed;
		break;
	case PLAYER_RIGHT_MOVE:
		_x += _speed;
		break;
	case PLAYER_LEFT_MOVE:
		_x -= _speed;
		break;
	case PLAYER_UP_CLIMB:
		if (KEYMANAGER->isStayKeyDown(VK_UP))_y -= _speed;
		break;
	case PLAYER_DOWN_CLIMB:
		if (KEYMANAGER->isStayKeyDown(VK_DOWN))_y += _speed;
		break;
	case PLAYER_EDGE_CLIMB:
		break;
	case PLAYER_RIGHT_ATTACK:
		if(_canAtk)	_attackRC = RectMakeCenter(_x + 100, _y + 30, 75, 100);
		break;
	case PLAYER_RIGHT_JUMP_ATTACK:
		break;
	case PLAYER_LEFT_ATTACK:
		if (_canAtk)	_attackRC = RectMakeCenter(_x - 100, _y + 30, 75, 100);
		break;
	case PLAYER_LEFT_JUMP_ATTACK:
		break;
	case PLAYER_DOWN_ATTACK:
		if (_canAtk)	_attackRC = RectMakeCenter(_x, _y + 50, 100, 100);
		break;
	case PLAYER_RIGHT_DOWN_ATTACK:
		if (_canAtk)	_attackRC = RectMakeCenter(_x, _y + 50, 100, 100);
		break;
	case PLAYER_LEFT_DOWN_ATTACK:
		if (_canAtk)	_attackRC = RectMakeCenter(_x, _y + 50, 100, 100);
		break;
	case PLAYER_RIGHT_HITTED:
		break;
	case PLAYER_LEFT_HITTED:
		break;
	case PLAYER_DEAD:
		break;
	
	}



	//if (_isJump && !_isLand && !_isLadder)
	//{
	//	_y -= _jumpPower;
	//	_jumpPower -= _gravity;
	//}

	//if (_isLand || _isLadder)
	//{
	//	_isJump = false;
	//}
	//

	////////////////////////////// 피격 상태가  아닐때에만 동작하는 플레이어 기본조작 //////////////////////////////////////////

	//if (_playerMainCondition != PLAYER_RIGHT_HITTED && _playerMainCondition != PLAYER_LEFT_HITTED)
	//{
	//	if (KEYMANAGER->isOnceKeyDown(VK_RIGHT))						  // 우측 방향키 입력 시 
	//	{
	//		if (_isJump)												  // 점프 중일 때
	//		{
	//			if (_playerMainCondition == PLAYER_DOWN_ATTACK)			  // 아래 공격일 경우
	//			{
	//				_playerMainCondition = PLAYER_RIGHT_DOWN_ATTACK;	  // 오른쪽 아래 공격 상태로 
	//			}
	//			else if (_playerMainCondition != PLAYER_DOWN_ATTACK)	  // 아래공격이 아닐 경우엔 오른쪽 점프 상태로 
	//			{
	//				_playerMainCondition = PLAYER_RIGHT_JUMP;
	//			}
	//			
	//			
	//		}
	//		if (_isLand && !_isLadder )												  // 바닥 착지상태
	//		{	
	//			_playerMainCondition = PLAYER_RIGHT_MOVE;			      // 플레이어 상태를 오른쪽 이동으로 변경 
	//			_image = IMAGEMANAGER->findImage("playerWalk");		
	//			_ani = KEYANIMANAGER->findAnimation("playerRightMove");
	//			_ani->start();
	//		}
	//		_dir = 1;													// 방향 판별용 변수값을 1로 변경

	//	}
	//	if (KEYMANAGER->isOnceKeyUp(VK_RIGHT) && _dir == 1)		// 방향 판별 변수가 1인 상태에서 키를 떼었을 경우
	//	{
	//		if (_isJump)												// 점프 상태인지 확인 하고 
	//		{
	//			if (_playerMainCondition == PLAYER_RIGHT_DOWN_ATTACK) _playerMainCondition = PLAYER_DOWN_ATTACK;			// 아래 공격 상태가 아닐경우 
	//			else _playerMainCondition = PLAYER_IDLE_JUMP;															// 기본 점프상태로 변경
	//		}
	//		else if (_isLand && !_isLadder)  
	//		{																											// 점프 상태가 아니고  사다리에 올라탄 상태가 아닐경우 
	//			_playerMainCondition = PLAYER_RIGHT_IDLE;
	//			_image = IMAGEMANAGER->findImage("playerIdle");
	//			_ani = KEYANIMANAGER->findAnimation("playerRightIdle");
	//			_ani->start();
	//		}
	//	}

	//	if (KEYMANAGER->isOnceKeyDown(VK_LEFT))
	//	{
	//		if (_isJump)
	//		{
	//			if (_playerMainCondition == PLAYER_DOWN_ATTACK)
	//			{
	//				_playerMainCondition = PLAYER_LEFT_DOWN_ATTACK;
	//			}
	//			else if (_playerMainCondition != PLAYER_DOWN_ATTACK)
	//			{
	//				_playerMainCondition = PLAYER_LEFT_JUMP;
	//			}
	//		}
	//		else if (_isLand && !_isLadder)
	//		{
	//			_playerMainCondition = PLAYER_LEFT_MOVE;
	//			_image = IMAGEMANAGER->findImage("playerWalk");
	//			_ani = KEYANIMANAGER->findAnimation("playerLeftMove");
	//			_ani->start();
	//		}
	//		_dir = -1;

	//	}
	//	else if (KEYMANAGER->isOnceKeyUp(VK_LEFT) && _dir == -1)
	//	{
	//		if (_isJump)
	//		{
	//			if (_playerMainCondition == PLAYER_LEFT_DOWN_ATTACK) _playerMainCondition = PLAYER_DOWN_ATTACK;
	//			else _playerMainCondition = PLAYER_IDLE_JUMP;
	//		}
	//		else if (_isLand && !_isLadder)
	//		{
	//			_ani->stop();
	//			_playerMainCondition = PLAYER_LEFT_IDLE;
	//			_image = IMAGEMANAGER->findImage("playerIdle");
	//			_ani = KEYANIMANAGER->findAnimation("playerLeftIdle");
	//			_ani->start();
	//		}

	//	}

	//	if (KEYMANAGER->isOnceKeyDown(VK_DOWN))
	//	{
	//		if (_isJump)
	//		{
	//			_playerMainCondition = PLAYER_DOWN_ATTACK;
	//			_image = IMAGEMANAGER->findImage("playerDownAtk");

	//			switch (_dir)
	//			{
	//			case 1:
	//				_ani = KEYANIMANAGER->findAnimation("playerRightDownAttack");

	//				break;

	//			case -1:
	//				_ani = KEYANIMANAGER->findAnimation("playerLeftDownAttack");

	//				break;
	//			}
	//			_ani->start();
	//		}
	//	

	//	}

	//	///////////////////////  플레이어가 사다리에 겹쳤을때 조작/////////////////////////////////////
	//	if (_playerSubCondition == PLAYER_LADDER)		
	//	{
	//		if (KEYMANAGER->isOnceKeyDown(VK_UP))
	//		{
	//			_playerMainCondition = PLAYER_UP_CLIMB;
	//			_isJump = false;
	//			_isLand = true;
	//			_image = IMAGEMANAGER->findImage("playerClimb");
	//			_ani = KEYANIMANAGER->findAnimation("playerClimb");
	//			_ani->start();
	//		}
	//		if (KEYMANAGER->isOnceKeyUp(VK_UP))
	//		{
	//			_ani->stop();
	//		}
	//		
	//		if (KEYMANAGER->isOnceKeyDown(VK_DOWN))
	//		{
	//			_playerMainCondition = PLAYER_DOWN_CLIMB;
	//			_isJump = false;
	//			_isLand = true;
	//			_image = IMAGEMANAGER->findImage("playerClimb");
	//			_ani = KEYANIMANAGER->findAnimation("playerClimb");
	//			_ani->start();
	//		}
	//		if (KEYMANAGER->isOnceKeyUp(VK_DOWN))
	//		{
	//			_ani->stop();
	//		}
	//	}
	//

	//	////////////////////////////////// 플레이어 점프 상태 관련////////////////////////////////////////
	//	if (KEYMANAGER->isOnceKeyDown(VK_SPACE) && _isJump == false && _isLand == true)
	//	{

	//	}

	//	{	//// 우측 보는 상태로 점프 키
	//		if (_playerMainCondition == PLAYER_RIGHT_IDLE)
	//		{
	//			_ani->stop();
	//			_playerMainCondition = PLAYER_IDLE_JUMP;
	//			_image = IMAGEMANAGER->findImage("playerJump");
	//			_ani = KEYANIMANAGER->findAnimation("playerRightJumpUp");
	//			_ani->start();
	//		}
	//		//// 우측으로 달리면서 점프
	//		if (_playerMainCondition == PLAYER_RIGHT_MOVE)
	//		{
	//			_ani->stop();
	//			_playerMainCondition = PLAYER_RIGHT_JUMP;
	//			_image = IMAGEMANAGER->findImage("playerJump");
	//			_ani = KEYANIMANAGER->findAnimation("playerRightJumpUp");
	//			_ani->start();
	//		}
	//		//// 좌측 보는 상태로 점프키
	//		if (_playerMainCondition == PLAYER_LEFT_IDLE)
	//		{
	//			_ani->stop();
	//			_playerMainCondition = PLAYER_IDLE_JUMP;
	//			_image = IMAGEMANAGER->findImage("playerJump");
	//			_ani = KEYANIMANAGER->findAnimation("playerLeftJumpUp");
	//			_ani->start();
	//		}
	//		//// 좌측으로 달리면서 점프
	//		if (_playerMainCondition == PLAYER_LEFT_MOVE)
	//		{
	//			//_ani->stop();
	//			_playerMainCondition = PLAYER_LEFT_JUMP;
	//			_image = IMAGEMANAGER->findImage("playerJump");
	//			_ani = KEYANIMANAGER->findAnimation("playerLeftJumpUp");
	//			_ani->start();
	//		}
	//		_isJump = true;
	//	}

	//	if (KEYMANAGER->isOnceKeyDown('A'))
	//	{
	//		switch (_dir)
	//		{
	//		case 1:
	//			//_ani->stop();
	//			_playerMainCondition = PLAYER_RIGHT_ATTACK;
	//			_image = IMAGEMANAGER->findImage("playerAtk");
	//			_ani = KEYANIMANAGER->findAnimation("playerRightAttack");
	//			_ani->start();
	//			break;

	//		case -1:
	//			//_ani->stop();
	//			_playerMainCondition = PLAYER_LEFT_ATTACK;
	//			_image = IMAGEMANAGER->findImage("playerAtk");
	//			_ani = KEYANIMANAGER->findAnimation("playerLeftAttack");
	//			_ani->start();
	//			break;
	//		}

	//	}
	//}
	//	

	//if (_isJump && !_isLand)
	//{
	//	switch (_dir)
	//	{
	//	case 1 :
	//		if (_playerMainCondition == PLAYER_RIGHT_DOWN_ATTACK) _ani = KEYANIMANAGER->findAnimation("playerRightDownAttack");
	//		else if (_playerMainCondition == PLAYER_DOWN_ATTACK) _ani = KEYANIMANAGER->findAnimation("playerRightDownAttack");
 //			else if (_jumpPower >= 0) _ani = KEYANIMANAGER->findAnimation("playerRightJumpUp");
	//		else if (_jumpPower < 0) _ani = KEYANIMANAGER->findAnimation("playerRightJumpDown");
	//		break;

	//	case -1:
	//		if (_playerMainCondition == PLAYER_LEFT_DOWN_ATTACK) _ani = KEYANIMANAGER->findAnimation("playerLeftDownAttack");
	//		else if (_playerMainCondition == PLAYER_DOWN_ATTACK) _ani = KEYANIMANAGER->findAnimation("playerLeftDownAttack");
	//		else if (_jumpPower >= 0) _ani = KEYANIMANAGER->findAnimation("playerLeftJumpUp");
	//		else if (_jumpPower < 0) _ani = KEYANIMANAGER->findAnimation("playerLeftJumpDown");
	//		break;
	//	}
	//}
	//
	//switch (_playerMainCondition)
	//{
	//case PLAYER_RIGHT_IDLE:
	//	_image = IMAGEMANAGER->findImage("playerIdle");
	//	_ani = KEYANIMANAGER->findAnimation("playerRightIdle");
	//	break;
	//case PLAYER_LEFT_IDLE:
	//	_image = IMAGEMANAGER->findImage("playerIdle");
	//	_ani = KEYANIMANAGER->findAnimation("playerLeftIdle");
	//	break;
	//case PLAYER_IDLE_JUMP:
	//	break;
	//case PLAYER_RIGHT_JUMP:
	//	_x += _speed;
	//	break;
	//case PLAYER_LEFT_JUMP:
	//	_x -= _speed;
	//	break;
	//case PLAYER_RIGHT_MOVE:
	//	_x += _speed;
	//	break;
	//case PLAYER_LEFT_MOVE:
	//	_x -= _speed;
	//	break;
	//case PLAYER_UP_CLIMB:
	//	if (KEYMANAGER->isStayKeyDown(VK_UP)) _y -= _speed;		
	//	break;
	//case PLAYER_DOWN_CLIMB:	
	//	if (KEYMANAGER->isStayKeyDown(VK_DOWN))_y += _speed;
	//	break;
	////case PLAYER_EDGE_CLIMB:
	////	if (KEYMANAGER->isStayKeyDown(VK_UP))
	////	{
	////		_y -= _speed;
	////		_playerMainCondition = PLAYER_RIGHT_CLIMB;
	////	}
	////	if (KEYMANAGER->isStayKeyDown(VK_DOWN))
	////	{
	////		_y += _speed;
	////		_playerMainCondition = PLAYER_RIGHT_CLIMB;
	////	}
	////	break;
	//case PLAYER_RIGHT_ATTACK:
	//	_attackRC = RectMakeCenter(_x + 100, _y + 30, 75, 100);
	//	
	//	break;
	//case PLAYER_RIGHT_JUMP_ATTACK:
	//	_attackRC = RectMakeCenter(_x + 100, _y + 30, 75, 100);
	//	
	//	break;
	//case PLAYER_LEFT_ATTACK:
	//	_attackRC = RectMakeCenter(_x - 100, _y + 30, 75, 100);
	//
	//	break;
	//case PLAYER_LEFT_JUMP_ATTACK:
	//	_attackRC = RectMakeCenter(_x - 100, _y + 30, 75, 100);
	//
	//	break;
	//case PLAYER_DOWN_ATTACK:
	//	_attackRC = RectMakeCenter(_x, _y + 50, 100, 100);
	//	break;
	//case PLAYER_RIGHT_DOWN_ATTACK:
	//	_x += _speed;
	//	_attackRC = RectMakeCenter(_x, _y + 50, 100, 100);
	//	break;
	//case PLAYER_LEFT_DOWN_ATTACK:
	//	_x -= _speed;
	//	_attackRC = RectMakeCenter(_x, _y + 50, 100, 100);
	//	break;
	//case PLAYER_RIGHT_HITTED:
	//	_image = IMAGEMANAGER->findImage("playerHitted");
	//	_ani = KEYANIMANAGER->findAnimation("playerRightHitted");
	//	_x -= _repulsivePower;
	//	_repulsivePower -= _frictionalPower;
	//	if (_repulsivePower <= 0) _playerMainCondition = PLAYER_RIGHT_IDLE;
	//	break;
	//case PLAYER_LEFT_HITTED:
	//	_image = IMAGEMANAGER->findImage("playerHitted");
	//	_ani = KEYANIMANAGER->findAnimation("playerLeftHitted");
	//	_x += _repulsivePower;
	//	_repulsivePower -= _frictionalPower;
	//	if (_repulsivePower <= 0) _playerMainCondition = PLAYER_LEFT_IDLE;
	//	break;
	//case PLAYER_DEAD:
	//	break;
	//}
	RECT temp1;
	if (IntersectRect(&temp1, &_playerRC, &LadderRC))
	{
		_playerSubCondition = PLAYER_LADDER;
	}
	else _playerSubCondition = PLAYER_NOTHING;

	RECT temp2;
	if (IntersectRect(&temp2, &_attackRC, &enemyRC))
	{
		collisonAttack(&enemyRC);
	}

	RECT temp3;
	if (IntersectRect(&temp3, &_playerRC, &enemyRC))
	{
		collisonHitted(&enemyRC);
	}


	 if (_playerMainCondition < 10 || _playerMainCondition >= 17)
	{
		_attackRC = RectMakeCenter(-150, 150, 100, 150);
	}

	_playerRC = RectMakeCenter(_x, _y, 150, 160);
	_imageRC = RectMakeCenter(_x, _y, 250, 250);
	
	
	
	KEYANIMANAGER->update();
	//pixelCollison();
	//usage();
	//_Relic->update();
	DATABASE->setPlayer_currentInfo(_currentHP, _maxHP, _currentMP, _playerGold);
	//usage();
}


void player::render()
{
	Rectangle(getMemDC(), CAMERAMANAGER->CameraRelativePointX(LadderRC.left), CAMERAMANAGER->CameraRelativePointY(LadderRC.top), CAMERAMANAGER->CameraRelativePointX(LadderRC.right), CAMERAMANAGER->CameraRelativePointY(LadderRC.bottom));
	Rectangle(getMemDC(), CAMERAMANAGER->CameraRelativePointX(enemyRC.left), CAMERAMANAGER->CameraRelativePointY(enemyRC.top), CAMERAMANAGER->CameraRelativePointX(enemyRC.right), CAMERAMANAGER->CameraRelativePointY(enemyRC.bottom));

	_image->aniRender(getMemDC(), CAMERAMANAGER->CameraRelativePointX( _imageRC.left), CAMERAMANAGER->CameraRelativePointY( _imageRC.top), _ani);

	char str[128];
	sprintf(str, "케릭터 메인상태값 : %d", _playerMainCondition);
	TextOut(getMemDC(), 100, 100, str, strlen(str));

	char str1[128];
	sprintf(str1, "케릭터 서브상태값 : %d", _playerSubCondition);
	TextOut(getMemDC(), 100, 200, str1, strlen(str1));

	
	//_Relic->render();
	if (KEYMANAGER->isToggleKey(VK_F1))
	{
		RectangleMake(getMemDC(), CAMERAMANAGER->CameraRelativePointX(_imageRC.left), CAMERAMANAGER->CameraRelativePointY(_imageRC.top),250,250);
		RectangleMake(getMemDC(), CAMERAMANAGER->CameraRelativePointX( _playerRC.left), CAMERAMANAGER->CameraRelativePointY(_playerRC.top), 150, 160);
		RectangleMake(getMemDC(), CAMERAMANAGER->CameraRelativePointX( _attackRC.left), CAMERAMANAGER->CameraRelativePointY(_attackRC.top),75, 100);
		sprintf(str, "attackRC LT %d %d RB %d %d", _attackRC.left, _attackRC.top, _attackRC.right, _attackRC.bottom);
		TextOut(getMemDC(), WINSIZEX / 2, WINSIZEY / 2, str, strlen(str));
	}

	char str2[128];
	sprintf(str2, " 중력 값 : %0.2f", _gravity);
	TextOut(getMemDC(), CAMERAMANAGER->CameraRelativePointX(_playerRC.left), CAMERAMANAGER->CameraRelativePointY(_playerRC.top)+ 100, str2, strlen(str2));

	char str3[128];
	sprintf(str3, "케릭터 _isJump: %d" ,_isJump);
	TextOut(getMemDC(), CAMERAMANAGER->CameraRelativePointX(_playerRC.left), CAMERAMANAGER->CameraRelativePointY(_playerRC.top)+120, str3, strlen(str3));
	
	char str4[128];
	sprintf(str4, "케릭터 점프파워: %0.2f", _jumpPower);
	TextOut(getMemDC(), CAMERAMANAGER->CameraRelativePointX(_playerRC.left), CAMERAMANAGER->CameraRelativePointY(_playerRC.top) + 140, str4, strlen(str4));

	char str5[128];
	sprintf(str5, "케릭터 _isLand: %d", _isLand);
	TextOut(getMemDC(), CAMERAMANAGER->CameraRelativePointX(_playerRC.left), CAMERAMANAGER->CameraRelativePointY(_playerRC.top) + 160, str5, strlen(str5));
}

void player::collisonAttack(RECT * obj)
{
	_canAtk = false;
	_repulsivePower = 3.0f;
	_frictionalPower = 0.3f;
	_jumpPower = 11.0f;
	_gravity = 0.35f;
	

	if (_playerMainCondition >= 10 && _playerMainCondition <= 13)
	{
		switch (_dir)
		{
		case 1:
			_x -= _repulsivePower;
			_repulsivePower -= _frictionalPower;
			break;

		case -1:
			_x += _repulsivePower;
			_repulsivePower -= _frictionalPower;
			break;
		}
	}

	else if (_playerMainCondition >= 14 && _playerMainCondition <= 16)
	{
	
		_y -= _jumpPower;
		_jumpPower -= _gravity;
	}

	_canAtk = true;
}

void player::collisonHitted(RECT * obj)
{
	_repulsivePower = 9.0f;
	_frictionalPower = 0.4f;

	switch (_dir)
	{
	case 1:
		_playerMainCondition = PLAYER_RIGHT_HITTED;
		break;

	case -1:
		_playerMainCondition = PLAYER_LEFT_HITTED;
		break;
	}
}

void player::collisonObject(int objType, int objValue)
{
	switch ( objType)
	{
	case 0:   // 사다리
		_playerSubCondition = PLAYER_LADDER;
		break;
	case 1:   // 보석
		_playerGold += objValue;

		break;

	case 2: // 스테이지에서 피채워주는 음식
		_currentHP += objValue;
		if (_currentHP > _maxHP) _currentHP = _maxHP;
		break;

	case 7:  // 물약
		_currentMP += objValue;
		if (_currentMP > _maxMP) _currentMP = _maxMP;
		break;

	}
}


void player::rightAttack(void* obj)
{
	player* p = (player*)obj;

	if (!p->getIsJump())
	{
		p->setPlayerMainCondition(PLAYER_RIGHT_IDLE);
		p->setPlayerImage(IMAGEMANAGER->findImage("playerIdle"));
		p->setPlayerAni(KEYANIMANAGER->findAnimation("playerRightIdle"));
		p->getPlayerAni()->start();
	}
	else
	{
		p->setPlayerMainCondition(PLAYER_IDLE_JUMP);
		p->setPlayerImage(IMAGEMANAGER->findImage("playerJump"));
		p->setPlayerAni(KEYANIMANAGER->findAnimation("playerRightJumpDown"));
		p->getPlayerAni()->start();
	}
}

void player::leftAttack(void * obj)
{
	player* p = (player*)obj;

	if (!p->getIsJump())
	{
		p->setPlayerMainCondition(PLAYER_LEFT_IDLE);
		p->setPlayerImage(IMAGEMANAGER->findImage("playerIdle"));
		p->setPlayerAni(KEYANIMANAGER->findAnimation("playerLeftIdle"));
		p->getPlayerAni()->start();
	}
	
	else 
	{
		p->setPlayerMainCondition(PLAYER_IDLE_JUMP);
		p->setPlayerImage(IMAGEMANAGER->findImage("playerJump"));
		p->setPlayerAni(KEYANIMANAGER->findAnimation("playerLeftJumpDown"));
		p->getPlayerAni()->start();
	}
}

void player::rightJumpAttack(void * obj)
{
}

void player::leftJumpAttack(void * obj)
{
}

void player::setPlayerCondition()
{
	switch (_playerMainCondition)
	{
	case PLAYER_RIGHT_IDLE:
		_image = IMAGEMANAGER->findImage("playerIdle");
		_ani = KEYANIMANAGER->findAnimation("playerRightIdle");
		_ani->start();
		break;
	case PLAYER_LEFT_IDLE:
		_image = IMAGEMANAGER->findImage("playerIdle");
		_ani = KEYANIMANAGER->findAnimation("playerLeftIdle");
		_ani->start();
		break;
	case PLAYER_IDLE_JUMP:
		_isLand = false;
		_isJump = true;
		_image = IMAGEMANAGER->findImage("playerJump");
		if (_dir == 1)	_ani = KEYANIMANAGER->findAnimation("playerRightJumpUp");
		else if (_dir == -1) _ani = KEYANIMANAGER->findAnimation("playerLeftJumpUp");
		_ani->start();
		break;
	case PLAYER_RIGHT_JUMP:
		_isLand = false;
		_isJump = true;
		_image = IMAGEMANAGER->findImage("playerJump");
		_ani = KEYANIMANAGER->findAnimation("playerRightJumpUp");
		_ani->start();
		break;
	case PLAYER_LEFT_JUMP:
		_isLand = false;
		_isJump = true;
		_image = IMAGEMANAGER->findImage("playerJump");
		_ani = KEYANIMANAGER->findAnimation("playerLeftJumpUp");
		_ani->start();
		break;
	case PLAYER_RIGHT_MOVE:
		_image = IMAGEMANAGER->findImage("playerWalk");
		_ani = KEYANIMANAGER->findAnimation("playerRightMove");
		_ani->start();
		break;
	case PLAYER_LEFT_MOVE:
		_image = IMAGEMANAGER->findImage("playerWalk");
		_ani = KEYANIMANAGER->findAnimation("playerLeftMove");
		_ani->start();
		break;
	case PLAYER_UP_CLIMB:
		_image = IMAGEMANAGER->findImage("playerClimb");
		_ani = KEYANIMANAGER->findAnimation("playerClimb");
		_ani->start();
		break;
	case PLAYER_DOWN_CLIMB:
		_image = IMAGEMANAGER->findImage("playerClimb");
		_ani = KEYANIMANAGER->findAnimation("playerClimb");
		_ani->start();
		break;
	case PLAYER_EDGE_CLIMB:
		_image = IMAGEMANAGER->findImage("playerClimb");
		_ani = KEYANIMANAGER->findAnimation("playerEdgeClimb");
		_ani->start();
		break;
	case PLAYER_RIGHT_ATTACK:
		_image = IMAGEMANAGER->findImage("playerAtk");
		_ani = KEYANIMANAGER->findAnimation("playerRightAttack");
		_ani->start();
		break;
	case PLAYER_RIGHT_JUMP_ATTACK:
		break;
	case PLAYER_LEFT_ATTACK:
		_image = IMAGEMANAGER->findImage("playerAtk");
		_ani = KEYANIMANAGER->findAnimation("playerLeftAttack");
		_ani->start();
		break;
	case PLAYER_LEFT_JUMP_ATTACK:
		break;
	case PLAYER_DOWN_ATTACK:
		_image = IMAGEMANAGER->findImage("playerDownAtk");
		if (_dir == 1) _ani = KEYANIMANAGER->findAnimation("playerRightAttack");
		else if (_dir == -1) _ani = KEYANIMANAGER->findAnimation("playerLeftAttack");
		_ani->start();
		break;
	case PLAYER_RIGHT_DOWN_ATTACK:
		_image = IMAGEMANAGER->findImage("playerDownAtk");
		_ani = KEYANIMANAGER->findAnimation("playerRightAttack");
		_ani->start();
		break;
	case PLAYER_LEFT_DOWN_ATTACK:
		_image = IMAGEMANAGER->findImage("playerDownAtk");
		_ani = KEYANIMANAGER->findAnimation("playerLeftAttack");
		_ani->start();
		break;
	case PLAYER_RIGHT_HITTED:
		break;
	case PLAYER_LEFT_HITTED:
		break;
	case PLAYER_DEAD:
		break;
	
	}
	
}
void player::getColMessage(LPCOLLISION_INFO message)
{
	if (message != NULL)
	{
		objects* temp;
		RECT _tempRC;
		switch (message->_colType)
		{
		case COL_MONSTER:
			switch (message->index_detail)
			{
			case 1:
				//static_cast<objects*>(message->object).
				break;
			case 2:
				break;
			case 3:
				break;
			}
			break;
		case COL_OBJECT:
			switch (message->index_detail)
			{
			case 11: // gem
				break;
			case 12: // 흙
			{


				static_cast<objects*>(message->object);
				temp = static_cast<objects*>(message->object);

				if (isCollisionReaction(temp->getRc(), _playerRC))
				{

				}
				//if (IntersectRect(&_tempRC, &temp->getRc(), &_playerRC))
				//{
				//	setPlayerCondition();
				//	float _width = _tempRC.right - _tempRC.left;
				//	float _height = _tempRC.bottom - _tempRC.top;
				//	if (_width > _height)
				//	{
				//
				//	}
				//
				//	if (_height > _width)
				//	{
				//		//if (_playerRC.bottom < temp->getRc().bottom)
				//		//{
				//			_isLand = true;
				//			_isJump = false;
				//		//}
				//	}
				//}		
			}
			break;
			case 13: //포션
				break;
			case 14: //음식
				break;
			case 15: // MEAL (체력최대치올리는음식)
				break;
			case 16: //방울
				break;
			case 17: //음악

				break;
			case 18: //발판
			{
				//static_cast<objects*>(message->object);
				//temp = static_cast<objects*>(message->object);
				//
				//if (isCollisionReaction(temp->getRc(), _playerRC))
				//{
				//
				//}
				////if (IntersectRect(&_tempRC, &_playerRC,&temp->getRc()))
				////{
				//if (IntersectRect(&_tempRC,&temp->getRc(), &_playerRC))
				//{
				//	//setPlayerCondition();
				//	float _width = _tempRC.right - _tempRC.left;
				//	float _height = _tempRC.bottom - _tempRC.top;
				//
				//	//if (_playerRC.bottom > temp->getRc().bottom)
				//	//{
				//	//	_isLand = true;
				//	//	_isJump = false;
				//	//}
				//
				//	if (_width > _height)
				//	{
				//		
				//	}
				//
				//	if (_height > _width)
				//	{
				//		_isLand = true;
				//		_isJump = false;
				//	}
				//}
				//}
				//(isCollisionReaction(temp->getRc(), _playerRC))
				//{
				//
				//}
			}
			break;
			case 19: //접시
				break;
			case 20: //가짜 벽
				break;
			}break;
			case COL_NPC:
				switch (message->index_detail)
				{
				case 1:
					break;
				case 2:
					break;
				case 3:
					break;
				}
				break;
			}
		}
		SAFE_DELETE(message);
	}

