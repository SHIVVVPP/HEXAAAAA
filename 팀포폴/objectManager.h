#pragma once
#include "gameNode.h"
#include "objects.h"
#include "gem.h"
#include "ladder.h"
#include "dirtpile.h"
#include "moveblock.h"
#include <vector>
class objectManager : public gameNode
{
private:
	typedef vector<objects*> vO;
	typedef vector<objects*> viO;
private:
	vO _vgem;
	vO _vladder;
	vO _vmoveblock;
	vO _vdirtpile;
public:
	objectManager();
	~objectManager();

	HRESULT init();
	void release();
	void update();
	void render();
	void setPosition();
	void player_object_collision();
};

