#include <iostream>
#include "Functions.h"
#include <clocale>

int main()
{
	system("chcp 65001");
	Vectors p, q;
	std::cout << "Введите координаты вектора p\n";
	std::cin >> p.x >> p.y >> p.z;
	std::cout << "Введите координаты вектора q\n";
	std::cin >> q.x >> q.y >> q.z;
	while (1)
	{
		Vectors a = p;
		Vectors b = q;
		std::cout << "1 - Найти модули векторов\n" << "2 - Найти противоположные векторы\n" << "3 - Сложить векторы\n" << "4 - Вычесть вектор q из вектора p\n" << "5 - Найти скалярное произведение векторов\n";
		std::cout << "6 - Найти векторное произведение векторов [p x q]\n" << "7 - Умножить векторы на скаляр n\n" << "0 - Завершить\n";
		int k; std::cin >> k; //Номер операции
		if (k == 0) break;
		else if (k == 1) std::cout << a.abs() << " " << b.abs() << std::endl;
		else if (k == 2) std::cout << ( - a) << " " << ( - b) << std::endl;
		else if (k == 3) std::cout << (a + b) << std::endl;
		else if (k == 4) std::cout << (a - b) << std::endl;
		else if (k == 5) std::cout << (a * b) << std::endl;
		else if (k == 6) std::cout << (a ^ b) << std::endl;
		else if (k == 7)
		{
			std::cout << "Введите скаляр n\n";
			double n;
			std::cin >> n;
			std::cout << n * a << " " << b * n;
		}
		else
		{
			std::cout << "ОШИБКА";
			break;
		}
	}
	
	return 0;
}