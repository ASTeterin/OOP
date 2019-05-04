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
		std::string info = "Triangle:\n\tarea = 6.00\n\tperimeter = 12.00\n\toutline color = ff0000\n\tVertex1 (0.00, 0.00)\n\tVertex2 (0.00, 3.00)\n\tVertex3 (4.00, 0.00)\n";
		WHEN("construct a triangle")
		{
			CTriangle triangle(vertex1, vertex2, vertex3, outlineColor, fillColor);
			THEN("a triangle has the following parametry")
			{
				CHECK(triangle.GetOutlineColor() == outlineColor);
				CHECK(triangle.GetFillColor() == fillColor);
				CHECK(triangle.GetArea() == 6.0);
				CHECK(triangle.GetPerimeter() == 12.0);
				CHECK(triangle.ToString() == info);
			}
			
		}
	}
}
