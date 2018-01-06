#include "stdafx.h"
#include "NPCManager.h"


NPCManager::NPCManager()
{
}


NPCManager::~NPCManager()
{
}

HRESULT NPCManager::init()
{
	a = 0;
	
	
	return S_OK;
}

void NPCManager::release()
{
}

void NPCManager::update()
{
	for (_viNPC = _vNPC.begin(); _viNPC != _vNPC.end(); )
	{
		(*_viNPC)->update();
		++_viNPC;
	}


	_p->update();
	//collision();
	player_npc_collision();
	
}

void NPCManager::render()
{
	for (_viNPC = _vNPC.begin(); _viNPC != _vNPC.end(); ++_viNPC)
	{
		(*_viNPC)->render();

	}
	//TextOut(getMemDC(), 50, 350, str, strlen(str));
}

void NPCManager::setNpc()
{
	NPC* watergirl;
	watergirl = new waterGirl;
	watergirl->init("watergirl","" ,PointMake(6400, 650), "./text/NPC/waterGirl.txt", "..", true, false, false, false);
	
	NPC* bard;
	bard = new Bard;
	bard->init("bardnomal","", PointMake(1865, 650), "./text/NPC/bard.txt", "./text/NPC/bard1-1.txt", false, false, true, false);

	NPC* molly;
	molly = new Molly;
	molly->init("����","" ,PointMake(2330, 650), "./text/NPC/����.txt", "..", true, false, false, false);

	NPC* gote;
	gote = new goatician;
	gote->init("����", "", PointMake(3170, 650), "./text/NPC/goatician.txt","./text/NPC/goatician2.txt", false, false, true, true);

	NPC* _wizard;
	_wizard = new Wizard;
	_wizard->init("������", "", PointMake(3710, 365), "./text/NPC/���ڵ�.txt", "./text/NPC/���ڵ�1.txt", false, false, true, true);

	NPC* _cooker;
	_cooker = new Sepp;
	_cooker->init("�丮��", "������", PointMake(2970,280), "./text/NPC/�丮��.txt", "./text/NPC/�丮��1.txt", false, false, true, false);

	NPC* _famer;
	_famer = new hedgeFarmer;
	_famer->init("hedgeFarmer", "" ,PointMake(5450, 650), "...","...", false, false,false,false);

	NPC* _gard;
	_gard = new gard;
	_gard->init("guard", "", PointMake(300, 650), "./text/NPC/gard.txt", "./text/NPC/gard1.txt", false, false, true, false);

	NPC* _crown;
	_crown = new Crown;
	_crown->init("����", "", PointMake(3470, 750), "./text/NPC/Merchant.txt", "./text/NPC/Merchant1.txt", false, false, true, true);
	
	_vNPC.push_back(watergirl);
	_vNPC.push_back(bard);
	_vNPC.push_back(molly);
	_vNPC.push_back(gote);
	_vNPC.push_back(_wizard);
	_vNPC.push_back(_cooker);
	_vNPC.push_back(_famer);
	_vNPC.push_back(_gard);
	_vNPC.push_back(_crown);

}

void NPCManager::setLeftNpc(bool _isRight)
{
	NPC* _bagFella;
	_bagFella = new bagFella;
	_bagFella->init("���� ����", "", PointMake(100, WINSIZEY - 250), "./text/NPC/����.txt", "..", true, _isRight, false, false );

	_vNPC.push_back(_bagFella);

}

void NPCManager::setRightNpc(bool _isRight)
{
	NPC* _deerlady;
	_deerlady = new maiden;
	_deerlady->init("deerLadyMove", "", PointMake(100, WINSIZEY - 330), "./text/NPC/�罿����.txt", "..", true, _isRight, false, false);

	_vNPC.push_back(_deerlady);
}


void NPCManager::removeNpc(int arrNum)
{
	SAFE_DELETE(_vNPC[arrNum]);
	_vNPC.erase(_vNPC.begin() + arrNum);
}

void NPCManager::collision()
{
	
	
	RECT temp;

	for (_viNPC = _vNPC.begin(); _viNPC != _vNPC.end();++_viNPC )
	{
		if (IntersectRect(&temp ,&(*_viNPC)->getimgRC(), &rc))
		{
			
			if (!(*_viNPC)->getisTolk()) 
			{
				if (KEYMANAGER->isOnceKeyDown(VK_UP)) 
				{
					(*_viNPC)->setisTolk(true);
					sprintf(str, "a : %d", a);
				}
			}
			if ((*_viNPC)->getisTolk()) {
				a++;
				(*_viNPC)->Converstion(a);
			}
			if (!(*_viNPC)->getisTolk()) {
				a = 0;
				
			}
		
			if (KEYMANAGER->isOnceKeyDown('X'))
			{
				(*_viNPC)->setcoversationCount(1);
				if ((*_viNPC)->getcoversationCount() == 1) {
					a = 0;
				}
				if (!(*_viNPC)->getisSaller())
				{
					if ((*_viNPC)->getcoversationCount() == 2) {
						(*_viNPC)->setisTolk(false);
						(*_viNPC)->setcoversationCount(-2);
					}
				}
			
			}
			if (KEYMANAGER->isOnceKeyDown('Z'))
			{
				if (!(*_viNPC)->getisTiket())(*_viNPC)->setisgetTiket(true);
				if(!(*_viNPC)->getisfirelod())(*_viNPC)->setisfirelod(true);
			}
			if (a >= (*_viNPC)->gettxtSizeMax()) {
				a = (*_viNPC)->gettxtSizeMax();
			}
		
		}
		else
		{
			(*_viNPC)->setisTolk(false);
			
		}

	}
}

LPCOLLISION_INFO NPCManager::player_npc_collision()
{
	LPCOLLISION_INFO tempInfo = new COLLISION_INFO;
	for (int i =0 ; i< _vNPC.size();i++)
	{
		RECT temp;
		if (IntersectRect(&temp, &_vNPC[i]->getimgRC(), _p->getPlayerRect()))
		{
			//�浹�޽��� �ۼ�
			tempInfo->_colType = COL_NPC;
			//tempInfo->index_detail = --- ���ι�ȣ
			if (!_vNPC[i]->getisTolk())
			{
				if (KEYMANAGER->isOnceKeyDown('Q'))
				{
					_vNPC[i]->setisTolk(true);
					
				}
			}
			if (_vNPC[i]->getisTolk()) {
				a++;
				_vNPC[i]->Converstion(a);
			}
			if (!_vNPC[i]->getisTolk()) {
				a = 0;

			}

			if (KEYMANAGER->isOnceKeyDown('X'))
			{
				_vNPC[i]->setcoversationCount(1);
				if (_vNPC[i]->getcoversationCount() == 1) {
					a = 0;
				}
				if (!_vNPC[i]->getisSaller())
				{
					if (_vNPC[i]->getcoversationCount() == 2) {
						_vNPC[i]->setisTolk(false);
						_vNPC[i]->setcoversationCount(-2);
					}
				}

			}
			if (KEYMANAGER->isOnceKeyDown('Z'))
			{
				if (!_vNPC[i]->getisTiket())(*_viNPC)->setisgetTiket(true);
				if (!_vNPC[i]->getisfirelod())(*_viNPC)->setisfirelod(true);
			}
			if (a >= _vNPC[i]->gettxtSizeMax()) {
				a = _vNPC[i]->gettxtSizeMax();
			}

		}
		else
		{
			_vNPC[i]->setisTolk(false);

		}
		
	}
	//�浹�޽��� ��ȯ -> �÷��̾ �Ѱ��ָ� �÷��̾ _colType�� index_detail�� ������ �Ǵ�, ó��
	if (tempInfo->_colType != COL_NONE)
		return tempInfo;
	else return NULL;
}

