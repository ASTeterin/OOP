
#include "pch.h"
#include "solve/equation.h"
#include <iostream>

SCENARIO("Solution qudraticequation")
{
	GIVEN("coefficients of the quadratic equation")
	{
		std::vector<double> root;
		WHEN("the equation has real roots")
		{
			THEN("it has 1 root")
			{
				root = Solve2(1, -4, 4);
				CHECK(root.size() == 1);
				CHECK(root.at(0) == 2);
			}
		}
	}
}
