#include "pch.h"
#include "../geometrical_figure/CCircle.h"

SCENARIO("Circle")
{
	GIVEN("circle with the radius and coordinates of the center")
	{
		uint32_t outlineColor = 0xFF0000;
		uint32_t fillColor = 0x00FF00;
		CPoint centre = {0, 0};
		double radius = 2.2;
		std::string info = "";
		WHEN ("construct a circle")
		{
			CCircle circle(centre, radius, outlineColor, fillColor);
			THEN("circle has the following parametry")
			{
				CHECK(circle.GetOutlineColor() == outlineColor);
				CHECK(circle.GetFillColor() == fillColor);
				CHECK(circle.GetArea() == 15.20);
				CHECK(circle.GetPerimeter() == 13.82);
				CHECK(circle.ToString() == info);
			}
		}
	}
}
