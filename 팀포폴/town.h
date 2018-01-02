#pragma once
#include "gameNode.h"
#include "NPCManager.h"

class town :public gameNode
{
private:
	image* townimage;
	image* townPix;
	NPCManager* _NPCM;

	RECT _table;			// 중점 x = 2770, y= 530


	bool _isvisible;		//픽셀이미지 보이게 하는 불값;
public:
	town();
	~town();

	HRESULT init();
	void release();
	void update();
	void render();
	void collision();

};

