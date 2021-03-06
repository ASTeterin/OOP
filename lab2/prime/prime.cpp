// prime.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <set>
#include <vector>
#include <string>
#include <iterator>

using namespace std;

set<uint32_t> GeneratePrimeNumbersSet(const unsigned int upperBound)
{
	vector<bool> isPrime(upperBound + 1, true);
	set<uint32_t> primes;

	for (uint32_t i = 3; i * i <= upperBound; i += 2)
	{
		if (isPrime[i])
		{
			for (uint32_t j = i * i; j <= upperBound; j += i)
			{
				isPrime[j] = false;
			}
		}
	}
	primes.insert(1);
	primes.insert(2);
	for (uint32_t i = 3; i <= upperBound; i += 2)
	{
		if (isPrime[i])
		{
			primes.insert(i);
		}
	}
	return primes;
}

void PrintSet(ostream &output, set<uint32_t> const& currentSet)
{
	for (auto element : currentSet)
	{
		output << element << "\n";
	}
}

bool ParseCommandLine(int argc, char *argv[], uint32_t &upperBound)
{
	if (argc != 2)
	{
		cout << "";
		return false;
			
	}
	upperBound = stoi(argv[1]);
	if (!upperBound)
	{
		return false;
		cout << "";
	}
	return true;
}

int main(int argc, char *argv[])
{
	if (!ParseCommandLine)
	{
		return 0;
	}
	set<uint32_t> primes;
	primes = GeneratePrimeNumbersSet(100000000);
	//PrintSet(cout, primes);
	cout << primes.size();
	return 1;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
