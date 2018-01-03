#pragma once
#include "gameNode.h"

class NPC :public gameNode
{
protected:

	image*		_Npcimage;				//npc�� �̹���
	RECT		_imgrc;					//npc�� ��Ʈ
	animation*  _aniNpc;				//animation
	image*		_conversaion;			//��ȭâ
	RECT		_tolkBox;				//��ȭâ

	image*		_yesBox;				//yes
	image*		_noBox;					//no

	float		_x;						//�߽���ǥ x
	float		_y;						//�߽���ǥ y
	int			_LeftStartMoveX;		//���� ���� NPC�� ���� ��ǥ
	int			_RightStartMoveX;		//������ ���� NPC�� ���� ��ǥ
	int			_tolkboxX;				//��ũ�ڽ� ������ x
	int			_tolkboxY;				//��ũ�ڽ� ������ y
	int			_tolkX;					//��ȭ ������x
	int			_tolkY;					//��ȭ ������y
	int         _tolkCout;				//��ũ ī��Ʈ;
	int			_tolkMaxsize;			//��ũ �ƽ� ī��Ʈ
	int			NpcSpeed;				//npc ������
	int			conversationCount;		//...
	
	bool		_isMove;				//�����̳�?
	bool		_isRight;				//�������̳�?
	bool		_istolk;				//��ũ �غ�
	bool		_isMoreConverstion;		//��ȭ�� ���ֳ�?
	bool		_isSaller;				//���� ��Ȱ�� �ϴ�?
	bool		_isYes;					//yes��?

	const char* fileName;				//�ؽ�Ʈ ���� �̸� ����
	const char* fileName2;				//�ؽ�Ʈ ���� �̸� ����
public:

	NPC();
	~NPC();

	//			�̹��� �̸�		�̹����� ��ǥ			 ��ȭ ����				��ȭ����2			 npc�� �����̴�?	npc�� ����			��ȭ�� ���ִ�			������Ȱ�̴�
	HRESULT init(const char * ImageName, POINT position, const char* _fileName, const char* _fileName2, bool isMove, bool isRight, bool ismoreConversation, bool isSaller);
	void release();
	void update();
	void render();
	virtual void Move(bool _isMvoe, bool _isRight);
	virtual void Converstion(int tolkCount);


	RECT getimgRC() { return _imgrc; }
	bool getisMove() { return _isMove; }
	bool getisRight() { return _isRight; }
	bool getisTolk() { return _istolk; }
	int	 getcoversationCount() { return conversationCount; }
	int  gettxtSizeMax() { return _tolkMaxsize; }

	void setcoversationCount(int num) { conversationCount += num; }
	void setisTolk(bool istolk) { _istolk = istolk; }


};

