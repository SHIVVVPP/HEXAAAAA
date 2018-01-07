#pragma once
#include "image.h"

class player;

static image* _backBuffer = IMAGEMANAGER->addImage("backBuffer", WINSIZEX, WINSIZEY);
static image* _backBuffer2 = IMAGEMANAGER->addImage("backBuffer2", WINSIZEX, WINSIZEY);


//�ݸ��� �޽���

enum COLLISION_TYPE
{
	COL_NONE,
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
	bool _isPlayer;

	tagCollisionInfo()
	{
		_colType = COL_NONE;
		index_detail = 0;
		object = NULL;
		_isPlayer = true;
	}
}COLLISION_INFO,*LPCOLLISION_INFO;




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

	virtual void AddressLinkWithPlayer(player* _p) {}


	gameNode();
	virtual ~gameNode();
};

