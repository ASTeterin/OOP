#include "pch.h"
#include "../geometrical_figure/CLineSegment.h"

SCENARIO("Line segment")
{
	GIVEN("Start and end points of line")
	{
		CPoint startPoint = { 0.0, 0.0 };
		CPoint endPoint = { 0.0, 3.0 };
		uint32_t outlineColor = 0xFF0000;
		std::string info = "LineSegment:\n\tarea = 0.00\n\tperimeter = 3.00\n\toutline color = ff0000\n\tstart point(0.00, 0.00)\n\tend point(0.00, 3.00)\n";
		WHEN("construct a line segment")
		{
			CLineSegment lineSegment(startPoint, endPoint, outlineColor);
			THEN("a line segment has the following parametry")
			{
				CHECK(lineSegment.GetStartPoint().x == 0.0);
				CHECK(lineSegment.GetStartPoint().y == 0.0);
				CHECK(lineSegment.GetEndPoint().x == 0.0);
				CHECK(lineSegment.GetEndPoint().y == 3.0);
				CHECK(lineSegment.GetArea() == 0);
				CHECK(lineSegment.GetPerimeter() == 3);
				CHECK(lineSegment.GetOutlineColor() == outlineColor);
				CHECK(lineSegment.ToString() == info);
			}
		}
	}
}