//#include "stdafx.h"

#include "rect.h"

void CRect::SetRect(LONG nLeft, LONG nTop, LONG nRight, LONG nBottom)
{
	left = nLeft;
   top = nTop;
   right = nRight;
   bottom = nBottom;
}

POINT CRect::GetTopLeft()
{
	POINT pt;
   pt.x = left;
   pt.y = top;
   return pt;
}

POINT CRect::GetBottomLeft()
{
	POINT pt;
   pt.x = left;
   pt.y = bottom;
   return pt;
}

POINT CRect::GetTopRight()
{
	POINT pt;
   pt.x = right;
   pt.y = top;
   return pt;
}

POINT CRect::GetBottomRight()
{
	POINT pt;
   pt.x = right;
   pt.y = bottom;
   return pt;
}

void CRect::SetOrigin(POINT &pt)
{
	right = (right-left)+pt.x;
	left = pt.x;
   bottom = (bottom-top)+pt.y;
   top = pt.y;
}

void CRect::SetOrigin(LONG nLeft, LONG nTop)
{
	right = (right-left)+nLeft;
   left = nLeft;
   bottom = (bottom-top)+nTop;
   top = nTop;
}

void CRect::OffsetRect(LONG dx, LONG dy)
{
    ::OffsetRect(this, dx, dy);
}

void CRect::OffsetRect(POINT &pt)
{
    ::OffsetRect(this, pt.x, pt.y);
}

const CRect& CRect::operator=(const CRect& rectSrc)
{
	left = rectSrc.left;
   top = rectSrc.top;
   right = rectSrc.right;
   bottom = rectSrc.bottom;

	return *this;
}

void CRect::UnionRect(LPRECT lpRect)
{
    ::UnionRect(this, this, lpRect);
}

BOOL CRect::PtInRect(int x, int y)
{
    POINT aPoint;

    aPoint.x = x;
    aPoint.y = y;

    return ::PtInRect(this, aPoint);
}
