#include "stdafx.h"
#include "objectManager.h"


objectManager::objectManager()
{
}


objectManager::~objectManager()
{
}

HRESULT objectManager::init()
{
	setPosition();

	return S_OK;
}

void objectManager::release()
{
}

void objectManager::update()
{
	for (int i = 0; i < _vmoveblock.size(); i++)
	{
		_vmoveblock[i]->update();
	}

	for (int i = 0; i < _vdirtpile.size(); i++)
	{
		for (int j = 0; j < _vgem.size(); j++)
		{
			_vdirtpile[i]->update();
			if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON)) //충돌 추가로 넣기
			{
				if (_vdirtpile[i]->getAni()->getPlayIndex() == 0)
				{
					_vdirtpile[i]->getAni()->setPlayIndex(1);
					//_vgem[j]->init(80,80,"bluedia",50);
				}
				else if (_vdirtpile[i]->getAni()->getPlayIndex() == 1)
				{
					_vdirtpile[i]->getAni()->setPlayIndex(2);
				}
				else if (_vdirtpile[i]->getAni()->getPlayIndex() == 2)
				{
					_vdirtpile[i]->getAni()->setPlayIndex(3);
				}
				else if (_vdirtpile[i]->getAni()->getPlayIndex() == 3)
				{
					_vdirtpile[i]->getAni()->setPlayIndex(4);
				}
				else if (_vdirtpile[i]->getAni()->getPlayIndex() == 4)
				{
					_vdirtpile.erase(_vdirtpile.begin());
				}
			}
		}
	}
}

void objectManager::render()
{
	for (int i = 0; i < _vgem.size(); i++)
	{
		_vgem[i]->render();
	}
	for (int i = 0; i < _vladder.size(); i++)
	{
		_vladder[i]->render();
	}
	for (int i = 0; i < _vmoveblock.size(); i++)
	{
		_vmoveblock[i]->render();
	}

	for (int i = 0; i < _vdirtpile.size(); i++)
	{
		_vdirtpile[i]->render();
	}
}

void objectManager::setPosition()
{
	objects* _obj;
	_obj = new gem;
	_obj->init(50, 50, "bluedia", 50);
	//smalldia
	//bluegem
	//greegem
	//sjewel
	//yellowgem
	_obj->init(60, 60, "smalldia", 10);
	_obj->init(80, 80, "bluegem", 20);
	_obj->init(90, 90, "greengem", 30);
	_obj->init(100, 100, "yellowgem", 30);
	_vgem.push_back(_obj);

	_obj = new ladder;
	_obj->init(50, 50, 100);
	_vladder.push_back(_obj);

	_obj = new moveblock;
	_obj->init(80, 80,50,false);
	_vmoveblock.push_back(_obj);


	_obj = new dirtpile;
	_obj->init(500, 100);
	_vdirtpile.push_back(_obj);

	_obj = new dirtpile;
	_obj->init(600, 200);
	_vdirtpile.push_back(_obj);
}

void objectManager::player_object_collision()
{
}
