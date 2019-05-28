
#include "pch.h"
#include "equation.h"

using namespace std;

EquationRoots Solve2(double a, double b, double c)
{
	if (a == 0)
	{
		throw invalid_argument("Coefficient a cannot be equal to 0");
	}
	double discriminant = b * b - 4 * a * c;
	EquationRoots root;
	if (discriminant == 0)
	{
		root.numRoots = 1;
		root.roots[0] = (-b / (2 * a));
	}
	else if (discriminant > 0)
	{
		root.numRoots = 2;
		root.roots[0] = (-b - sqrt(discriminant)) / (2 * a);
		root.roots[1] = (-b + sqrt(discriminant)) / (2 * a);
	}
	else
	{
		throw std::domain_error("The equation has no real roots");
	}
	return root;
}
