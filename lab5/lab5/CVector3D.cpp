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

CVector3D CVector3D::operator+() const
{
	return CVector3D(x, y, z);
}

CVector3D const CVector3D::operator+(CVector3D const& operand2) const
{
	return CVector3D(x + operand2.x, y + operand2.y, z + operand2.z);
}

CVector3D const CVector3D::operator-(CVector3D const& operand2) const
{
	return CVector3D(x - operand2.x, y - operand2.y, z - operand2.z);
}

CVector3D CVector3D::operator +=(CVector3D const& operand2)
{
	x += operand2.x;
	y += operand2.y;
	z += operand2.z;
	return *this;
}

CVector3D CVector3D::operator -=(CVector3D const& operand2)
{
	x -= operand2.x;
	y -= operand2.y;
	z -= operand2.z;
	return *this;
}

CVector3D const CVector3D::operator *(double scalar) const
{
	return CVector3D(x * scalar, y * scalar, z * scalar);
}

CVector3D const operator*(double scalar, CVector3D const& vector)
{
	return vector * scalar;
}

CVector3D const CVector3D::operator /(double scalar) const
{
	if (scalar == 0)
	{
		throw "scalar cannot be 0";
	}
	return CVector3D(x / scalar, y / scalar, z / scalar);
}


