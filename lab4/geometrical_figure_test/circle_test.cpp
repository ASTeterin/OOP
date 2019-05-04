#include "pch.h"
#include <cmath>
#include <limits>
#include "../geometrical_figure/CCircle.h"

bool IsEqual(double x, double y)
{
	return std::fabs(x - y) < pow(10, -6);
}

SCENARIO("Circle")
{
	GIVEN("circle with the radius and coordinates of the center")
	{
		uint32_t outlineColor = 0xFF0000;
		uint32_t fillColor = 0x00FF00;
		CPoint centre = {0, 0};
		double radius = 2.2;
		std::string info = "Circle:\n\tarea = 15.21\n\tperimeter = 13.82\n\toutline color = ff0000\n\tCenter(0.00, 0.00)\n\tRadius = 2.20\n";
		WHEN ("construct a circle")
		{
			CCircle circle(centre, radius, outlineColor, fillColor);
			THEN("circle has the following parametry")
			{
				CHECK(circle.GetOutlineColor() == outlineColor);
				CHECK(circle.GetFillColor() == fillColor);
				CHECK(IsEqual(circle.GetArea(), 15.2053084434) == true);
				CHECK(IsEqual(circle.GetPerimeter(), 13.8230076758) == true);
				CHECK(circle.ToString() == info);
			}
		}
	}
}
