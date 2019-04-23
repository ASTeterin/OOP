#include "pch.h"
#include "CRectangle.h"

using namespace std;

CRectangle::CRectangle(CPoint const& leftTop, CPoint const& rightBottom, uint32_t outlineColor, uint32_t fillColor)
	: m_leftTop(leftTop)
	, m_rightBottom(rightBottom)
	, CSolidShape("Rectangle", outlineColor, fillColor)

{
}

CPoint CRectangle::GetLeftTop() const
{
	return m_leftTop;
}

CPoint CRectangle::GetRightBottom() const
{
	return m_rightBottom;
}


double CRectangle::GetHeight() const
{
	return abs(m_leftTop.x - m_rightBottom.x);
}

double CRectangle::GetWidth() const
{
	return abs(m_leftTop.y - m_rightBottom.y);
}

double CRectangle::GetArea() const
{
	return GetWidth() * GetHeight();
}

double CRectangle::GetPerimeter() const
{
	return 2 * (GetWidth() + GetHeight());
}

void CRectangle::AppendProperty(std::ostream& strm) const
{
	strm << fixed << setprecision(2);

	strm << "\tLeftTop(" << m_leftTop.x << ", " << m_leftTop.y << ")" << endl
		 << "\tRightBottom(" << m_rightBottom.x << ", " << m_rightBottom.y << ")" << endl;
}