#include "stdafx.h"
#include "enemyManager.h"
#include "player.h"
#include "objectManager.h"




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
	temp->init(MON_REDBITTLE, { 3289,3419 });
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
	vector<int> _eraseArr;
			
	for (int i = 0; i < _vEnemy.size(); i++)
	{
		_vEnemy[i]->pixelCollisionReact(_pixelColImage,_ptReal);
		_vEnemy[i]->update();
		if (_vEnemy[i]->getMainCondition() == DYINGOUT) _eraseArr.push_back(i);
	}
	collisionCheck();


	eraseMonster(_eraseArr);
	

	

	
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
		if (!IntersectRect(&temp, _player->getPlayerRect(), &_vEnemy[i]->getColRect())
			|| !_vEnemy[i]->canCollisionCheck()) continue;
		
		tempColInfo->_colType = COL_MONSTER;
		tempColInfo->index_detail = _vEnemy[i]->getMonsterIndex();
		tempColInfo->object = _vEnemy[i];
		_player->getColMessage(tempColInfo);
		break;
	}
	
	tempColInfo = new COLLISION_INFO;
	for (int i = 0; i < _vEnemy.size(); i++)
	{
		if (!IntersectRect(&temp, _player->getPlayerAttackRect(), &_vEnemy[i]->getColRect())
			|| !_vEnemy[i]->canCollisionCheck()) continue;

		_vEnemy[i]->CollisionReact();
		tempColInfo->_colType = COL_MONSTER;
		tempColInfo->index_detail = _vEnemy[i]->getMonsterIndex();
		tempColInfo->object = _vEnemy[i];
		tempColInfo->_isPlayer = false;
		_player->getColMessage(tempColInfo);
		break;
	}


}

void enemyManager::eraseMonster(vector<int> v)
{
	if (v.size() != 0)
	{
		while (v.size() != 0)
		{
			int i = v.size() - 1;
			for (int k = 0; k < 3; k++)
			{
				objM->createGem(40, _vEnemy[v[i]]->getPOINT().x, _vEnemy[v[i]]->getPOINT().y, _vEnemy[v[i]]->getPOINT().x, _vEnemy[v[i]]->getPOINT().y);
			}
			_vEnemy.erase(_vEnemy.begin() + v[i]);
			v.pop_back();
		}
	}
}



void enemyManager::monsterSetting(int roomNumber)
{
	enemy* temp;
	/*enemy* temp = new redBeetle;
	temp->init(MON_REDBITTLE, { 3289,3419 });
	_vEnemy.push_back(temp);*/

	/*temp = new skeleton;
	temp->init(MON_SKELETON, { 877,3259 });
	temp->setPlayerRc(_player->getPlayerRect());
	_vEnemy.push_back(temp);*/
	_vEnemy.clear();
	switch (roomNumber)
	{
	case 1:
		temp = new redBeetle;
		temp->init(MON_REDBITTLE, { 3134,3467 });
		_vEnemy.push_back(temp);
		break;
	case 2:

		break;
	case 3:

		break;
	case 4:

		break;
	case 5:

		break;
	case 6:
		temp = new skeleton;
		temp->init(MON_SKELETON, { 11812,2518 });
		temp->setPlayerRc(_player->getPlayerRect());
		_vEnemy.push_back(temp);
		break;
	case 7:
		temp = new skeleton;
		temp->init(MON_SKELETON, { 11625,3171 });
		temp->setPlayerRc(_player->getPlayerRect());
		_vEnemy.push_back(temp);
		break;
	case 8:
		temp = new skeleton;
		temp->init(MON_SKELETON, { 11474,4955 });
		temp->setPlayerRc(_player->getPlayerRect());
		_vEnemy.push_back(temp);

		break;
	case 801:

		break;
	case 9:
		temp = new redBeetle;
		temp->init(MON_REDBITTLE, { 13543,5000 });
		_vEnemy.push_back(temp);
		break;
	case 10:
		temp = new redBeetle;
		temp->init(MON_REDBITTLE, { 14689,5000 });
		_vEnemy.push_back(temp);
		break;
	case 11:

		break;
	case 1101:

		break;
	case 12:

		break;
	case 13:

		break;
	case 14:

		break;
	case 15:
		temp = new skeleton;
		temp->init(MON_SKELETON, { 23063,2420 });
		temp->setPlayerRc(_player->getPlayerRect());
		_vEnemy.push_back(temp);
		break;
	case 1501:

		break;
	case 16:

		break;
	case 17:

		break;
	}
}