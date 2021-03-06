// mini_dictionary_test.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include "mini_dictionary/dictionary.h"
using namespace std;


TEST_CASE("Download the dictionary and check the translation of an existing word")
{
	map<string, string> dictionary;
	string fileName = "../dic.txt";
	string word = "cat";
	string translateWord = "кошка";
	
	LoadDictionary(fileName, dictionary);
	CHECK(Translate(dictionary, word) == translateWord);
}

TEST_CASE("Check a new word is added to the dictionary")
{
	setlocale(LC_CTYPE, "rus");
	map<string, string> dictionary1 = 
	{	
		{"cat", "кошка"},
		{"dog", "собака"} 
	};
	map<string, string> dictionary2 =
	{
		{"cat", "кошка"},
		{"dog", "собака"},
		{"ball", "мяч"}
	};
	string word = "Ball";
	string translateWord = "мяч";
	ToLower(word);
	AddWordInDictionary(word, translateWord, dictionary1);
	
	CHECK(dictionary1 == dictionary2);
}

TEST_CASE("Check to save the dictionary to a file")
{
	map<string, string> dictionaryInput =
	{
		{"cat", "кошка"},
		{"dog", "собака"}
	};

	const string fileName = "dic2.txt";
	map<string, string> dictionaryOutput;
	
	SaveDictionaryToFile(fileName, dictionaryInput);
	LoadDictionary(fileName, dictionaryOutput);
	
	CHECK(dictionaryInput == dictionaryOutput);
}