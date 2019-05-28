
#include "pch.h"
#include <iostream>
#include "solve/equation.h"


SCENARIO("Solution qudraticequation")
{
	GIVEN("coefficients of the quadratic equation")
	{
		EquationRoots root;
		WHEN("discriminant = 0")
		{
			root = Solve2(1, -4, 4);
			THEN("it has 1 root")
			{
				CHECK(root.numRoots == 1);
				CHECK(root.roots[0] == 2);
			}
		}
		AND_WHEN("discriminant > 0")
		{
			root = Solve2(1, -5, 6);
			THEN("it has 2 root")
			{
				CHECK(root.numRoots == 2);
				CHECK(root.roots[0] == 2);
				CHECK(root.roots[1] == 3);
			}
		}
		AND_WHEN("discriminant < 0")
		{
			CHECK_THROWS_WITH(Solve2(1, 2, 2), "The equation has no real roots");
		}
		AND_WHEN("a = 0")
		{
			CHECK_THROWS_WITH(Solve2(0, 2, 2), "Coefficient a cannot be equal to 0");	
		}
	}
}
