#pragma once
#include "gameNode.h"
#include "objects.h"
#include "platter.h"
#include "dirtblock.h"
#include "smalldirtblock.h"
#include "gem.h"
#include "ladder.h"
#include "dirtpile.h"
#include "moveblock.h"
#include "potion.h"
#include "food.h"
#include "meal.h"
#include "part.h"
#include "part2.h"
#include "bubbles.h"
#include "fakedirt.h"
#include "musicsheet.h"
#include "player.h"
#include "effect.h"
#include <vector>


#define GEM 0
#define DIRTPILE 1
#define DIRTFAKE 2
#define POTION 3
#define PLATTER 4
#define FOOD 5
#define MEAL 6
#define BUBBLE 6
#define MUSIC_SHEET 7

class objectManager : public gameNode
{
private:
	typedef vector<objects*> vO;
	typedef vector<objects*>::iterator viO;
private:
	vO _vgem;
	vO _vladder;
	vO _vmoveblock; 
	vO _vdirtpile;
	vO _vUse;
	vO _vdirtblock;
	vO _vbubble;
	vO _vplatter;
	vO _vpart;
	vO _vfakedirt;
	vO _vsheet;
	objects* _obj;
	int _hitcount;
	int _leftX;		   //여기까지 좌표 저장용 ;
	int _topY;		   //여기까지 좌표 저장용 ;
	int _x, _y;		   //여기까지 좌표 저장용 ;
	int x, y;		   //여기까지 좌표 저장용 ;
	int _tempx, _tempy;//여기까지 좌표 저장용 ;
	int _count;
	bool _isOpen;
	bool _iscrush;
	bool _istouched;
	player* _p;
	effect* _pickeffect;
public:
	objectManager();
	~objectManager();

	HRESULT init();
	void release();
	void update();
	void render();
	void setPosition();
	LPCOLLISION_INFO player_object_collision();
	void connectPlayer(player* p) { _p = p; }
};

