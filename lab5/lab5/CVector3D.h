#pragma once
#include "pch.h"
class CVector3D
{
public:
	// ������������ ������� ������
	CVector3D();

	// ������������ ������ � ��������� ������������
	CVector3D(double x0, double y0, double z0);

	~CVector3D();

	// ���������� ����� �������
	double GetLength() const;

	// ����������� ������ (�������� ��� � ��������� �����)
	void Normalize();

	CVector3D operator -() const;
	CVector3D operator +() const;

	CVector3D const operator +(CVector3D const& operand2) const;
	CVector3D const operator -(CVector3D const& operand2) const;

	CVector3D operator +=(CVector3D const& operand2);
	CVector3D operator -=(CVector3D const& operand2);

	CVector3D const operator *(double scalar) const;
	CVector3D const operator /(double scalar) const;

	CVector3D& operator*=(double scalar);
	CVector3D& operator /=(double scalar);

	bool operator ==(CVector3D const& operand2) const;
	bool operator !=(CVector3D const& operand2) const;



	// ������ ������ � �������� ������

	// � ������ ������ ������ ����� ������� ����������
	double x, y, z;
};

CVector3D const operator *(double scalar, CVector3D const& vector);
double DotProduct(CVector3D const& v1, CVector3D const& v2);
CVector3D CrossProduct(CVector3D const& v1, CVector3D const& v2);
std::ostream& operator <<(std::ostream& strm, CVector3D const& vector);
std::istream& operator >>(std::istream& strm, CVector3D& vector);

