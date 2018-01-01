#pragma once
#include "singletonBase.h"
#include <vector>
#include <map>


enum DATABASE_CLASS
{
	DATABASE_SYSTEM,
	DATABASE_PLAYER,
	DATABASE_ITEM,
	DATABASE_MONSTER,
};


class element_system
{
public:
	//game
	bool pause_on_lost_focus;
	bool show_feats;
	//control
	bool relic_input_type;
	//audio
	float music_volume;
	float sound_volume;
	

	element_system() 
	{ 
		pause_on_lost_focus = false;
		show_feats = false;
		relic_input_type = false;
		music_volume = 0.5f;
		sound_volume = 0.5f;
	};
	~element_system() {};
};

class element_player
{
public:
	int player_HP;
	int player_MaxHP;
	int player_MP;
	int player_Gold;

	element_player() {};
	~element_player() {};

};

class database : public singletonBase<database>
{
private:
	typedef vector<string> vString;
	typedef vector<string>::iterator viString;

private:
	element_system* sys_element;

	element_player* player_current_element; //현재 플레이어의 정보
	element_player* player_save_element; // 세이브 포인트시 플레이어의 정보



public:
	database();
	~database();


	HRESULT init();
	void release();

	//시스템
		//접근자
	element_system* getElement_system() { return sys_element; }
	//설정자
	void setSys_pauseOnLostFocus(bool state) { sys_element->pause_on_lost_focus = state; }
	void setSys_showFeats(bool state) { sys_element->show_feats = state; }
	void setSys_relicInputType(bool state) { sys_element->relic_input_type = state; }
	void setSys_musicVolume(float value) { sys_element->music_volume = value; }
	void setSys_soundVolume(float value) { sys_element->sound_volume = value; }


	//플레이어
	element_player* getCurrentPlayerInfo() { return player_current_element; }
	element_player* getPresentPlayerInfo() { return player_save_element; }

	void setPlayer_currentInfo(int HP, int max, int MP, int Gold)
	{
		player_current_element->player_HP = HP;
		player_current_element->player_MaxHP = max;
		player_current_element->player_MP = MP;
		player_current_element->player_Gold = Gold;
	}

	void setPlayer_savePoint(int HP, int max, int MP, int Gold)
	{
		player_save_element->player_HP = HP;
		player_current_element->player_MaxHP = max;
		player_save_element->player_MP = MP;
		player_save_element->player_Gold = Gold;
	}
};

