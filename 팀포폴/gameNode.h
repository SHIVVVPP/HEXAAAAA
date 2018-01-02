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
	virtual HRESULT init();		//초기화 함수
	virtual HRESULT init(bool managerInit);
	virtual void release();		//메모리 해제 함수
	virtual void update();		//연산 함수
	virtual void render();		//그려주는 함수(a.k.a WM_PAINT)

	//백버퍼 접근자
	image* getBackBuffer() { return _backBuffer; }
	image* getBackBuffer2() { return _backBuffer2; }
	//메모리DC 접근자
	HDC getMemDC() { return _backBuffer->getMemDC(); }
	HDC getMemDC2() { return _backBuffer2->getMemDC(); }
	HDC getHDC() { return _hdc; }

	LRESULT MainProc(HWND, UINT, WPARAM, LPARAM);


	void addressLinkWithPlayer(player* p) {}

	gameNode();
	virtual ~gameNode();
};

