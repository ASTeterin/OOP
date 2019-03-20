// mini_dictionary_test.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include "mini_dictionary/dictionary.h"
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
	vector<double> in = { -1 };
	vector<double> out = { 1 };
	ProcessVector(in);
	CHECK(in == out);
}
