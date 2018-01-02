#pragma once
#include "gameNode.h"
#include "NPCManager.h"

class town :public gameNode
{
private:
	image* townimage;
	image* townPix;
	image* backsideimg;
	NPCManager* _NPCM;

	RECT _table;			// ���� x = 2770, y= 530


	bool _isvisible;		//�ȼ��̹��� ���̰� �ϴ� �Ұ�;


public:
	town();
	~town();

	HRESULT init();
	void release();
	void update();
	void render();
	void collision();

};

