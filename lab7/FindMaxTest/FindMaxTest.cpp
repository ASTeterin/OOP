#include "pch.h"
#include <iostream>
#include "FindMax/FindMax.h"

TEST_CASE("test FindMax for empty vector")
{
	std::vector<int> v{};
	int result;
	CHECK(!FindMax(v, result));
}
