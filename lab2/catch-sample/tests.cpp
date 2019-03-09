#include "pch.h"
#include "lab2_1/processVector.h"
using namespace std;

TEST_CASE("Process vector") 
{
	vector<float> in = {2, 3};
	vector<float> out = {4, 6};

	ProcessVector(in);
	
	CHECK(in == out);
}