// mini_dictionary_test.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include "mini_dictionary/dictionary.h"
using namespace std;


TEST_CASE("Search for an existing word in the dictionary and return the translation")
{
	setlocale(LC_CTYPE, "rus");
	map<string, string> dictionary;
	string fileName = "../dic.txt";
	string word = "cat";
	string translateWord = "кошка";
	
	LoadDictionary(fileName, dictionary);
	CHECK(Translate(dictionary, word) == translateWord);
}

TEST_CASE("Search for an existing word in the dictionary and return the translation")
{
	setlocale(LC_CTYPE, "rus");
	map<string, string> dictionary;
	string fileName = "../dic.txt";
	string word = "cat";
	string translateWord = "кошка";

	LoadDictionary(fileName, dictionary);
	CHECK(Translate(dictionary, word) == translateWord);
}