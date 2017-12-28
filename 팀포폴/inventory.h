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

#define Relics0 0 //�κ��丮 â ����
#define Relics1 1
#define Relics2 2

#define Gear0 3   //�κ��丮 â�� ���
#define Gear1 4
#define Gear2 5
#define Gear3 6
#define Gear4 7
#define Gear5 8
#define Gear6 9

struct tagRelics
{
	image* _image; //�κ��� �������� �̹���.
	RECT _rc;	  //�κ� ���� �������� ��Ʈ (Ŀ������ ��Ʈ�浹�� ���ÿ��� Ȯ��)
	float _x, _y; //�κ� �������� ��ǥ.
	int _itemNum;
	bool _isRelic;
	//������ ���� ����.
};

struct tagGear
{
	image* _image;
	RECT _rc;
	float _x, _y;
};
class inventoryItem : public gameNode
{
private:
	vector<tagRelics> _vRelic; //�κ� �� ���� ������ 
	vector<tagRelics>::iterator _viRelic; //�κ� ��  ���� ������
private:
	const char* _imageName;
	bool _isGet;
public:
	HRESULT init(const char* imageName, int itemNum, bool isrelic, bool isGet);

	void release();
	void update();
	void render();

	//����������.
	vector<tagRelics> &getVRelic() { return _vRelic; }
	vector<tagRelics>::iterator &getViRelic() { return _viRelic; }
	inventoryItem();
	~inventoryItem();
};

class inventory : public gameNode
{
private:
	inventoryItem * _invenItem;
	RECT _checkRect; //������ Ȯ�ο� ��Ʈ.
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

					   //����Ҽ��� ������ �� �ϳ� ����.
	static void invenScene();
};

