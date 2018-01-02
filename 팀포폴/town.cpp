#include "stdafx.h"
#include "town.h"


town::town()
{
}


town::~town()
{
}

HRESULT town::init()
{
	townimage = IMAGEMANAGER->findImage("town");		//���� �̹���
	townPix = IMAGEMANAGER->findImage("townPix");		//���� �ȼ��̹���
	_NPCM = new NPCManager;								//
	_NPCM->init();
	_NPCM->setNpc();
	_table = RectMake(2770, 530, 260, 20);				//���̺� ��Ʈ
	_isvisible = false;
	return S_OK;
}

void town::release()
{
}

void town::update()
{
	_NPCM->update();
}

void town::render()
{
	if (KEYMANAGER->isToggleKey('F1')) {
		_isvisible = true;
	}
	if (!_isvisible) {
		townPix->render(getMemDC());
		townimage->render(getMemDC());
	}
	else {
		Rectangle(getMemDC(), _table.left, _table.top, _table.right, _table.bottom);
		townPix->render(getMemDC());
	}
	_NPCM->render();
}

void town::collision()
{
	RECT temp;								//�浹�� ���� ��Ʈ

	for (int i = 0; i<_NPCM->getVnpc().max_size(); i++)
	{
		//Ź�ڿ� �÷��̾� if (IntersectRect(&temp,&_NPCM->getVnpc()[i]->getimgRC(),//�÷��̾� ��Ʈ)) {

		//}

		//NPC�� �÷��̾� if (IntersectRect(&temp,&_NPCM->getVnpc()[i]->getimgRC(),//�÷��̾� ��Ʈ)) {
		//	_NPCM->getVnpc()[i]->Converstion()
		//}
	}
}
