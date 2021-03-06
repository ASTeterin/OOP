// ConsoleApplication1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

void FindText(istream &inputStream, string const& text)
{
	string str;
	int stringNumber = 0;
	if (text == "")
	{
		return;
	}
	while (getline(inputStream, str))
	{
		stringNumber++;
		if (str.find(text) != string::npos) 
		{
			cout << stringNumber << '\n';
		}
	}
}

int main(int argc, char * argv[])
{

	if (argc != 3)
	{
		cout << "Invalid arguments count. Use program call format findText.exe <file> <search string>\n";
		return 1;
	}
	
	ifstream input(argv[1]);

	if (!input.is_open())
	{
		cout << "Can't open file";
		return 1;
	}
	
	FindText(input, argv[2]);
	return 0;
}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
