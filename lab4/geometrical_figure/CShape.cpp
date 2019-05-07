#include "pch.h"
#include "CShape.h"
#include "IShape.h"
#include <stdint.h>

using namespace std;

CShape::CShape(string const& type, uint32_t outlineColor)
	: m_type(type), m_outlineColor(outlineColor)
{
}

uint32_t CShape::GetOutlineColor() const
{
	return m_outlineColor;
}

void CShape::SetOutlineColor(uint32_t color)
{
	m_outlineColor = color;
}

string CShape::ToString() const
{
	ostringstream strm;
	strm << m_type << ":" << endl
		 << fixed << setprecision(2)
		 << "\tarea = " << GetArea() << endl
		 << "\tperimeter = " << GetPerimeter() << endl
		 << "\toutline color = " << setfill('0') << setw(6) << hex << GetOutlineColor() << endl;
	AppendProperty(strm);
	return strm.str();
}

void CShape::AppendProperty(std::ostream& strm) const
{
}
