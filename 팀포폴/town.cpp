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
	backsideimg = IMAGEMANAGER->findImage("backsideimg");
	_NPCM = new NPCManager;								//
	_NPCM->init();
	
	_NPCM->setLeftNpc(false);
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
	if (KEYMANAGER->isOnceKeyDown(VK_F1)) {
		_isvisible = true;
	}
	if (KEYMANAGER->isOnceKeyDown(VK_F2)) {
		_isvisible = false;
	}
	

}

void town::render()
{
	
	
	if (!_isvisible) {
		
		townPix->render(getMemDC(),0, 0, CAMERAMANAGER->getCameraPoint().x, CAMERAMANAGER->getCameraPoint().y, WINSIZEX, WINSIZEY);
		backsideimg->render(getMemDC(), 0, 0, CAMERAMANAGER->getCameraPoint().x, CAMERAMANAGER->getCameraPoint().y, WINSIZEX, WINSIZEY);
		townimage->render(getMemDC(),0,0,CAMERAMANAGER->getCameraPoint().x,CAMERAMANAGER->getCameraPoint().y, WINSIZEX, WINSIZEY);
	}
	else {
		Rectangle(getMemDC(), _table.left, _table.top, _table.right, _table.bottom);
		//townPix->render(getMemDC(), 0, 0, CAMERAMANAGER->getCameraPoint().x, CAMERAMANAGER->getCameraPoint().y, WINSIZEX, WINSIZEY);
	}
	_NPCM->render();
	//TextOut(getMemDC(), 50, 50, str, strlen(str));
}

