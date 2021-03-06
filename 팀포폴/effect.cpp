#include "stdafx.h"
#include "effect.h"
#include "animation.h"

effect::effect()
	: _effectImage(NULL),
	_effectAnimation(NULL),
	_isRunning(false),
	_x(0), _y(0)
{
}


effect::~effect()
{
	
}

HRESULT effect::init(image* effectImage, int frameW, int frameH, int fps, float elapsedTime)
{
	//이펙트 이미지가 없으면 실패처리 
	if ( !effectImage ) return E_FAIL;

	_isRunning = false;
	_effectImage = effectImage;
	_elapsedTime = elapsedTime;

	//이펙트 애니메이션이 없다면 할당해준다
	if ( !_effectAnimation ) _effectAnimation = new animation;

	_effectAnimation->init(_effectImage->getWidth(), _effectImage->getHeight(), frameW, frameH);
	_effectAnimation->setDefPlayFrame(false, false);
	_effectAnimation->setFPS(fps);
	_effectAnimation->stop();


	return S_OK;
}


void effect::release(void)
{
	_effectImage = NULL;
	SAFE_DELETE(_effectAnimation);
}

void effect::update(void) 
{
	//이펙트 재생이 False라면 실행시키지 않는다
	if ( !_isRunning ) return;

	//이펙트 애니메이션 재생시킨다
	_effectAnimation->frameUpdate(_elapsedTime);
	
	if ( !_effectAnimation->isPlay() ) killEffect();
}

void effect::render(void) 
{
	if ( !_isRunning ) return;

	_effectImage->aniRender(getMemDC(), CAMERAMANAGER->CameraRelativePointX(_x), CAMERAMANAGER->CameraRelativePointY(_y), _effectAnimation);
}

//이펙트 시작위치(center Axis 보정)
void effect::startEffect(int x, int y)
{
	if ( !_effectImage || !_effectAnimation ) return;

	_x = x;
	_y = y;
	_isRunning = true;
	_effectAnimation->start();
}

void effect::stretchstartEffect(int x, int y, int width, int height, int scale, bool use)
{
	if (!_effectImage || !_effectAnimation) return;
	_x = x; //x,y는 레프트 탑 좌표.
	_y = y;
	_width = width;
	_height = height;
	_useHeight = use;
	_isRunning = true;
	_effectAnimation->start();
	if (_effectAnimation->getPlayIndex() <= 0)
	{
		_effectAnimation->stop();
		_x += RND->getInt((_x +_width)/ scale);
		if(_useHeight)_y += RND->getInt((_y + _height) / scale);
		else _y = y;
		_isRunning = true;
		_effectAnimation->start();
	}
}


void effect::killEffect(void)
{
	_isRunning = false;
}
