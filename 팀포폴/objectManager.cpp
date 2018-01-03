#include "stdafx.h"
#include "objectManager.h"


objectManager::objectManager()
{
}


objectManager::~objectManager()
{
}

HRESULT objectManager::init()
{
	
	return S_OK;
}

void objectManager::release()
{
}

void objectManager::update()
{
}

void objectManager::render()
{
	for (int i = 0; i < _vgem.size(); i++)
	{
		_vgem[i]->render();
	}
}

void objectManager::player_object_collision()
{
}
