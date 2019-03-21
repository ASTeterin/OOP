#pragma once

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>
#include <sstream>
#include <Windows.h>
#include <map>
#include <algorithm>

using namespace std;

void ParseCommandLine(int argc, char* argv[], string& fileName);
void StartTranslation(string fileName, map<string, string> &dictionary);
bool LoadDictionary(string const& fileName, map<string, string> &dictionary);
string Translate(map<string, string> const& dictionary, string const& word);
void AddWordInDictionary(string word, string translateWord, map<string, string> &dictionary);
void SaveDictionaryToFile(string fileName, map<string, string> const& dictionary);
void ToLower(string &str);