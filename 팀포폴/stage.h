#pragma once
#include "gameNode.h"

class stage : public gameNode
{
private
	pixelMap* _pm;
   

public:
	stage();
	~stage();

	HRESULT init();
	void release();
	void update();
	void render();

	pixelMap();
	~pixelMap();
};

