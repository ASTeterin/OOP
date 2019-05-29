
#include "pch.h"
#include "equation.h"
#include "math_function.h"
#define _USE_MATH_DEFINES
#include <math.h>

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

EquationRoots3 Solve3(double coeficientA, double coeficientB, double coeficientC, double coeficientD)
{
	if (coeficientA == 0)
	{
		throw invalid_argument("Coefficient a cannot be equal to 0");
	}
	double a = coeficientB / coeficientA;
	double b = coeficientC / coeficientA;
	double c = coeficientD / coeficientA;
	double t;
	EquationRoots3 root;
	double q = (a * a - 3 * b) / 9;
	double r = (2 * a * a * a - 9 * a * b + 27 * c) / 54;
	double s = pow(q, 3) - r * r; //что лучше pow(q, 3) или q * q * q

	if (s > 0)
	{
		t = acos(r / sqrt(q * q * q)) / 3;
		root.numRoots = 3;
		root.roots[0] = -2 * sqrt(q) * cos(t) - a / 3;
		root.roots[1] = -2 * sqrt(q) * cos(t + 2 * M_PI / 3) - a / 3;
		root.roots[2] = -2 * sqrt(q) * cos(t - 2 * M_PI / 3) - a / 3;
	}
	else if (s < 0)
	{
		root.numRoots = 1;
		if (q > 0)
		{
			double t = acosh(abs(r) / sqrt(pow(q, 3))) / 3;
			root.roots[0] = -2 * Sign(r) * sqrt(q) * cosh(t) - a / 3;
		}
		if (q < 0)
		{
			double t = asinh(abs(r) / sqrt(pow(abs(q), 3))) / 3;
			root.roots[0] = -2 * Sign(r) * sqrt(abs(q)) * sinh(t) - a / 3;
		}
		if (q == 0)
		{
			root.roots[0] = -pow((c - pow(a, 3) / 27), 1 / 3.0) - a / 3.0;
		}
	}
	else
	{
		root.numRoots = 2;
		root.roots[0] = -2 * Sign(r) * sqrt(q) - a / 3;
		root.roots[1] = Sign(r) * sqrt(q) - a / 3; 
	}
	return root;
}
