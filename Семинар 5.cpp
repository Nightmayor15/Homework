#include <iostream>
#include "Nature.h"

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
	BinTree Dict;
	Dict["Russia"] = "Moscow";
	Dict["USA"] = "Washington";
	std::cout << Dict["Russia"] << Dict["USA"];

}