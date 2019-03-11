#include "pch.h"
#include "lab2_1/processVector.h"
using namespace std;

TEST_CASE("Empty vector") 
{
	vector<double> in = {};
	vector<double> out = {};
	ProcessVector(in);
	CHECK(in == out);
}

TEST_CASE("1 element")
{
	vector<double> in = {-1};
	vector<double> out = {1};
	ProcessVector(in);
	CHECK(in == out);
}

TEST_CASE("3 element")
{
	vector<double> in = { 4, -1.5, 12 };
	vector<double> out = { -6, 2.25, -18};
	ProcessVector(in);
	CHECK(in == out);
}

TEST_CASE("2 equal minimum element")
{
	vector<double> in = { 4, -1.5, 12, -1.5 };
	vector<double> out = { -6, 2.25, -18, 2.25 };
	ProcessVector(in);
	CHECK(in == out);
}
