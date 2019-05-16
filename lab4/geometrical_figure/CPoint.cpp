#include "pch.h"
#include "CPoint.h"

bool CPoint::operator ==(CPoint const& point2) const
{
	return (x == point2.x) && (y == point2.y);
}

double GetDistance(CPoint const& point1, CPoint const& point2)
{
	return sqrt((point1.x - point2.x) * (point1.x - point2.x) + (point1.y - point2.y) * (point1.y - point2.y));
}