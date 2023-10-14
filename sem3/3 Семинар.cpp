#include <iostream>
#include "Solve.h"

int main()
{
	int NUM;
	std::cin >> NUM;
	if (NUM == 1)
	{
		LinkedList* L = new LinkedList;
		std::string k;
		while (k != "End")
		{
			std::cout << "<Push>, <Pop> or <End>?" << std::endl;
			std::cin >> k;
			if (k == "Push")
			{
				int n;
				std::cin >> n;
				L->push(n);
			}
			if (k == "Pop")
			{
				std::cout << L->pop() << std::endl;
			}
		}
		delete L;
	}
	if (NUM == 2)
	{
		LinkedList_s L = Polska();
		LinkedList_s P;
		while (L.root != nullptr)
		{
			P.push(L.pop());
		}
		while (P.root != nullptr) std::cout << P.pop();
	}
	return 0;
	
}
