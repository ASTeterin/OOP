
#include "pch.h"
#include "solve/equation.h"
#include "solve/math_function.h"

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

SCENARIO("Solution of equations of 3 degrees")
{
	GIVEN("coefficients of the equation")
	{
		EquationRoots3 root;
		WHEN("s > 0")
		{
			root = Solve3(1, 4, -8, 2);
			CHECK(root.numRoots == 3);
			CHECK(IsEqual(root.roots[0], -5.5160458708) == true);
			CHECK(IsEqual(root.roots[1], 1.2184794534) == true);
			CHECK(IsEqual(root.roots[2], 0.2975664174) == true);
		}
		AND_WHEN("s < 0 and q < 0")
		{
			root = Solve3(1, 1, 1, 1);
			CHECK(root.numRoots == 1);
			CHECK(root.roots[0] == -1);
		}
		AND_WHEN("s < 0 and q > 0")
		{
			root = Solve3(1, 2, 1, 1);
			CHECK(root.numRoots == 1);
			CHECK(IsEqual(root.roots[0], -1.7548776662));
		}
		AND_WHEN("s < 0 and q = 0")
		{
			root = Solve3(1, -3, 3, 0);
			CHECK(root.numRoots == 1);
			CHECK(root.roots[0] == 0);
		}
		AND_WHEN("s = 0")
		{
			root = Solve3(1, 3, 3, 1);
			CHECK(root.numRoots == 2);
			CHECK(IsEqual(root.roots[0], -1.0));
			CHECK(IsEqual(root.roots[1], -1.0));
		}
		AND_WHEN("coefficient a = 0")
		{
			CHECK_THROWS_WITH(Solve3(0, 2, 2, 4), "Coefficient a cannot be equal to 0");	
		}
	}
}
