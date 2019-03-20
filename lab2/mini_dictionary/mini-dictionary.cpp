

#include "pch.h"
#include "mini_dictionary/dictionary.h"

int main(int argc, char *argv[])
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	map<string, string> dictionary;
	string dictionaryFileName;
	ParseCommandLine(argc, argv, dictionaryFileName);
	StartTranslation(dictionaryFileName, dictionary);
}