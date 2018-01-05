#pragma once
#include "image.h"

class player;

static image* _backBuffer = IMAGEMANAGER->addImage("backBuffer", WINSIZEX, WINSIZEY);
static image* _backBuffer2 = IMAGEMANAGER->addImage("backBuffer2", WINSIZEX, WINSIZEY);


//콜리전 메시지

enum COLLISION_TYPE
{
	COL_ITEM,
	COL_MONSTER,
	COL_OBJECT,
	COL_NPC,
};

typedef struct tagCollisionInfo
{
	COLLISION_TYPE _colType;
	int index_detail;
	void* object;
}COLLISION_INFO,*LPCOLLISION_INFO;




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

	virtual void AddressLinkWithPlayer(player* _p) {}


	gameNode();
	virtual ~gameNode();
};

