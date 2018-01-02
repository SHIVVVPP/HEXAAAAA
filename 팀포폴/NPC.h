#pragma once
#include "gameNode.h"

class NPC :public gameNode
{
protected:

	image*		_Npcimage;			//npc�� �̹���
	RECT		_imgrc;				//npc�� ��Ʈ
	animation*  _aniNpc;			//animation

	float		_x;					//�߽���ǥ x
	float		_y;					//�߽���ǥ y
	int			_LeftStartMoveX;	//���� ���� NPC�� ���� ��ǥ
	int			_RightStartMoveX;   //������ ���� NPC�� ���� ��ǥ
	int			_tolkboxX;			//��ũ�ڽ� ������ x
	int			_tolkboxY;			//��ũ�ڽ� ������ y
	int			_tolkX;				//��ȭ ������x
	int			_tolkY;				//��ȭ ������y
	int         _tolkCout;			//��ũ ī��Ʈ;
	bool		_isRight;			//�������̳�?

	const char* fileName;			//�ؽ�Ʈ ���� �̸� ����

public:

	NPC();
	~NPC();

	//			�̹��� �̸�		�̹����� ��ǥ			 ��ȭ ����				��ȭ ��ġ			��ȭ�ڽ� ��ġ   npc�� ������
	HRESULT init(const char * ImageName, POINT position, const char* _fileName, POINT Talkposition, POINT TalkBox, bool isRight);
	void release();
	void update();
	void render();
	virtual void Move(bool _isRight);
	virtual void Converstion(int tolkCount);


	RECT getimgRC() {	return _imgrc;	}
};

