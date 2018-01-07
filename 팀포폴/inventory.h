#pragma once
#include "gameNode.h"
#include <string>
#include <vector>

#define CURSORPOINT0 0 //커서위치 판별
#define CURSORPOINT1 1
#define CURSORPOINT2 2
#define CURSORPOINT3 3
#define CURSORPOINT4 4
#define CURSORPOINT5 5
#define CURSORPOINT6 6
#define CURSORPOINT7 7
#define CURSORPOINT8 8
#define CURSORPOINT9 9

#define Relics0 11 //인벤토리 창 유물
#define Relics1 12
#define Relics2 13

#define Gear0 14   //인벤토리 창의 장비 삽
#define Gear1 15   //갑옷
#define Gear2 16   //체력캡
#define Gear3 17   //밀티켓
#define Gear4 18   //악보
struct tagRelics
{
	image* _image; //인벤속 아이템의 이미지.
	RECT _rc;	  //인벤 내의 아이템의 렉트 (커서와의 렉트충돌로 선택여부 확인)
	float _x, _y; //인벤 아이템의 좌표.
	int _itemNum;
	int _textPos;
	bool _isRelic;
	//아이템 소지 여부.
};

struct tagGear
{
	image* _image;
	RECT _rc;
	float _x, _y;
	int _itemNum;
	int _textPos;
	bool _isGear;
};
class inventoryRelic : public gameNode
{
private:
	vector<tagRelics> _vRelic; //인벤 내 유물 아이템 
	vector<tagRelics>::iterator _viRelic; //인벤 내  유물 아이템
private:
	const char* _RelicName;

	bool _isGet;
public:
	HRESULT init(const char* imageName, int itemNum, bool isrelic, bool isGet);
	void release();
	void update();
	void render();

	//벡터접근자.
	vector<tagRelics> &getVRelic() { return _vRelic; }
	vector<tagRelics>::iterator &getViRelic() { return _viRelic; }

	inventoryRelic();
	~inventoryRelic();
};

class inventoryGear : public gameNode
{
private:
	vector<tagGear> _vGear; //인벤 내 기어 아이템
	vector<tagGear>::iterator _viGear;
private:
	const char* _GearName;
	bool _isGet;
public:
	HRESULT init(const char* imageName, int itemNum, bool isGear, bool isGet);
	void release();
	void update();
	void render();

	vector<tagGear> &getVGear() { return _vGear; }
	vector<tagGear>::iterator &getViGear() { return _viGear; }


	inventoryGear();
	~inventoryGear();
};
class inventory : public gameNode
{
private:

	inventoryRelic* _invenRelic;
	inventoryGear* _invenGear;
	RECT _checkRect; //아이템 확인용 렉트.
	RECT _checkRect2;
	//이하 커서조작용 변수들
	RECT _cursorRect; //커서의 렉트
	POINT _center; //커서 중심좌표
	int _cursorPoint; //커서움직임 (스위치로 판단.)
	int _cursorAlpha; //커서 알파값
	int _count; //알파값 깜빡이 카운트
	bool _relic; // 유물창 ? 장비창 여부.
	image* _invenImage; //인벤 창띄우기용.
	image* _cursor; //커서이미지;
	animation* _invenani; //인벤 열리는 애니메이션.
public:
	inventory();
	~inventory();

	HRESULT init();
	void release();
	void update();
	void render();
	void cursorMove(); //커서 움직임 함수
					   //인벤 내의 벡터 접근자 설정.
	void draw();
	//사용할수도 있으니 씬 하나 만듬.
	static void invenScene();
};

