#include "stdafx.h"
#include "mainGame.h"

#define CRTDBG_MAP_ALLOC 
#include <stdlib.h>
#include <crtdbg.h>
#ifdef _DEBUG

#define new new( _NORMAL_BLOCK, __FILE__, __LINE__ )   // #include <new.h>등으로 operator new나 malloc을 

// Derived해서 정의 한 경우, 사용 할 수 없다.

#endif

mainGame::mainGame()
{
}

mainGame::~mainGame()
{
}

HRESULT mainGame::init()			//초기화 함수
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

	//SCENEMANAGER->addScene("스테이지", new stage);
	//SCENEMANAGER->addScene("인벤토리", new inventory);
	//
	//SCENEMANAGER->changeScene("인벤토리","스테이지",_player);

	//_ui = new ui;
	//_ui->init(UI_STAGE);
	CAMERAMANAGER->setBackground(8137, 900);
	CAMERAMANAGER->setStartBackground(0, 0);

	_town = new town;
	_town->init();
	
	rc = RectMake(WINSIZEX / 2, WINSIZEX / 2, 50, 50);
	CAMERAMANAGER->setCameraCondition(false, CAMERA_AIMING);
	CAMERAMANAGER->setCameraAim(&rc);

	//_objectManager = new objectManager;
	//_objectManager->init();
	return S_OK;
}

void mainGame::release()			//메모리 해제 함수
{
	gameNode::release();


}

void mainGame::update()				//연산 함수
{
	gameNode::update();

	if (KEYMANAGER->isStayKeyDown(VK_RIGHT)) {
		rc.left += 5;
		rc.right += 5;
	}
	if (KEYMANAGER->isStayKeyDown(VK_LEFT)) {
		rc.left -= 5;
		rc.right -= 5;
	}
	
	//sys->update();
	//SCENEMANAGER->update();
	//_player->update();
	
	//_ui->update();
	_town->update();
	//_objectManager->update();
}

void mainGame::render()		//그려주는 함수(a.k.a WM_PAINT)
{
	//흰색 도화지 한장~
	PatBlt(getMemDC(), 0, 0, WINSIZEX, WINSIZEY, WHITENESS);
	//==================== 건들지마라 ======================
	//sys->render();
	//SCENEMANAGER->render();

	//_player->render();

	//_ui->render();
	
	_town->render();
	//Rectangle(getMemDC(), rc.left, rc.top, rc.right, rc.bottom);
	//_objectManager->render();
	//==================== 건들지마라 =======================
	//TIMEMANAGER->render(getMemDC());
	this->getBackBuffer()->render(getHDC(), 0, 0);
}