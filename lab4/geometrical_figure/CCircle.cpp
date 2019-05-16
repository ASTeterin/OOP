#include "pch.h"
#include "CCircle.h"
#define _USE_MATH_DEFINES
#include <math.h>


using namespace std;

CCircle::CCircle(CPoint const& center, double const& radius, uint32_t outlineColor, uint32_t fillColor)
	: CSolidShape("Circle", outlineColor, fillColor) 
	, m_center(center)
	, m_radius(radius)
{
}

double CCircle::GetArea() const
{
	return (M_PI * pow(m_radius, 2));
}

double CCircle::GetPerimeter() const
{
	return (2 * M_PI *  m_radius);
}

CPoint CCircle::GetCenter() const
{
	return m_center;
}

double CCircle::GetRadius() const
{
	return m_radius;
}

void CCircle::AppendProperty(std::ostream& strm) const
{
	strm << fixed << setprecision(2);

	strm << "\tCenter(" << m_center.x << ", " << m_center.y << ")" << endl
		 << "\tRadius = " << m_radius << endl;
}