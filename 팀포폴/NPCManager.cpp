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
// npcÀÇ ¹«´ë°ª;
	/*for (int i = 0; i < _vNPC.max_size(); i++) {
		if ((*_viNPC)->getisMove()) 
		{
			if ((*_viNPC)->getisRight()) 
			{
				if ((*_viNPC)->getimgRC().left > 8137) 
				{
					removeNpc(i);
				}
			}
			else {
				if ((*_viNPC)->getimgRC().left > 2530) 
				{
					removeNpc(i);
				}
			}
		}
	}*/
}

void NPCManager::render()
{
	for (_viNPC = _vNPC.begin(); _viNPC != _vNPC.end(); ++_viNPC)
	{
		(*_viNPC)->render();

	}
}

void NPCManager::setNpc()
{
	NPC* watergirl;
	watergirl = new waterGirl;
	watergirl->init("watergirl", PointMake(6400, WINSIZEY - 250), "./text/NPC/waterGirl.txt",PointMake(WINSIZEX,100),PointMake(WINSIZEX, 100),false,false);
	NPC* bard;
	bard = new Bard;
	bard->init("bardfun", PointMake(1865, WINSIZEY - 250), "./text/NPC/bard.txt", PointMake(WINSIZEX, 100), PointMake(WINSIZEX, 100), false, false);

	NPC* molly;
	molly = new Molly;
	molly->init("¸ô¸®", PointMake(2430, WINSIZEY - 250), "./text/NPC/¸ô¸®.txt", PointMake(WINSIZEX, 100), PointMake(WINSIZEX, 100), false, false);

	NPC* gote;
	gote = new Merchant;
	gote->init("¿°¼Ò", PointMake(3170, WINSIZEY - 250), "./text/NPC/goatician.txt", PointMake(WINSIZEX, 100), PointMake(WINSIZEX, 100), false, false);

	NPC* _wizard;
	_wizard = new Wizard;
	_wizard->init("¸¶¹ý»ç", PointMake(3710, WINSIZEY - 535), "./text/NPC/À§ÀÚµå.txt", PointMake(WINSIZEX, 100), PointMake(WINSIZEX, 100), false, false);

	NPC* _cooker;
	_cooker = new Sepp;
	_cooker->init("¿ä¸®»ç", PointMake(2935, WINSIZEY - 610), "./text/NPC/¿ä¸®»ç.txt", PointMake(WINSIZEX, 100), PointMake(WINSIZEX, 100), false, false);

	_vNPC.push_back(watergirl);
	_vNPC.push_back(bard);
	_vNPC.push_back(molly);
	_vNPC.push_back(gote);
	_vNPC.push_back(_wizard);
	_vNPC.push_back(_cooker);

}

void NPCManager::setLeftNpc(bool _isRight)
{
	NPC* _bagFella;
	_bagFella = new bagFella;
	_bagFella->init("Áüµç ³²ÀÚ",PointMake(100, WINSIZEY - 250), "./text/NPC/Áü²Û.txt", PointMake(600, 100), PointMake(600, 100), true , _isRight);

	_vNPC.push_back(_bagFella);

}

void NPCManager::setRightNpc(bool _isRight)
{
	NPC* _deerlady;
	_deerlady = new maiden;
	_deerlady->init("deerLadyMove", PointMake(100, WINSIZEY - 330), "./text/NPC/»ç½¿¿©ÀÎ.txt", PointMake(100, 100), PointMake(100, 100), true,_isRight);

	_vNPC.push_back(_deerlady);
}


void NPCManager::removeNpc(int arrNum)
{
	SAFE_DELETE(_vNPC[arrNum]);
	_vNPC.erase(_vNPC.begin() + arrNum);
}

