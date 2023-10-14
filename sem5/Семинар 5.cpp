#include <iostream>
#include "Nature.h"
#include <clocale>

/*
class Mylist
{
private:
	int* data;
	int N;
public:
	Mylist(int N = 0) { data = new int[N]; };
};

int main()
{
	Mylist a = Mylist(10);
	for (int i = 0; i < N; ++i)
	{
		cout << data[i] << " ";
	}


}*/

int main()
{
	BinTree<int> Dict;
	Dict["Russia"] = 1;
	Dict["USA"] = 2;
	std::cout << Dict["Russia"] << Dict["USA"];

}