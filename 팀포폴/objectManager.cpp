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
	//_hitcount = 9;
	for (int i = 0; i < _vgem.size(); i++)
	{
		_vgem[i]->_canHit = true;
	}
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
		if(_hitcount <5)_vgem[i]->update();
	}
	player_object_collision();
}

void objectManager::render()
{
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

	for (int i = 0; i < _vgem.size(); i++)
	{
		_vgem[i]->render();
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
	_obj->init("reddia", 10);
	_vgem.push_back(_obj);
	//
	_obj = new gem;
	_obj->init("bluegem", 20);
	_vgem.push_back(_obj);
	//
	_obj = new gem;
	_obj->init("greengem", 30);
	_vgem.push_back(_obj);
	//
	_obj = new gem;
	_obj->init("smalljew", 30);
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
	for (int i = 0; i < _vdirtpile.size(); i++)
	{
		for (int j = 0; j < _vgem.size(); j++)
		{
			if (_vgem[j]->_canHit)
			{
				if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON)) //충돌 추가로 넣기 한대쳤을떄
				{
					if (_vdirtpile[i]->getAni()->getPlayIndex() == 0)
					{
						_hitcount = 4;
						_vdirtpile[i]->getAni()->setPlayIndex(1);
						_vgem[3]->fire(_vdirtpile[i]->getX(), _vdirtpile[i]->getY(), _vdirtpile[i]->getX(), _vdirtpile[i]->getY(), 3.0f, PI);
					}
					else if (_vdirtpile[i]->getAni()->getPlayIndex() == 1)
					{
						_hitcount = 3;
						_vdirtpile[i]->getAni()->setPlayIndex(2);
					}
					else if (_vdirtpile[i]->getAni()->getPlayIndex() == 2)
					{
						_hitcount = 2;
						_vdirtpile[i]->getAni()->setPlayIndex(3);
					}
					else if (_vdirtpile[i]->getAni()->getPlayIndex() == 3)
					{
						_hitcount = 1;
						_vdirtpile[i]->getAni()->setPlayIndex(4);
					}
					else if (_vdirtpile[i]->getAni()->getPlayIndex() == 4)
					{
						_hitcount = 0;
						_vdirtpile.erase(_vdirtpile.begin());
					}
				}
			
			}
		}break;
	}

	for (_vigem = _vgem.begin(); _vigem != _vgem.end(); ++_vigem)
	{
		//(*_vigem)->_rc = 
	}
	//for (int i = 0; i < _vdirtpile.size(); ++i) // 2
	//{
	//	for (int j = 0; j < _vgem.size(); ++j)
	//	{
	//		int _leftX = _vdirtpile[i]->_x;
	//		int _topY = _vdirtpile[i]->_y;
	//		switch (_hitcount)
	//		{
	//		case 0:
	//			//_vgem[j]->setRC(RectMake(_vdirtpile[i]->getX(), _vdirtpile[i]->getY(), IMAGEMANAGER->findImage(_vgem[j]->getImage())->getWidth(), IMAGEMANAGER->findImage(_vgem[j]->getImage())->getHeight()));
	//			_vgem[j]->fire(200, _topY, _vdirtpile[i]->getX(), _vdirtpile[i]->getY(), 3.0f, PI);
	//			break;
	//		case 1:
	//			//_vgem[j]->setRC(RectMake(_vdirtpile[i]->getX(), _vdirtpile[i]->getY(), IMAGEMANAGER->findImage(_vgem[j]->getImage())->getWidth(), IMAGEMANAGER->findImage(_vgem[j]->getImage())->getHeight()));
	//			_vgem[j]->fire(_leftX, _topY, _vdirtpile[i]->getX(), _vdirtpile[i]->getY(), 3.0f, PI);
	//			break;
	//		case 2:
	//			//_vgem[j]->setRC(RectMake(_vdirtpile[i]->getX(), _vdirtpile[i]->getY(), IMAGEMANAGER->findImage(_vgem[j]->getImage())->getWidth(), IMAGEMANAGER->findImage(_vgem[j]->getImage())->getHeight()));
	//			_vgem[j]->fire(_leftX, _topY, _vdirtpile[i]->getX(), _vdirtpile[i]->getY(), 3.0f, PI);
	//			break;
	//		case 3:
	//			//_vgem[j]->setRC(RectMake(_vdirtpile[i]->getX(), _vdirtpile[i]->getY(), IMAGEMANAGER->findImage(_vgem[j]->getImage())->getWidth(), IMAGEMANAGER->findImage(_vgem[j]->getImage())->getHeight()));
	//			_vgem[j]->fire(_leftX, _topY, _vdirtpile[i]->getX(), _vdirtpile[i]->getY(), 3.0f, PI);
	//			break;
	//		case 4:
	//			//_vgem[j]->setRC(RectMake(_vdirtpile[i]->getX(), _vdirtpile[i]->getY(), IMAGEMANAGER->findImage(_vgem[j]->getImage())->getWidth(), IMAGEMANAGER->findImage(_vgem[j]->getImage())->getHeight()));
	//			_vgem[j]->fire(_leftX, _topY, _vdirtpile[i]->getX(), _vdirtpile[i]->getY(), 3.0f, PI);
	//			//_vgem[1]->fire(_vdirtpile[i]->getX(), _vdirtpile[i]->getY(), 3.0f, PI * 2);
	//			break;
	//		}
	//	}
	//	break;
	//}
}
