// multimatrix.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;
const int N = 3;
const string FILE_1 = "file1";
const string FILE_2 = "file2";


typedef vector<vector<float>>  Matrix;




void InitMatrix(Matrix &matrix)
{
	vector<float> currentRow(N, 0);
	for (int row = 0; row < N; row++)
	{
		matrix.push_back(currentRow);
	}
}

void PrintMatrix(Matrix const& matrix)
{
	for (int row = 0; row < N; row++)
	{
		for (int col = 0; col < N; col++)
		{
			cout << round(matrix[row][col] * 1000) / 1000 << ' ';
		}
		cout << '\n';
	}
}

bool LoadMatrix(istream &inputFile, Matrix &matrix)
{
	int row = 0;
	int col = 0;
	string line;
	while ((getline(inputFile, line)) && (row < N))
	{
		
		istringstream currentLine(line);
		while ((currentLine) && (col < N))
		{
			currentLine >> matrix[row][col++];
		}

		if (col != N)
		{
			return false;
		}

		col = 0;
		row++;
	}
	if (row != N)
	{
		return false;
	}
	return true;
}

Matrix MultipleMatrix(Matrix const& matrix1, Matrix const& matrix2)
{
	Matrix resultMatrix;
	InitMatrix(resultMatrix);
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
	return resultMatrix;
}

bool CheckCountParams(int countParam)
{
	if (countParam != 3)
	{
		cout << "Invalid arguments count. Use program call format multimatrix.exe <matrix file1> <matrix file2>";
		return false;
	}
	return true;
}

bool CheckFile(ifstream& input, string commandLineParam)
{
	if (!input.is_open())
	{
		cout << "Failed to open matrix " << commandLineParam << "\n";
		return false;
	}
	return true;
}


int main(int argc, char * argv[])
{
	if (!CheckCountParams(argc))
	{
		return 1;
	}

	ifstream input1(argv[1]);
	ifstream input2(argv[2]);

	if (!CheckFile(input1, FILE_1))
	{
		return 1;
	}

	if (!CheckFile(input2, FILE_2))
	{
		return 1;
	}

	Matrix matrix1;
	Matrix matrix2;
	Matrix resultMatrix;

	InitMatrix(matrix1);
	InitMatrix(matrix2);

	if ((!LoadMatrix(input1, matrix1)) || (!LoadMatrix(input2, matrix2)))
	{
		cout << "Invalid input file format\n";
		return 1;
	}
	resultMatrix = MultipleMatrix(matrix1, matrix2);

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
