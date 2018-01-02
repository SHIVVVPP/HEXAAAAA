#pragma once
#include "gameNode.h"
#include "system_option.h"
#include "enemyManager.h"

class mainGame : public gameNode
{
private:
	system_option* sys;
	enemyManager* _em;

public:
	virtual HRESULT init();			
	virtual void release();			
	virtual void update();			
	virtual void render();	

	void setImages();

	mainGame();
	~mainGame();
};

