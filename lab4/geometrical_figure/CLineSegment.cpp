#include "pch.h"
#include "CLineSegment.h"


CLineSegment::CLineSegment(CPoint const& startPont, CPoint const& endPoint, uint32_t outlineColor)
	: m_startPoint(startPont)
	, m_endPoint(endPoint)
	, CShape("LineSegment", outlineColor)
{
}

CPoint CLineSegment::GetStartPoint() const
{
	return m_startPoint;
}

CPoint CLineSegment::GetEndPoint() const
{
	return m_endPoint;
}

double CLineSegment::GetArea() const
{
	return 0;
}

double CLineSegment::GetPerimeter() const
{
	CPoint startPoint = GetStartPoint();
	CPoint endPoint = GetEndPoint();
	return hypot(startPoint.x - endPoint.x, startPoint.y - endPoint.y);
}



