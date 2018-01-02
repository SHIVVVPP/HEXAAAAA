#pragma once
#include "gameNode.h"

class player;

class stage : public gameNode
{
	player* _player;

public:
	stage();
	~stage();

	HRESULT init();
	void release();
	void update();
	void render();

	void addressLinkWithPlayer(player* p) { _player = p; }

};

