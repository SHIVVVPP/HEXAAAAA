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
	//game
	bool pause_on_lost_focus;
	bool show_feats;
	//control
	bool relic_input_type;
	//audio
	float music_volume;
	float sound_volume;
	

	element_system() {};
	~element_system() {};
};

class database : public singletonBase<database>
{
private:
	//시스템 정보
	typedef vector<string> arrElements;
	typedef vector<string>::iterator iterElements;

	typedef map<string, element_system*> arrElement_sys;
	typedef map<string, element_system*>::iterator iterElement_sys;

private:
	arrElement_sys _mSysElement;
	


public:
	database();
	~database();

	HRESULT init();
	void release();

	void loadDataBase(DATABASE_CLASS kind);


//SYSTEM 관련
	//설정자
	void setSystemData_pause_on_lost_focus(DATABASE_CLASS kind, bool state);
	void setSystemData_show_feats(DATABASE_CLASS kind, bool state);
	void setSystemData_relic_input_type(DATABASE_CLASS kind, bool state);
	void setSystemData_music_volume(DATABASE_CLASS kind, float value);
	void setSystemData_sound_volume(DATABASE_CLASS kind, float value);
	//접근자
	element_system getSystemData(DATABASE_CLASS kind) { return	arrElement_sys; }
};

