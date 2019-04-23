#include "pch.h"
#include "CSolidShape.h"
#include "CShape.h"
#include "IShape.h"


using namespace std;

CSolidShape::CSolidShape(const string& type, uint32_t outlineColor, uint32_t fillColor)
	/*: m_type(type)
	, m_outlineColor(outlineColor)
	, m_fillColor(fillColor)*/
	: CShape::CShape(type, outlineColor), 
	m_fillColor(fillColor)
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
	//return m_outlineColor;
	return CShape::GetOutlineColor();
}

string CSolidShape::ToString() const
{
	/*ostringstream strm;
	strm << fixed << setprecision(2);
	strm << m_type << ":" << endl
		 << "\tarea = " << GetArea() << endl
		 << "\tperimeter = " << GetPerimeter() << endl
		 << "\toutline color = #" << GetOutlineColor() << endl;
		 //<< "\tfill color = #" << GetFillColor() << endl;
	AppendProperty(strm);
	return strm.str();*/
	return CShape::ToString();
}


void CSolidShape::AppendProperty(std::ostream& strm) const
{
	strm << "\tfill color = #" << CSolidShape::GetFillColor() << endl;
}
