#pragma once
#include "objects.h"
class dirtblock : public objects
{
public:

	HRESULT init(int x, int y);
	void update();
	void render();
	dirtblock();
	~dirtblock();
};

