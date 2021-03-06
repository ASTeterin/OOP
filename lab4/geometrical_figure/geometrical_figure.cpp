// geometrical_figure.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include "pch.h"
#include <iostream>
#include "CRectangle.h"
#include "CShapeProcessor.h"
 
using namespace std;

int main()
{
	try
	{
		CShapeProcessor shapes(cin, cout);
		while (!cin.eof() && !cin.fail())
		{
			shapes.HandleCommand();
		}
		shapes.PrintInfo();
		shapes.PrintShapeWithMaxArea();
		shapes.PrintShapeWithMinPerimeter();
	}
	catch (const exception& e)
	{
		cerr << e.what() << endl;

		return 1;
	}
	return 0;
}