#include "pch.h"
#include "math_function.h"
#include <float.h>
#include <cmath>

bool IsEqual(double x, double y)
{
	return std::fabs(x - y) < pow(10, -6); 
}

int Sign(double value)
{
	int sign = 0;
	if (value > 0)
	{
		sign = 1;
	}
	else if (value < 0)
	{
		sign = -1;
	}
	return sign;
}