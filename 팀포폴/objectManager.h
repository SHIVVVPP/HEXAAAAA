#pragma once
#include "gameNode.h"
#include "objects.h"
//#include "platter.h"
#include "dirtblock.h"
#include "smalldirtblock.h"
#include "gem.h"
#include "ladder.h"
#include "dirtpile.h"
#include "moveblock.h"
#include "potion.h"
#include "food.h"
#include "part.h"
#include "part2.h"
#include "player.h"
#include "effect.h"
#include <vector>

class objectManager : public gameNode
{
private:
	typedef vector<objects*> vO;
	typedef vector<objects*>::iterator viO;
private:
	vO _vgem;
	viO _vigem;
	vO _vladder;
	vO _vmoveblock; 
	vO _vdirtpile;
	vO _vUse;
	viO _vidirtpile;
	vO _vdirtblock;
	objects* _obj;
	int _hitcount;
	int _leftX;
	int _topY;
	int  col;
	player* _p;
	effect* _pickeffect;
public:
	objectManager();
	~objectManager();

	HRESULT init();
	void release();
	void update();
	void render();
	void setPosition();
	LPCOLLISION_INFO player_object_collision();
	void connectPlayer(player* p) { _p = p; }
};

