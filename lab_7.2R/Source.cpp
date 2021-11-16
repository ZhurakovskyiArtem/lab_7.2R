// Lab_7_2_2.cpp
// < Жураковського Артема >
// Лабораторна робота № 7.2.2)
// Опрацювання багатовимірних масивів рекурсивними способами.
// Варіант 5
#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;
void CreateRow(int** a, const int k, const int rowNo, const int n, const int Low,
	const int High, int colNo)
{
	a[rowNo][colNo] = Low + rand() % (High - Low + 1);
	if (colNo < n - 1)
		CreateRow(a, k, rowNo, n, Low, High, colNo + 1);
}
void CreateRows(int** a, const int k, const int n, const int Low, const int High, int rowNo)
{
	CreateRow(a, k, rowNo, n, Low, High, 0);
	if (rowNo < k - 1) 
		CreateRows(a, k, n, Low, High, rowNo + 1);
}
void PrintRow(int** a, const int k, const int rowNo, const int n, int colNo)
{
	cout << setw(4) << a[rowNo][colNo];
	if (colNo < n - 1)
		PrintRow(a, k, rowNo, n, colNo + 1);
	else
		cout << endl;
}
void PrintRows(int** a, const int k, const int n, int rowNo)
{
	PrintRow(a, k, rowNo, n, 0);
	if (rowNo < k - 1)
		PrintRows(a, k, n, rowNo + 1);
	else
		cout << endl;
}
int SumMinElem(int** a, const int k, const int n, int i, int S, int min, int j)
{
	if (a[i][j] < min && i % 2 != 0)
		min = a[i][j];
	if (j < n - 1)
	{
		return SumMinElem(a, k, n, i, S, min, j + 1);
	}
	if (i % 2 != 0)
		S += min;
	if (i < k - 1)
		return SumMinElem(a, k, n, i + 1, S, a[i][0], 0);
	return S;
}
int main()
{
	srand((unsigned)time(NULL));
	int n, k;
	cout << "k = "; cin >> k;
	cout << "n = "; cin >> n;
	cout << endl;
	int** a = new int* [k];
	for (int i = 0; i < k; i++)
		a[i] = new int[n];
	int Low = 7, High = 65;
	CreateRows(a, k, n, Low, High, 0);
	PrintRows(a, k, n, 0);
	int min = a[1][0];
	cout << "Sum of min elements = " << SumMinElem(a, k, n, 1, 0, min, 0) << endl;
}