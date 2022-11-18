// Lab_7_2_1.cpp
// < Царук В'ячеслав >
// Лабораторна робота № 7.2.1)
// Опрацювання багатовимірних масивів ітераційними способами.
// Варіант 25
#include <iostream>
#include <iomanip>
#include <time.h>
using namespace std;
void Create(int** a, const int n, const int Low, const int High);
void Print(int** a, const int n);
void SearchSum(int** a, const int n, int& Sum);
int main()
{
	
	srand((unsigned)time(NULL));
	int Low = 7;
	int High = 65;
	int n;
	int Sum=0;
	cout << "n = "; cin >> n;
	int** a = new int* [n];
	for (int i = 0; i < n; i++)
		a[i] = new int[n];
	Create(a, n, Low, High);
	SearchSum(a, n, Sum);
	Print(a, n);
	cout << " Sum= " << Sum;
		for (int i = 0; i < n; i++)
			delete[] a[i];
	delete[] a;
	return 0;
}
void Create(int** a, const int n, const int Low, const int High)
{
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			a[i][j] = Low + rand() % (High - Low + 1);
}
void Print(int** a, const int n)
{
	cout << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cout << setw(4) << a[i][j];
		cout << endl;
	}
	cout << endl;
}
void SearchSum(int** a, const int n, int& Sum)
{
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i == j) {
				Sum += a[i][j];
			}
		}
	}	
}

