#include "stdafx.h"
#include "database.h"


database::database()
{
}


database::~database()
{
}

HRESULT database::init()
{
	sys_element = new element_system;

	player_current_element = new element_player;
	player_save_element = new element_player;

	return S_OK;
}

void database::release()
{
}

