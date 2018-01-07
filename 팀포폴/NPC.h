#pragma once
#include "gameNode.h"
enum selectNum
{	
	selectNum0,
	selectNum1,
	selectNum2,
	selectNum3,
	selectNum4,
	selectNum5,
	selectNum6,
	selectNum7
};

class NPC :public gameNode
{
protected:

	image*		_Npcimage;				//npc�� �̹���
	RECT		_imgrc;					//npc�� ��Ʈ
	animation*  _aniNpc;				//animation
	image*		_conversaion;			//��ȭâ
	RECT		_tolkBox;				//��ȭâ

	image*		_storeUI;				//����UI
	image*		_firelod;				//���̾�ε�
	image*		_invenMusicSheet;		//�Ǻ�
	image*		_invenMealTickets;		//����Ƽ��
	image*		_posion;
	image*		_selectRectimg;			//���÷�Ʈ
	image*		_yesBox;				//yes
	image*		_noBox;					//no
	image*		_selectBox;				//�ڽ��ڽ��ڽ�
	image*		_done;					//����
	
	image*		_bardUI;				//�ٵ� ��û��
	image*		_bardUI2;				//�ٵ� �ȳ�â
	image*		_bardselectRectimg;		//�ٵ� ��û��� ����â
	image*		_bardYes;				//��������
	image*		_bardNo;				//������ ����

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
	int			selectx;
	int			selecty;
	int			_selectBoxX;
	int			_selectBoxY;
	int			selectbox;
	int			crrentx, crrenty;

	bool		_isMove;				//�����̳�?
	bool		_isRight;				//�������̳�?
	bool		_istolk;				//��ũ �غ�
	bool		_isMoreConverstion;		//��ȭ�� ���ֳ�?
	bool		_isSaller;				//���� ��Ȱ�� �ϴ�?
	bool		_isBuyYes;				//yes��?
	bool		_isSelect;				//���õǾ���?
	bool		_isgetTiket;			//Ƽ���� �ִ�?
	bool		_isgetfirelod;			//������ �ִ�?
	bool        _isgetMusicSheet;		//��Ʈ�� �ִ�?
	bool		_musicStart;			//���ǽ���

	const char* fileName;				//�ؽ�Ʈ ���� �̸� ����
	const char* fileName2;				//�ؽ�Ʈ ���� �̸� ����
	const char* _imgName;
	const char* _imgName2;
	const char* MusicName;

	char str[128];
public:

	NPC();
	~NPC();

	//			�̹��� �̸�		�̹����� ��ǥ			 ��ȭ ����				��ȭ����2			 npc�� �����̴�?	npc�� ����			��ȭ�� ���ִ�			������Ȱ�̴�
	HRESULT init(const char * ImageName, const char * ImageName2, POINT position, const char* _fileName, const char* _fileName2, bool isMove, bool isRight, bool ismoreConversation, bool isSaller);
	void release();
	void update();
	virtual void render();
	virtual void aniMove();
	virtual void tolkdrow();
	virtual void Move(bool _isMvoe, bool _isRight);
	virtual void Converstion(int tolkCount);  
	void imgset();

	RECT getimgRC() { return _imgrc; }
	bool getisMove() { return _isMove; }
	bool getisRight() { return _isRight; }
	bool getisTolk() { return _istolk; }
	bool getisSaller() { return _isSaller; }

	int	 getcoversationCount() { return conversationCount; }
	int  gettxtSizeMax() { return _tolkMaxsize; }

	bool getisTiket() { return _isgetTiket; }
	void setisgetTiket(bool Tiket) { _isgetTiket = Tiket; }

	bool getisfirelod() { return _isgetfirelod; }
	void setisfirelod(bool Tiket) { _isgetfirelod = Tiket; }

	bool getisMusicSheet() { return _isgetMusicSheet; }
	void setisMusicSheet(bool Tiket) { _isgetMusicSheet = Tiket; }

	bool getMusicStart() { return _musicStart; }
	void setMusicStart(bool Tiket) { _musicStart = Tiket; }

	void setcoversationCount(int num) { conversationCount += num; }
	void setisTolk(bool istolk) { _istolk = istolk; }

	const char* getMusicname() { return MusicName; }
};

