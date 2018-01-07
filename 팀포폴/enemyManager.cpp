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

	return S_OK;
}

void enemyManager::release()
{
}

void enemyManager::update()
{
	if (KEYMANAGER->isOnceKeyDown('O'))
	{
		enemy* temp = new redBeetle;
		temp->init(MON_REDBITTLE, { _ptMouse.x + CAMERAMANAGER->getCameraPoint().x,_ptMouse.y + CAMERAMANAGER->getCameraPoint().y });
		_vEnemy.push_back(temp);
	}

	if (KEYMANAGER->isOnceKeyDown('P'))
	{
		enemy* temp = new skeleton;
		temp->init(MON_SKELETON, { _ptMouse.x + CAMERAMANAGER->getCameraPoint().x,_ptMouse.y + CAMERAMANAGER->getCameraPoint().y });
		temp->setPlayerRc(_player->getPlayerRect());
		_vEnemy.push_back(temp);
	}
			
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


