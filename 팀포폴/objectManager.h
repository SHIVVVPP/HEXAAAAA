#pragma once
#include "gameNode.h"
#include "objects.h"
#include <vector>
class objectManager : public gameNode
{
private:
	typedef vector<objects*> vO;
	typedef vector<objects*> viO;
private:
	vO _vgem;
public:
	objectManager();
	~objectManager();

	HRESULT init();
	void release();
	void update();
	void render();

	void player_object_collision();
};

