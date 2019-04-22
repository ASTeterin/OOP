#include "pch.h"
#include "CTriangle.h"
#include "CSolidShape.h"
#include "CPoint.h"

CTriangle::CTriangle(CPoint const& vertex1, CPoint const& vertex2, CPoint const& vertex3, uint32_t outlineColor, uint32_t fillColor)
	: m_vertex1(vertex1)
	, m_vertex2(vertex2)
	, m_vertex3(vertex3)
	, CSolidShape("Triangle", outlineColor, fillColor)
{
}

double CTriangle::GetSide(CPoint const& vertex1, CPoint const& vertex2) const
{
	return sqrt(pow((vertex1.x - vertex2.x), 2) + pow((vertex1.x - vertex2.y), 2));
}

void CTriangle::AppendProperty(std::ostream& strm) const
{
	strm << "Vertex1 (" << m_vertex1.x << ", " << m_vertex1.y << ")\n"
		 << "Vertex2 (" << m_vertex2.x << ", " << m_vertex2.y << ")\n"
		 << "Vertex3 (" << m_vertex3.x << ", " << m_vertex3.y << ")\n";
	return;
}