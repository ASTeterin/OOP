#include "pch.h"
#include "../geometrical_figure/CTriangle.h"


SCENARIO("Triangle")
{
	GIVEN("the 3 points, outline color and fill color")
	{
		CPoint vertex1 = { 0.0, 0.0 };
		CPoint vertex2 = { 0.0, 3.0 };
		CPoint vertex3 = { 4.0, 0.0 };
		uint32_t outlineColor = 0xFF0000;
		uint32_t fillColor = 0x00FF00;
		WHEN("construct a triangle")
		{
			CTriangle triangle(vertex1, vertex2, vertex3, outlineColor, fillColor);
			THEN("a triangle has the following parametry")
			{
				CHECK(triangle.GetOutlineColor() == outlineColor);
				CHECK(triangle.GetFillColor() == fillColor);
				CHECK(triangle.GetArea() == 6.0);
				CHECK(triangle.GetPerimeter() == 12.0);
			}
			
		}
	}
}
