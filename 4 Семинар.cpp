#include <iostream>
#include "Functions.h"
#include <clocale>

int main4()
{
	setlocale(LC_ALL, "Russian");
	Vectors p, q;
	std::cout << "������� ���������� ������� p\n";
	std::cin >> p.x >> p.y >> p.z;
	std::cout << "������� ���������� ������� q\n";
	std::cin >> q.x >> q.y >> q.z;
	while (1)
	{
		Vectors a = p;
		Vectors b = q;
		std::cout << "1 - ����� ������ ��������\n" << "2 - ����� ��������������� �������\n" << "3 - ������� �������\n" << "3 - ������� ������ q �� ������� p\n" << "4 - ����� ��������� ������������ ��������\n";
		std::cout << "5 - ����� ��������� ������������ �������� [p x q]\n" << "6 - �������� ������� �� ������ n\n" << "0 - ���������\n";
		int k; std::cin >> k;
		if (k == 0) break;
		else if (k == 1) std::cout << a.abs() << " " << b.abs() << std::endl;
		else if (k == 2) std::cout << ( - a) << " " << ( - b) << std::endl;
		else if (k == 3) std::cout << (a + b) << std::endl;
		else if (k == 4) std::cout << (a * b) << std::endl;
		else if (k == 5) std::cout << (a ^ b) << std::endl;
		else if (k == 6)
		{
			std::cout << "������� ������ n\n";
			double n;
			std::cin >> n;
			std::cout << n * a << " " << b * n;
		}
		else
		{
			std::cout << "������";
			break;
		}
	}
	
	return 0;
}