#pragma once
#include "gameNode.h"
// MoveNPC
#include"waterGirl.h"
#include"maiden.h"
#include"hedgeFarmer.h"
#include"bagFella.h"
#include"genericKnight.h"
// NotMove NPC
#include"Molly.h"
#include"Tim.h"
#include"Bard.h"
#include"Merchant.h"
#include"Sepp.h"
#include"waterGirl.h"
#include"Wizard.h"

class NPCManager : public gameNode
{
private:
	typedef vector<NPC*> vNPC;				//Npc관리를 위해 벡터에 담음
	typedef vector<NPC*>::iterator viNPC;	//Npc관리를 위한 이터레이터
private:


	vNPC  _vNPC;
	viNPC _viNPC;

	float _x;								//Npc 지정 X죄표
	float _y;								//Npc 지정 Y좌표

	int _rndInt;							//랜덤한 수를 뽑기 위한 INT

public:
	NPCManager();
	~NPCManager();

	HRESULT init();
	void release();
	void update();
	void render();

	void setNpc();							// 자리고정 npc호출
	void setLeftNpc(bool _isRight);			// 움직이는 npc
	void setRightNpc(bool _isRight);		// 움직이는 npc
	void removeNpc(int arrNum);

	
	vector<NPC*> getVnpc() { return _vNPC; }
	vector<NPC*>::iterator getVinpc() { return _viNPC; }
};

