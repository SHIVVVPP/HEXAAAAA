#pragma once
#include "enemy.h"
class skeleton : public enemy
{
public:
	skeleton();
	~skeleton();

	HRESULT init(MONSTER_INDEX mon_index, POINT leftX_topY);
	void release();
	void update();
	void render();

	void CollisionReact();
	
	void setMainCondition(MONSTER_MAINCONDITION mainCondition);
	void setSubCondition(MONSTER_SUBCONDITION subCondition);
	void setCondition();
	void changeDirection();

	static void attackReturn(void* obj);
};

