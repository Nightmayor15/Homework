#include <iostream>
#include "Shapes.h"

double Triangle::area()
{ return sqrt(((a + b + c) / 2. - a) * ((a + b + c) / 2. - b) * ((a + b + c) / 2. - c) * (a + b + c) / 2.); }

double Rectangle::area()
{
	return a * b;
}

std::ostream& operator<<(std::ostream& stream, Shape* p)
{
	return p->MyName(stream);

}

std::ostream& Triangle::MyName(std::ostream& stream)
{
	return stream << "This is Triangle a = " << a << ", b = " << b << ", c = " << c << "\n";
}

std::ostream& Rectangle::MyName(std::ostream& stream)
{
	return stream << "This is Rectangle a = ?, b = ?\n";
}

std::ostream& Circle::MyName(std::ostream& stream)
{
	return stream << "This is Circle R =?\n";
}