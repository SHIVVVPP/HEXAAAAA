#pragma once
#include "objects.h"

class gem : public objects
{
public:
	HRESULT init(int x, int y,const char* imageName, int goldup);
	void update();
	void render();
	gem();
	~gem();
};

