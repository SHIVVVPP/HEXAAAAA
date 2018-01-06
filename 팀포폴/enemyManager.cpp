#include "stdafx.h"
#include "enemyManager.h"




enemyManager::enemyManager()
{
}
enemyManager::~enemyManager()
{
}



HRESULT enemyManager::init()
{
	

	generalFrameCounter = 0;

	return S_OK;
}

void enemyManager::release()
{
}

void enemyManager::update()
{
	for (_viRedBeetle = _vRedBeetle.begin(); _viRedBeetle != _vRedBeetle.end(); ++_viRedBeetle)
	{
		(*_viRedBeetle)->update();
		(*_viRedBeetle)->frameMove();
		(*_viRedBeetle)->generalMove();
	

	}

	for (_viSkeleton = _vSkeleton.begin(); _viSkeleton != _vSkeleton.end(); ++_viSkeleton)
	{
		(*_viSkeleton)->update();
		(*_viSkeleton)->frameMove();
		(*_viSkeleton)->generalMove();
		
	}

	for (_viGreenDragon = _vGreenDragon.begin(); _viGreenDragon != _vGreenDragon.end(); ++_viGreenDragon)
	{
		(*_viGreenDragon)->update();
		(*_viGreenDragon)->frameMove();
		(*_viGreenDragon)->generalMove();
		
	}

	for (_viYellowDragon = _vYellowDragon.begin(); _viYellowDragon != _vYellowDragon.end(); ++_viYellowDragon)
	{
		(*_viYellowDragon)->update();
		(*_viYellowDragon)->frameMove();
	}

	for (_viBlueSlime = _vBlueSlime.begin(); _viBlueSlime != _vBlueSlime.end(); ++_viBlueSlime)
	{
		(*_viBlueSlime)->update();
		(*_viBlueSlime)->frameMove();
		(*_viBlueSlime)->generalMove();
		//(*_viBlueSlime)->slimeAni();
	}

	for (_viBoss = _vBoss.begin(); _viBoss != _vBoss.end(); ++_viBoss)
	{
		(*_viBoss)->update();
		(*_viBoss)->frameMove();
	}

	for (_viBubble = _vBubble.begin(); _viBubble != _vBubble.end(); ++_viBubble)
	{
		(*_viBubble)->update();
		(*_viBubble)->frameMove();
		(*_viBubble)->move();
	}
	//////////////////////////////////////////////////////////
	if (KEYMANAGER->isOnceKeyDown('Q'))setRedBeetle();
	if (KEYMANAGER->isOnceKeyDown('W'))setSkeleton();
	if (KEYMANAGER->isOnceKeyDown('E'))setBlueSlime();
	if (KEYMANAGER->isOnceKeyDown('R'))setGreenDragon();
	if (KEYMANAGER->isOnceKeyDown('T'))setYellowDragon();
	if (KEYMANAGER->isOnceKeyDown('Y'))setBoss();
	//if (KEYMANAGER->isOnceKeyDown('B'))setBubble();
	///////////////////////////////////////////////////////////


	///////////////////////////////////////////////////////

}

void enemyManager::render()
{
	for (_viRedBeetle = _vRedBeetle.begin(); _viRedBeetle != _vRedBeetle.end(); ++_viRedBeetle)
	{
		(*_viRedBeetle)->render();
	}

	for (_viSkeleton = _vSkeleton.begin(); _viSkeleton != _vSkeleton.end(); ++_viSkeleton)
	{
		(*_viSkeleton)->render();
	}

	for (_viGreenDragon = _vGreenDragon.begin(); _viGreenDragon != _vGreenDragon.end(); ++_viGreenDragon)
	{
		(*_viGreenDragon)->render();
	}

	for (_viYellowDragon = _vYellowDragon.begin(); _viYellowDragon != _vYellowDragon.end(); ++_viYellowDragon)
	{
		(*_viYellowDragon)->render();
	}

	for (_viBlueSlime = _vBlueSlime.begin(); _viBlueSlime != _vBlueSlime.end(); ++_viBlueSlime)
	{
		(*_viBlueSlime)->render();
	}

	for (_viBoss = _vBoss.begin(); _viBoss != _vBoss.end(); ++_viBoss)
	{
		(*_viBoss)->render();

	}

	for (_viBubble = _vBubble.begin(); _viBubble != _vBubble.end(); ++_viBubble)
	{
		(*_viBubble)->render();

	}
}



void enemyManager::setRedBeetle()
{
	for (int i = 0; i < 1; i++)
	{
		for (int j = 0; j < 1; j++)
		{
			enemy* _beetle;
			_beetle = new redBeetle;

			_beetle->init(MON_REDBITTLE, PointMake(WINSIZEX / 2 - 200, WINSIZEY / 2 + 200));

			_vRedBeetle.push_back(_beetle);
		}
	}
}

void enemyManager::setGreenDragon()
{
	for (int i = 0; i < 1; i++)
	{
		for (int j = 0; j < 1; j++)
		{
			enemy* _greenDragon;
			_greenDragon = new greenDragon;

			_greenDragon->init(MON_GREENDRAGON, PointMake(WINSIZEX / 2 - 100, WINSIZEY / 2 + 200));

			_vGreenDragon.push_back(_greenDragon);
		}
	}
}

void enemyManager::setBlueSlime()
{
	for (int i = 0; i < 1; i++)
	{
		for (int j = 0; j < 1; j++)
		{
			enemy* _slime;
			_slime = new blueSlime;

			_slime->init(MON_SLIME, PointMake(WINSIZEX / 2, WINSIZEY / 2 + 200));

			_vBlueSlime.push_back(_slime);
		}
	}
}

void enemyManager::setSkeleton()
{
	for (int i = 0; i < 1; i++)
	{
		for (int j = 0; j < 1; j++)
		{
			enemy* _skeleton;
			_skeleton = new skeleton;

			_skeleton->init(MON_SKELETON, PointMake(WINSIZEX / 2 + 100, WINSIZEY / 2 + 200));

			_vSkeleton.push_back(_skeleton);
		}
	}
}

void enemyManager::setYellowDragon()
{
	for (int i = 0; i < 1; i++)
	{
		for (int j = 0; j < 1; j++)
		{
			enemy* _yellowDragon;
			_yellowDragon = new yellowDragon;

			_yellowDragon->init(MON_YELLOWDRAGON, PointMake(WINSIZEX / 2 + 200, WINSIZEY / 2 + 200));

			_vYellowDragon.push_back(_yellowDragon);
		}
	}
}

void enemyManager::setBubble(int bubbleX , int bubbleY)
{
	_bubbleX = bubbleX;
	_bubbleY = bubbleY;
	for (int i = 0; i < 1; i++)
	{
		for (int j = 0; j < 1; j++)
		{
			enemy* _bubble;
			_bubble = new bubble;

			_bubble->init(MON_BUBBLE, PointMake(_bubbleX , _bubbleY));

			_vBubble.push_back(_bubble);
		}

	}
}

void enemyManager::attackPlayer()
{
	//for (_viSkeleton = _vSkeleton.begin(); _viSkeleton != _vSkeleton.end(); ++_viSkeleton)
	//{
	//	RECT temp;
	//	if (IntersectRect(&temp, &(*_viSkeleton)->getDetectRect(), &_player->getPlayerRect())
	//	{
	//	
	//	}
	//	
	//}
}

void enemyManager::setBoss()
{
	for (int i = 0; i < 1; i++)
	{
		for (int j = 0; j < 1; j++)
		{
			enemy* _boss;
			_boss = new boss;

			_boss->init(MON_BOSS, PointMake(WINSIZEX / 2 - 200, WINSIZEY / 2 + 200));

			_vBoss.push_back(_boss);
		}

	}
}

void enemyManager::frameMove()
{
}

void enemyManager::killSomething(int arrNum)
{
	if (_vBlueSlime[arrNum]->getHitCounter() == 0)
	{
		SAFE_DELETE(_vBlueSlime[arrNum]);
		_vBlueSlime.erase(_vBlueSlime.begin() + arrNum);
	}

	if (_vRedBeetle[arrNum]->getHitCounter() == 0)
	{
		SAFE_DELETE(_vRedBeetle[arrNum]);
		_vRedBeetle.erase(_vRedBeetle.begin() + arrNum);
	}

	if (_vGreenDragon[arrNum]->getHitCounter() == 0)
	{
		SAFE_DELETE(_vGreenDragon[arrNum]);
		_vGreenDragon.erase(_vGreenDragon.begin() + arrNum);
	}
	if (_vSkeleton[arrNum]->getHitCounter() == 0)
	{
		SAFE_DELETE(_vSkeleton[arrNum]);
		_vSkeleton.erase(_vSkeleton.begin() + arrNum);
	}
	if (_vYellowDragon[arrNum]->getHitCounter() == 0)
	{
		SAFE_DELETE(_vYellowDragon[arrNum]);
		_vYellowDragon.erase(_vYellowDragon.begin() + arrNum);
	}


}


/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////// 미완성 코드

//for (int i = 0; i < _em->getVSkeleton().size(); i++)
//{
//	int playerX;
//	playerX = _player->getPlayerRect().right - _player->getPlayerRect().left;
//	RECT temp;
//	if (IntersectRect(&temp, &_em->getVSkeleton()[i]->getDetectRect(), &_player->getPlayerRect()))
//	{
//		if (_isAttack == false)
//		{
//			
//				if (playerX - _em->getVSkeleton()[i]->getCenterX > 100)
//				{
//					_em->getVSkeleton()[i]->getMonsetrDirection = rightMove;
//				}
//				if (playerX - _em->getVSkeleton()[i]->getCenterX < -100)
//				{
//					_em->getVRedBeetle()[i]->getMonsetrDirection = leftMove;
//				}
//				if (playerX - _em->getVSkeleton()[i]->getCenterX > 0 && playerX - _em->getVSkeleton()[i]->getCenterX < 100)
//				{
//					_em->getVSkeleton()[i]->getMonsetrDirection = rightAttack;
//					_em->getVSkeleton()[i]->getCurrentFrameX = 0;
//					_isAttack = true;
//				}
//
//				if (playerX - _em->getVSkeleton()[i]->getCenterX < 0 && playerX - _em->getVSkeleton()[i]->getCenterX > -100)
//				{
//					_em->getVSkeleton()[i]->getMonsetrDirection = leftAttack;
//					_em->getVSkeleton()[i]->getCurrentFrameX = 3;
//					_isAttack = true;
//				}
//		}
//	}
//	else 
//}
//
//if (_isAttack = true)
//{
//	readyCounter++;
//}
//
//if (readyCounter % 20 == 0)
//{
//	_em->getVRedBeetle()[i]->getMonsetrDirection = leftMove;
//	readyCounter = 0;
//	_isAttack = false;
//}
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//for (int i = 0; i < _em->getVBoss().size(); i++)
//{
//
//	if (_isAttack == false)
//	{
//		if (_pattern == 1)
//		{
//			if (playerX - _em->getVBoss()[i]->getCenterX > 100)
//			{
//				_em->getVBoss()[i]->getMonsetrDirection = rightMove;
//			}
//			if (playerX - _em->getVRedBeetle()[i]->getCenterX < -100)
//			{
//				_em->getVBoss()[i]->getMonsetrDirection = leftMove;
//			}
//		}
//
//
//		if (_pattern == 2)
//		{
//			if (playerX - _em->getVBoss()[i]->getCenterX > 100)
//			{
//				_em->getVBoss()[i]->getMonsetrDirection = rightJump;
//				_isAttack = true;
//			}
//			if (playerX - _em->getVRedBeetle()[i]->getCenterX < -100)
//			{
//				_em->getVBoss()[i]->getMonsetrDirection = leftJump;
//				_isAttack = true;
//			}
//		}
//
//		if (_pattern == 3)
//		{
//			if (playerX - _em->getVBoss()[i]->getCenterX > 100)
//			{
//				_em->getVBoss()[i]->getMonsetrDirection = rightJump;
//				_em->getVBoss()[i]->getJumpPower = 10.0f;
//				_em->getVBoss()[i]->getGravity = 0.2f;
//
//				_isAttack = true;
//			}
//			if (playerX - _em->getVRedBeetle()[i]->getCenterX < -100)
//			{
//				_em->getVBoss()[i]->getMonsetrDirection = leftJump;
//				_em->getVBoss()[i]->getJumpPower = 10.0f;
//				_em->getVBoss()[i]->getGravity = 0.2f;
//
//				_isAttack = true;
//			}
//		}
//		
//	}
//}
//if()
//
//else if ((_em->getVBoss()[i]->getMonsterDirection == rightJump || _em->getVBoss()[i]->getMonsterDirection == leftJump) &&
//	_em->getVBoss()[i]->getCenterX )
//{
//	if (_em->getVBoss()[i]->getMonsterDirection() == rightJump)
//	{
//		_em->getVBoss()[i]->getMonsterDirection() = rightJumpAttack;
//	}
//
//	if (_em->getVBoss()[i]->getMonsterDirection() == rightJump)
//	{
//		_em->getVBoss()[i]->getMonsterDirection() = leftJumpAttack;
//	}
//}
//
//	else if (_em->getVBoss()[i]->getJumpPower <= 0)
//	{
//		if (_em->getVBoss()[i]->getMonsterDirection() == rightJump)
//		{
//			_em->getVBoss()[i]->getMonsterDirection() = rightJumpAttack;
//		}
//
//		if (_em->getVBoss()[i]->getMonsterDirection() == rightJump)
//		{
//			_em->getVBoss()[i]->getMonsterDirection() = leftJumpAttack;
//		}
//	}
//
//
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//
//for (int i = 0; i < _em->getVYellow().size(); i++)
//{
//	//int playerX;
//	//playerX = _player->getPlayerRect().right - _player->getPlayerRect().left;
//	RECT temp;
//	if (IntersectRect(&temp, &_em->getVYellowDragon()[i]->getDetectRect(), &_player->getPlayerRect()))
//	{
//		if (bubbleReady == true)
//		{
//			bubbleShoot = true;
//			_monsterDirection = leftAttack;
//		}
//	}
//
//	if (bubbleReady == false)
//	{
//		readyCounter++;
//		if (readyCounter % 80 == 0)
//		{
//			bubbleReady = true;
//			readyCounter = 0;
//		}
//	}
//
//	if (bubbleShoot == true)
//	{
//		if (bubbleCount < 3)
//		{
//			_em->setBubble(_em->getVYellowDragon()[i]->getCollsionRect.left, _em->getVYellowDragon()[i]->getCenterY());
//			bubbleCount++;
//		}
//		else
//		{
//			bubbleReady = false;
//			bubbleShoot = false;
//			bubbleCount = 0;
//
//			_em->getvYellowDragon()[i]->getMonsterDirection = leftStand;
//		}
//
//		
//	}
//
//}