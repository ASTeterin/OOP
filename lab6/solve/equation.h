#pragma once
#include <vector>

struct EquationRoots
{
	int numRoots;
	double roots[2];
};

struct EquationRoots3
{
	int numRoots;
	double roots[3];
};


EquationRoots Solve2(double a, double b, double c);
EquationRoots3 Solve3(double a, double b, double c, double d);