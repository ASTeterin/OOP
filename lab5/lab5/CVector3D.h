#pragma once
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


	// ������ ������ � �������� ������

	// � ������ ������ ������ ����� ������� ����������
	double x, y, z;
};
