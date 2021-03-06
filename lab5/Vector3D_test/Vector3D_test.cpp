#include "pch.h"
#include "lab5/CVector3D.h"
#include "lab5/math_function.h"
#include <float.h>

TEST_CASE("creating a vector with zero coordinates")
{
	CVector3D vector;
	CHECK(IsEqual(vector.x, 0));
	CHECK(IsEqual(vector.y, 0));
	CHECK(IsEqual(vector.x, 0));
}

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

		double scalar = 5;
		int bad_divisor = 0;

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

		WHEN("use multiplication of a vector by a scalar")
		{

			vector1 *= scalar;
			THEN("the coordinates of the vector will be increased by 5 times")
			{
				CHECK(IsEqual(vector1.x, x1 * scalar));
				CHECK(IsEqual(vector1.y, y1 * scalar));
				CHECK(IsEqual(vector1.z, z1 * scalar));
			}
		}

		WHEN("used the operator *")
		{
			CVector3D vector3 = vector1 * scalar;
			THEN("the coordinates of the new vector are the coordinates of the original, multiplied by 5")
			{
				CHECK(IsEqual(vector3.x, vector1.x * scalar));
				CHECK(IsEqual(vector3.y, vector1.y * scalar));
				CHECK(IsEqual(vector3.z, vector1.z * scalar));
			}
		}

		WHEN("operation scalar * vector")
		{
			CVector3D vector3 = scalar * vector1;
			THEN("the coordinates of the new vector are the coordinates of the original, multiplied by 5")
			{
				CHECK(IsEqual(vector3.x, vector1.x * scalar));
				CHECK(IsEqual(vector3.y, vector1.y * scalar));
				CHECK(IsEqual(vector3.z, vector1.z * scalar));
			}
		}

		WHEN("used the operation /")
		{
			THEN("the divisor is 0")
			{
				CVector3D vector3;
				CHECK_THROWS(vector3 = vector1 / bad_divisor);
			}

			AND_THEN("the coordinates of the new vector are the coordinates of the original, divided by scalar")
			{
				CVector3D vector3 = vector1 / scalar;
				CHECK(IsEqual(vector3.x, vector1.x / scalar));
				CHECK(IsEqual(vector3.y, vector1.y / scalar));
				CHECK(IsEqual(vector3.z, vector1.z / scalar));
			}
		}

		WHEN("used the operation /=")
		{
			THEN("the divisor is 0")
			{
				CHECK_THROWS(vector1 /= bad_divisor);
			}

			AND_THEN("the coordinates of the new vector are the coordinates of the original, divided by scalar")
			{
				vector1 /= scalar;
				CHECK(IsEqual(vector1.x, x1 / scalar));
				CHECK(IsEqual(vector1.y, y1 / scalar));
				CHECK(IsEqual(vector1.z, z1 / scalar));
			}
		}
		WHEN("used the operation <<")
		{
			std::stringstream outputStream;
			std::stringstream outputVectorStream;
			outputStream << x1 << " " << y1 << " " << z1 << "\n";
			std::string outputString = outputStream.str();
			outputVectorStream << vector1;

			THEN("the output string is equal to the specified value")
			{
				CHECK(outputString == outputVectorStream.str());
			}
		}
		WHEN("used the operation >>")
		{
			CVector3D resultVector;
			std::stringstream inputStringStream;
			THEN("the resulting vector is equal to the specified")
			{
				inputStringStream << x1 << " " << y1 << " " << z1 << "\n";
				inputStringStream >> resultVector;
				CHECK(vector1 == resultVector);
			}
			AND_THEN(" bad stream")
			{
				std::ios_base::iostate old_state = inputStringStream.rdstate();
				inputStringStream << x1 << " " << y1 << " \n";
				inputStringStream >> resultVector;
				CHECK_FALSE(old_state == inputStringStream.rdstate());

			}
		}
	}
}

SCENARIO("testing the comparison of vectors")
{
	GIVEN("coordinates of 2 vectors")
	{
		double x1 = 1.11111111111111111;
		double y1 = 2.2;
		double z1 = 5.5;

		double equalX1 = 1.11111111111111112;
		double notEqualX1 = 1.1111112;

		CVector3D vector1(x1, y1, z1);
		CVector3D vector2(notEqualX1, y1, z1);

		WHEN("vectors are equal")
		{
			CVector3D vector3(equalX1, y1, z1);
			CHECK(vector1 == vector3);
			CHECK_FALSE(vector1 == vector2);
		}
		WHEN("vectors are not equal")
		{
			CVector3D vector3(equalX1, y1, z1);
			CHECK_FALSE(vector1 != vector3);
			CHECK(vector1 != vector2);
		}
	}
}

SCENARIO("testing the operation of a vector")
{
	GIVEN("coordinates of vector")
	{
		double x1 = 2;
		double y1 = 2;
		double z1 = 2;
		CVector3D vector(x1, y1, z1);
		WHEN("testing the operation of normalization of a vector")
		{
			CVector3D normalizedVector(0.5773502691896258, 0.5773502691896258, 0.5773502691896258);
			THEN("the normalized vector will be equal to")
			{
				vector.Normalize();
				CHECK(vector == normalizedVector);
			}
		}
		WHEN("testing scalar prodict of vectors")
		{
			CVector3D vector2(2, 3, 4.5);
			THEN("scalar prodict of vectors")
			{
				CHECK(DotProduct(vector, vector2) == 19);
			}
		}
		WHEN("testing vector product of vectors")
		{
			CVector3D vector2(2, 3, 4);
			CVector3D result(2, -4, 2);
			THEN("vector prodict of vectors")
			{
				CHECK(CrossProduct(vector, vector2) == result);
			}
		}
	}
}