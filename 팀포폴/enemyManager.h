#pragma once
#include "gameNode.h"

class enemyManager : gameNode
{
public:
	enemyManager();
	~enemyManager();

	HRESULT init();
	void release();
	void update();
	void render();
};

