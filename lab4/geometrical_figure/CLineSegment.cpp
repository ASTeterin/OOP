#include "pch.h"
#include "CLineSegment.h"

using namespace std;

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

void CLineSegment::AppendProperty(ostream& strm) const
{
	strm << fixed << setprecision(2) << "\tstart point(" << m_startPoint.x << ", " << m_startPoint.y << ")" << endl
		 << "\tend point(" << m_endPoint.x << ", " << m_endPoint.y << ")" << endl;
}



