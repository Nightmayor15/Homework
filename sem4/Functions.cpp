#include <iostream>
#include "Functions.h"
#include <cmath>
/*
double& Complex::Re()
{
	return a;

};
double& Complex::Im()
{
	return b;
}
double Complex::abs()
{
	return sqrt(a * a + b * b);

}

Complex::Complex(double a, double b)
{
	this->a = a;
	this->b = b;

}


Complex Complex::operator+(Complex other)
{
	return Complex(a + other.a, b + other.b);

}
Complex Complex::operator-()
{
	return Complex(-a, -b);

}

std::ostream& operator<<(std::ostream& stream, Complex z)
{
	return stream << z.Re() << "+" << z.Im() << "i");

}
*/

/// @brief Конструктор
/// @param a Первая координата (действительное число)
/// @param b Вторая координата (действительное число)
/// @param c Третья координата (действительное число)
Vectors::Vectors(double a, double b, double c):x(a), y(b), z(c){};

/// @brief Нахождение обратного вектора
/// @return Обратный вектор
Vectors Vectors::operator-()
{
	return Vectors(-x, -y, -z);
}

/// @brief Нахождение длины вектора
/// @return Длина вектора (действительное число)
double Vectors::abs()
{
	return sqrt(x * x + y * y + z * z);
}

/// @brief Вывод координат вектора
/// @param stream Поток
/// @param p Вектор
/// @return Координаты вектора (поток)
std::ostream& operator<<(std::ostream& stream, Vectors p)
{
	return stream << "(" << p.x << ", " << p.y << ", " << p.z << ")";
}

/// @brief Сложение векторов
/// @param other Вектор
/// @return Вектор
Vectors Vectors::operator+(Vectors other)
{
	return Vectors(x + other.x, y + other.y, z + other.z);
}

/// @brief Вычитание одного вектора из другого
/// @param other Вектор
/// @return Вектор
Vectors Vectors::operator-(Vectors other)
{
	return Vectors(x - other.x, y - other.y, z - other.z);
}

/// @brief Умножение вектора на скаляр слева
/// @param n Действительное число
/// @param p Вектор
/// @return Вектор
Vectors operator*(double n, Vectors p)
{
	return Vectors(p.x * n, p.y * n, p.z * n);
}

/// @brief Умножение вектора на скаляр справа
/// @param n Действительное число
/// @return Вектор
Vectors Vectors::operator*(double n)
{
	return Vectors(x * n, y * n, z * n);
}

/// @brief Скалярное произведение векторов
/// @param other Вектор
/// @return Действительное число
double Vectors::operator*(Vectors other)
{
	return x * other.x + y * other.y + z * other.z;
}

/// @brief Векторное произведение векторов
/// @param other Вектор
/// @return Вектор
Vectors Vectors::operator^(Vectors other)
{
	return Vectors(y * other.z - z * other.y, z * other.x - x * other.z, x * other.y - y * other.x);
}

