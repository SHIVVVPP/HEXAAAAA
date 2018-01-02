#pragma once
#include "gameNode.h"

class player;

class worldMap : public gameNode
{
private:
	player* _player;
public:
	worldMap();
	~worldMap();

	HRESULT init();
	void release();
	void update();
	void render();
	void addressLinkWithPlayer(player* p) { _player = p; }

};

