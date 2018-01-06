#pragma once
#include "objects.h"
class meal :public objects
{
public:

	HRESULT init(int x, int y);
	void update();
	void render();

	meal();
	~meal();
};

