// Lab_7_2_2.cpp
// < Царук В'ячеслав >
// Лабораторна робота № 7.2.1)
// Опрацювання багатовимірних масивів ітераційними способами.
// Варіант 25
#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;
void CreateRow(int** a, const int rowNo, const int N, const int Low,const int High, int colNo)
{
	a[rowNo][colNo] = Low + rand() % (High - Low + 1);
	if (colNo < N - 1)
		CreateRow(a, rowNo, N, Low, High, colNo + 1);
}
void CreateRows(int** a, const int N, const int Low, const int High, int rowNo)
{
	CreateRow(a, rowNo, N, Low, High, 0);
	if (rowNo < N - 1)
		CreateRows(a, N, Low, High, rowNo + 1);
}
void PrintRow(int** a, const int rowNo, const int N, int colNo)
{
	cout << setw(4) << a[rowNo][colNo];
	if (colNo < N - 1)
		PrintRow(a, rowNo, N, colNo + 1);
	else
		cout << endl;
}
void PrintRows(int** a, const int N, int rowNo)
{
	PrintRow(a, rowNo, N, 0);
	if (rowNo < N - 1)
		PrintRows(a, N, rowNo + 1);
	else
		cout << endl;
}
void SearchSum(int** a, const int N, const int rowNo,  int colNo, int& Sum)
{
	if (rowNo== colNo)
	{
		Sum += a[rowNo][colNo];
		
	}
		if (colNo < N - 1 && rowNo<N-1)
			SearchSum(a, N, rowNo+1, colNo+1, Sum);
}

int main()
{
	srand((unsigned)time(NULL));
	int N;
	cout << "N = "; cin >> N;
	cout << endl;
	int** a = new int* [N];
	for (int i = 0; i < N; i++)
		a[i] = new int[N];
	int Low = -9, High = 9;
	int Sum = 0;
	CreateRows(a, N, Low, High, 0);
	PrintRows(a, N, 0);
	SearchSum(a, N, 0, 0, Sum);
	cout << " Sum= " << Sum;
	
	for (int i = 0; i < N; i++)
		delete[] a[i];
	delete[] a;
	return 0;
}
