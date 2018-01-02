#pragma once
#include "gameNode.h"
struct tagbullet
{
	image* bulletImage;
	RECT rc;
	float x, y;
	float angle;
	float radius;
	float speed;
	float fireX, fireY;
	bool isFire;
	int count;
};
class bullet : public gameNode
{
private:
	vector<tagbullet> _vBullet;
	vector<tagbullet>::iterator _viBullet;

	const char* _imageName;
	float _range;
	int _bulletMax;
public:

	HRESULT init(const char* imageName, int bulletMax, float range);
	void release(void);
	void update(void);
	void render(void);

	void fire(float x, float y, float angle, float speed);

	void move(void);

	void removeBullet(int arrNum);

	vector<tagbullet> getVBullet() { return _vBullet; }
	vector<tagbullet>::iterator getVIBullet() { return _viBullet; }
	bullet();
	~bullet();
};

