#include "pch.h"
#include "../geometrical_figure/CRectangle.h"

SCENARIO("Rectangle")
{
	GIVEN("rectangle with coordinates of the upper left corner and dimensions")
	{
		CPoint leftTopPoint = { 0.0, 10.5 };
		CPoint rightBottomPoint = { 12.5, 0.0 };
		uint32_t outlineColor = 0xFF0000;
		uint32_t fillColor = 0x00FF00;
		std::string info = "Rectangle:\n\tarea = 131.25\n\tperimeter = 46.00\n\toutline color = ff0000\n\tLeftTop(0.00, 10.50)\n\tRightBottom(12.50, 0.00)\n";
		WHEN("construct a rectangle")
		{
			CRectangle rectangle(leftTopPoint, rightBottomPoint, outlineColor, fillColor);
			THEN("rectangle has a width")
			{
				CHECK(rectangle.GetWidth() == 10.5);
			}
			AND_THEN("rectangle has a height")
			{
				CHECK(rectangle.GetHeight() == 12.5);
			}
			AND_THEN("rectangle has a outline color")
			{
				CHECK(rectangle.GetOutlineColor() == outlineColor);
			}
			AND_THEN("rectangle has a fill color")
			{
				CHECK(rectangle.GetFillColor() == fillColor);
			}
			AND_THEN("perimeter is equal to")
			{
				CHECK(rectangle.GetPerimeter() == 46.0);
			}
			AND_THEN("the area of a rectangle is equal to")
			{
				CHECK(rectangle.GetArea() == 131.25);
			}
			AND_THEN("")
			{
				CHECK(rectangle.ToString() == info);
			}
		}
	}
}