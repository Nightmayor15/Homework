#include <iostream>
#include "Array.h"

int main()
{
	int*a = new int[5];
	a[0] = 2;
	a[1] = 5;
	a[2] = 3;
	a[3] = 4;
	a[4] = 0;
	a[5] = 3;
	merge_sort(a, 6);
	print_array(a, 6);
}
int main1()
{
	int Num; //Номер задания
	std::cin >> Num;
	if (Num == 1 || Num == 2 || Num == 3)
	{
		int n; //Количество элементов в массиве
		std::cin >> n;
		int* a = new int[n];

		for (int i = 0; i < n; ++i)
		{
			std::cin >> a[i]; //Элементы массива
		}
		if (Num == 1) insert_sort(a, n); 
		if (Num == 2) merge_sort(a, n);
		if (Num == 3) hybrid_sort(a, n);
		print_array(a, n);
		delete[] a;
	}

	if (Num == 4)
	{
		int x, y; //Какие-то x и y
		std::cin >> x >> y;
		swap(x, y);
		std::cout << x << " " << y;
	}
	
	if (Num == 5)
	{
		int n; //Номер числа Фибоначчи
		std::cin >> n;
		int F = fib(n);
		std::cout << F;
	}
	return 0;

}

