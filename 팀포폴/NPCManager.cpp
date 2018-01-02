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
	watergirl->init("watergirl", PointMake(50, WINSIZEY - 200), "./text/NPC/waterGirl.txt",PointMake(100,100),PointMake(100, 100),false);
	NPC* bard;
	bard = new Bard;
	bard->init("bardfun", PointMake(100, WINSIZEY - 330), "./text/NPC/bard.txt", PointMake(100, 100), PointMake(100, 100), false);

	NPC* molly;
	molly = new Molly;
	molly->init("����", PointMake(300, WINSIZEY - 330), "./text/NPC/����.txt", PointMake(100, 100), PointMake(100, 100), false);

	NPC* gote;
	gote = new Merchant;
	gote->init("����", PointMake(450, WINSIZEY - 330), "./text/NPC/goatician.txt", PointMake(100, 100), PointMake(100, 100), false);

	NPC* _wizard;
	_wizard = new Wizard;
	_wizard->init("������", PointMake(450, WINSIZEY - 330), "./text/NPC/���ڵ�.txt", PointMake(100, 100), PointMake(100, 100), false);

	NPC* _cooker;
	_cooker = new Sepp;
	_cooker->init("�丮��", PointMake(450, WINSIZEY - 330), "./text/NPC/�丮��.txt", PointMake(100, 100), PointMake(100, 100), false);

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
	_bagFella->init("bagFellaMove",PointMake(300, WINSIZEY - 330), "./text/NPC/����.txt", PointMake(100, 100), PointMake(100, 100), _isRight);

	_vNPC.push_back(_bagFella);

}

void NPCManager::setRightNpc(bool _isRight)
{
	NPC* _deerlady;
	_deerlady = new maiden;
	_deerlady->init("deerLadyMove", PointMake(300, WINSIZEY - 330), "./text/NPC/�罿����.txt", PointMake(100, 100), PointMake(100, 100), _isRight);

	_vNPC.push_back(_deerlady);
}


void NPCManager::removeNpc(int arrNum)
{
	SAFE_DELETE(_vNPC[arrNum]);
	_vNPC.erase(_vNPC.begin() + arrNum);
}

