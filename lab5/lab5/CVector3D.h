#pragma once
class CVector3D
{
public:
	// Конструирует нулевой вектор
	CVector3D();

	// Конструирует вектор с заданными координатами
	CVector3D(double x0, double y0, double z0);

	~CVector3D();

	// Возвращает длину вектора
	double GetLength() const;

	// Нормализует вектор (приводит его к единичной длине)
	void Normalize();

	CVector3D operator-() const;
	CVector3D operator+() const;

	// Другие методы и операции класса

	// В данном случае данные можно сделать публичными
	double x, y, z;
};
