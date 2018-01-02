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
	sys = new system_option;
	sys->init();

	_em = new enemyManager;
	_em->init();
	_em->setRedBeetle();

	return S_OK;
}

void mainGame::release()			//�޸� ���� �Լ�
{
	gameNode::release();


}

void mainGame::update()				//���� �Լ�
{
	gameNode::update();
	sys->update();
	_em->update();
	
}

void mainGame::render()		//�׷��ִ� �Լ�(a.k.a WM_PAINT)
{
	//��� ��ȭ�� ����~
	PatBlt(getMemDC(), 0, 0, WINSIZEX, WINSIZEY, WHITENESS);
	//==================== �ǵ������� ======================
	
	sys->render();
	_em->render();
	

	//==================== �ǵ������� =======================
	//TIMEMANAGER->render(getMemDC());
	this->getBackBuffer()->render(getHDC(), 0, 0);
}