#include "pch.h"
#include "CTriangle.h"
#include "CPoint.h"
#include "CSolidShape.h"


CTriangle::CTriangle(CPoint const& vertex1, CPoint const& vertex2, CPoint const& vertex3, uint32_t outlineColor, uint32_t fillColor)
	: m_vertex1(vertex1)
	, m_vertex2(vertex2)
	, m_vertex3(vertex3)
	, CSolidShape("Triangle", outlineColor, fillColor)
{
}

double CTriangle::GetSide(CPoint const& vertex1, CPoint const& vertex2) const
{
	return sqrt(pow((vertex1.x - vertex2.x), 2) + pow((vertex1.y - vertex2.y), 2));
}

void CTriangle::AppendProperty(std::ostream& strm) const
{
	strm << "\tVertex1 (" << m_vertex1.x << ", " << m_vertex1.y << ")\n"
		 << "\tVertex2 (" << m_vertex2.x << ", " << m_vertex2.y << ")\n"
		 << "\tVertex3 (" << m_vertex3.x << ", " << m_vertex3.y << ")\n";
	return;
}

double CTriangle::GetPerimeter() const
{
	return GetSide(m_vertex1, m_vertex2) + GetSide(m_vertex2, m_vertex3) + GetSide(m_vertex1, m_vertex3);
}

double CTriangle::GetArea() const
{
	double side1 = GetSide(m_vertex1, m_vertex2);
	double side2 = GetSide(m_vertex2, m_vertex3);
	double side3 = GetSide(m_vertex1, m_vertex3);
	double halfPerimetr = (side1 + side2 + side3) / 2;
	return sqrt(halfPerimetr * (halfPerimetr - side1) * (halfPerimetr - side2) * (halfPerimetr - side3));
}