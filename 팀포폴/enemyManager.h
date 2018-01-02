#pragma once
#include "gameNode.h"

////////////////////////////
#include "blueSlime.h"
#include "greenDragon.h"
#include "redBeetle.h"
#include "skeleton.h"
#include "yellowDragon.h"
////////////////////////////

#include "boss.h"

#include <vector>


class enemyManager : gameNode
{
private:
	typedef vector<enemy*> vEnemy;
	typedef vector<enemy*>::iterator viEnemy;

	int generalFrameCounter;

public:

	vEnemy		 _vBlueSlime;
	viEnemy		 _viBlueSlime;

	vEnemy		 _vGreenDragon;
	viEnemy		 _viGreenDragon;

	vEnemy		 _vSkeleton;
	viEnemy		 _viSkeleton;

	vEnemy		 _vRedBeetle;
	viEnemy		 _viRedBeetle;

	vEnemy		 _vYellowDragon;
	viEnemy		 _viYellowDragon;

	vEnemy		 _vBoss;
	viEnemy		 _viBoss;

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();

	void setRedBeetle();
	void setGreenDragon();
	void setBlueSlime();
	void setSkeleton();
	void setYellowDragon();

	void frameMove();
	void killSomething(int arrNum);

	vector<enemy*> getVRedBeetle() { return _vRedBeetle; }
	vector<enemy*>::iterator getVIRedBeetle() { return _viRedBeetle; }

	vector<enemy*> getVGreenDragon() { return _vGreenDragon; }
	vector<enemy*>::iterator getVIDragon() { return _viGreenDragon; }

	vector<enemy*> getVSkeleton() { return _vSkeleton; }
	vector<enemy*>::iterator getVISkeleton() { return _viSkeleton; }

	vector<enemy*> getVYellowDragon() { return _vYellowDragon; }
	vector<enemy*>::iterator getVIYellowDragon() { return _viYellowDragon; }

	vector<enemy*> getVSlime() { return _vBlueSlime; }
	vector<enemy*>::iterator getVISlime() { return _viBlueSlime; }

	vector<enemy*> getVBoss() { return _vBoss; }
	vector<enemy*>::iterator getVIBoss() { return _viBoss; }

	enemyManager();
	~enemyManager();
};

