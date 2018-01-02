#pragma once
#include "image.h"

class player;

static image* _backBuffer = IMAGEMANAGER->addImage("backBuffer", WINSIZEX, WINSIZEY);
static image* _backBuffer2 = IMAGEMANAGER->addImage("backBuffer2", WINSIZEX, WINSIZEY);
class gameNode
{
private:
	HDC _hdc;
	bool _managerInit;

public:
	virtual HRESULT init();		//�ʱ�ȭ �Լ�
	virtual HRESULT init(bool managerInit);
	virtual void release();		//�޸� ���� �Լ�
	virtual void update();		//���� �Լ�
	virtual void render();		//�׷��ִ� �Լ�(a.k.a WM_PAINT)

	//����� ������
	image* getBackBuffer() { return _backBuffer; }
	image* getBackBuffer2() { return _backBuffer2; }
	//�޸�DC ������
	HDC getMemDC() { return _backBuffer->getMemDC(); }
	HDC getMemDC2() { return _backBuffer2->getMemDC(); }
	HDC getHDC() { return _hdc; }

	LRESULT MainProc(HWND, UINT, WPARAM, LPARAM);


	void addressLinkWithPlayer(player* p) {}

	gameNode();
	virtual ~gameNode();
};

