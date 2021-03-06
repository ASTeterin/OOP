#pragma once
#include "CPoint.h"
#include "CSolidShape.h"

class CCircle : public CSolidShape
{
public:
	CCircle(CPoint const& center, double const& radius, uint32_t outlineColor, uint32_t fillColor);

	double GetArea() const override;
	double GetPerimeter() const override;

	double GetRadius() const;
	CPoint GetCenter() const;

private:
	CPoint m_center;
	double m_radius;

	void AppendProperty(std::ostream& strm) const;
};
