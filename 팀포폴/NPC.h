#pragma once
#include "gameNode.h"

class NPC :public gameNode
{
protected:

	image*		_Npcimage;			//npc�� �̹���
	RECT		_imgrc;				//npc�� ��Ʈ
	animation*  _aniNpc;			//animation
	image*		_conversaion;		//��ȭâ
	RECT		_tolkBox;			//��ȭâ

	float		_x;					//�߽���ǥ x
	float		_y;					//�߽���ǥ y
	int			_LeftStartMoveX;	//���� ���� NPC�� ���� ��ǥ
	int			_RightStartMoveX;   //������ ���� NPC�� ���� ��ǥ
	int			_tolkboxX;			//��ũ�ڽ� ������ x
	int			_tolkboxY;			//��ũ�ڽ� ������ y
	int			_tolkX;				//��ȭ ������x
	int			_tolkY;				//��ȭ ������y
	int         _tolkCout;			//��ũ ī��Ʈ;
	int			NpcSpeed;
	
	bool		_isMove;			//�����̳�?
	bool		_isRight;			//�������̳�?
	bool		_istolk;			//��ũ �غ�
	

	const char* fileName;			//�ؽ�Ʈ ���� �̸� ����

public:

	NPC();
	~NPC();

	//			�̹��� �̸�		�̹����� ��ǥ			 ��ȭ ����	   npc�� �����̴�?	npc�� ����	
	HRESULT init(const char * ImageName, POINT position, const char* _fileName, bool isMove,bool isRight);
	void release();
	void update();
	void render();
	virtual void Move(bool _isMvoe, bool _isRight);
	virtual void Converstion(int tolkCount);


	RECT getimgRC() { return _imgrc; }
	bool getisMove() { return _isMove; }
	bool getisRight() { return _isRight; }
	bool getisTolk() { return _istolk; }
	void setisTolk(bool istolk) { _istolk = istolk; }
};

