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
		(*_viRedBeetle)->redbeetleFrameMove();
		(*_viRedBeetle)->generalMove();

	}

	for (_viSkeleton = _vSkeleton.begin(); _viSkeleton != _vSkeleton.end(); ++_viSkeleton)
	{
		(*_viSkeleton)->update();
		
	}

	for (_viGreenDragon = _vGreenDragon.begin(); _viGreenDragon != _vGreenDragon.end(); ++_viGreenDragon)
	{
		(*_viGreenDragon)->update();
		(*_viGreenDragon)->greenDragonFrameMove();
		
	}

	for (_viYellowDragon = _vYellowDragon.begin(); _viYellowDragon != _vYellowDragon.end(); ++_viYellowDragon)
	{
		(*_viYellowDragon)->update();
		(*_viYellowDragon)->yellowDragonFrameMove();
	}

	for (_viBlueSlime = _vBlueSlime.begin(); _viBlueSlime != _vBlueSlime.end(); ++_viBlueSlime)
	{
		(*_viBlueSlime)->update();
		(*_viBlueSlime)->slimeFameMove();
		//(*_viBlueSlime)->slimeAni();
	}

	//////////////////////////////////////////////////////////
	if (KEYMANAGER->isOnceKeyDown('Q'))setRedBeetle();
	if (KEYMANAGER->isOnceKeyDown('W'))setSkeleton();
	if (KEYMANAGER->isOnceKeyDown('E'))setBlueSlime();
	if (KEYMANAGER->isOnceKeyDown('R'))setGreenDragon();
	if (KEYMANAGER->isOnceKeyDown('T'))setYellowDragon();
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
}



void enemyManager::setRedBeetle()
{
	for (int i = 0; i < 1; i++)
	{
		for (int j = 0; j < 1; j++)
		{
			enemy* _beetle;
			_beetle = new redBeetle;

			_beetle->init("레드비틀", PointMake(WINSIZEX / 2 - 200, WINSIZEY / 2 + 200), 1, 60, 35, 0, 0);

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

			_greenDragon->init("초록용", PointMake(WINSIZEX / 2 - 100, WINSIZEY / 2), 3, 50, 50, 0, 0);

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

			_slime->init("슬라임", PointMake(WINSIZEX / 2, WINSIZEY / 2), 2, 50, 50, 0, 10);

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

			_skeleton->init("해골", PointMake(WINSIZEX / 2 + 100, WINSIZEY / 2), 3, 50, 70, 0, 0);

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

			_yellowDragon->init("노란용", PointMake(WINSIZEX / 2 + 200, WINSIZEY / 2), 7, 50, 50, 0, 0, 50, 50, 0, 0);

			_vYellowDragon.push_back(_yellowDragon);
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