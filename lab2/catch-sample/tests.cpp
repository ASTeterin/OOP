#include "pch.h"
#include "lab2_1/processVector.h"
using namespace std;

TEST_CASE("Function takes an empty vector and returns an empty vector") 
{
	vector<double> in = {};
	vector<double> out = {};
	ProcessVector(in);
	CHECK(in == out);
}

TEST_CASE("Function takes 1 element and return 1 element multiplied by itself")
{
	vector<double> in = {-1};
	vector<double> out = {1};
	ProcessVector(in);
	CHECK(in == out);
}


TEST_CASE("Function takes an array with zero and returns an array of zeros")
{
	vector<double> in = { 4, 0, 12 };
	vector<double> out = { 0, 0, 0 };
	ProcessVector(in);
	CHECK(in == out);
}
