#pragma once
#include "objects.h"

class gem : public objects
{
public:
	HRESULT init(int x, int y,const char* imageName, int goldup);
	void update();
	void render();
	void respawn(int x, int y, bool fire, float angle);
	gem();
	~gem();
};

