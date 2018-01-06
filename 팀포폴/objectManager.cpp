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
	//_pickeffect = new effect;

	EFFECTMANAGER->addEffect("보석", "./image/object/pickupSparkle.bmp", 42, 14, 14, 14, 1.0f, 0.05f, 100);
	EFFECTMANAGER->addEffect("블록", "./image/object/dirtblock_effect.bmp", 540, 148, 180, 148, 1.0f, 0.1f, 100);
	EFFECTMANAGER->addEffect("작은블록", "./image/object/dirtblock_small_effect.bmp", 320, 72, 106, 72, 1.0f, 0.1f, 100);
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

	for (int i = 0; i < _vUse.size(); i++)
	{
		_vUse[i]->update();
	}

	for (int i = 0; i < _vbubble.size(); i++)
	{
		_vbubble[i]->update();
	}
	//player_object_collision()을 stage에서 처리 반환값을 COLLISION_INFO구조체로
	player_object_collision();
	_p->update();
	EFFECTMANAGER->update();
}

void objectManager::render()
{
	//for (int i = 0; i < _vladder.size(); i++)
	//{
	//	_vladder[i]->render();
	//}
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

	for (int i = 0; i < _vUse.size(); i++)
	{
		_vUse[i]->render();
	}

	for (int i = 0; i < _vdirtblock.size(); i++)
	{
		_vdirtblock[i]->render();
	}

	for (int i = 0; i < _vbubble.size(); i++)
	{
		_vbubble[i]->render();
	}
	EFFECTMANAGER->render();
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
	//_obj = new gem;
	//_obj->init("smalljew", 30, 30);
	//_vgem.push_back(_obj);
	//
	//_obj = new gem;
	//_obj->init("reddia", 10, 30);
	//_vgem.push_back(_obj);
	//
	//_obj = new gem;
	//_obj->init("yellowgem", 30, 30);
	//_vgem.push_back(_obj);

	_obj = new gem;
	_obj->init(50, 3300, 3450, 3300, 3450, 2.0f, PI);
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
	_obj->init(3100, 3450);
	_vdirtpile.push_back(_obj);

	_obj = new dirtpile;
	_obj->init(3300, 3450);
	_vdirtpile.push_back(_obj);

	_obj = new dirtpile;
	_obj->init(3700, 3450);
	_vdirtpile.push_back(_obj);

	_obj = new potion;
	_obj->init(3500, 3200);
	_vUse.push_back(_obj);

	_obj = new potion;
	_obj->init(3900, 3200);
	_vUse.push_back(_obj);

	_obj = new food;
	_obj->init(3200, 3100);
	_vUse.push_back(_obj);

	//_obj = new platter;
	//_obj->init(3200, 3150);
	//_vUse.push_back(_obj);

	_obj = new dirtblock;
	_obj->init(2550, 3050);
	_vdirtblock.push_back(_obj);

	_obj = new dirtblock;
	_obj->init(2300, 3150);
	_vdirtblock.push_back(_obj);

	_obj = new smalldirtblock;
	_obj->init(2100, 3300);
	_vdirtblock.push_back(_obj);

	_obj = new bubbles;
	_obj->init(3464, 3100,3464,3100,90);
	_vbubble.push_back(_obj);

	_obj = new bubbles;
	_obj->init(3200, 3100, 3200, 3100, 90);
	_vbubble.push_back(_obj);
}

LPCOLLISION_INFO objectManager::player_object_collision()
{
	LPCOLLISION_INFO tempInfo = new COLLISION_INFO;


	for (int i = 0; i < _vdirtpile.size(); i++)
	{
		_leftX = _vdirtpile[i]->getX();
		_topY = _vdirtpile[i]->getY();

		//dirty는 충돌시 플레이어에 영향을 주지 않으므로 pass
			RECT temp;
			if(IntersectRect(&temp, _p->getPlayerAttackRect(), &_vdirtpile[i]->_rc))
			{
			
				if (_vdirtpile[i]->getAni()->getPlayIndex() == 0)
				{
					_vdirtpile[i]->getAni()->setPlayIndex(1);
					//col = 1;
					_p->setPlayerAttackRect(RectMake(-1500, 100, 150, 100));
				}
				else if (_vdirtpile[i]->getAni()->getPlayIndex() == 1)
				{
					col = 2;
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
	for (int i = 0; i < _vgem.size(); i++)
	{
		if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
		{
			_obj = new gem;
			_obj->init(20, _leftX, _topY, _leftX, _topY,2.0f,PI);
			_vgem.push_back(_obj);
		
			//_obj = new gem;
			//_obj->init("reddia", 10, 30);
			//_vgem.push_back(_obj);
		  	
			//_obj = new gem;
			//_obj->init("yellowgem", 10, 30, _leftX, _topY, _leftX, _topY, 2.0f, PI);
			//_vgem.push_back(_obj);
		}
		//if (PtInRect(&_vgem[i]->_rc, _ptMouse))
		//{
			RECT temp;
			if (IntersectRect(&temp, _p->getPlayerRect(), &_vgem[i]->_rc))
			{
				EFFECTMANAGER->play("보석", _vgem[i]->_leftX,_vgem[i]->_topY);
				_vgem.erase(_vgem.begin() + i);
				_obj = new gem;
				_obj->init(30, _leftX, _topY, _leftX, _topY, 2.0f, PI);
				_vgem.push_back(_obj);
				//충돌메시지 작성
				tempInfo->_colType = COL_OBJECT;
				//tempInfo->index_detail = --- 세부번호
				tempInfo->object = _vgem[i];
			}
			//if (_vgem.size() >= 10)_vgem.erase(_vgem.begin(),_vgem.end());
			if (KEYMANAGER->isOnceKeyDown(VK_RBUTTON))
			{
				//vector<objects*> temp;
				//temp.push_back(_vgem[i]);
				_vgem.erase(_vgem.begin() + i);
				//_vgem.push_back(_vgem[i]);
				//_vgem.erase(_vgem.begin() + i);
			}
			if (_vdirtpile.size() <= 0)
			{
				_vgem[i]->_leftX = 0;
				_vgem[i]->_topY = 0;
			}
		//}
	}
	
	//포션
	for (int i = 0; i < _vUse.size(); i++)
	{
		RECT temp;
		if (IntersectRect(&temp, _p->getPlayerRect(), &_vUse[i]->_rc) && _vUse[i]->_type == TYPE_POTION)
		{
			//if(_vUse[i]->_type != TYPE_FOOD)
			_vUse.erase(_vUse.begin() + i);
		}

		else if (IntersectRect(&temp, _p->getPlayerRect(), &_vUse[i]->_rc) && _vUse[i]->_type == TYPE_FOOD)
		{
			_vUse.erase(_vUse.begin() + i);
		}
	}

	for (int i = 0; i < _vdirtblock.size(); i++)
	{
		RECT temp;
		if (IntersectRect(&temp, _p->getPlayerAttackRect(), &_vdirtblock[i]->_rc))
		{
			if(_vdirtblock[i]->_type == TYPE_BLOCK)EFFECTMANAGER->play("블록",_vdirtblock[i]->_leftX, _vdirtblock[i]->_topY);

			else if (_vdirtblock[i]->_type == TYPE_SMALL_BLOCK)EFFECTMANAGER->play("작은블록", _vdirtblock[i]->_leftX, _vdirtblock[i]->_topY);
			_vdirtblock.erase(_vdirtblock.begin() + i);
		}
	}

	for (int i = 0; i < _vbubble.size(); i++)
	{
		RECT temp;
		if (IntersectRect(&temp, _p->getPlayerAttackRect(), &_vbubble[i]->_rc))
		{
			_obj = new bubbles;
			_obj->init(_vbubble[i]->_leftX, _vbubble[i]->_topY, _vbubble[i]->_leftX, _vbubble[i]->_topY, 90);
			_vbubble.push_back(_obj);

			_vbubble.erase(_vbubble.begin() + i);

		}
	}
	//충돌메시지 반환 -> 플레이어에 넘겨주면 플레이어가 _colType과 index_detail을 가지고 판단, 처리
	if(tempInfo->_colType != COL_NONE)
	return tempInfo;
	else return NULL;
}
