#include <iostream>

#include <locale.h>


using namespace std;

int CorrectInput(int& value);

void PrintMatrix(int n, int m, int matrix[100][50]);

void NumbersOfLinesWithMax(int n, int m, int matrix[100][50], int max, int arr[100], int &count);

int max(int n, int m, int matrix[100][50]);

int main()
{
	int matrix[100][50];
	int n, m;
	int Arr[100];
	int count = 0;
	for (int i = 0; i < 100; i++)
		Arr[i] = 0;
	setlocale(LC_ALL, "RUS");
	cout << "Введите количество строк и столбцов через пробел\n";
	cin >> n >> m;
	cout << "Вводите числа...\n";
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			CorrectInput(matrix[i][j]);
	PrintMatrix(n, m, matrix);
	int MAX = max(n, m, matrix);
	cout << "Максимальный элемент равен " << MAX << endl;
	NumbersOfLinesWithMax(n,m,matrix,MAX,Arr, count);
}

int CorrectInput(int& value)
{
	char fail;
	cin >> value;
	while (cin.fail())
	{
		cout << "Данные некорректны\n";
		cin.clear();
		cin >> fail;
		cin >> value;
	}
	return value;
}

void PrintMatrix(int n, int m, int matrix[100][50])
{
	for (int i = 0; i < n; i++)
	{
		cout << endl;
		for (int j = 0; j < m; j++)
			cout << matrix[i][j] << "\t";
	}
	cout << endl;
}

int max(int n, int m, int matrix[100][50])
{
	int max = matrix[0][0];
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (matrix[i][j] > max)
				max = matrix[i][j];
	return max;
}

void NumbersOfLinesWithMax(int n, int m, int matrix[100][50], int max, int arr[100], int &count)
{
	for(int i = 0; i < n; i++)
		for(int j = 0; j < m; j++)
			if (matrix[i][j] == max) 
			{
				arr[count] = i;
				cout << i << "\t";
				i++;
				count++;
			}
}