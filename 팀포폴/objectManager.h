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


#define GEM 11
#define DIRTBLOCK 12
#define POTION 13
#define FOOD 14
#define MEAL 15
#define BUBBLE 16
#define MUSIC_SHEET 17
#define MOVING_PILE 18
#define PLATTER 19
#define FAKEDIRT 20
#define DIRTPILE 21
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
	int _rangeCount;
	int tempY;
	bool _isOpen;
	bool _iscrush;
	bool _istouched;
	bool _isHit;
	int addY;
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
	void player_object_collision();
	void connectPlayer(player* p) { _p = p; }
	void createGem(int range, int leftX,int topY, int leftX2, int topY2){
		_obj = new gem;
		_obj->init(range, leftX, topY, leftX2, topY2, 3.0f, PI);
		_vgem.push_back(_obj);
	}
};

