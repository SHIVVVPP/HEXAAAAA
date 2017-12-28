#pragma once
#include "option.h"
class option_controls: public option
{
public:
	option_controls();
	~option_controls();

	HRESULT init();
	void release();
	void update();
	void render();
};

