#pragma once
#include "gameNode.h"
class stage : public gameNode
{
public:
	stage();
	~stage();

	HRESULT init();
	void release();
	void update();
	void render();
};

