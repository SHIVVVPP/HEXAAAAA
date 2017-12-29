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

	return S_OK;
}

void database::release()
{
}

