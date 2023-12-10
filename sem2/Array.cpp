#include <iostream>
#include "Array.h"

void sort_array(int* a, int n) {
	if (n < 2) return;
	int* first = a;
	int* last = a + n - 2;
	int* f = a + n - 1;
	while (first < last)
	{
		while (*(++first) < *f);
		while (last > first && *(--last) > *f);
		if (first < last) {
			int tmp = *first;
			*first = *last;
			*last = tmp;
		}
	}
	if (first < f) {
		int tmp = *first;
		*first = *f;
		*f = tmp;
	}
}

void print_array(int* a, int n) //Вывод списка
{
	for (int i = 0; i < n; ++i) {
		std::cout << a[i] << " ";
	}
}

void insert_sort(int* a, int n) //Сортировка вставками
{
	for (int i = 1; i < n; ++i) //Включаем элемент слева к уже отсортированному списку
	{
		for (int j = i-1; j >= 0 && a[j] > a[j+1]; --j) //Проверяем элементы, сравниваем с предыдущим элементом
		{
			int tmp = a[j]; //Меняем j-ый и i-ый элементы
			a[j] = a[j+1];
			a[j+1] = tmp;
			//--i;
		}
	}


}

// void merge_sort(int* a, int n) //Сортировка слиянием
// {
// 	if (n < 10) {insert_sort(a, n); return};
// 	int m = n / 2;
// 	merge_sort(a, m);
// 	merge_sort(a+m, n-m);
// 	merge(a, m, a+m, n-m);
// }

void merge_sort(int* a, int n) //Сортировка слиянием
{
	int mid = n / 2; //Выбираем центральный элемент
	if (mid%2 == 0) mid++;
	int* c = new int[n]; //Создаем новый массив
	for (int i = 1; i <= mid; i = i * 2) //
	{
		int step = i; //Шаг для сортировки
		int j = mid; //Индекс элементов "второго" массива при слиянии
		int k = 0;	//Индекс элементов "первого" массива при слиянии
		int r = 0;	//Индекс элементов нового списка
		while (step < mid) //Пока шаг не стал больше массива
		{
			while ((k <= step) && (j < n) && (j < (mid + step))) //Сортировка в пределе одного массива (шага)
			{
				if (a[k] < a[j]) {c[r] = a[k]; k++; r++; } //Сравниваем элементы двух массивов на слияние и сортируем их (слева направо)
				else { c[r] = a[j]; j++; r++; std::cout << c[r-1] << " Here\n";}

			}
			while (k < step) //Если элементы одного из массивов закончились, то в массив слияния добавляем оставшийся ммассив
			{
				c[r] = a[k];
				k++; r++;
				std::cout << c[r-1] << " Here\n";
			}
			while ((j < (mid + step)) && (j < n))
			{
				c[r] = a[j];
				r++; j++;
				std::cout << c[r-1] << " Here\n";
			}
			step = step + i; //Сливаем остальные массивы
		}
		for (int t = mid+step; t < n; t++) {c[t] = a[t];}
		for (int p = 0; p < n; p++) {a[p] = c[p];} //Переписываем элементы в исходный список
	}
	delete[] c;

}

void hybrid_sort(int* a, int n) //Гибридная сортировка
{
	for (int t = 1; t<=n; t += 10) //Сортировка вставками
	{
		for (int i = t; i < t+10 && i<n; ++i) //Включаем элемент слева к уже отсортированному списку
		{
			for (int j = i-1; j >= 0 && a[j] > a[j+1]; --j) //Проверяем элементы, сравниваем с предыдущим элементом
			{
				int tmp = a[j]; //Меняем j-ый и i-ый элементы
				a[j] = a[j+1];
				a[j+1] = tmp;
			}
		}
	}
	std::cout << a << "Here\n";

	int mid = n / 2; //Выбираем центральный элемент
	if (mid % 2 == 1) ++mid;
	int* c = new int[n]; //Создаем новый массив
	for (int i = 10; i < n; i = i * 2) //Сортировка слиянием
	{	
		int step = i; //Шаг для сортировки
		int j = mid; //Индекс элементов "второго" массива при слиянии
		int k = 0;	//Индекс элементов "первого" массива при слиянии
		int r = 0;	//Индекс элементов нового списка
		while (step <= mid) //Пока шаг не стал больше середины массива
		{
			while ((k < step) && (j < n) && (j < (mid + step))) //Сортировка в пределе одного массива (шага)
			{
				if (a[k] < a[j]) { c[r] = a[k]; k++; r++; } //Сравниваем элементы двух массивов на слияние и сортируем их (слева направо)
				else { c[r] = a[j]; j++; r++; }
			}
			while (k < step) //Если элементы одного из массивов закончились, то в массив слияния добавляем оставшийся ммассив
			{
				c[r] = a[k];
				k++; r++;
			}
			while ((j < (mid + step)) && (j < n))
			{
				c[r] = a[j];
				r++; j++;
			}
			step = step + i; //Сливаем остальные массивы
		}
			for (int p = 0; p < n; p++) a[p] = c[p]; //Переписываем элементы в исходный список
	}
	delete[] c;	
}

void swap(int& x, int& y) //Замена переменных XOR-суммой
{
	x = x ^ y;
	y = x ^ y;
	x = y ^ x;

}

int fib(int n) //Вычисление чисел Фибоначчи
{
	if (n == 1 || n == 2) return 1;
	else return fib(n - 1) + fib(n - 2);
}