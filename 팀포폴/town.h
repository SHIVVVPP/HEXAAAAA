#pragma once
#include "gameNode.h"

class player;

class town :public gameNode
{
private:
	player* _player;
public:
	town();
	~town();

	HRESULT init();
	void release();
	void update();
	void render();
	void addressLinkWithPlayer(player* p) { _player = p; }

};

