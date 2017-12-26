#pragma once
#include "gameNode.h"
class NPCManager : public gameNode
{
public:
	NPCManager();
	~NPCManager();

	HRESULT init();
	void release();
	void update();
	void render();
};

