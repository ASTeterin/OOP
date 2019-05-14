#include "pch.h"
#include "CVector3D.h"
#include <math.h>

using namespace std;

CVector3D::CVector3D()
{
}

CVector3D::CVector3D(double x0, double y0, double z0)
	: x(x0)
	, y(y0)
	, z(z0)
{
}

CVector3D::~CVector3D()
{
}

double CVector3D::GetLength() const
{
	return (sqrt(x * x + y * y + z * z));
}

CVector3D CVector3D::operator-() const
{
	return CVector3D(-x, -y, -z);
}
