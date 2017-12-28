#include "stdafx.h"
#include "option.h"


option::option()
{
}


option::~option()
{
}

HRESULT option::init()
{
	_background = IMAGEMANAGER->findImage("option_main_background");

	tagOptions* temp;
	temp = new tagOptions;
	temp->image = IMAGEMANAGER->findImage("back");
	temp->_connectedOption = OPTION_OUT;
	_vOptions.push_back(temp);
	
	temp = new tagOptions;
	temp->image = IMAGEMANAGER->findImage("main_game");
	temp->_connectedOption = OPTION_GAME;
	_vOptions.push_back(temp);


	temp = new tagOptions;
	temp->image = IMAGEMANAGER->findImage("main_controls");
	temp->_connectedOption = OPTION_CONTROLS;
	_vOptions.push_back(temp);

	temp = new tagOptions;
	temp->image = IMAGEMANAGER->findImage("main_audio");
	temp->_connectedOption = OPTION_AUDIO;
	_vOptions.push_back(temp);


	temp = new tagOptions;
	temp->image = IMAGEMANAGER->findImage("main_video");
	temp->_connectedOption = OPTION_VIDEO;
	

	for (int i = 0; i < _vOptions.size(); i++)
	{
		_vOptions[i]->_ani = new animation;
		_vOptions[i]->_ani->init(_vOptions[i]->image->getWidth(), _vOptions[i]->image->getHeight(), _vOptions[i]->image->getFrameWidth(), _vOptions[i]->image->getFrameHeight());

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

void option::release()
{
}

void option::update()
{
	if (KEYMANAGER->isOnceKeyDown(VK_DOWN))
	{
		_vOptions[_currentIndex]->isSelected = false;
		int arrAni1[1] = { 0 };
		_vOptions[_currentIndex]->_ani->setPlayFrame(arrAni1, 1, false);

		_vOptions[_currentIndex]->_ani->setFPS(1);
		_vOptions[_currentIndex]->_ani->start();


		_currentIndex++;
		if (_currentIndex == _vOptions.size()) _currentIndex = 0;
		_vOptions[_currentIndex]->isSelected = true;
		int arrAni2[2] = { 1,2 };
		_vOptions[_currentIndex]->_ani->setPlayFrame(arrAni2, 2, true);

		_vOptions[_currentIndex]->_ani->setFPS(1);
		_vOptions[_currentIndex]->_ani->start();
	}
	if (KEYMANAGER->isOnceKeyDown(VK_UP))
	{
		_vOptions[_currentIndex]->isSelected = false;
		int arrAni1[1] = { 0 };
		_vOptions[_currentIndex]->_ani->setPlayFrame(arrAni1, 1, false);
		_vOptions[_currentIndex]->_ani->setFPS(1);
		_vOptions[_currentIndex]->_ani->start();

		_currentIndex--;
		if (_currentIndex < 0) _currentIndex = _vOptions.size()-1;
		_vOptions[_currentIndex]->isSelected = true;
		int arrAni2[2] = { 1,2 };
		_vOptions[_currentIndex]->_ani->setPlayFrame(arrAni2, 2, true);

		_vOptions[_currentIndex]->_ani->setFPS(1);
		_vOptions[_currentIndex]->_ani->start();
	}

	
	for (int i = 0; i < _vOptions.size(); i++)
	{
		_vOptions[i]->_ani->frameUpdate(TIMEMANAGER->getElapsedTime() * 5);
	}

}

void option::render()
{
	_background->render(getMemDC(), WINSIZEX / 2 - _background->getWidth() / 2, WINSIZEY / 2 - _background->getHeight() / 2);

	for (int i = 0; i < _vOptions.size(); i++)
	{
		_vOptions[i]->image->aniRender(getMemDC(), WINSIZEX / 2 - _background->getWidth() / 2 + 10, WINSIZEY / 2 - _background->getHeight() / 2 + 64 + 41 * i,_vOptions[i]->_ani);
	}
}
