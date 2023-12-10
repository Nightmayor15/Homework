#include <iostream>
#include "Shapes.h"

/// @brief Вычисление площади треугольника
/// @return Площадь треугольника (действительное число)
double Triangle::area()
{ return sqrt(((a + b + c) / 2. - a) * ((a + b + c) / 2. - b) * ((a + b + c) / 2. - c) * (a + b + c) / 2.); }

/// @brief Вычисление площади прямоугольника
/// @return Площадь прямоугольника (действительное число)
double Rectangle::area()
{
	return a * b;
}

/// @brief Вывод фигуры
/// @param stream 
/// @param p Указатель на фигуру
/// @return Имя фигуры (поток)
std::ostream& operator<<(std::ostream& stream, Shape* p)
{
	return p->MyName(stream);

}

/// @brief Вывод треугольника
/// @param stream 
/// @return Имя треугольника (поток)
std::ostream& Triangle::MyName(std::ostream& stream)
{
	return stream << "This is Triangle a = " << a << ", b = " << b << ", c = " << c << "\n";
}

/// @brief Вывод прямоугольника
/// @param stream 
/// @return Имя прямоугольика (поток)
std::ostream& Rectangle::MyName(std::ostream& stream)
{
	return stream << "This is Rectangle a = " << a << ", b= " << b << "\n";
}

/// @brief Вывод круга
/// @param streaкруга
/// @return Имя круга (поток)
std::ostream& Circle::MyName(std::ostream& stream)
{
	return stream << "This is Circle R = " << a << "\n";
}