// solve.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include "equation.h"
#include <iostream>
#include <vector>

using namespace std;

void PrintRoots(EquationRoots3 const& root)
{
	cout << "the equation has roots:\n";
	for (uint8_t i = 0; i < root.numRoots; i++)
	{
		cout << root.roots[i] << '\n';
	}
}

int main()
{
	double a;
	double b;
	double c;
	double d;
	cout << "Enter a coefficients of equation\n";
	while ((cin >> a) && (cin >> b) && (cin >> c) && (cin >> d))
	{
		try
		{
			EquationRoots3 root = Solve3(a, b, c, d);
			PrintRoots(root);
			cout << "Enter a coefficients of equation\n";
		}
		catch (const exception& e)
		{
			cout << "Error: " << e.what() << "\n";
		}
	}
	

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
