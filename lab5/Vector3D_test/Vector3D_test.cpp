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

SCENARIO("testing operations on vector")
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
