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
}

void enemyManager::render()
{
	for (int i = 0; i < _vEnemy.size(); i++)
	{
		_vEnemy[i]->render();
	}
}


