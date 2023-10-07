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

Vectors::Vectors(double a, double b, double c)
{
	this->x = a;
	this->y = b;
	this->z = c;
}

Vectors Vectors::operator-()
{
	return Vectors(-x, -y, -z);
}

double Vectors::abs()
{
	return sqrt(x * x + y * y + z * z);
}

std::ostream& operator<<(std::ostream& stream, Vectors p)
{
	return stream << "(" << p.x << ", " << p.y << ", " << p.z << ")";
}


Vectors Vectors::operator+(Vectors other)
{
	return Vectors(x + other.x, y + other.y, z + other.z);
}

Vectors Vectors::operator-(Vectors other)
{
	return Vectors(x - other.x, y - other.y, z - other.z);
}

Vectors operator*(double n, Vectors p)
{
	return Vectors(p.x * n, p.y * n, p.z * n);
}

Vectors operator*(Vectors p, double n)
{
	return Vectors(p.x * n, p.y * n, p.z * n);
}

double Vectors::operator*(Vectors other)
{
	return x * other.x + y * other.y + z * other.z;
}

Vectors Vectors::operator^(Vectors other)
{
	return Vectors(y * other.z - z * other.y, z * other.x - x * other.z, x * other.y - y * other.x);
}

