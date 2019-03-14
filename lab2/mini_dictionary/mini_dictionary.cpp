// mini_dictionary.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <string>
#include <sstream>
#include <map>    //подключили библиотеку для работы с map


using namespace std;

map <string, string> myDictionary = { 
	{"cat", "кошка"},
	{"dog", "собака"}
};


string translate(map<string, string> const& dictionary, string const& word)
{
	for (auto currWord = dictionary.begin(); currWord != dictionary.end(); ++currWord)
	{
		if ((*currWord).first == word)
		{
			return (*currWord).second;
		}
	}
	return "";
}

void addWordInDictionary(string word, string translateWord, map<string, string> &dictionary)
{
	dictionary.insert(pair<string, string>(word, translateWord));
}

void RunDictionary(istream &inputStream)
{
	string str;
	while (getline(inputStream, str))
	{
				
	}
}

/*int main()
{
    std::cout << "Hello World!\n"; 
}*/

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
