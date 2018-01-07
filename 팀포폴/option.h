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
	OPTION_SELECT,
	OPTION_PROGRESS,
	OPTION_DEFAULTSET,
	OPTION_NONE,
};

enum SELECT
{
	SELECT_ON,
	SELECT_OFF,
	SELECT_NONE,
};

struct tagOptions
{
	image* image;
	animation* _ani;
	bool isSelected;
	OPTIONS _connectedOption;
	int _connectedSelectOption;
	SELECT _selectCondition;
};

struct tagProgressBar
{
	image* _image;
	int _max;
	float _value;
	int _connectedOption;
};


class option :public gameNode
{
private:
	typedef vector<tagOptions*> vo;
	typedef vector<tagOptions*>::iterator vio;
	typedef vector<tagProgressBar*> vp;
	typedef vector<tagProgressBar*>::iterator vip;

protected:
	image* _background;

	vo _vOptions;
	int _currentIndex;

	vo _vSelection;
	vp _vProgress;



public:
	option();
	~option();

	virtual HRESULT init();
	virtual void release();
	virtual void update();
	virtual void render();

	OPTIONS getConnectedOption() { return _vOptions[_currentIndex]->_connectedOption; }
	void setSelectCondition() {
		if (_vSelection[_vOptions[_currentIndex]->_connectedSelectOption]->_selectCondition == SELECT_OFF)
		{
			_vSelection[_vOptions[_currentIndex]->_connectedSelectOption]->_selectCondition = SELECT_ON;
		}
		else if (_vSelection[_vOptions[_currentIndex]->_connectedSelectOption]->_selectCondition == SELECT_ON)
		{
			_vSelection[_vOptions[_currentIndex]->_connectedSelectOption]->_selectCondition = SELECT_OFF;

		}
	}

	virtual void setDefault();
};