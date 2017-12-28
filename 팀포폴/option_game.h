#pragma once
#include "option.h"
class option_game: public option
{
public:
	option_game();
	~option_game();

	HRESULT init();
	void release();
	void update();
	void render();
};

