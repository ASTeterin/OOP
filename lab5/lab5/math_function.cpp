#include "pch.h"
#include "math_function.h"
#include <float.h>
#include <cmath>

bool IsEqual(double x, double y)
{
	return std::fabs(x - y) < DBL_EPSILON; //pow(10, -6);
}