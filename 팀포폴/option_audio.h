#pragma once
#include "option.h"

class option_audio: public option
{
public:
	option_audio();
	~option_audio();

	HRESULT init();
	void release();
	void update();
	void render();
};

