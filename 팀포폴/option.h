#pragma once
#include "gameNode.h"
#include "animation.h"
#include <vector>

enum OPTIONS 
{
	OPTION_OUT,
	OPTION_MAIN,
	OPTION_GAME,
	OPTION_CONTROLS,
	OPTION_AUDIO,
	OPTION_VIDEO,
	
};

struct tagOptions
{
	image* image;
	animation* _ani;
	bool isSelected;
	OPTIONS _connectedOption;

};


class option :public gameNode
{
private:
	typedef vector<tagOptions*> vo;
	typedef vector<tagOptions*> vio;

private:
	image* _background;

	vo _vOptions;
	int _currentIndex;



public:
	option();
	~option();

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();

};

