#pragma once
#include <vector>

struct EquationRoots
{
	int numRoots;
	double roots[2];
};

EquationRoots Solve2(double a, double b, double c);