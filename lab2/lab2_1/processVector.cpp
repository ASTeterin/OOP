#include "pch.h"
#include "processVector.h"

using namespace std;

bool ReadVector(istream &inputStream, vector<double> &v)
{
	float element;
	while (inputStream >> element)
	{
		v.push_back(element);
	}
	if (v.empty())
	{
		return false;
	}
	return true;
}

void PrintVector(vector<double> const& v)
{
	copy(v.begin(), v.end(), ostream_iterator<double>(cout, " "));
}

double MinElementVector(vector<double> const& v)
{
	if (v.empty())
	{
		return NULL;
	}
	else
	{
		return *min_element(v.begin(), v.end());
	}
}

void ProcessVector(vector<double> &v)
{
	double min = MinElementVector(v);
	if (!min)
	{
		return;
	}
	for (size_t i = 0; i < v.size(); i++)
	{
		v[i] *= min;
	}
}

void Sort(vector<double> &v)
{
	sort(v.begin(), v.end());
}