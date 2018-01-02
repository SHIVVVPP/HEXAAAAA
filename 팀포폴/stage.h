#pragma once
#include "gameNode.h"

class stage : public gameNode
{
private:
	
   

public:
	stage();
	~stage();

	HRESULT init();
	void release();
	void update();
	void render();

};

