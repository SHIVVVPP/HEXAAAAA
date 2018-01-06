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
#include"gard.h"
#include"Crown.h"
#include"goatician.h"

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

	int a;							//������ ���� �̱� ���� INT
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
	
	vector<NPC*> getVnpc() { return _vNPC; }
	vector<NPC*>::iterator getVinpc() { return _viNPC; }
};

