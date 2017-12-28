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

	int rightIdle[] = { 0 };
	KEYANIMANAGER->addArrayFrameAnimation("playerRightIdle", "playerIdle", rightIdle, 1, 6, true);
	int leftIdle[] = { 1 };
	KEYANIMANAGER->addArrayFrameAnimation("playerLeftIdle", "playerIdle", leftIdle, 1, 6, true);
	int rightMove[] = { 0,1,2,3,4,5 };
	KEYANIMANAGER->addArrayFrameAnimation("playerRightMove", "playerWalk", rightMove, 6, 6, true);
	int leftMove[] = { 6,7,8,9,10,11 };
	KEYANIMANAGER->addArrayFrameAnimation("playerLeftMove", "playerWalk", leftMove, 6, 6, true);
	//int jumpIdle[] = 
	int rightAttack[] = { 0,1,2,3 };
	KEYANIMANAGER->addArrayFrameAnimation("playerRightAttack", "playerAttack", rightAttack, 4, 6, true);
	int leftAttack[] = { 4,5,6,7 };
	KEYANIMANAGER->addArrayFrameAnimation("playerLeftAttack", "playerAttack", leftAttack, 4, 6, true);
	int leftDownAttack[] = { 0 };
	KEYANIMANAGER->addArrayFrameAnimation("playerLeftDownAttack", "playerDownAttack", leftDownAttack, 1, 6, true);
	int rightDownAttack[] = { 1 };
	KEYANIMANAGER->addArrayFrameAnimation("playerRightDownAttack", "playerDownAttack", rightDownAttack, 1, 6, true);
	int rightHitted[] = { 0 };
	KEYANIMANAGER->addArrayFrameAnimation("playerRightHitted", "playerHitted", rightHitted, 1, 6, true);
	int leftHitted[] = { 1 };
	KEYANIMANAGER->addArrayFrameAnimation("playerLeftHitted", "playerHitted", leftHitted, 1, 6, true);
	int leftClimb[] = { 0 };
	KEYANIMANAGER->addArrayFrameAnimation("playerLeftClimb", "playerClimb", leftClimb, 1, 6, true);
	int rightClimb[] = { 1 };
	KEYANIMANAGER->addArrayFrameAnimation("playerRightClimb", "playerClimb", rightClimb, 1, 6, true);
	int edgeClimb[] = { 2 };
	KEYANIMANAGER->addArrayFrameAnimation("playerEdgeClimb", "playerClimb", rightClimb, 1, 6, true);
	//_ani = KEYANIMANAGER->findAnimation()

	_ani = KEYANIMANAGER->findAnimation("playerRightIdle");
	return S_OK;
}
void player::release()
{
}
void player::update()
{

}
void player::render()
{
}
