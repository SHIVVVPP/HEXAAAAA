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
	

	EFFECTMANAGER->addEffect("����", "./image/object/pickupSparkle.bmp", 42, 14, 14, 14, 1.0f, 0.1f, 50);
	EFFECTMANAGER->addEffect("���", "./image/object/dirtblock_effect.bmp", 540, 148, 180, 148, 1.0f, 0.1f, 100);
	EFFECTMANAGER->addEffect("�������", "./image/object/dirtblock_small_effect.bmp", 320, 72, 106, 72, 1.0f, 0.1f, 100);
	EFFECTMANAGER->addEffect("����", "./image/object/bubbleeffect.bmp", 200, 100, 100, 100, 1.0f, 0.1f, 100);
	
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

	for (int i = 0; i < _vplatter.size(); i++)
	{
		_vplatter[i]->update();
	}

	for (int i = 0; i < _vpart.size(); i++)
	{
		_vpart[i]->update();
	}
	for (int i = 0; i < _vfakedirt.size(); i++)
	{
		_vfakedirt[i]->update();
	}
	for (int i = 0; i < _vsheet.size(); i++)
	{
		_vsheet[i]->update();
	}
	//player_object_collision()�� stage���� ó�� ��ȯ���� COLLISION_INFO����ü��
	//player_object_collision();
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

	for (int i = 0; i < _vplatter.size(); i++)
	{
		_vplatter[i]->render();
	}

	for (int i = 0; i < _vpart.size(); i++)
	{
		_vpart[i]->render();
	}

	for (int i = 0; i < _vfakedirt.size(); i++)
	{
		_vfakedirt[i]->render();
	}
	for (int i = 0; i < _vsheet.size(); i++)
	{
		_vsheet[i]->render();
	}
	EFFECTMANAGER->render();
}

void objectManager::setPosition()
{
	_obj = new gem;
	_obj->init(50, 100, 3450, 3300, 3450, 2.0f, PI);
	_vgem.push_back(_obj);
	
	_obj = new ladder;
	_obj->init(50, 50, 100);
	_vladder.push_back(_obj);

	_obj = new moveblock;
	_obj->init(2800, 3150,50,false);
	_vmoveblock.push_back(_obj);

	_obj = new moveblock;
	_obj->init(2000, 3150, 200, false);
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
	
	_obj = new meal;
	_obj->init(3200, 3200);
	_vUse.push_back(_obj);

	_obj = new dirtblock;
	_obj->init(1500, 3350);
	_vdirtblock.push_back(_obj);

	_obj = new dirtblock;
	_obj->init(1900, 3350);
	_vdirtblock.push_back(_obj);

	_obj = new smalldirtblock;
	_obj->init(1100, 3350);
	_vdirtblock.push_back(_obj);

	_obj = new bubbles;
	_obj->init(3464, 3100,3464,3100,90);
	_vbubble.push_back(_obj);

	_obj = new bubbles;
	_obj->init(3200, 3100, 3200, 3100, 90);
	_vbubble.push_back(_obj);

	_obj = new platters;
	_obj->init(3600, 3200);
	_vplatter.push_back(_obj);

	_obj = new platters;
	_obj->init(4000, 3200);
	_vplatter.push_back(_obj);

	_obj = new fakedirt;
	_obj->init(3500, 3200,500);
	_vfakedirt.push_back(_obj);  

	_obj = new musicsheet;
	_obj->init(3400, 3400);
	_vsheet.push_back(_obj);

	//****���Ʒ� ��ǥ//
	
}

LPCOLLISION_INFO objectManager::player_object_collision()
{
	LPCOLLISION_INFO tempInfo = new COLLISION_INFO;


	for (int i = 0; i < _vdirtpile.size(); i++)
	{
		_leftX = _vdirtpile[i]->getX();
		_topY = _vdirtpile[i]->getY();

		//dirty�� �浹�� �÷��̾ ������ ���� �����Ƿ� pass
			RECT temp;
			if(IntersectRect(&temp, _p->getPlayerAttackRect(), &_vdirtpile[i]->_rc))
			{
				tempInfo->_colType = COL_OBJECT;
				tempInfo->object = _vdirtpile[i];
				tempInfo->index_detail = DIRTPILE;
				tempInfo->_isPlayer = false;

				if (_vdirtpile[i]->getAni()->getPlayIndex() == 0)
				{
					_vdirtpile[i]->getAni()->setPlayIndex(1);
					_obj = new gem;
					_obj->init(30, _leftX, _topY, _leftX, _topY, 2.0f, PI);
					_vgem.push_back(_obj);
					//_p->setPlayerAttackRect(RectMake(-1500, 100, 150, 100));
				}
				else if (_vdirtpile[i]->getAni()->getPlayIndex() == 1)
				{
					_obj = new gem;
					_obj->init(30, _leftX, _topY, _leftX, _topY, 2.0f, PI);
					_vgem.push_back(_obj);
					_vdirtpile[i]->getAni()->setPlayIndex(2);	
				}
				else if (_vdirtpile[i]->getAni()->getPlayIndex() == 2)
				{	
					_obj = new gem;
					_obj->init(30, _leftX, _topY, _leftX, _topY, 2.0f, PI);
					_vgem.push_back(_obj);
					_vdirtpile[i]->getAni()->setPlayIndex(3);
				}
				else if (_vdirtpile[i]->getAni()->getPlayIndex() == 3)
				{
					_obj = new gem;
					_obj->init(30, _leftX, _topY, _leftX, _topY, 2.0f, PI);
					_vgem.push_back(_obj);
					_vdirtpile[i]->getAni()->setPlayIndex(4);
				}
				else if (_vdirtpile[i]->getAni()->getPlayIndex() == 4)
				{
					_obj = new gem;
					_obj->init(30, _leftX, _topY, _leftX, _topY, 2.0f, PI);
					_vgem.push_back(_obj);
					_vdirtpile.erase(_vdirtpile.begin() + i);
				}
			}
    }
	for (int i = 0; i < _vgem.size(); i++)
	{
		//if (KEYMANAGER->isOnceKeyDown(VK_LBUTTON))
		//{
		//	_obj = new gem;
		//	_obj->init(30, _leftX, _topY, _leftX, _topY,2.0f,PI);
		//	_vgem.push_back(_obj);
		//
		//	//_obj = new gem;
		//	//_obj->init("reddia", 10, 30);
		//	//_vgem.push_back(_obj);
		//  	
		//	//_obj = new gem;
		//	//_obj->init("yellowgem", 10, 30, _leftX, _topY, _leftX, _topY, 2.0f, PI);
		//	//_vgem.push_back(_obj);
		//}
		//if (PtInRect(&_vgem[i]->_rc, _ptMouse))
		//{
			RECT temp;
			if (IntersectRect(&temp, _p->getPlayerRect(), &_vgem[i]->_rc))
			{
				//�浹�޽��� �ۼ�
				tempInfo->_colType = COL_OBJECT;
				//tempInfo->index_detail = --- ���ι�ȣ
				tempInfo->object = _vgem[i];
				tempInfo->index_detail = GEM;

				EFFECTMANAGER->play("����", _vgem[i]->_leftX,_vgem[i]->_topY);
				_vgem.erase(_vgem.begin() + i);
			}
			//if (_vgem.size() >= 10)_vgem.erase(_vgem.begin(),_vgem.end());
			
			//if (_vdirtpile.size() <= 0)
			//{
			//	_vgem[i]->_leftX = 0;
			//	_vgem[i]->_topY = 0;
			//}
		//}
	}
	
	//����, food , meal
	for (int i = 0; i < _vUse.size(); i++)
	{
		RECT temp;
		if (IntersectRect(&temp, _p->getPlayerRect(), &_vUse[i]->_rc) && _vUse[i]->_type == TYPE_POTION)
		{
			tempInfo->_colType = COL_OBJECT;
			tempInfo->object = _vUse[i];
			tempInfo->index_detail = POTION;
			_vUse.erase(_vUse.begin() + i);
		}

		else if (IntersectRect(&temp, _p->getPlayerRect(), &_vUse[i]->_rc) && _vUse[i]->_type == TYPE_FOOD)
		{
			tempInfo->_colType = COL_OBJECT;
			tempInfo->object = _vUse[i];
			tempInfo->index_detail = FOOD;
			_istouched = true;
			_tempx = _vUse[i]->_leftX;
			_tempy = _vUse[i]->_topY;
			_vUse.erase(_vUse.begin() + i);
		}

		else if (IntersectRect(&temp, _p->getPlayerRect(), &_vUse[i]->_rc) && _vUse[i]->_type == TYPE_MEAL)
		{
			tempInfo->_colType = COL_OBJECT;
			tempInfo->object = _vUse[i];
			tempInfo->index_detail = MEAL;
			_istouched = true;
			_tempx = _vUse[i]->_leftX;
			_tempy = _vUse[i]->_topY;
			_vUse.erase(_vUse.begin() + i);
		}
	}

	for (int i = 0; i < _vdirtblock.size(); i++)
	{
		RECT temp;
		if (IntersectRect(&temp, _p->getPlayerRect(), &_vdirtblock[i]->_rc))
		{
			tempInfo->_colType = COL_OBJECT;
			tempInfo->object = _vdirtblock[i];
			tempInfo->index_detail = DIRTBLOCK;
			tempInfo->_isPlayer = false;
		}
		if (IntersectRect(&temp, _p->getPlayerAttackRect(), &_vdirtblock[i]->_rc))
		{
			if(_vdirtblock[i]->_type == TYPE_BLOCK)EFFECTMANAGER->play("���",_vdirtblock[i]->_leftX - 30 , _vdirtblock[i]->_topY - 15);

			else if (_vdirtblock[i]->_type == TYPE_SMALL_BLOCK)EFFECTMANAGER->play("�������", _vdirtblock[i]->_leftX - 30, _vdirtblock[i]->_topY - 15);

			tempInfo->_colType = COL_OBJECT;
			tempInfo->object = _vdirtblock[i];
			tempInfo->index_detail = DIRTBLOCK;
			tempInfo->_isPlayer = false;

			_vdirtblock.erase(_vdirtblock.begin() + i);
		}


	}

	for (int i = 0; i < _vbubble.size(); i++)
	{
		RECT temp;
		if (IntersectRect(&temp, _p->getPlayerAttackRect(), &_vbubble[i]->_rc))
		{
			//_obj = new bubbles;
			//_obj->init(_vbubble[i]->_leftX, _vbubble[i]->_topY, _vbubble[i]->_leftX, _vbubble[i]->_topY, 90);
			//_vbubble.push_back(_obj);
			tempInfo->_colType = COL_OBJECT;
			tempInfo->object = _vbubble[i];
			tempInfo->index_detail = BUBBLE;
			tempInfo->_isPlayer = false;
			EFFECTMANAGER->play("����", _vbubble[i]->_leftX, _vbubble[i]->_topY);
			_vbubble.erase(_vbubble.begin() + i);

		}
	}

	for (int i = 0; i < _vplatter.size(); i++) //���ô� �浹�� �÷��̾�� ������ ����.
	{
		RECT temp;
		if (IntersectRect(&temp, _p->getPlayerAttackRect(), &_vplatter[i]->_rc))
		{
			_x = _vplatter[i]->_leftX + 10;
			_y = _vplatter[i]->_topY + 10;
			tempInfo->_colType = COL_OBJECT;
			tempInfo->object = _vplatter[i];
			tempInfo->index_detail = PLATTER;
			tempInfo->_isPlayer = false;
			_vplatter.erase(_vplatter.begin() + i);
			_isOpen = true;
			//_obj = new part;
			//_obj->init(_x, _y);
			//_vpart.push_back(_obj);
			//
			//_obj = new part2;
			//_obj->init(_x + 50, _y);
			//_vpart.push_back(_obj);
		}
	}
	if (_isOpen)
	{
		_obj = new part;
		_obj->init(_x, _y);
		_vpart.push_back(_obj);

		_obj = new part2;
		_obj->init(_x + 50, _y);
		_vpart.push_back(_obj);

		_obj = new food;
		_obj->init(_x, _y);
		_vUse.push_back(_obj);
		_isOpen = false;
	}
	

	for (int i = 0; i < _vfakedirt.size(); i++) //��¥ ���� �浹�� �÷��̾�� �ִ� ������ ����.
	{
		RECT temp;
		if (IntersectRect(&temp,_p->getPlayerAttackRect(), &_vfakedirt[i]->_rc))
		{
			tempInfo->_colType = COL_OBJECT;
			tempInfo->object = _vfakedirt[i];
			tempInfo->index_detail = PLATTER;
			tempInfo->_isPlayer = false;

			x = _vfakedirt[i]->_leftX;
			y = _vfakedirt[i]->_topY;
			_iscrush = true;
			_vfakedirt.erase(_vfakedirt.begin() + i);
		}
	}

	for (int i = 0; i < _vsheet.size(); i++)
	{
		RECT temp;
		if (IntersectRect(&temp, _p->getPlayerRect(), &_vsheet[i]->_rc))
		{
			tempInfo->_colType = COL_OBJECT;
			tempInfo->object = _vsheet[i];
			tempInfo->index_detail = MUSIC_SHEET;
			_istouched = true;
			_tempx = _vsheet[i]->_leftX;
			_tempy = _vsheet[i]->_topY;
			_vsheet[i]->_gainValue += 1;
			_vsheet.erase(_vsheet.begin() + i);
		}
	}

	for (int i = 0; i < _vmoveblock.size(); i++)
	{
		RECT temp;
		if (IntersectRect(&temp, _p->getPlayerRect(), &_vmoveblock[i]->_rc))
		{
			tempInfo->_colType = COL_OBJECT;
			tempInfo->object = _vmoveblock[i];
			tempInfo->index_detail = MOVING_PILE;
		}
	}
	_count++;
	if (_iscrush)
	{
		EFFECTMANAGER->stretchplay("���", x, y,IMAGEMANAGER->findImage("leftfakehead")->getWidth(),0,8,false);
		if (_count % 50 == 0)
		{
			_iscrush = false;
			_count = 0;
		}
	}

	if (_istouched)
	{
		EFFECTMANAGER->stretchplay("����", _tempx, _tempy, IMAGEMANAGER->findImage("sparkle")->getWidth(), IMAGEMANAGER->findImage("sparkle")->getHeight(), 58, true);
		if (_count % 50 == 0)
		{
			_istouched = false;
			_count = 0;
		}
	}

	//�浹�޽��� ��ȯ -> �÷��̾ �Ѱ��ָ� �÷��̾ _colType�� index_detail�� ������ �Ǵ�, ó��
	if(tempInfo->_colType != COL_NONE)
	return tempInfo;
	else return NULL;
}
