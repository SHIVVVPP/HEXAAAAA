#pragma once
#include "objects.h"
class food : public objects
{
public:

	HRESULT init(int x, int y);
	void update();
	void render();
	food();
	~food();
};

