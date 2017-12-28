#pragma once
#include "gameNode.h"
#include "option.h"

class system_option : public gameNode
{
private:
	option* _currentOption;


public:
	system_option();
	~system_option();

	HRESULT init();
	void release();
	void update();
	void render();
};


