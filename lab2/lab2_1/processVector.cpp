#include "pch.h"
#include "processVector.h"

using namespace std;

void ReadVector(vector<double> &v)
{
	float element;
	while (cin >> element)
	{
		v.push_back(element);
	}
}

void PrintVector(vector<double> const& v)
{
	copy(v.begin(), v.end(), ostream_iterator<double>(cout, " "));
}

double MinElementVector(vector<double> const& v)
{
	double min = NULL;
	if (v.empty())
	{
		return min;
	}
	return *min_element(v.begin(), v.end());
}

bool ProcessVector(vector<double> &v)
{
	double min = MinElementVector(v);
	if (!min)
	{
		return false;
	}
	for (size_t i = 0; i < v.size(); i++)
	{
		v[i] *= min;
	}
	return true;
}

void Sort(vector<double> &v)
{
	sort(v.begin(), v.end());
}