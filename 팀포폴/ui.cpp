#include "stdafx.h"
#include "ui.h"


ui::ui()
{
}


ui::~ui()
{
}

HRESULT ui::init(UI_STYLE style)
{
	_style = style;
	_uiBackground = new image;
	switch (_style)
	{
	case UI_STAGE: case UI_TOWN:
		_uiBackground = IMAGEMANAGER->findImage("UI_basic");
	break;
	case UI_WORLDMAP:
		_uiBackground = IMAGEMANAGER->findImage("UI_worldMap");
	break;
	}
	/*_playerHP = DATABASE->getCurrentPlayerInfo()->player_HP;
	_playerMaxHP = DATABASE->getCurrentPlayerInfo()->player_MaxHP;
	_playerMP = DATABASE->getCurrentPlayerInfo()->player_MP;
	_gold = _gold_render = DATABASE->getCurrentPlayerInfo()->player_Gold;*/
	_playerHP = 0;
	_playerMaxHP = 10;
	_playerMP = 30;
	_gold = _gold_render = 1000;

	return S_OK;
}

void ui::release()
{
}

void ui::update()
{
	/*_playerHP = DATABASE->getCurrentPlayerInfo()->player_HP;
	_playerMaxHP = DATABASE->getCurrentPlayerInfo()->player_MaxHP;
	_playerMP = DATABASE->getCurrentPlayerInfo()->player_MP;
	_gold = DATABASE->getCurrentPlayerInfo()->player_Gold;*/

	if (_gold > _gold_render)
	{
		_gold_render += 1.0f;
		if (_gold_render > _gold) _gold_render = _gold;
	}

	if (KEYMANAGER->isOnceKeyDown(VK_UP))
	{
		_playerHP++;
		_gold += 10;
	}
}

void ui::render()
{
	switch (_style)
	{
	case UI_STAGE: case UI_TOWN:
		_uiBackground->render(getMemDC(), 0, 0);

		break;
	case UI_WORLDMAP:
		_uiBackground->render(getMemDC(), 0, WINSIZEY-_uiBackground->getHeight());

		break;
	}

	render_Gold();
	render_HP();
}

void ui::render_Gold()
{
	//224 764
	int p = _gold_render;
	int k = 0;
	int i = 0;
	for (int j = 1; j <= _gold_render; j *=10)
	{
		i++;
	}


	switch (_style)
	{
	case UI_STAGE: case UI_TOWN:
		while (p != 0)
		{
			IMAGEMANAGER->findImage("number")->frameRender(getMemDC(), 51 + 30 * (i - 1) - 30 * k, 33, p % 10, 0);
			p /= 10;
			k++;
		}
		break;
	case UI_WORLDMAP:
		while (p != 0)
		{
			IMAGEMANAGER->findImage("number")->frameRender(getMemDC(), 224 + 30 * (i - 1) - 30 * k, 764, p % 10, 0);
			p /= 10;
			k++;
		}
		break;

	}

}

void ui::render_HP()
{//268 816
	int maxHpPlace = 0;
	int HpPlace = 0;

	for (int i = 0; i < _playerMaxHP; i += 2)
	{
		maxHpPlace++;
	}
	for (int i = 0; i < _playerHP; i += 2)
	{
		HpPlace++;
	}
	switch (_style)
	{
	case UI_STAGE: case UI_TOWN:
		for (int i = 0; i < maxHpPlace; i++)
		{
			IMAGEMANAGER->findImage("ui_playerHP")->frameRender(getMemDC(), 624 + i * 34, 30, 0, 0);
		}

		for (int i = 0; i < HpPlace; i++)
		{
			if (i == HpPlace - 1)
				IMAGEMANAGER->findImage("ui_playerHP")->frameRender(getMemDC(), 624 + i * 34, 30, 2 - _playerHP % 2, 0);
			else
				IMAGEMANAGER->findImage("ui_playerHP")->frameRender(getMemDC(), 624 + i * 34, 30, 2, 0);
		}
		break;
	case UI_WORLDMAP:
		for (int i = 0; i < maxHpPlace; i++)
		{
			IMAGEMANAGER->findImage("ui_playerHP")->frameRender(getMemDC(), 268 + i * 34, 816, 0, 0);
		}

		for (int i = 0; i < HpPlace; i++)
		{
			if (i == HpPlace - 1)
				IMAGEMANAGER->findImage("ui_playerHP")->frameRender(getMemDC(), 268 + i * 34, 816, 2 - _playerHP % 2, 0);
			else
				IMAGEMANAGER->findImage("ui_playerHP")->frameRender(getMemDC(), 268 + i * 34, 816, 2, 0);
		}
		break;

	}
}


void ui::render_bossHP()
{
}
