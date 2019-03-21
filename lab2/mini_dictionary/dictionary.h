#pragma once

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>
#include <sstream>
#include <Windows.h>
#include <map>

using namespace std;

bool ParseCommandLine(int argc, char* argv[], string& fileName);
void StartTranslation(string fileName, map<string, string> &dictionary);
bool LoadDictionary(string const& fileName, map<string, string> &dictionary);
string Translate(map<string, string> const& dictionary, string const& word);