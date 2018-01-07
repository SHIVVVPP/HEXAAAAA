#pragma once
#include "gameNode.h"

#include "greenDragon.h"
#include "redBeetle.h"
#include "skeleton.h"
#include "yellowDragon.h"

#include "boss.h"

#include <vector>




class enemyManager : gameNode
{
private:
	typedef vector<enemy*> vEnemy;
	typedef vector<enemy*>::iterator viEnemy;

	int generalFrameCounter;

	

public:

	vEnemy	_vEnemy;

	image* _pixelColImage;
	POINT _ptReal;

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();

	void setPixelColInfo(image* image, POINT ptReal) { _pixelColImage = image; _ptReal = ptReal; }
	
	
	enemyManager();
	~enemyManager();
};

