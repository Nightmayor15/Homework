#include <iostream>
#include "Shapes.h"

/*
class A
{
	int a;
public:
	A() { a = 1; };
	virtual int foo() { return a; };
	void print() { std::cout << a; };
};

class B : public::A
{
	int b;
public:
	B():A() { b = 2 * A::foo(); };
	virtual int foo() { return b; };
};

class Parallelogramm
{
protected:
	double a, b, angle;
public:
	Parallelogramm(double a, double b, double angle) :a(a), b(b), angle(angle) {};

};

class Square : public::Parallelogramm
{
public:
	Square(double size) : Parallelogramm(size, size, 3.14 / 2.) {};


};
int main()
{
	A* data[2];
	data[0] = new A();
	data[1] = new B();

	for (int i = 0; i < 2; ++i)
	{
		std::cout << data[i]->foo() << " ";
		data[i]->print();
		std::cout << std::endl;
	}


	return 0;

}
*/

int main() 
{
	Shape* data[3]; //Массив фигур
	data[0] = new Triangle(3, 4, 5); //Треугольник
	data[1] = new Rectangle(6, 8); //Прямоугольник
	data[2] = new Circle(5); //Круг

	for (int i = 0; i < 3; ++i) { //Вывод всех фигур
		std::cout << data[i] << std::endl;
	}
	double res = 0; //Переменная для вычисления площади фигур
	for (int i = 0; i < 3; ++i) { //Вычисление суммарной площади фигур
		res = res + data[i]->area();
	}
	std::cout << "sum area is " << res << std::endl;
	return 0;
}