#pragma once
#include "gameNode.h"
#include "NPCManager.h"

class objectManager;
class player;
class ui;

class town :public gameNode
{
private:
	image* townimage;
	image* townPix;
	image* backsideimg;
	NPCManager* _NPCM;
	player* _player;
	ui* _ui;
	objectManager* _objectManager;

	//�ӽ� ��Ʈ

	RECT _rc;
	RECT _table;			// ���� x = 2770, y= 530


	bool _isvisible;		//�ȼ��̹��� ���̰� �ϴ� �Ұ�;

	const char* crrentMusicName;
	const char* oldMusicName;
public:
	town();
	~town();

	HRESULT init();
	void release();
	void update();
	void render();
	//void collision();
	void  AddressLinkWithPlayer(player* _p) { _player = _p; }


	//void sendColMessage();
	void pixelCollison();
};

