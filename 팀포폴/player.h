#pragma once
#include "gameNode.h"

enum PLAYERMAINCONDITION       // �ɸ����� ���� ���°� ������ ���� �̳ѹ�
{
	PLAYER_RIGHT_IDLE,  		  // ������ ������
	PLAYER_LEFT_IDLE,			  // ���� ������ 
	PLAYER_IDLE_JUMP,			  // ���ڸ� ����
	PLAYER_RIGHT_JUMP,			  // ������ ����
	PLAYER_LEFT_JUMP,			  // ���� ����
	PLAYER_RIGHT_MOVE,			  // ������ �̵�
	PLAYER_LEFT_MOVE,			  // ���� �̵�
	PLAYER_RIGHT_CLIMB,			  // ��ٸ� Ÿ���� ������ ��������
	PLAYER_LEFT_CLIMB,			  // ��ٸ� Ÿ���� ����Ű ��������
	PLAYER_CLIMB_EDGE,			  // ��ٸ� ��� ���ڶ��� ��ģ����
	PLAYER_RIGHT_ATTACK,		  // ������ ���� 
	PLAYER_RIGHT_JUMP_ATTACK,	  // ������ ��������
	PLAYER_LEFT_ATTACK,			  // ���� ���� 
	PLAYER_LEFT_JUMP_ATTACK,	  // ���� ��������
	PLAYER_DOWN_ATTACK,			  // �Ʒ� ����
	PLAYER_RIGHT_HITTED,		  // �����ʿ����� �ǰ�
	PLAYER_LEFT_HITTED,			  // ���ʿ����� �ǰ�
	PLAYER_DEAD,				  // ����

};

enum PLAYERSUBCONDITION		  // �÷��̾� ���� ���°��� ����  ex) npc�� ��ٸ��� ��Ʈ �浹 �� ���¿��� ����Ű�� ���� ��� Ʈ���� �뵵
{
	PLAYER_NOTHING,
	PLAYER_NPC,
	PLAYER_LADDER,
};
class player : public gameNode
{
	PLAYERMAINCONDITION _playerMainCondition;
	PLAYERSUBCONDITION _playerSubCondition;
	image* _image;
	animation* _ani;
	RECT _imageRC;
	RECT _playerRC;
	RECT _attackRC;
	int _maxHP;
	int _currentHP;
	int _maxMP;
	int _currentMP;
	int _playerGold;
	int _equipmentRelic;
	float _speed;
	float _jumpPower;
	float _gravity;
	float _x;
	float _y;
	float _probeY;
	float _repulsivePower;      // Ÿ�� �� �÷��̾ �ڷ� �ڿ������� �о�� ���� �ݹ߷�
	float _frictionalPower;		// �ݹ߷��� ������ �谨��Ű�� ���� ������
	bool _isJump;


public:
	player();
	~player();


	HRESULT init();
	void release();
	void update();
	void render();

	static void rightAttack(void* obj);
	static void leftAttack(void* obj);
	static void rightJumpAttack(void* obj);
	static void leftJumpAttack(void* obj);
	static void downAttack(void* obj);


	/////////// ĳ������ ���λ��� ������, ������ 
	PLAYERMAINCONDITION getPlayerMainCondition(void) { return _playerMainCondition; }
	void setPlayerMainCondition(PLAYERMAINCONDITION condition) { _playerMainCondition = condition; }

	//////////// ĳ������ ������� ������ ������
	PLAYERSUBCONDITION getPlayerSubCondition(void) { return _playerSubCondition; }
	void setPlayerSubCondition(PLAYERSUBCONDITION condition) { _playerSubCondition = condition; }


	////////  �÷��̾� �浹��Ʈ ������ ������
	RECT getPlayerRect() { return _playerRC; }

	//////// ���� ü�� ������ ������

	int getPlayerCurrentHP() { return _currentHP; }
	void setPlayerCurrentHP(int hp) { _currentHP = hp; }

	//////// �ִ� ü�� ������ ������
	int getPlayerMaxHP() { return _maxHP; }
	void setPlayerMaxHP(int hp) { _maxHP = hp; }


	/////// ���� ����  ������ ������
	int getPlayerCurrentMP() { return _currentMP; }
	void setPlayerCurrentMP(int mp) { _currentMP = mp; }


	/////// �ִ� ���� ������ ������  
	int getPlayerMaxMP() { return _maxMP; }
	void setPlayerMaxMP(int mp) { _maxMP = mp; }


	/////// ���  ������ ������
	int getPlayerGold() { return _playerGold; }
	void setPlayerGold(int gold) { _playerGold = gold; }


	//////  ������ ������ ������ȣ ������ ������
	int getEquipRelic() { return _equipmentRelic; }
	void setEquipRelic(int relicValue) { _equipmentRelic = relicValue; }

};

