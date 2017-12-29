#include "stdafx.h"
#include "system_option.h"

#include "option_audio.h"
#include "option_game.h"
#include "option_controls.h"
#include "option_video.h"


system_option::system_option()
{
}


system_option::~system_option()
{
}

HRESULT system_option::init()
{
	_currentOption = new option;
	_currentOption->init();

	return S_OK;
}

void system_option::release()
{
}

void system_option::update()
{
	_currentOption->update();

	if (KEYMANAGER->isOnceKeyDown(VK_RETURN))
	{
		switch (_currentOption->getConnectedOption())
		{
				/*OPTION_OUT,
				OPTION_MAIN,
				OPTION_GAME,
				OPTION_CONTROLS,
				OPTION_AUDIO,
				OPTION_VIDEO,
				OPTION_SELECT,
				OPTION_PROGRESS,
				OPTION_NONE,*/
		case OPTION_OUT:
			
		break;
		case OPTION_MAIN:
			SAFE_RELEASE(_currentOption);
			_currentOption = new option;
			_currentOption->init();
		break;
		case OPTION_GAME:
			SAFE_RELEASE(_currentOption);
			_currentOption = new option_game;
			_currentOption->init();
		break;
		case OPTION_CONTROLS:
			SAFE_RELEASE(_currentOption);
			_currentOption = new option_controls;
			_currentOption->init();
		break;
		case OPTION_AUDIO:
			SAFE_RELEASE(_currentOption);
			_currentOption = new option_audio;
			_currentOption->init();
		break;
		case OPTION_VIDEO:
			SAFE_RELEASE(_currentOption);
			_currentOption = new option_video;
			_currentOption->init();
		break;
		case OPTION_SELECT:
		break;
		case OPTION_PROGRESS:
		break;
		case OPTION_NONE:
			
		break;
		}
	}
}

void system_option::render()
{
	_currentOption->render();
}
