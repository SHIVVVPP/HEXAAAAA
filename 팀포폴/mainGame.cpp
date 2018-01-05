#include "stdafx.h"
#include "mainGame.h"

#define CRTDBG_MAP_ALLOC 
#include <stdlib.h>
#include <crtdbg.h>
#ifdef _DEBUG

#define new new( _NORMAL_BLOCK, __FILE__, __LINE__ )   // #include <new.h>������ operator new�� malloc�� 

// Derived�ؼ� ���� �� ���, ��� �� �� ����.

#endif

mainGame::mainGame()
{
}

mainGame::~mainGame()
{
}

HRESULT mainGame::init()			//�ʱ�ȭ �Լ�
{
	gameNode::init(true);
	setImages();

	/*

	_player = new player;
	_player->init();*/

	//_player = new player;
	//_player->init();

	//sys = new system_option;
	//sys->init();

	//SCENEMANAGER->addScene("��������", new stage);
	//SCENEMANAGER->changeScene("��������", _player);
	//SCENEMANAGER->addScene("�κ��丮", new inventory);
	//

	//_ui = new ui;
	//_ui->init(UI_STAGE);
	//CAMERAMANAGER->setBackground(8137, 900);
	//CAMERAMANAGER->setStartBackground(0, 0);
   
	//_town = new town;
	//_town->init();
	
	//rc = RectMake(WINSIZEX / 2, WINSIZEY/2, 50, 50);
	//CAMERAMANAGER->setCameraCondition(false, CAMERA_AIMING);
	//CAMERAMANAGER->setCameraAim(&rc);

	_objectManager = new objectManager;
	_objectManager->init();
	return S_OK;
}

void mainGame::release()			//�޸� ���� �Լ�
{
	gameNode::release();


}

void mainGame::update()				//���� �Լ�
{
	gameNode::update();

	//if (KEYMANAGER->isStayKeyDown(VK_RIGHT)) {
	//	rc.left += 5;
	//	rc.right += 5;
	//}
	//if (KEYMANAGER->isStayKeyDown(VK_LEFT)) {
	//	rc.left -= 5;
	//	rc.right -= 5;
	//}
	
	//sys->update();
	//SCENEMANAGER->update();
	//_player->update();
	
	//_ui->update();
	//_town->update();
	_objectManager->update();
}

void mainGame::render()		//�׷��ִ� �Լ�(a.k.a WM_PAINT)
{
	//��� ��ȭ�� ����~
	PatBlt(getMemDC(), 0, 0, WINSIZEX, WINSIZEY, WHITENESS);
	//==================== �ǵ������� ======================
	//sys->render();
	//SCENEMANAGER->render();

	//_player->render();

	//_ui->render();
	
	//_town->render();
	//Rectangle(getMemDC(), rc.left, rc.top, rc.right, rc.bottom);
	_objectManager->render();
	//==================== �ǵ������� =======================
	//TIMEMANAGER->render(getMemDC());
	this->getBackBuffer()->render(getHDC(), 0, 0);
}