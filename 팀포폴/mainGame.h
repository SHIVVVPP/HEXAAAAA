#pragma once
#include "gameNode.h"
#include "system_option.h"
#include "inventory.h"
#include "stage.h"
#include "player.h"	
#include "ui.h"
#include "town.h"

class mainGame : public gameNode
{
private:
	RECT rc;
	system_option* sys;
	player* _player;
	town*	_town;
	//system_option* sys;
	gameNode * _inventory;
	gameNode* _stage;
	//gameNode* _town;
	ui* _ui;

	bool _Nowsys_option;
	bool _Nowinventory;
	
public:
	virtual HRESULT init();			
	virtual void release();			
	virtual void update();			
	virtual void render();	

	void setImages();

	mainGame();
	~mainGame();
};

