#pragma once
#include "gameNode.h"
// MoveNPC
#include"waterGirl.h"
#include"deerLady.h"
#include"hedgeFarmer.h"
#include"bagFella.h"
#include"genericKnight.h"
// NotMove NPC
#include"Molly.h"
#include"Tim.h"
#include"Bard.h"
#include"Sepp.h"
#include"waterGirl.h"
#include"Wizard.h"
#include"gard.h"
#include"Crown.h"
#include"goatician.h"


#include "player.h"

class NPCManager : public gameNode
{
private:
	typedef vector<NPC*> vNPC;				//Npc������ ���� ���Ϳ� ����
	typedef vector<NPC*>::iterator viNPC;	//Npc������ ���� ���ͷ�����
private:


	vNPC  _vNPC;
	viNPC _viNPC;

	float _x;								//Npc ���� X��ǥ
	float _y;								//Npc ���� Y��ǥ

	player* _p;

	int _CCount;							//������ ���� �̱� ���� INT

	RECT rc;
	RECT _table;			// ���� x = 2770, y= 530
	const char* crrentMusicName;
	const char* oldMusicName;
	char str[128];
public:
	NPCManager();
	~NPCManager();

	HRESULT init();
	void release();
	void update();
	void render();

	void setNpc();							// �ڸ����� npcȣ��
	void setLeftNpc(bool _isRight);			// �����̴� npc
	void setRightNpc(bool _isRight);		// �����̴� npc
	void removeNpc(int arrNum);

	void collision();
	LPCOLLISION_INFO player_npc_collision();
	vector<NPC*> getVnpc() { return _vNPC; }
	vector<NPC*>::iterator getVinpc() { return _viNPC; }
	void connectPlayer(player* p) { _p = p; }
};

