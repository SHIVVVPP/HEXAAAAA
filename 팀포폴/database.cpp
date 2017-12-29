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
}

void database::release() 
{

}


void database::loadDataBase(DATABASE_CLASS kind)
{
	arrElements vTemp;
	string name;
	switch (kind)
	{
	case DATABASE_SYSTEM:
		name = "database_system.txt";
		vTemp = TXTDATA->txtLoad(name.c_str());
		break;
	case DATABASE_PLAYER:
		name = "database_player.txt";
		vTemp = TXTDATA->txtLoad(name.c_str());
		break;
	case DATABASE_ITEM:
		name = "database_item.txt";
		vTemp = TXTDATA->txtLoad(name.c_str());
		break;
	case DATABASE_MONSTER:
		name = "database_monster.txt";
		vTemp = TXTDATA->txtLoad(name.c_str());
		break;
	}

	string str;
	int count = 0;

	for (int i = 0; i < vTemp.size(); i++)
	{
		if (vTemp[i] == "|")
		{
			switch (kind)
			{
			case DATABASE_SYSTEM:
				break;
			case DATABASE_PLAYER:
				break;
			case DATABASE_ITEM:
				break;
			case DATABASE_MONSTER:
				break;
			}

		}
	}
}