#pragma once
#include "gameNode.h"

enum UI_STYLE 
{
	UI_STAGE,
	UI_TOWN,
	UI_WORLDMAP,
};

class ui : public gameNode
{
private:
	UI_STYLE _style;


	image* _uiBackground;

	int _gold;
	float _gold_render;
	int _playerMaxHP,_playerHP, _bossHP;
	int _playerMP;

public:
	ui();
	~ui();

	HRESULT init(UI_STYLE style);
	void release();
	void update();
	void render();

	void render_Gold();
	void render_HP();
	void render_bossHP();

};

