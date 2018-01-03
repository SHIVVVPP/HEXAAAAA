#pragma once
#include "objects.h"
class dirtpile : public objects
{
public:
	dirtpile();
	~dirtpile();

	HRESULT init(int x, int y);
	void update();
	void render();
};

