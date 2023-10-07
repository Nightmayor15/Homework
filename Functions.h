#pragma once
/*
class Complex
{
private:
	double a, b;

public:
	double& Re();
	double& Im();

	double abs();
	Complex(double Re, double Im = 0);  // онструктор, название совпадает с названием класса
	Complex() { a = 0; b = 0; }; // онструктор по умолчанию

	Complex operator+(Complex other);
	Complex operator-(Complex other);
	Complex operator-();
	Complex operator*(Complex other);
	Complex operator*(double other);
	friend Complex operator*(double first, Complex second);
	
	friend std::ostream& operator<<(std::ostream& stream, Complex z);

};

//Complex operator*(double first, Complex second);

std::ostream& operator<<(std::ostream& stream, Complex z);
*/


class Vectors
{
public:
	double x;
	double y;
	double z;

	Vectors(double a = 0, double b = 0, double c = 0);
	friend std::ostream& operator<<(std::ostream& stream, Vectors p);
	
	Vectors operator-();
	double abs();

	Vectors operator+(Vectors other);
	Vectors operator-(Vectors other);
	double operator*(Vectors other);
	Vectors operator^(Vectors other);
	friend Vectors operator*(double n, Vectors p);
	friend Vectors operator*(Vectors p, double n);
	

};

std::ostream& operator<<(std::ostream& stream, Vectors p);

Vectors operator*(double n, Vectors p);
Vectors operator*(Vectors p, double n);