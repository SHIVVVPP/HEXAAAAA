#pragma once
#include "objects.h"
class smalldirtblock : public objects
{
public:

	HRESULT init(int x, int y);
	void update();
	void render();

	smalldirtblock();
	~smalldirtblock();
};

