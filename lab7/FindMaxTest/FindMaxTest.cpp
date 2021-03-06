#include "pch.h"
#include <iostream>
#include "FindMax/FindMax.h"

TEST_CASE("test FindMax for empty vector")
{
	std::vector<int> v{};
	int maxValue;
	CHECK(!FindMax(v, maxValue));
}

TEST_CASE("test FindMax for vector of integer")
{
	std::vector<int> v = {1, 5, 7, 2};
	int maxValue;
	CHECK(FindMax(v, maxValue));
	CHECK(maxValue == 7);
}

TEST_CASE("test FindMax for vector of double")
{
	std::vector<double> v = { 1.0, -5.5, -7.0, 2.2 };
	double maxValue;
	CHECK(FindMax(v, maxValue));
	CHECK(maxValue == 2.2);
}

TEST_CASE("test FindMax for vector of string")
{
	std::vector<std::string> v = { "asd", "qwe", "zxd", "zxc"};
	std::string maxValue;
	CHECK(FindMax(v, maxValue));
	CHECK(maxValue == "zxd");
}

TEST_CASE("test FindMax for vector of const char*")
{
	std::vector<const char*> v = { "asd", "qwe", "zxd", "zxc" };
	const char* maxValue;
	CHECK(FindMax(v, maxValue));
	CHECK(maxValue == "zxd");
}
