#pragma once
#include <cmath>

/// @brief Класс фигур
class Shape
{
public:
	/// @brief Вычисление площади фигуры
	/// @return Площадь фигуры
	virtual double area() = 0;
	/// @brief Вывод самой фигуры
	/// @param  
	/// @return Имя фигуры (поток)
	virtual std::ostream& MyName(std::ostream&) = 0;
};

/// @brief Подкласс треугольников
class Triangle : public::Shape
{
	double a, b, c; //Длина сторон треугольника
public:
	Triangle(double a, double b, double c) : a(a), b(b), c(c) {};
	virtual double area();
	virtual std::ostream& MyName(std::ostream&); 
};

/// @brief Подкласс прямоугольников
class Rectangle : public::Shape
{
	double a, b; //Длина сторон прямоугольника
public:
	Rectangle(double a, double b) : a(a), b(b) {};
	virtual double area(); 
	virtual std::ostream& MyName(std::ostream&);
};

/// @brief Подкласс кружочков
class Circle : public::Shape
{
	double a; //Радиус круга
public:
	Circle(double a) : a(a) {};

	/// @brief Вычисление площади круга
	/// @return Площадь круга (действительное число)
	virtual double area() { return 3.14*a*a; }
	virtual std::ostream& MyName(std::ostream&);
};

std::ostream& operator<<(std::ostream& stream, Shape* p);
