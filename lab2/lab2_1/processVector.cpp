#include "pch.h"
#include "processVector.h"

using namespace std;

void ReadVector(vector<float> &v)
{
	float element;
	while (cin >> element)
	{
		v.push_back(element);
	}
}

void PrintVector(vector<float> const& v)
{
	copy(v.begin(), v.end(), ostream_iterator<float>(cout, " "));
}

float MinElementVector(vector<float> const& v)
{
	float min = NULL;
	if (v.size() == 0)
	{
		return min;
	}
	return *min_element(v.begin(), v.end());
}

bool ProcessVector(vector<float> &v)
{
	float min = MinElementVector(v);
	if (!min)
	{
		return false;
	}
	for (size_t i = 0; i < v.size(); i++)
	{
		v[i] *= min;
	}
	return 0;
}

void Sort(vector<float> &v)
{
	sort(v.begin(), v.end());
}