#pragma once
#include "objects.h"
class musicsheet : public objects
{
public:

	HRESULT init(int x, int y);
	void update();
	void render();

	musicsheet();
	~musicsheet();
};

