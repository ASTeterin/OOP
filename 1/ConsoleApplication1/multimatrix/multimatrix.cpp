// multimatrix.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include <fstream>

using namespace std;
const int N = 3;

void InitMatrix(float matrix[N][N])
{
	for (int row = 0; row < N; row++)
	{
		for (int col = 0; col < N; col++)
		{
			matrix[row][col] = 0;
		}
	}
}

void PrintMatrix(float matrix[N][N])
{
	for (int row = 0; row < N; row++)
	{
		for (int col = 0; col < N; col++)
		{
			cout << matrix[row][col] << ' ';
		}
		cout << '\n';
	}
}

void GetMatrixCoefficients(istream &inputFile, float matrix[N][N])
{
	int i = 0;
	int j = 0;
	while (!inputFile.eof())
	{
		inputFile >> matrix[i][j];
		if (j == (N - 1))
		{
			i++;
			j = 0;
		}
		else
		{
			j++;
		}
	}
}



int main(int argc, char * argv[])
{
	if (argc != 3)
	{
		cout << "Invalid arguments count. Use program call format multimatrix.exe <matrix file1> <matrix file2>";
		return 1;
	}

	ifstream input1("d:\\1.txt");
	ifstream input2("d:\\1.txt");
	//ifstream input2(argv[2]);

	if ((!input1.is_open()) || (!input2.is_open()))
	{
		cout << "Failed to open input file\n";
		return 1;
	}

	float matrix1[N][N], matrix2[N][N];
	float resultMatrix[N][N];

	InitMatrix(resultMatrix);
	GetMatrixCoefficients(input1, matrix1);
	GetMatrixCoefficients(input2, matrix2);
	
	
	for (int row = 0; row < N; row++) 
	{
		for (int col = 0; col < N; col++) 
		{
			for (int j = 0; j < N; j++) 
			{
				resultMatrix[row][col] += matrix1[row][j] * matrix2[j][col];
			}
		}
	}

	PrintMatrix(resultMatrix);

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
