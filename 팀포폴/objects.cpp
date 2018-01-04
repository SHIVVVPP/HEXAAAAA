#include "stdafx.h"
#include "objects.h"


objects::objects()
{
}


objects::~objects()
{
}

HRESULT objects::init(int x, int y, int range, bool isRight)
{
	return E_NOTIMPL;
}

HRESULT objects::init(int x, int y, int startX, int startY)
{
	return E_NOTIMPL;
}

HRESULT objects::init(int x, int y)
{
	return E_NOTIMPL;
}

HRESULT objects::init(int x, int y, float length)
{
	return E_NOTIMPL;
}

HRESULT objects::init(const char* imageName, int goldup,  int range)
{
	return E_NOTIMPL;
}

void objects::update()
{
	move();
}

void objects::render()
{
}

void objects::release()
{
}

void objects::move()
{
}

void objects::fire(int x, int y,int startX, int startY, float speed, float angle)
{
}
