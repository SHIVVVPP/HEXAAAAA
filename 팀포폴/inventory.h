#pragma once
#include "gameNode.h"
#include <string>
#include <vector>

#define CURSORPOINT0 0 //Ŀ����ġ �Ǻ�
#define CURSORPOINT1 1
#define CURSORPOINT2 2
#define CURSORPOINT3 3
#define CURSORPOINT4 4
#define CURSORPOINT5 5
#define CURSORPOINT6 6
#define CURSORPOINT7 7
#define CURSORPOINT8 8
#define CURSORPOINT9 9

#define Relics0 11 //�κ��丮 â ����
#define Relics1 12
#define Relics2 13

#define Gear0 14   //�κ��丮 â�� ���
#define Gear1 15
#define Gear2 16
#define Gear3 17
#define Gear4 18
#define Gear5 19
#define Gear6 20

struct tagRelics
{
	image* _image; //�κ��� �������� �̹���.
	RECT _rc;	  //�κ� ���� �������� ��Ʈ (Ŀ������ ��Ʈ�浹�� ���ÿ��� Ȯ��)
	float _x, _y; //�κ� �������� ��ǥ.
	int _itemNum;
	int _textPos;
	bool _isRelic;
	//������ ���� ����.
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
	vector<tagRelics> _vRelic; //�κ� �� ���� ������ 
	vector<tagRelics>::iterator _viRelic; //�κ� ��  ���� ������
private:
	const char* _RelicName;

	bool _isGet;
public:
	HRESULT init(const char* imageName, int itemNum, bool isrelic, bool isGet);
	void release();
	void update();
	void render();

	//����������.
	vector<tagRelics> &getVRelic() { return _vRelic; }
	vector<tagRelics>::iterator &getViRelic() { return _viRelic; }

	inventoryRelic();
	~inventoryRelic();
};

class inventoryGear : public gameNode
{
private:
	vector<tagGear> _vGear; //�κ� �� ��� ������
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
	RECT _checkRect; //������ Ȯ�ο� ��Ʈ.
	RECT _checkRect2;
	//���� Ŀ�����ۿ� ������
	RECT _cursorRect; //Ŀ���� ��Ʈ
	POINT _center; //Ŀ�� �߽���ǥ
	int _cursorPoint; //Ŀ�������� (����ġ�� �Ǵ�.)
	int _cursorAlpha; //Ŀ�� ���İ�
	int _count; //���İ� ������ ī��Ʈ
	bool _relic; // ����â ? ���â ����.
	image* _invenImage; //�κ� â�����.
	image* _cursor; //Ŀ���̹���;
	animation* _invenani; //�κ� ������ �ִϸ��̼�.
public:
	inventory();
	~inventory();

	HRESULT init();
	void release();
	void update();
	void render();
	void cursorMove(); //Ŀ�� ������ �Լ�
					   //�κ� ���� ���� ������ ����.
	void draw();
	//����Ҽ��� ������ �� �ϳ� ����.
	static void invenScene();
};

