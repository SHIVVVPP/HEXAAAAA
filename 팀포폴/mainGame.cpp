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

	

	_player = new player;
	_player->init();


	//sys = new system_option;
	//sys->init();
	
	//SCENEMANAGER->addScene("스테이지", new stage);
	//SCENEMANAGER->addScene("인벤토리", new inventory);
	//SCENEMANAGER->addScene("시스템", new system_option);
	//

	/*_ui = new ui;
	_ui->init(UI_STAGE);*/
	//CAMERAMANAGER->setBackground(8137, 900);
	//CAMERAMANAGER->setStartBackground(0, 0);
   
	//_town = new town;
	//_town->init();
	SCENEMANAGER->addScene("마을", new town);
	SCENEMANAGER->changeScene("마을", _player);
	//rc = RectMake(WINSIZEX / 2, WINSIZEY/2, 50, 50);
	//CAMERAMANAGER->setCameraCondition(false, CAMERA_AIMING);
	//CAMERAMANAGER->setCameraAim(&rc);

	SCENEMANAGER->changeScene("스테이지", _player);
	
	_Nowsys_option = false;
	_Nowinventory = false;
	
	return S_OK;
}

void mainGame::release()			//메모리 해제 함수
{
	gameNode::release();


}

void mainGame::update()				//연산 함수
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
	//if (KEYMANAGER->isStayKeyDown(VK_DOWN)) {
	//	rc.top += 5;
	//	rc.bottom += 5;
	//}
	//if (KEYMANAGER->isStayKeyDown(VK_UP)) {
	//	rc.top -= 5;
	//	rc.bottom -= 5;
	//}

	SCENEMANAGER->update();

	if (KEYMANAGER->isOnceKeyDown('I'))
	{
		if (_Nowinventory)
		{
			_Nowinventory = false;
			SCENEMANAGER->returnScene();
		}
		else
		{
			_Nowinventory = true;
			SCENEMANAGER->tempScene("인벤토리");
		}
	}

	if (KEYMANAGER->isOnceKeyDown('O'))
	{
		if (_Nowsys_option) {
			_Nowsys_option = false;
			SCENEMANAGER->returnScene();
		} 
		else
		{
			_Nowsys_option = true;
			SCENEMANAGER->tempScene("시스템");
		}
	}
	

	//sys->update();
	//_player->update();
	//_ui->update();
	//_town->update();
}

void mainGame::render()		//그려주는 함수(a.k.a WM_PAINT)
{
	//흰색 도화지 한장~
	PatBlt(getMemDC(), 0, 0, WINSIZEX, WINSIZEY, WHITENESS);
	//==================== 건들지마라 ======================
	//sys->render();
	
	SCENEMANAGER->render();
	//_town->render();
	//_player->render();

	//_ui->render();
	
	//RectangleMake(getMemDC(), CAMERAMANAGER->CameraRelativePoint(rc).x, CAMERAMANAGER->CameraRelativePoint(rc).y,50, 50);
	//Rectangle(getMemDC(), rc.left, rc.top, rc.right, rc.bottom);
	//==================== 건들지마라 =======================
	TIMEMANAGER->render(getMemDC());
	this->getBackBuffer()->render(getHDC(), 0, 0);
}