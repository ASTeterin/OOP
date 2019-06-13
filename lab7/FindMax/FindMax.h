#pragma once

template <typename T>
bool FindMax(std::vector<T> const& arr, T& maxValue)
{
	if (arr.empty())
	{
		return false;
	}
	const T *maxElement = &arr[0];

	for (auto &currentElement : arr)
	{
		if (*maxElement < currentElement)
		{
			maxElement = &currentElement;
		}
	}

	maxValue = *maxElement;
	return true;
}

template <>
bool FindMax(std::vector<const char*> const& arr, const char* & maxValue)
{
	if (arr.empty())
	{
		return false;
	}
	size_t indexOfMaxElement = 0;

	for (size_t i = 1; i < arr.size(); i++)
	{
		if (strcmp(arr[i], arr[indexOfMaxElement]) > 0)
		{
			indexOfMaxElement = i;
		}
	}

	maxValue = arr[indexOfMaxElement];
	return true;
}
