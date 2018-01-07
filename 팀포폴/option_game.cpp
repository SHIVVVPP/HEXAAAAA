#include "stdafx.h"
#include "option_game.h"


option_game::option_game()
{
}


option_game::~option_game()
{
}

HRESULT option_game::init()
{
	_background = IMAGEMANAGER->findImage("option_game_background");

	tagOptions* temp;
	temp = new tagOptions;
	temp->image = IMAGEMANAGER->findImage("back");
	temp->_connectedOption = OPTION_MAIN;
	_vOptions.push_back(temp);

	temp = new tagOptions;
	temp->image = IMAGEMANAGER->findImage("game_pauseOnLostFocus");
	temp->_connectedOption = OPTION_SELECT;
	temp->_connectedSelectOption = 0;
	_vOptions.push_back(temp);

	temp = new tagOptions;
	temp->image = IMAGEMANAGER->findImage("enable_option");
	temp->_selectCondition = SELECT_OFF;
	_vSelection.push_back(temp);

	temp = new tagOptions;
	temp->image = IMAGEMANAGER->findImage("game_showFeats");
	temp->_connectedOption = OPTION_SELECT;
	temp->_connectedSelectOption = 1;
	_vOptions.push_back(temp);

	temp = new tagOptions;
	temp->image = IMAGEMANAGER->findImage("enable_option");
	temp->_selectCondition = SELECT_OFF;
	_vSelection.push_back(temp);






	for (int i = 0; i < _vOptions.size(); i++)
	{
		_vOptions[i]->_ani = new animation;
		_vOptions[i]->_ani->init(_vOptions[i]->image->getWidth(), _vOptions[i]->image->getHeight(), _vOptions[i]->image->getFrameWidth(), _vOptions[i]->image->getFrameHeight());

		if (_vOptions[i]->_connectedOption == OPTION_SELECT)
		{
			_vSelection[_vOptions[i]->_connectedSelectOption]->_connectedSelectOption = i;
		}


		if (i == 0)
		{
			_vOptions[i]->isSelected = true;
			int arrAni[2] = { 1,2 };
			_vOptions[i]->_ani->setPlayFrame(arrAni, 2, true);
		}
		else
		{
			_vOptions[i]->isSelected = false;
			int arrAni[1] = { 0 };
			_vOptions[i]->_ani->setPlayFrame(arrAni, 1, false);
		}
		_vOptions[i]->_ani->setFPS(1);
		_vOptions[i]->_ani->start();
	}



	_currentIndex = 0;

	return S_OK;
}

void option_game::release()
{
}

void option_game::update()
{
	option::update();
}

void option_game::render()
{
	option::render();


	for (int i = 0; i < _vSelection.size(); i++)
	{
		if (_vSelection[i]->_selectCondition == SELECT_OFF)
		{
			_vSelection[i]->image->frameRender(getMemDC(), WINSIZEX / 2 - _background->getWidth() / 2 + 550, WINSIZEY / 2 - _background->getHeight() / 2 + 80 + 41 * _vSelection[i]->_connectedSelectOption, 1, 0);
		}
		else if (_vSelection[i]->_selectCondition == SELECT_ON)
		{
			_vSelection[i]->image->frameRender(getMemDC(), WINSIZEX / 2 - _background->getWidth() / 2 + 550, WINSIZEY / 2 - _background->getHeight() / 2 + 80 + 41 * _vSelection[i]->_connectedSelectOption, 0, 0);
		}
	}
}