#include "pch.h"
#include "CLineSegment.h"
#include "CPoint.h"

using namespace std;

CLineSegment::CLineSegment(CPoint const& startPont, CPoint const& endPoint, uint32_t outlineColor)
	: CShape("LineSegment", outlineColor)
	, m_startPoint(startPont)
	, m_endPoint(endPoint)
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
	return GetDistance(m_startPoint, m_endPoint);
}

void CLineSegment::AppendProperty(ostream& strm) const
{
	strm << fixed << setprecision(2) << "\tstart point(" << m_startPoint.x << ", " << m_startPoint.y << ")" << endl
		 << "\tend point(" << m_endPoint.x << ", " << m_endPoint.y << ")" << endl;
}
