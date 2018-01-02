#pragma once
#include "gameNode.h"

class NPC :public gameNode
{
protected:

	image*		_Npcimage;			//npc의 이미지
	RECT		_imgrc;				//npc의 렉트
	animation*  _aniNpc;			//animation

	float		_x;					//중심좌표 x
	float		_y;					//중심좌표 y
	int			_LeftStartMoveX;	//왼쪽 시작 NPC를 위한 좌표
	int			_RightStartMoveX;   //오른쪽 시작 NPC를 위한 좌표
	int			_tolkboxX;			//토크박스 포지션 x
	int			_tolkboxY;			//토크박스 포지션 y
	int			_tolkX;				//대화 포지션x
	int			_tolkY;				//대화 포지션y
	int         _tolkCout;			//토크 카운트;
	bool		_isRight;			//오른쪽이냐?

	const char* fileName;			//텍스트 파일 이름 저장

public:

	NPC();
	~NPC();

	//			이미지 이름		이미지의 좌표			 대화 파일				대화 위치			대화박스 위치   npc의 움직임
	HRESULT init(const char * ImageName, POINT position, const char* _fileName, POINT Talkposition, POINT TalkBox, bool isRight);
	void release();
	void update();
	void render();
	virtual void Move(bool _isRight);
	virtual void Converstion(int tolkCount);


	RECT getimgRC() {	return _imgrc;	}
};

