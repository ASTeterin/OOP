#pragma once
class CPoint
{
public:
	bool operator ==(CPoint const& point2) const;

	double x;
	double y;
};

double GetDistance(CPoint const& point1, CPoint const& point2);

