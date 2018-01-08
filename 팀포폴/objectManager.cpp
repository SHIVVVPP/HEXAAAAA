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
	

	EFFECTMANAGER->addEffect("보석", "./image/object/pickupSparkle.bmp", 42, 14, 14, 14, 1.0f, 0.1f, 50);
	EFFECTMANAGER->addEffect("블록", "./image/object/dirtblock_effect.bmp", 540, 148, 180, 148, 1.0f, 0.1f, 100);
	EFFECTMANAGER->addEffect("작은블록", "./image/object/dirtblock_small_effect.bmp", 320, 72, 106, 72, 1.0f, 0.1f, 100);
	EFFECTMANAGER->addEffect("버블", "./image/object/bubbleeffect.bmp", 200, 100, 100, 100, 1.0f, 0.1f, 100);
	
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
	//player_object_collision()을 stage에서 처리 반환값을 COLLISION_INFO구조체로
	//player_object_collision();
	//_p->update();
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
	
	_obj = new meal;
	_obj->init(3200, 3200);
	_vUse.push_back(_obj);

	_obj = new moveblock;
	_obj->init(1700, 3350, 100, false, true, false);
	_vmoveblock.push_back(_obj);

	//****레아루 좌표//
	_obj = new dirtblock;
	_obj->init(2127, 3378);
	_vdirtblock.push_back(_obj);
	_obj = new dirtblock;
	_obj->init(2387, 3249);
	_vdirtblock.push_back(_obj);
	_obj = new dirtblock;
	_obj->init(5965, 2990);
	_vdirtblock.push_back(_obj);
	_obj = new dirtblock;
	_obj->init(5965, 3118);
	_vdirtblock.push_back(_obj);
	_obj = new dirtblock;
	_obj->init(5965, 3246);
	_vdirtblock.push_back(_obj);
	_obj = new dirtblock;
	_obj->init(6602, 3250);
	_vdirtblock.push_back(_obj);
	_obj = new dirtblock;
	_obj->init(6988, 3119);
	_vdirtblock.push_back(_obj);
	_obj = new dirtblock;
	_obj->init(16332, 2476);
	_vdirtblock.push_back(_obj);
	_obj = new dirtblock;
	_obj->init(16523, 2348);
	_vdirtblock.push_back(_obj);
	_obj = new dirtblock;
	_obj->init(14796, 4702);
	_vdirtblock.push_back(_obj);
	_obj = new dirtblock;
	_obj->init(14796, 4817);
	_vdirtblock.push_back(_obj);
	_obj = new dirtblock;
	_obj->init(14796, 4965);
	_vdirtblock.push_back(_obj);
	_obj = new dirtblock;
	_obj->init(20810, 2564);
	_vdirtblock.push_back(_obj);
	_obj = new dirtblock;
	_obj->init(20938, 2564);
	_vdirtblock.push_back(_obj);
	_obj = new dirtblock;
	_obj->init(21066, 2564);
	_vdirtblock.push_back(_obj);
	_obj = new dirtblock;
	_obj->init(21194, 2564);
	_vdirtblock.push_back(_obj);
	_obj = new dirtblock;
	_obj->init(21322, 2564);
	_vdirtblock.push_back(_obj);
	_obj = new dirtblock;
	_obj->init(21450, 2564);
	_vdirtblock.push_back(_obj);
	_obj = new dirtblock;
	_obj->init(21578, 2564);
	_vdirtblock.push_back(_obj);
	_obj = new dirtblock;
	_obj->init(21706, 2564);
	_vdirtblock.push_back(_obj);
	//=====블락 끝 //
	_obj = new smalldirtblock;
	_obj->init(13259, 4712);
	_vdirtblock.push_back(_obj);
	_obj = new smalldirtblock;
	_obj->init(13317, 4712);
	_vdirtblock.push_back(_obj);
	_obj = new smalldirtblock;
	_obj->init(13375, 4712);
	_vdirtblock.push_back(_obj);
	_obj = new smalldirtblock;
	_obj->init(13433, 4712);
	_vdirtblock.push_back(_obj);
	_obj = new smalldirtblock;
	_obj->init(13491, 4712);
	_vdirtblock.push_back(_obj);
	_obj = new smalldirtblock;
	_obj->init(13549, 4712);
	_vdirtblock.push_back(_obj);

	_obj = new smalldirtblock;
	_obj->init(13259, 4770);
	_vdirtblock.push_back(_obj);
	_obj = new smalldirtblock;
	_obj->init(13317, 4770);
	_vdirtblock.push_back(_obj);
	_obj = new smalldirtblock;
	_obj->init(13375, 4770);
	_vdirtblock.push_back(_obj);
	_obj = new smalldirtblock;
	_obj->init(13433, 4770);
	_vdirtblock.push_back(_obj);
	_obj = new smalldirtblock;
	_obj->init(13491, 4770);
	_vdirtblock.push_back(_obj);
	_obj = new smalldirtblock;
	_obj->init(13549, 4770);
	_vdirtblock.push_back(_obj);

	_obj = new smalldirtblock;
	_obj->init(23117, 1329);
	_vdirtblock.push_back(_obj);
	_obj = new smalldirtblock;
	_obj->init(23117, 1387);
	_vdirtblock.push_back(_obj);
	_obj = new smalldirtblock;
	_obj->init(23117, 1445);
	_vdirtblock.push_back(_obj);
	_obj = new smalldirtblock;
	_obj->init(23117, 1503);
	_vdirtblock.push_back(_obj);
	_obj = new smalldirtblock;
	_obj->init(23117, 1561);
	_vdirtblock.push_back(_obj);

	_obj = new smalldirtblock;
	_obj->init(23175, 1329);
	_vdirtblock.push_back(_obj);
	_obj = new smalldirtblock;
	_obj->init(23175, 1387);
	_vdirtblock.push_back(_obj);
	_obj = new smalldirtblock;
	_obj->init(23175, 1445);
	_vdirtblock.push_back(_obj);
	_obj = new smalldirtblock;
	_obj->init(23175, 1503);
	_vdirtblock.push_back(_obj);
	_obj = new smalldirtblock;
	_obj->init(23175, 1561);
	_vdirtblock.push_back(_obj);

	_obj = new smalldirtblock;
	_obj->init(23233, 1329);
	_vdirtblock.push_back(_obj);
	_obj = new smalldirtblock;
	_obj->init(23233, 1387);
	_vdirtblock.push_back(_obj);
	_obj = new smalldirtblock;
	_obj->init(23233, 1445);
	_vdirtblock.push_back(_obj);
	_obj = new smalldirtblock;
	_obj->init(23233, 1503);
	_vdirtblock.push_back(_obj);
	_obj = new smalldirtblock;
	_obj->init(23233, 1561);
	_vdirtblock.push_back(_obj);

	_obj = new smalldirtblock;
	_obj->init(23291, 1329);
	_vdirtblock.push_back(_obj);
	_obj = new smalldirtblock;
	_obj->init(23291, 1387);
	_vdirtblock.push_back(_obj);
	_obj = new smalldirtblock;
	_obj->init(23291, 1445);
	_vdirtblock.push_back(_obj);
	_obj = new smalldirtblock;
	_obj->init(23291, 1503);
	_vdirtblock.push_back(_obj);
	_obj = new smalldirtblock;
	_obj->init(23291, 1561);
	_vdirtblock.push_back(_obj);

	_obj = new smalldirtblock;
	_obj->init(23349, 1329);
	_vdirtblock.push_back(_obj);
	_obj = new smalldirtblock;
	_obj->init(23349, 1387);
	_vdirtblock.push_back(_obj);
	_obj = new smalldirtblock;
	_obj->init(23349, 1445);
	_vdirtblock.push_back(_obj);
	_obj = new smalldirtblock;
	_obj->init(23349, 1503);
	_vdirtblock.push_back(_obj);
	_obj = new smalldirtblock;
	_obj->init(23349, 1561);
	_vdirtblock.push_back(_obj);

	_obj = new smalldirtblock;
	_obj->init(23407, 1329);
	_vdirtblock.push_back(_obj);
	_obj = new smalldirtblock;
	_obj->init(23407, 1387);
	_vdirtblock.push_back(_obj);
	_obj = new smalldirtblock;
	_obj->init(23407, 1445);
	_vdirtblock.push_back(_obj);
	_obj = new smalldirtblock;
	_obj->init(23407, 1503);
	_vdirtblock.push_back(_obj);
	_obj = new smalldirtblock;
	_obj->init(23407, 1561);
	_vdirtblock.push_back(_obj);
	//작은블락 배치끝
	_obj = new potion;
	_obj->init(18433, 4075);
	_vUse.push_back(_obj);
	//포션 끝.
	_obj = new bubbles;
	_obj->init(8515, 3400, 8515, 3400, 90);
	_vbubble.push_back(_obj);

	_obj = new bubbles;
	_obj->init(16500, 4982, 16500, 4982, 90);
	_vbubble.push_back(_obj);

	_obj = new bubbles;
	_obj->init(17817, 4111, 17817, 4111, 90);
	_vbubble.push_back(_obj);

	_obj = new bubbles;
	_obj->init(18089, 4111, 18089, 4111, 90);
	_vbubble.push_back(_obj);

	_obj = new bubbles;
	_obj->init(18767, 4111, 18767, 4111, 90);
	_vbubble.push_back(_obj);

	_obj = new bubbles;
	_obj->init(18957, 4111, 18957, 4111, 90);
	_vbubble.push_back(_obj);

	_obj = new bubbles;
	_obj->init(19132, 4111, 19132, 4111, 90);
	_vbubble.push_back(_obj);

	_obj = new bubbles;
	_obj->init(21241, 793, 21241, 793, 90);
	_vbubble.push_back(_obj);

	_obj = new bubbles;
	_obj->init(21047, 793, 21047, 793, 90);
	_vbubble.push_back(_obj);

	//버블 배치 끝;
	_obj = new moveblock;
	_obj->init(8200, 2284, 500, false, true, false);
	_vmoveblock.push_back(_obj);

	_obj = new moveblock;
	_obj->init(10000, 2667, 350, false, true, false);
	_vmoveblock.push_back(_obj);

	_obj = new moveblock;
	_obj->init(16462, 4005, 350, false, true, false);
	_vmoveblock.push_back(_obj);

	_obj = new moveblock;
	_obj->init(16012, 3930, 330, false, true, true);
	_vmoveblock.push_back(_obj);

	_obj = new moveblock;
	_obj->init(19788, 2168, 400, false, true, true);
	_vmoveblock.push_back(_obj);
	//발판 끝
	_obj = new musicsheet;
	_obj->init(9547, 4917);
	_vsheet.push_back(_obj);
	_obj = new musicsheet;
	_obj->init(19447, 3949);
	_vsheet.push_back(_obj);
	//음악 끝

	_obj = new platters;
	_obj->init(4395, 3105);
	_vplatter.push_back(_obj);

	_obj = new platters;
	_obj->init(24530, 610);
	_vplatter.push_back(_obj);
	//
	_obj = new fakedirt;
	_obj->init(11535, 4138, 523);
	_vfakedirt.push_back(_obj);

	_obj = new fakedirt;
	_obj->init(16311, 3175, 700);
	_vfakedirt.push_back(_obj);
}

void objectManager::player_object_collision()
{
	LPCOLLISION_INFO tempInfo;


	for (int i = 0; i < _vdirtpile.size(); i++)
	{
		_leftX = _vdirtpile[i]->getX();
		_topY = _vdirtpile[i]->getY();

		//dirty는 충돌시 플레이어에 영향을 주지 않으므로 pass
			RECT temp;
			if(IntersectRect(&temp, _p->getPlayerAttackRect(), &_vdirtpile[i]->_rc))
			{
				tempInfo = new COLLISION_INFO;
				tempInfo->_colType = COL_OBJECT;
				tempInfo->object = _vdirtpile[i];
				tempInfo->index_detail = DIRTPILE;
				tempInfo->_isPlayer = false;
				_p->getColMessage(tempInfo);

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
				//충돌메시지 작성
				tempInfo = new COLLISION_INFO;
				tempInfo->_colType = COL_OBJECT;
				//tempInfo->index_detail = --- 세부번호
				tempInfo->object = _vgem[i];
				tempInfo->index_detail = GEM;
				_p->getColMessage(tempInfo);

				EFFECTMANAGER->play("보석", _vgem[i]->_leftX,_vgem[i]->_topY);
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
	
	//포션, food , meal
	for (int i = 0; i < _vUse.size(); i++)
	{
		RECT temp;
		if (IntersectRect(&temp, _p->getPlayerRect(), &_vUse[i]->_rc) && _vUse[i]->_type == TYPE_POTION)
		{
			tempInfo = new COLLISION_INFO;
			tempInfo->_colType = COL_OBJECT;
			tempInfo->object = _vUse[i];
			tempInfo->index_detail = POTION;
			_p->getColMessage(tempInfo);
			_vUse.erase(_vUse.begin() + i);
		}

		else if (IntersectRect(&temp, _p->getPlayerRect(), &_vUse[i]->_rc) && _vUse[i]->_type == TYPE_FOOD)
		{
			tempInfo = new COLLISION_INFO;
			tempInfo->_colType = COL_OBJECT;
			tempInfo->object = _vUse[i];
			tempInfo->index_detail = FOOD;
			_p->getColMessage(tempInfo);
			_istouched = true;
			_tempx = _vUse[i]->_leftX;
			_tempy = _vUse[i]->_topY;
			_vUse.erase(_vUse.begin() + i);
		}

		else if (IntersectRect(&temp, _p->getPlayerRect(), &_vUse[i]->_rc) && _vUse[i]->_type == TYPE_MEAL)
		{
			tempInfo = new COLLISION_INFO;
			tempInfo->_colType = COL_OBJECT;
			tempInfo->object = _vUse[i];
			tempInfo->index_detail = MEAL;
			_p->getColMessage(tempInfo);
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
			tempInfo = new COLLISION_INFO;
			tempInfo->_colType = COL_OBJECT;
			tempInfo->object = _vdirtblock[i];
			tempInfo->index_detail = DIRTBLOCK;
			
			_p->getColMessage(tempInfo);
		}
	}
	for (int i = 0; i<_vdirtblock.size(); i++)
	{
		RECT temp;
		if (IntersectRect(&temp, _p->getPlayerAttackRect(), &_vdirtblock[i]->_rc))
		{
			if(_vdirtblock[i]->_type == TYPE_BLOCK)EFFECTMANAGER->play("블록",_vdirtblock[i]->_leftX - 30 , _vdirtblock[i]->_topY - 15);

			else if (_vdirtblock[i]->_type == TYPE_SMALL_BLOCK)EFFECTMANAGER->play("작은블록", _vdirtblock[i]->_leftX - 30, _vdirtblock[i]->_topY - 15);
			tempInfo = new COLLISION_INFO;
			tempInfo->_colType = COL_OBJECT;
			tempInfo->object = _vdirtblock[i];
			tempInfo->index_detail = DIRTBLOCK;
			tempInfo->_isPlayer = false;
			_p->getColMessage(tempInfo);
			_vdirtblock.erase(_vdirtblock.begin() + i);
		}
	}

	for (int i = 0; i < _vbubble.size(); i++)
	{
		RECT temp;
		if (IntersectRect(&temp, _p->getPlayerAttackRect(), &_vbubble[i]->_rc))
		{
			
			addY = 200;
			_rangeCount = 200;
			_obj = new bubbles;
			_obj->init(_vbubble[i]->_leftX , _vbubble[i]->_topY + addY, _vbubble[i]->_leftX, _vbubble[i]->_topY + addY, _rangeCount);
			_vbubble.push_back(_obj);

			tempInfo = new COLLISION_INFO;
			tempInfo->_colType = COL_OBJECT;
			tempInfo->object = _vbubble[i];
			tempInfo->index_detail = BUBBLE;
			tempInfo->_isPlayer = false;
			_p->getColMessage(tempInfo);
			EFFECTMANAGER->play("버블", _vbubble[i]->_leftX, _vbubble[i]->_topY);
			_vbubble.erase(_vbubble.begin() + i);

		}
	}

	for (int i = 0; i < _vplatter.size(); i++) //접시는 충돌시 플레이어와 영향이 없음.
	{
		RECT temp;
		if (IntersectRect(&temp, _p->getPlayerAttackRect(), &_vplatter[i]->_rc))
		{
			_x = _vplatter[i]->_leftX + 10;
			_y = _vplatter[i]->_topY + 10;
			tempInfo = new COLLISION_INFO;
			tempInfo->_colType = COL_OBJECT;
			tempInfo->object = _vplatter[i];
			tempInfo->index_detail = PLATTER;
			tempInfo->_isPlayer = false;
			_p->getColMessage(tempInfo);
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
	

	for (int i = 0; i < _vfakedirt.size(); i++) //가짜 벽은 충돌시 플레이어에게 주는 영향이 없음.
	{
		RECT temp;
		if (IntersectRect(&temp,_p->getPlayerAttackRect(), &_vfakedirt[i]->_rc))
		{
			tempInfo = new COLLISION_INFO;
			tempInfo->_colType = COL_OBJECT;
			tempInfo->object = _vfakedirt[i];
			tempInfo->index_detail = PLATTER;
			tempInfo->_isPlayer = false;
			_p->getColMessage(tempInfo);
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
			tempInfo = new COLLISION_INFO;
			tempInfo->_colType = COL_OBJECT;
			tempInfo->object = _vsheet[i];
			tempInfo->index_detail = MUSIC_SHEET;
			_p->getColMessage(tempInfo);
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
			tempInfo = new COLLISION_INFO;
			tempInfo->_colType = COL_OBJECT;
			tempInfo->object = _vmoveblock[i];
			tempInfo->index_detail = MOVING_PILE;
			_p->getColMessage(tempInfo);
		}
	}
	_count++;
	if (_iscrush)
	{
		EFFECTMANAGER->stretchplay("블록", x, y,IMAGEMANAGER->findImage("leftfakehead")->getWidth(),0,8,false);
		if (_count % 50 == 0)
		{
			_iscrush = false;
			_count = 0;
		}
	}

	if (_istouched)
	{
		EFFECTMANAGER->stretchplay("보석", _tempx, _tempy, IMAGEMANAGER->findImage("sparkle")->getWidth(), IMAGEMANAGER->findImage("sparkle")->getHeight(), 58, true);
		if (_count % 50 == 0)
		{
			_istouched = false;
			_count = 0;
		}
	}

	//충돌메시지 반환 -> 플레이어에 넘겨주면 플레이어가 _colType과 index_detail을 가지고 판단, 처리
	
	
}
