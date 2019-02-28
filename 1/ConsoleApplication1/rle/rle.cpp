// rle.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

bool ParseCommandLine(int argc, char* argv[])
{
	if (argc != 4)
	{
		cout << "Invalid number of arguments. Use rle.exe pack <input file> <output file> or rle.exe unpack <input file> <output file>";
		return false;
	}
	if ((strcmp(argv[1], "pack") != 0) && (strcmp(argv[1], "unpack") != 0))
	{
		cout << "Wrong mode of the program. Use rle.exe pack <input file> <output file> or rle.exe unpack <input file> <output file>";
		return false;
	}

	return true;
}

void CompressFile(istream &input, ostream &output)
{
	char ch;
	char next_ch = NULL;
	unsigned int count = 0;
	while (input.get(ch))
	{
		
		next_ch = input.peek();
		count++;
		if (((next_ch != ch)) || (next_ch == EOF) || (count == 256))
		{
			output << count << ',' << ch;
			if (next_ch != EOF)
			{
				output << ',';
			}
			count = 0;
		}
	}
}

void DecompressFile(istream &input, ostream &output)
{
	char ch;
	string str;
	char next_ch = NULL;
	unsigned int count = 0;
	while (getline(input, str, ','))
	{
		if ((str == "") || (str == "\n\n"))
		{
			continue;
		}	
		count = stoi(str);
		ch = input.peek();

		//if (getline(input, str, ','))
		{
			for (int i = count; i > 0; i--)
			{
				output << ch;
			}
		}
		
		input.get(ch);
		
	}
}


int main(int argc, char * argv[])
{
	if (!ParseCommandLine(argc, argv))
	{
		return 1;
	}

	ifstream input(argv[2], ios::binary);
	ofstream output(argv[3], ios::binary);

	if (!input.is_open())
	{
		cout << "Can't open input file to read\n";
		return 1;
	}

	/*if (!output.is_open())
	{
		cout << "Can't open output file to write\n";
		return 1;
	}*/

	(strcmp(argv[1], "pack") == 0) ? CompressFile(input, output) : DecompressFile(input, output);
	
	return 0;
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
