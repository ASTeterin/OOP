
#include "pch.h"
#include "equation.h"

using namespace std;

vector<double> Solve2(double a, double b, double c)
{
	double discriminant = b * b - 4 * a * c;
	vector<double> root;
	if (discriminant == 0)
	{
		//root.resize(1);
		root.push_back(-b / (2 * a));
	}
	else if (discriminant > 0)
	{
		//root.resize(2);
		root.push_back((-b - sqrt(discriminant)) / (2 * a));
		root.push_back((-b + sqrt(discriminant)) / (2 * a));
	}
	return root;
}
