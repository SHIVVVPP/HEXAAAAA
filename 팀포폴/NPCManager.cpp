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
	
	collision();

}

void NPCManager::render()
{
	for (_viNPC = _vNPC.begin(); _viNPC != _vNPC.end(); ++_viNPC)
	{
		(*_viNPC)->render();

	}
	TextOut(getMemDC(), 50, 350, str, strlen(str));
}

void NPCManager::setNpc()
{
	NPC* watergirl;
	watergirl = new waterGirl;
	watergirl->init("watergirl", PointMake(6400, 650), "./text/NPC/waterGirl.txt", "..", true, false, false, false);
	
	NPC* bard;
	bard = new Bard;
	bard->init("bardnomal", PointMake(1865, 650), "./text/NPC/bard.txt", "./text/NPC/bard1-1.txt", false, false, true, false);

	NPC* molly;
	molly = new Molly;
	molly->init("����", PointMake(2330, 650), "./text/NPC/����.txt", "..", true, false, false, false);

	NPC* gote;
	gote = new Merchant;
	gote->init("����", PointMake(3170, 650), "./text/NPC/goatician.txt","./text/NPC/goatician2.txt", false, false, true, true);

	NPC* _wizard;
	_wizard = new Wizard;
	_wizard->init("������", PointMake(3710, 365), "./text/NPC/���ڵ�.txt", "./text/NPC/���ڵ�1.txt", false, false, true, true);

	NPC* _cooker;
	_cooker = new Sepp;
	_cooker->init("�丮��", PointMake(2935,	280), "./text/NPC/�丮��.txt", "./text/NPC/�丮��1.txt", false, false, true, false);

	NPC* _famer;
	_famer = new hedgeFarmer;
	_famer->init("hedgeFarmer", PointMake(5450, 650), "...","...", false, false,false,false);

	NPC* _gard;
	_gard = new gard;
	_gard->init("guard", PointMake(300, 650), "./text/NPC/gard.txt", "./text/NPC/gard1.txt", false, false, true, false);

	NPC* _crown;
	_crown = new Crown;
	_crown->init("����", PointMake(50, 700), "./text/NPC/Merchant.txt", "./text/NPC/Merchant1.txt", false, false, true, true);
	
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
	_bagFella->init("���� ����",PointMake(100, WINSIZEY - 250), "./text/NPC/����.txt", "..", true, _isRight, false, false );

	//_vNPC.push_back(_bagFella);

}

void NPCManager::setRightNpc(bool _isRight)
{
	NPC* _deerlady;
	_deerlady = new maiden;
	_deerlady->init("deerLadyMove", PointMake(100, WINSIZEY - 330), "./text/NPC/�罿����.txt", "..", true, _isRight, false, false);

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
		if (IntersectRect(&temp ,&(*_viNPC)->getimgRC(), &RectMake(_ptMouse.x,_ptMouse.y,50,50)))
		{
			
			if (KEYMANAGER->isOnceKeyDown(VK_UP)) {
			
				(*_viNPC)->setisTolk(true);
			}
			if ((*_viNPC)->getisTolk()) {
				a++;
				(*_viNPC)->Converstion(a);
			}
			if (!(*_viNPC)->getisTolk()) {
				a = 0;
				
			}
			sprintf(str, "a : %d", a);
			if (KEYMANAGER->isOnceKeyDown('X'))
			{
				(*_viNPC)->setcoversationCount(1);
			
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

