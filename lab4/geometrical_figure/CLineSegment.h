#pragma once
#include "CPoint.h"
#include "CShape.h"

class CLineSegment final : public CShape
{
public:
	CLineSegment(CPoint const& startPont, CPoint const& endPoint, uint32_t outlineColor);
	double GetArea() const override;
	double GetPerimeter() const override;
	void AppendProperty(std::ostream& strm) const;

	CPoint GetStartPoint() const;
	CPoint GetEndPoint() const;

private:
	CPoint m_startPoint;
	CPoint m_endPoint;



};

