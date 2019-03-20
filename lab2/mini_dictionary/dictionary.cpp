// mini_dictionary.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <mini_dictionary/dictionary.h>


using namespace std;


void addWordInDictionary(string word, string translateWord, map<string, string> &dictionary)
{
	dictionary.insert(pair<string, string>(word, translateWord));
}

bool LoadDictionary(string const& fileName, map<string, string> &dictionary)
{
	ifstream input(fileName);
	string str;
	string word;
	string translateWord;
	if (!input.is_open())
	{
		return false;
	}
	while (getline(input, word))
	{
		if (getline(input, translateWord))
		{
			addWordInDictionary(word, translateWord, dictionary);
		}
	}
	return true;
}

string Translate(map<string, string> const& dictionary, string const& word)
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



void SaveDictionaryToFile(string fileName, map<string, string> &dictionary)
{
	ofstream output(fileName);
	for (auto item = dictionary.begin(); item != dictionary.end(); ++item)
	{
		output << (*item).first << endl << (*item).second << endl;
	}
}

void CompleteTranslation(string const& fileName, map<string, string> &dictionary, bool needSaveChanges)
{
	if (!needSaveChanges)
	{
		cout << "Изменения отсутствуют\n";
		return;
	}

	char ch;
	cout << "В словарь были внесены изменения. Введите Y или y для сохранения перед выходом." << endl;
	cout << ">";
	cin >> ch;
	if (ch == 'Y' || ch == 'y')
	{
		SaveDictionaryToFile(fileName, dictionary);
		cout << "Изменения сохранены. До свидания." << endl;
	}
	else
	{
		cout << "Изменения не сохранены. До свидания." << endl;
	}
}

void StartTranslation(string fileName, map<string, string> &dictionary)
{
	bool needSaveChanges = false;
	string word;
	string translation;

	LoadDictionary(fileName, dictionary);


	while (getline(cin, word))
	{
		if (word == "...")
		{
			
			CompleteTranslation(fileName, dictionary, needSaveChanges);
			return;
		}
		translation = Translate(dictionary, word);
		if (translation.empty())
		{
			cout << "The word not fount in dictionary, please, enter the translate \n";
			getline(cin, translation);
			if (translation.empty())
			{
				cout << "The word will be ignored.\n";
				continue;
			}
			addWordInDictionary(word, translation, dictionary);
			needSaveChanges = true;
		}
		
		
	}
}

bool ParseCommandLine(int argc, char* argv[], string& fileName)
{
	if (argc != 2)
	{
		cout << "Указано неверное количество аргументов. Для запуска используйте mini_dictionary.exe [<файл словаря>]";
		return false;
	}
	fileName = argv[1];
	return true;
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
