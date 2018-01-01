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
	_playerMaxHP = 3;
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
		_gold_render += 0.3f;
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
	_uiBackground->render(getMemDC(), 0, 0);

	render_Gold();
	render_HP();
}

void ui::render_Gold()
{
	int p = _gold_render;
	int k = 0;
	int i = 0;
	for (int j = 1; j <= _gold_render; j *=10)
	{
		i++;
	}



	while (p != 0)
	{
		IMAGEMANAGER->findImage("number")->frameRender(getMemDC(), 51+ 30*(i-1) - 30*k , 33, p % 10, 0);
		p /= 10;
		k++;
	}

}

void ui::render_HP()
{
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

	/*for (int i = 0; i < maxHpPlace; i++)
	{
		IMAGEMANAGER->findImage("ui_playerHP")->frameRender(getMemDC(), 624+ i*34, 30, 0, 0);
	}
*/
	for (int i = 0; i < HpPlace; i++)
	{
		if(i == HpPlace -1)
			IMAGEMANAGER->findImage("ui_playerHP")->frameRender(getMemDC(), 624 + i * 34, 30, 2-_playerHP%2, 0);
		else
			IMAGEMANAGER->findImage("ui_playerHP")->frameRender(getMemDC(), 624 + i * 34, 30, 2, 0);
	}
}

void ui::render_bossHP()
{
}
