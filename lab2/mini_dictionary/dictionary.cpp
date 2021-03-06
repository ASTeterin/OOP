// mini_dictionary.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <mini_dictionary/dictionary.h>
#include <locale>
#include <functional>
#include <cctype>


using namespace std;

void ToLower(string &str)
{
	transform(str.begin(), str.end(), str.begin(), tolower);
}


void AddWordInDictionary(string word, string translateWord, map<string, string> &dictionary)
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
			AddWordInDictionary(word, translateWord, dictionary);
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



void SaveDictionaryToFile(string fileName, map<string, string> const& dictionary)
{
	if (fileName.empty())
	{
		fileName = "temp_dictionary.txt";
	}
	ofstream output(fileName);
	for (auto item = dictionary.begin(); item != dictionary.end(); ++item)
	{
		output << (*item).first << endl << (*item).second << endl;
	}
}

void CompleteTranslation(string fileName, map<string, string> &dictionary, bool needSaveChanges)
{
	if (!needSaveChanges)
	{
		cout << "Изменения отсутствуют\n";
		return;
	}

	char ch;
	cout << "В словарь были внесены изменения. Введите Y или y для сохранения перед выходом.\n";
	cout << ">";
	cin >> ch;
	if (ch == 'Y' || ch == 'y')
	{
		if (fileName.empty())
		{
			cout << "Введите имя файла для сохранения словаря. \n" << "> ";
			cin >> fileName;
		}
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

	if (!LoadDictionary(fileName, dictionary))
	{
		cout << "Не удалось загрузить словарь.\n";
	}

	cout << "> ";
	while (getline(cin, word))
	{
		if (word == "...")
		{
			CompleteTranslation(fileName, dictionary, needSaveChanges);
			return;
		}
		ToLower(word);
		translation = Translate(dictionary, word);
		if (translation.empty())
		{
			cout << "Неизвестное слово " << word << ". Введите перевод или пустую строку для отказа. \n";
			getline(cin, translation);
			if (translation.empty())
			{
				cout << "Слово " << word << " проигнорировано.\n" << "> ";;
				continue;
			}
			ToLower(translation);
			AddWordInDictionary(word, translation, dictionary);
			cout << "Слово " << word << " сохранено в словаре как " << translation << "\n";
			needSaveChanges = true;
		}
		else
		{
			cout << translation << "\n";
		}
		cout << "> ";
	}
}

void ParseCommandLine(int argc, char* argv[], string& fileName)
{
	if (argc > 2)
	{
		cout << "Указано неверное количество аргументов. Для запуска используйте mini_dictionary.exe [<файл словаря>] \n";
		return;
	}
	if (argc == 2)
	{
		fileName = argv[1];
	}
	return;
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
