#pragma once
#include "gameNode.h"

class objectManager : public gameNode
{
public:
	objectManager();
	~objectManager();

	HRESULT init();
	void release();
	void update();
	void render();
};

