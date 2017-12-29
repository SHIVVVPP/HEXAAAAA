#include "stdafx.h"
#include "option_audio.h"


option_audio::option_audio()
{
}


option_audio::~option_audio()
{
}

HRESULT option_audio::init()
{
	_background = IMAGEMANAGER->findImage("option_audio_background");

	tagOptions* temp;
	temp = new tagOptions;
	temp->image = IMAGEMANAGER->findImage("back");
	temp->_connectedOption = OPTION_MAIN;
	_vOptions.push_back(temp);

	temp = new tagOptions;
	temp->image = IMAGEMANAGER->findImage("audio_musicVolume");
	temp->_connectedOption = OPTION_PROGRESS;
	temp->_connectedSelectOption = 0;
	_vOptions.push_back(temp);

	tagProgressBar* tempP;
	tempP = new tagProgressBar;
	tempP->_image = IMAGEMANAGER->findImage("audio_progressValue");
	tempP->_max = IMAGEMANAGER->findImage("audio_progressBar")->getWidth();
	tempP->_value = 0.5f;
	_vProgress.push_back(tempP);



	temp = new tagOptions;
	temp->image = IMAGEMANAGER->findImage("audio_soundVolume");
	temp->_connectedOption = OPTION_PROGRESS;
	temp->_connectedSelectOption = 1;
	_vOptions.push_back(temp);


	tempP = new tagProgressBar;
	tempP->_image = IMAGEMANAGER->findImage("audio_progressValue");
	tempP->_max = IMAGEMANAGER->findImage("audio_progressBar")->getWidth();
	tempP->_value = 0.5f;
	_vProgress.push_back(tempP);

	temp = new tagOptions;
	temp->image = IMAGEMANAGER->findImage("audio_setToDefault");
	temp->_connectedOption = OPTION_SELECT;
	temp->_connectedSelectOption = 0;
	_vOptions.push_back(temp);



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

void option_audio::release()
{
}

void option_audio::update()
{
	option::update();

	if (KEYMANAGER->isOnceKeyDown(VK_LEFT))
	{
		if (_vOptions[_currentIndex]->_connectedOption == OPTION_PROGRESS)
		{
			if (_vProgress[_vOptions[_currentIndex]->_connectedSelectOption]->_value > 0)
				_vProgress[_vOptions[_currentIndex]->_connectedSelectOption]->_value -= 0.05f;
		}
	}

	if (KEYMANAGER->isOnceKeyDown(VK_RIGHT))
	{
		if (_vOptions[_currentIndex]->_connectedOption == OPTION_PROGRESS)
		{
			if (_vProgress[_vOptions[_currentIndex]->_connectedSelectOption]->_value < 1)
				_vProgress[_vOptions[_currentIndex]->_connectedSelectOption]->_value += 0.05f;
		}
	}
}

void option_audio::render()
{
	_background->render(getMemDC(), WINSIZEX / 2 - _background->getWidth() / 2, WINSIZEY / 2 - _background->getHeight() / 2);

	for (int i = 0; i < _vOptions.size(); i++)
	{
		_vOptions[i]->image->aniRender(getMemDC(), WINSIZEX / 2 - _background->getWidth() / 2 + 10, WINSIZEY / 2 - _background->getHeight() / 2 + 64 + 41 * i, _vOptions[i]->_ani);
		if (_vOptions[i]->_connectedOption == OPTION_PROGRESS)
		{
			IMAGEMANAGER->findImage("audio_progressBar")->render(getMemDC(), WINSIZEX / 2 + _background->getWidth() / 2 - 215, WINSIZEY / 2 - _background->getHeight() / 2 + 78 + 41 * i);
			int k = _vOptions[i]->_connectedSelectOption;
			_vProgress[k]->_image->render(getMemDC(), WINSIZEX / 2 + _background->getWidth() / 2 - 215 + _vProgress[k]->_max*_vProgress[k]->_value, WINSIZEY / 2 - _background->getHeight() / 2 + 78 + 41 * i);
		}
	}


}
