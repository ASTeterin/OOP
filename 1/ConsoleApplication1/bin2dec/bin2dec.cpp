// bin2dec.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

bool IsBinaryNumber(const char *number)
{
	int i = 0;
	while (number[i])
	{
		if ((number[i] != '0') && (number[i] != '1'))
		{
			return false;
		}
		i++;
	}
	return true;
}

unsigned int ConvertBinaryToDecimat(const char *binaryNumber)
{
	int i = 0;
	unsigned int decimalNumber = 0;
	size_t n = strlen(binaryNumber) - 1;
	while (binaryNumber[i])
	{
		if (binaryNumber[i] == '1')
		{
			decimalNumber += (unsigned int)(1 << n);
		}
		i++;
		n--;
	}
	return decimalNumber;
}

int main(int argc, char * argv[])
{
	if (argc != 2)
	{
		cout << "Invalid arguments count. Use the program call format bin2dec.cpp <number in binary system>\n" ;
		return 1;
	}

	if (strlen(argv[1]) > 32)
	{
		cout << "Number outside the allowed range\n";
		return 1;
	}

	if (!IsBinaryNumber(argv[1]))
	{
		cout << "Incorrect binary number format\n";
		return 1;
	}	
	cout << ConvertBinaryToDecimat(argv[1]);
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
