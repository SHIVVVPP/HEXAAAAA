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
	int leftIdle[] = { 1 };
	int rightMove[] = { 0,1,2,3,4,5 };
	int leftMove[] = { 6,7,8,9,10 };
	//int jumpIdle[] = 
	int rightAttack[] = { 0,1,2,3 };
	int leftAttack[] = { 4,5,6,7 };
	int leftDownAttack[] = { 0 };
	int rightDownAttack[] = { 1 };
	int rightHitted[] = { 0 };
	int leftHitted[] = { 1 };
	int leftClimb[] = { 0 };
	int rightClimb[] = { 1 };
	int edgeClimb[] = { 2 };

	//_ani = KEYANIMANAGER->findAnimation()

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
