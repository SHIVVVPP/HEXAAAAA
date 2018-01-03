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
		_vdirtpile[i]->update();
	}

	for (int i = 0; i < _vgem.size(); i++)
	{
		if (_vgem[i]->getisHit())_vgem[i]->update();
	}

	for (int i = 0; i < _vdirtpile.size(); i++)
	{
		for (int j = 0; j < _vgem.size(); j++)
		{
			if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON)) //충돌 추가로 넣기 한대쳤을떄
			{
				if (_vdirtpile[i]->getAni()->getPlayIndex() == 0)
				{
					_vgem[0]->setisHit(true);
					_vdirtpile[i]->getAni()->setPlayIndex(1);
				}
				else if (_vdirtpile[i]->getAni()->getPlayIndex() == 1)
				{
					_vdirtpile[i]->getAni()->setPlayIndex(2);
					//_vgem[j]->setisHit(true);
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

			if (_vgem[0]->getisHit() == true)
			{
				//_vgem[j]->setRC(RectMake(_vdirtpile[i]->getX(), _vdirtpile[i]->getY(), IMAGEMANAGER->findImage(_vgem[j]->getImage())->getWidth(), IMAGEMANAGER->findImage(_vgem[j]->getImage())->getHeight()));
				_vgem[1]->fire(_vdirtpile[i]->getX(), _vdirtpile[i]->getY(), 3.0f, PI * 2);
				_vgem[3]->fire(_vdirtpile[i]->getX(), _vdirtpile[i]->getY(), 3.0f, PI * 2);
				_vgem[2]->setisHit(false);
			}
		}
		break;
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
	
	
	//_obj = new gem;
	//_obj->init(_vdirtpile[i]->getX(),_vdirtpile[i]->getY(), "bluedia", 50);
	//_vgem.push_back(_obj);
	
	//
	_obj = new gem;
	_obj->init("reddia", 10,false);
	_vgem.push_back(_obj);
	//
	_obj = new gem;
	_obj->init("bluegem", 20,false);
	_vgem.push_back(_obj);
	//
	_obj = new gem;
	_obj->init("greengem", 30,false);
	_vgem.push_back(_obj);
	//
	_obj = new gem;
	_obj->init("smalljew", 30,false);
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
