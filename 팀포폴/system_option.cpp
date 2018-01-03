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
}

void system_option::render()
{
	_currentOption->render();
}
