#pragma once

//=============================================
// ## 17.09.29 ## CommonMacroFunction ##
//=============================================

inline POINT PointMake(int x, int y)
{
	POINT pt = { x, y };

	return pt;
}

inline RECT resiezeRect(RECT rc,int x, int y)
{
	int centerX = (rc.left + rc.right) / 2;
	int centerY = (rc.top + rc.bottom) / 2;
	int width = rc.right - rc.left;
	int height = rc.bottom - rc.top;

	RECT R  = { centerX - (width / 2)+x/2, centerY - (height / 2)+y/2, centerX + (width / 2)-x/2, centerY + (height / 2)-y/2 };
	return R;
}
inline RECT resiezeRect(RECT* rc, int x, int y)
{
	int centerX = (rc->left + rc->right) / 2;
	int centerY = (rc->top + rc->bottom) / 2;
	int width = rc->right - rc->left;
	int height = rc->bottom - rc->top;

	RECT R = { centerX - (width / 2) + x / 2, centerY - (height / 2) + y / 2, centerX + (width / 2) - x / 2, centerY + (height / 2) - y / 2 };
	return R;
}

inline bool isOut(RECT rc1, RECT rc2)
{
	if ((rc1.left > rc2.right || rc1.right < rc2.left))
	{
		return true;
	}
	else return false;
}

inline int getCenterX(RECT rc)
{
	return (rc.left + rc.right) / 2;
}
inline int getCenterY(RECT rc)
{
	return (rc.top + rc.bottom) / 2;
}
inline int getWidth(RECT rc)
{
	return rc.right - rc.left;
}
inline int getHeight(RECT rc)
{
	return rc.bottom - rc.top;
}


inline void easyRectangle(HDC hdc, RECT rc)
{
	Rectangle(hdc, rc.left, rc.top, rc.right, rc.bottom);
}

inline void LineMake(HDC hdc, int x1, int y1, int x2, int y2)
{
	MoveToEx(hdc, x1, y1, NULL);
	LineTo(hdc, x2, y2);
}

inline RECT RectMake(int x, int y, int width, int height)
{
	RECT rc = { x, y, x + width, y + height };

	return rc;
}

inline RECT RectMakeCenter(int x, int y, int width, int height)
{
	RECT rc = { x - (width / 2), y - (height / 2), x + (width / 2), y + (height / 2) };

	return rc;
}

inline void RectangleMake(HDC hdc, int x, int y, int width, int height)
{
	Rectangle(hdc, x, y, x + width, y + height);
}

inline void RectangleMakeCenter(HDC hdc, int x, int y, int width, int height)
{
	Rectangle(hdc, x - width / 2, y - height / 2, x + width / 2, y + height / 2);
}

inline void EllipseMake(HDC hdc, int x, int y, int width, int height)
{
	Ellipse(hdc, x, y, x + width, y + height);
}

inline void EllipseMakeCenter(HDC hdc, int x, int y, int width, int height)
{
	Ellipse(hdc, x - width / 2, y - height / 2, x + width / 2, y + height / 2);
}