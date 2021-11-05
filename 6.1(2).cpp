#include <iostream>
#include <iomanip>
#include <time.h>

using namespace std;

void Create(int* a, const int size, const int Low, const int High, int i)
{
	a[i] = Low + rand() % (High - Low + 1);
	if (i < size - 1)
		Create(a, size, Low, High, i + 1);
}

void Print(int* a, const int size, int i)
{
	cout << setw(4) << a[i];
	if (i < size - 1)
		Print(a, size, i + 1);
	else
		cout << endl;
}
int Sum(int* a, const int size, int i)
{
	if (i < size-1)
	{
		if (!(a[i] > 0 || i % 2 == 0))
			return a[i] + Sum(a, size, i + 1);
		else
			return Sum(a, size, i + 1);
	}
	else
		return 0;
}
int Count(const int* const a, const int size, int i)
{
	if (i < size-1)
	{
		if (!(a[i] > 0 || i % 2 == 0))
			return  Count(a, size, i + 1)+1;
		else
			return Count(a, size, i + 1);
	}
	else
	return 0;
}
void Replacement(int a[], const int size,int i)
{
	if (i < size-1)
	{
		if (!(a[i] > 0 || i % 2 == 0))
			a[i] = 0;
		return Replacement(a, size, i + 1);
	}
	
}
int main()
{
	srand((unsigned)time(NULL));

	const int n = 26;
	int a[n];

	int Low = -40;
	int High = 20;
	Create(a, n, Low, High, 0);
	Print(a, n, 0);
	cout << "The sum of the elements that satisfy the condition is  " << Sum(a, n, 0) << endl;
	cout << "The number of elements that satisfy the condition is  " << Count(a, n,0) << endl;
	Replacement(a, n,0);
	Print(a, n, 0);
	return 0;
}