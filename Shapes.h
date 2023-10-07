#pragma once
#include <cmath>


class Shape
{
public:
	virtual double area() = 0;
	virtual std::ostream& MyName(std::ostream&) = 0;
};

class Triangle : public::Shape
{
	int a, b, c;
public:
	Triangle(double a, double b, double c) : a(a), b(b), c(c) {};
	virtual double area();
	virtual std::ostream& MyName(std::ostream&);
};

class Rectangle : public::Shape
{
	int a, b;
public:
	Rectangle(double a, double b) : a(a), b(b) {};
	virtual double area();
	virtual std::ostream& MyName(std::ostream&);
};

class Circle : public::Shape
{
	int a;
public:
	Circle(double a) : a(a) {};
	virtual double area() { return 3.14*a*a; }
	virtual std::ostream& MyName(std::ostream&);
};

std::ostream& operator<<(std::ostream& stream, Shape* p);
