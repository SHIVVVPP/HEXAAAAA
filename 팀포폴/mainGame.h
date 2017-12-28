#pragma once
#include "gameNode.h"
#include "system_option.h"

class mainGame : public gameNode
{
private:
	system_option* sys;


public:
	virtual HRESULT init();			
	virtual void release();			
	virtual void update();			
	virtual void render();	

	void setImages();

	mainGame();
	~mainGame();
};

