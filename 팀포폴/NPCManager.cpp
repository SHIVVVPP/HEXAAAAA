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
	//TextOut(getMemDC(), 50, 50, str, strlen(str));
}

void NPCManager::setNpc()
{
	NPC* watergirl;
	watergirl = new waterGirl;
	watergirl->init("watergirl", PointMake(6400, 650), "./text/NPC/waterGirl.txt", "..", true, false, false, false);
	
	NPC* bard;
	bard = new Bard;
	bard->init("bardnomal", PointMake(1865, 650), "./text/NPC/bard.txt", "./text/NPC/bard1-1.txt", true, false, true, false);

	NPC* molly;
	molly = new Molly;
	molly->init("¸ô¸®", PointMake(2330, 650), "./text/NPC/¸ô¸®.txt", "..", true, false, false, false);

	NPC* gote;
	gote = new Merchant;
	gote->init("¿°¼Ò", PointMake(3170, 650), "./text/NPC/goatician.txt","./text/NPC/goatician2.txt", true, false, true, true);

	NPC* _wizard;
	_wizard = new Wizard;
	_wizard->init("¸¶¹ı»ç", PointMake(3710, 365), "./text/NPC/À§ÀÚµå.txt", "./text/NPC/À§ÀÚµå1.txt", true, false, true, true);

	NPC* _cooker;
	_cooker = new Sepp;
	_cooker->init("¿ä¸®»ç", PointMake(2935,	280), "./text/NPC/¿ä¸®»ç.txt", "./text/NPC/¿ä¸®»ç1.txt", true, false, true, false);

	NPC* _famer;
	_famer = new hedgeFarmer;
	_famer->init("hedgeFarmer", PointMake(5450, 650), "...","...", false, false,false,false);

	NPC* _gard;
	_gard = new gard;
	_gard->init("guard", PointMake(300, 650), "./text/NPC/gard.txt", "./text/NPC/gard1.txt", true, false, true, false);

	NPC* _crown;
	_crown = new Crown;
	_crown->init("±¤´ë", PointMake(3710, 650), "./text/NPC/Merchant.txt", "./text/NPC/Merchant1.txt", true, false, true, true);
	
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
	_bagFella->init("Áüµç ³²ÀÚ",PointMake(100, WINSIZEY - 250), "./text/NPC/Áü²Û.txt", "..", true, _isRight, false, false );

	_vNPC.push_back(_bagFella);

}

void NPCManager::setRightNpc(bool _isRight)
{
	NPC* _deerlady;
	_deerlady = new maiden;
	_deerlady->init("deerLadyMove", PointMake(100, WINSIZEY - 330), "./text/NPC/»ç½¿¿©ÀÎ.txt", "..", true, _isRight, false, false);

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
			a++;
			(*_viNPC)->Converstion(a);
			if (KEYMANAGER->isOnceKeyDown('X')) {
				(*_viNPC)->setcoversationCount(1);
				a = 0;
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

