#include "stdafx.h"
#include "town.h"
#include "player.h"
#include "ui.h"
#include "objectManager.h"


town::town()
{
}


town::~town()
{
}

HRESULT town::init()
{
	//./image/town/goatician_test

	townimage = IMAGEMANAGER->findImage("town");		//마을 이미지
	townPix = IMAGEMANAGER->findImage("townPix");		//마을 픽셀이미지
	backsideimg = IMAGEMANAGER->findImage("backsideimg");
	_NPCM = new NPCManager;								//
	_NPCM->init();

	CAMERAMANAGER->setBackground(8137, 900);
	CAMERAMANAGER->setStartBackground(0, 0);
	_rc = RectMake(WINSIZEX / 2, 400, 50, 50);
	CAMERAMANAGER->setCameraCondition(false, CAMERA_AIMING);
	CAMERAMANAGER->setCameraCondition(true, CAMERA_AIMING);
	CAMERAMANAGER->setCameraAim(_player->getPlayerRect());

	_player->setPlayerX(500);
	_player->setPlayerY(800);

	_objectManager = new objectManager;
	_objectManager->connectPlayer(_player);
	_objectManager->init();

	_NPCM->setLeftNpc(false);
	_NPCM->setNpc();
	_NPCM->connectPlayer(_player);
	_ui = new ui;
	_ui->init(UI_STAGE);

	_table = RectMake(2770, 530, 260, 20);				//테이블 렉트
	_isvisible = false;
	return S_OK;
}

void town::release()
{
}

void town::update()
{
	
	
	if (KEYMANAGER->isOnceKeyDown(VK_F1)) {
		_isvisible = true;
	}
	if (KEYMANAGER->isOnceKeyDown(VK_F2)) {
		_isvisible = false;
	}
	
	/*if (KEYMANAGER->isStayKeyDown(VK_RIGHT))
	{
		_rc.left += 15;
		_rc.right += 15;
	}
	if (KEYMANAGER->isStayKeyDown(VK_LEFT))
	{
		_rc.left -= 15;
		_rc.right -= 15;
	}
	if (KEYMANAGER->isStayKeyDown(VK_DOWN))
	{
		_rc.top += 15;
		_rc.bottom += 15;
	}
	if (KEYMANAGER->isStayKeyDown(VK_UP))
	{
		_rc.top -= 15;
		_rc.bottom -= 15;
	}*/
	
	_player->update();
	_NPCM->update();
	_objectManager->update();

	_ui->update();

	pixelCollison();

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
	_ui->render();
	_NPCM->render();
	_player->render();

	_objectManager->render();

	RectangleMake(getMemDC(), CAMERAMANAGER->CameraRelativePointX(_rc.left), CAMERAMANAGER->CameraRelativePointY(_rc.top), 50, 50);
	
}

void town::pixelCollison()
{
	COLORREF color;
	int r, g, b;

	// 머리 충돌판정
	if (_player->getJumpPower() > 0)
	{
		_player->setProbeY(_player->getPlayerRect()->top);

		color = GetPixel(townPix->getMemDC(), _player->getPlayerRect()->left , _player->getPlayerRect()->top);

		r = GetRValue(color);
		g = GetGValue(color);
		b = GetBValue(color);

		//	if ()
	}

	else if (_player->getJumpPower() <= 0)
	{
		_player->setProbeY(_player->getPlayerRect()->bottom);
		bool k = false;
		int a = 0;
		int b = 0;
		bool istop = false;
		for (int i = _player->getprobeY() + 30; i > _player->getprobeY() - 30; --i)
		{
			color = GetPixel(townPix->getMemDC(), (_player->getPlayerRect()->left + _player->getPlayerRect()->right) / 2 , i);

			r = GetRValue(color);
			g = GetGValue(color);
			b = GetBValue(color);


			if (r == 0 && g == 255 && b == 0)
			{
				k = true;
				_player->setPlayerY(i - getHeight(*_player->getPlayerRect()) / 2);
				a++;
			}
		}
		if (k)
		{
			_player->setIsJump(false);
			_player->setIsLand(true);
		}
		else
		{
			_player->setIsJump(true);
			_player->setIsLand(false);
		}


	}
}

