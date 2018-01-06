#pragma once
#include "gameNode.h"
enum selectNum
{	
	selectNum0,
	selectNum1,
	selectNum2,
	selectNum3,
	selectNum4,
	selectNum5
};

class NPC :public gameNode
{
protected:

	image*		_Npcimage;				//npc의 이미지
	RECT		_imgrc;					//npc의 렉트
	animation*  _aniNpc;				//animation
	image*		_conversaion;			//대화창
	RECT		_tolkBox;				//대화창

	image*		_storeUI;				//상점UI
	image*		_firelod;				//파이어로드
	image*		_invenMusicSheet;		//악보
	image*		_invenMealTickets;		//음식티켓
	image*		_selectRectimg;			//선택렉트
	image*		_yesBox;				//yes
	image*		_noBox;					//no
	image*		_selectBox;				//박스박스박스
	image*		_done;

	float		_x;						//중심좌표 x
	float		_y;						//중심좌표 y
	int			_LeftStartMoveX;		//왼쪽 시작 NPC를 위한 좌표
	int			_RightStartMoveX;		//오른쪽 시작 NPC를 위한 좌표
	int			_tolkboxX;				//토크박스 포지션 x
	int			_tolkboxY;				//토크박스 포지션 y
	int			_tolkX;					//대화 포지션x
	int			_tolkY;					//대화 포지션y
	int         _tolkCout;				//토크 카운트;
	int			_tolkMaxsize;			//토크 맥스 카운트
	int			NpcSpeed;				//npc 움직임
	int			conversationCount;		//...
	int			selectx;
	int			selecty;
	int			_selectBoxX;
	int			_selectBoxY;
	int			selectbox;
	int			crrentx, crrenty;

	bool		_isMove;				//움직이냐?
	bool		_isRight;				//오른쪽이냐?
	bool		_istolk;				//토크 준비
	bool		_isMoreConverstion;		//대화가 더있냐?
	bool		_isSaller;				//상점 역활을 하니?
	bool		_isBuyYes;				//yes니?
	bool		_isSelect;				//선택되었니?
	bool		_isgetTiket;			//티켓이 있니?
	bool		_isgetfirelod;			//지팡이 있니?
	const char* fileName;				//텍스트 파일 이름 저장
	const char* fileName2;				//텍스트 파일 이름 저장
	const char* _imgName;
	const char* _imgName2;
	char str[128];
public:

	NPC();
	~NPC();

	//			이미지 이름		이미지의 좌표			 대화 파일				대화파일2			 npc의 움직이니?	npc의 방향			대화가 더있니			상점역활이니
	HRESULT init(const char * ImageName, const char * ImageName2, POINT position, const char* _fileName, const char* _fileName2, bool isMove, bool isRight, bool ismoreConversation, bool isSaller);
	void release();
	void update();
	virtual void render();
	virtual void aniMove();
	virtual void tolkdrow();
	virtual void Move(bool _isMvoe, bool _isRight);
	virtual void Converstion(int tolkCount);  

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
	void setcoversationCount(int num) { conversationCount += num; }
	void setisTolk(bool istolk) { _istolk = istolk; }


};

