#include "pch.h"
#include "lab5/CVector3D.h"

bool IsEqual(double x, double y)
{
	return std::fabs(x - y) < pow(10, -6);
}

/*TEST_CASE("creating a vector with zero coordinates")
{
	CVector3D vector;
	CHECK(IsEqual(vector.x, 0));
	CHECK(IsEqual(vector.y, 0));
	CHECK(IsEqual(vector.x, 0));
}
*/

TEST_CASE("creating a vector with specified coordinates")
{
	double x = 1.1;
	double y = 2.2;
	double z = 5.5;
	CVector3D vector(x, y, z);
	CHECK(IsEqual(vector.x, x));
	CHECK(IsEqual(vector.y, y));
	CHECK(IsEqual(vector.z, z));
}

SCENARIO("testing unary operations on vector")
{
	GIVEN("vector with specified coordinates")
	{
		double x = 1.1;
		double y = 2.2;
		double z = 5.5;
		CVector3D vector(x, y, z);
		WHEN("used the operator +")
		{
			CVector3D vector2 = +vector;
			THEN("the new vector has coordinates equal to the original")
			{
				CHECK(IsEqual(vector2.x, vector.x));
				CHECK(IsEqual(vector2.y, vector.y));
				CHECK(IsEqual(vector2.z, vector.z));
			}
		}

		WHEN("used the operator -")
		{
			CVector3D vector2 = -vector;
			THEN("the new vector has coordinates opposite in sign to the original")
			{
				CHECK(IsEqual(vector2.x, -vector.x));
				CHECK(IsEqual(vector2.y, -vector.y));
				CHECK(IsEqual(vector2.z, -vector.z));
			}
		}

	}
}

SCENARIO("testing binary operations on vector")
{
	GIVEN("2 vectors with specified coordinates")
	{
		double x1 = 1.1;
		double y1 = 2.2;
		double z1 = 5.5;

		double x2 = -1.1;
		double y2 = 10.5;
		double z2 = 6.5;

		CVector3D vector1(x1, y1, z1);
		CVector3D vector2(x2, y2, z2);
		WHEN("used the operator +")
		{
			CVector3D vector3 = vector1 + vector2;
			THEN("The coordinates are the sum of the coordinates of the original vectors")	
			{
				CHECK(IsEqual(vector3.x, vector1.x + vector2.x)); 
				CHECK(IsEqual(vector3.y, vector1.y + vector2.y));
				CHECK(IsEqual(vector3.z, vector1.z + vector2.z));
			}
		}

		WHEN("used the operator -")
		{
			CVector3D vector3 = vector1 - vector2;
			THEN("The coordinates are the difference of the coordinates of the original vectors")
			{
				CHECK(IsEqual(vector3.x, vector1.x - vector2.x));
				CHECK(IsEqual(vector3.y, vector1.y - vector2.y));
				CHECK(IsEqual(vector3.z, vector1.z - vector2.z));
			}
		}

		WHEN("used the operator +=")
		{
			vector1 += vector2;
			THEN("The coordinates of the first vector will increase by the value of the coordinates of the seconds")
			{
				CHECK(IsEqual(vector1.x, x1 + x2));
				CHECK(IsEqual(vector1.y, y1 + y2));
				CHECK(IsEqual(vector1.z, z1 + z2));
			}
		}

		WHEN("used the operator -=")
		{
			vector1 -= vector2;
			THEN("The coordinates of the first vector are reduced by the value of the coordinates of the seconds")
			{
				CHECK(IsEqual(vector1.x, x1 - x2));
				CHECK(IsEqual(vector1.y, y1 - y2));
				CHECK(IsEqual(vector1.z, z1 - z2));
			}
		}
	}
}
