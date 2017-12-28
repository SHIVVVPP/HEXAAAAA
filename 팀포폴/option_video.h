#pragma once
#include "option.h"
class option_video : public option
{
public:
	option_video();
	~option_video();

	HRESULT init();
	void release();
	void update();
	void render();
};

