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
	_p = new player;
	_p->init();
	return S_OK;
}

void objectManager::release()
{

}

void objectManager::update()
{
	for (int i = 0; i < _vdirtpile.size(); i++)
	{
		_vdirtpile[i]->update();
	}

	for (int i = 0; i < _vmoveblock.size(); i++)
	{
		_vmoveblock[i]->update();
	}
	for (int i = 0; i < _vgem.size(); i++)
	{
		_vgem[i]->update();
	}
	_p->update();
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
	
	//_vgem.clear();
	//_vdirtpile.clear();
	//_obj = new gem;
	//_obj->init("bluegem", 20,30);
	//_vgem.push_back(_obj);
	//
	//_obj = new gem;
	//_obj->init("greengem", 30,30);
	//_vgem.push_back(_obj);
	//
	//_obj = new gem;
	//_obj->init("bluedia", 10, 30);
	//_vgem.push_back(_obj);
	_obj = new gem;
	_obj->init("smalljew", 30, 30);
	_vgem.push_back(_obj);

	_obj = new gem;
	_obj->init("reddia", 10, 30);
	_vgem.push_back(_obj);

	_obj = new gem;
	_obj->init("yellowgem", 30, 30);
	_vgem.push_back(_obj);

	_obj = new ladder;
	_obj->init(50, 50, 100);
	_vladder.push_back(_obj);

	_obj = new moveblock;
	_obj->init(2600, 2800,50,false);
	_vmoveblock.push_back(_obj);

	_obj = new moveblock;
	_obj->init(2600, 3000, 200, false);
	_vmoveblock.push_back(_obj);

	_obj = new dirtpile;
	_obj->init(2800, 3100);
	_vdirtpile.push_back(_obj);

	_obj = new dirtpile;
	_obj->init(2800, 3200);
	_vdirtpile.push_back(_obj);

	_obj = new dirtpile;
	_obj->init(2800, 3300);
	_vdirtpile.push_back(_obj);
}

void objectManager::player_object_collision()
{
	for (int i = 0; i < _vdirtpile.size(); i++)
	{
			RECT temp;
			if(IntersectRect(&temp, _p->getPlayerAttackRect(), &_vdirtpile[i]->_rc))
			{
				_leftX = _vdirtpile[i]->getX();
				_topY = _vdirtpile[i]->getY();
				if (_vdirtpile[i]->getAni()->getPlayIndex() == 0)
				{
					_vdirtpile[i]->getAni()->setPlayIndex(1);
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
					_vdirtpile.erase(_vdirtpile.begin() + i);
				}
			}
    }

	if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
	{

	}
	for (int i = 0; i < _vgem.size(); i++)
	{
		//if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
		//{
		//	_obj = new gem;
		//	_obj->init("reddia", 10, 30);
		//	_vgem.push_back(_obj);
		//
		//	_obj = new gem;
		//	_obj->init("reddia", 10, 30);
		//	_vgem.push_back(_obj);
		//
		//	_obj = new gem;
		//	_obj->init("yellowgem", 30, 30);
		//	_vgem.push_back(_obj);
		//
		//}
		if (PtInRect(&_vgem[i]->_rc, _ptMouse))
		{
			RECT temp;
			if (KEYMANAGER->isOnceKeyDown(VK_RBUTTON))
			{
				//vector<objects*> temp;
				//temp.push_back(_vgem[i]);
				//_vgem.erase(_vgem.begin());
				//_vgem.push_back(_vgem[i + 1]);
				//_vgem.erase(_vgem.begin() + i);
			}//break;
		}
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
