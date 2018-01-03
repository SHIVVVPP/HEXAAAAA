#pragma once
#include "objects.h"

class gem : public objects
{
private:

public:
	HRESULT init(int x, int y);
	void update();
	void render();
	gem();
	~gem();
};

