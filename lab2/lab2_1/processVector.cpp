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


void ProcessVector(vector<double> &v)
{
	if (v.size() == 0)
	{
		return;
	}
	double min = *min_element(v.begin(), v.end());
	for (auto& item : v)
	{
		item *= min;
	}
}

void Sort(vector<double> &v)
{
	sort(v.begin(), v.end());
}