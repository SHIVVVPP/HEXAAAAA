#pragma once
#include "gameNode.h"

class player : public gameNode
{
public:
	player();
	~player();

	HRESULT init();
	void release();
	void update();
	void render();
};

