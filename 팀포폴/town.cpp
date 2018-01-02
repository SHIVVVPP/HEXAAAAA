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
	townimage = IMAGEMANAGER->findImage("town");		//마을 이미지
	townPix = IMAGEMANAGER->findImage("townPix");		//마을 픽셀이미지
	_NPCM = new NPCManager;								//
	_NPCM->init();
	_NPCM->setNpc();
	_table = RectMake(2770, 530, 260, 20);				//테이블 렉트
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
	RECT temp;								//충돌을 위한 렉트

	for (int i = 0; i<_NPCM->getVnpc().max_size(); i++)
	{
		//탁자와 플레이어 if (IntersectRect(&temp,&_NPCM->getVnpc()[i]->getimgRC(),//플레이어 렉트)) {

		//}

		//NPC와 플레이어 if (IntersectRect(&temp,&_NPCM->getVnpc()[i]->getimgRC(),//플레이어 렉트)) {
		//	_NPCM->getVnpc()[i]->Converstion()
		//}
	}
}
