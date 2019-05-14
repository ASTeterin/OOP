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

	CVector3D operator-() const;
	CVector3D operator+() const;

	// ������ ������ � �������� ������

	// � ������ ������ ������ ����� ������� ����������
	double x, y, z;
};
