#include "stdafx.h"
#include "enemyManager.h"
#include "player.h"



enemyManager::enemyManager()
{
}
enemyManager::~enemyManager()
{
}



HRESULT enemyManager::init()
{
	

	generalFrameCounter = 0;

	enemy* temp = new redBeetle;
	temp->init(MON_REDBITTLE, { 980,3259 });
	_vEnemy.push_back(temp);

	temp = new skeleton;
	temp->init(MON_SKELETON, { 877,3259 });
	temp->setPlayerRc(_player->getPlayerRect());
	_vEnemy.push_back(temp);

	return S_OK;
}

void enemyManager::release()
{
}

void enemyManager::update()
{
		
			
	for (int i = 0; i < _vEnemy.size(); i++)
	{
		_vEnemy[i]->pixelCollisionReact(_pixelColImage,_ptReal);
		_vEnemy[i]->update();
	}

	collisionCheck();
}

void enemyManager::render()
{
	for (int i = 0; i < _vEnemy.size(); i++)
	{
		_vEnemy[i]->render();
	}
}

void enemyManager::collisionCheck()
{
	LPCOLLISION_INFO tempColInfo = new COLLISION_INFO;

	RECT temp;
	for (int i = 0; i < _vEnemy.size(); i++)
	{
		if (!IntersectRect(&temp, _player->getPlayerRect(), &_vEnemy[i]->getColRect())) continue;
		
		tempColInfo->_colType = COL_MONSTER;
		tempColInfo->index_detail = _vEnemy[i]->getMonsterIndex();
		tempColInfo->object = _vEnemy[i];
		_player->getColMessage(tempColInfo);
		break;
	}
	
	tempColInfo = new COLLISION_INFO;
	for (int i = 0; i < _vEnemy.size(); i++)
	{
		if (!IntersectRect(&temp, _player->getPlayerAttackRect(), &_vEnemy[i]->getColRect())) continue;

		_vEnemy[i]->CollisionReact();
		tempColInfo->_colType = COL_MONSTER;
		tempColInfo->index_detail = _vEnemy[i]->getMonsterIndex();
		tempColInfo->object = _vEnemy[i];
		tempColInfo->_isPlayer = false;
		_player->getColMessage(tempColInfo);
		break;
	}


}


