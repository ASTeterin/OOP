#include "pch.h"
#include "IShape.h"
#include "CShape.h"
#include "CSolidShape.h"


using namespace std;

CSolidShape::CSolidShape(const string& type, uint32_t outlineColor, uint32_t fillColor)
	: m_type(type)
	, m_outlineColor(outlineColor)
	, m_fillColor(fillColor)
{
}

void CSolidShape::SetFillColor(uint32_t color)
{
	m_fillColor = color;
}

uint32_t CSolidShape::GetFillColor() const
{
	return m_fillColor;
}

void CSolidShape::SetOutlineColor(uint32_t color)
{
	CShape::SetOutlineColor(color);
}

uint32_t CSolidShape::GetOutlineColor() const
{
	return CShape::GetOutlineColor();
}

string CSolidShape::ToString() const
{
	ostringstream strm;
	strm << fixed << setprecision(2);
	strm << m_type << ":" << endl
		 << "\tarea = " << CShape::GetArea() << endl
		 << "\tperimeter = " << CShape::GetPerimeter() << endl
		 << "\toutline color = #" << GetOutlineColor() << endl
		 << "\tfill color = #" << GetFillColor() << endl;
	AppendProperties(strm);
	return strm.str();
}




