#pragma once
#include "gameNode.h"

class animation;

class effect : public gameNode
{
protected:
	int			_x;			//¿Ã∆Â∆Æ ¡¬«•
	int			_y;
	int			_width;
	int			_height;
	int			_scale;
	bool		_useHeight;
	image*		_effectImage;
	animation*	_effectAnimation;
	BOOL		_isRunning;
	float		_elapsedTime;

public:
	effect();
	~effect();

	virtual HRESULT init(image* effectImage, int frameW, int frameH, int fps, float elapsedTime);

	virtual void release(void);
	virtual void update(void);
	virtual void render(void);

	void startEffect(int x, int y);
	void stretchstartEffect(int x, int y, int width ,int height, int scale , bool use);
	virtual void killEffect(void);

	BOOL getIsRunning(void) { return _isRunning; }
};

