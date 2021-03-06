// multimatrix.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "pch.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
#include <array>

using namespace std;
const int MATRIX_DIMENSION = 3;

typedef std::array<std::array<float, MATRIX_DIMENSION>, MATRIX_DIMENSION> Matrix;

void InitMatrix(Matrix &matrix)
{
	for (int row = 0; row < MATRIX_DIMENSION; row++)
	{
		for (int col = 0; col < MATRIX_DIMENSION; col++)
		{
			matrix[row][col] = 0;
		}
		
	}
}

void PrintMatrix(Matrix const& matrix)
{
	for (int row = 0; row < MATRIX_DIMENSION; row++)
	{
		for (int col = 0; col < MATRIX_DIMENSION; col++)
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
	while ((getline(inputFile, line)) && (row < MATRIX_DIMENSION))
	{
		
		istringstream currentLine(line);
		while ((currentLine) && (col < MATRIX_DIMENSION))
		{
			currentLine >> matrix[row][col++];
		}

		if (col != MATRIX_DIMENSION)
		{
			return false;
		}

		col = 0;
		row++;
	}
	if (row != MATRIX_DIMENSION)
	{
		return false;
	}
	return true;
}

Matrix MultipleMatrix(Matrix const& matrix1, Matrix const& matrix2)
{
	Matrix resultMatrix;
	InitMatrix(resultMatrix);
	for (int row = 0; row < MATRIX_DIMENSION; row++)
	{
		for (int col = 0; col < MATRIX_DIMENSION; col++)
		{
			for (int j = 0; j < MATRIX_DIMENSION; j++)
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

bool ParseCommandLine(int argc, char* argv[], string& mat1FileName, string& mat2FileName)
{
	if (!CheckCountParams(argc))
	{
		return false;
	}
	mat1FileName = argv[1];
	mat2FileName = argv[2];
	return true;
}

bool LoadMatrixFromFile(const string& fileName, Matrix& mat)
{
	ifstream input(fileName);
	if (!input.is_open())
	{
		cout << "Failed to open matrix\n";
		return false;
	}
	if (!LoadMatrix(input, mat))
	{
		cout << "Invalid input file format\n";
		return false;
	}
	return true;
}


int main(int argc, char * argv[])
{
	string inputFileName1;
	string inputFileName2;
	Matrix matrix1;
	Matrix matrix2;
	Matrix resultMatrix;

	if (!ParseCommandLine(argc, argv, inputFileName1, inputFileName2))
	{
		return 1;
	}


	if ((!LoadMatrixFromFile(inputFileName1, matrix1)) || (!LoadMatrixFromFile(inputFileName2, matrix2)))
	{
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
