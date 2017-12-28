#pragma once
#include "gameNode.h"
#include "system_option.h"
#include "inventory.h"
#include "stage.h"
#include "player.h"	

class mainGame : public gameNode
{
private:
	system_option* sys;
	player* _player;
	//system_option* sys;
	gameNode * _inventory;
	gameNode* _stage;

public:
	virtual HRESULT init();			
	virtual void release();			
	virtual void update();			
	virtual void render();	

	void setImages();

	mainGame();
	~mainGame();
};

