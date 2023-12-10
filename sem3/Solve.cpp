#include "Solve.h"
#include <iostream>
#include <exception>	

/// @brief Ввод данных в список
/// @param n Целое число
void LinkedList::push(int n)
{
	Node* r;
	r = new Node;
	r->data = n;
	r->next = this->root;
	this->root = r;
}

/// @brief Вывод данных из списка
/// @return Данные (целое число)
int LinkedList::pop()
{
	if (root == nullptr){ throw std::out_of_range("List is Empty");}
	Node* n = this->root;
	int a = this->root->data;
	this->root = this->root->next;
	delete n;
	return a;
}

/// @brief Ввод данных в список
/// @param n Строка
void LinkedList_s::push(std::string n)
{
	Node_s* r;
	r = new Node_s;
	r->data = n;
	r->next = this->root;
	this->root = r;
}

/// @brief Вывод данных из списка
/// @return Данные (строка)
std::string LinkedList_s::pop()
{
	if (this->root == nullptr) return "ERROR";
	else
	{
		Node_s* n = this->root;
		std::string a = this->root->data;
		this->root = this->root->next;
		delete n;
		return a;
	}
}

/// @brief Обратная польская запись
/// @return Связный список
LinkedList_s Polska()
{
	LinkedList_s* L1 = new LinkedList_s; //Список 1 (итоговый)
	LinkedList_s* L2 = new LinkedList_s; //Список 2 (промежуточный)
	std::string k; //Считыватель символов из терминала
	while (1)
	{
		std::string c = "_"; //Считыватель символов из списка 2
		std::cin >> k;
		if (k == "=") break;

		if (k == "(") L2->push(k);
		else if (k == ")")
		{
			while (1)
			{
				c = L2->pop();
				if (c == "(" || c == "ERROR") break;
				if (c != "(") L1->push(c);
			}
		}
		else if (k == "*") L2->push(k);
		else if (k == "/") L2->push(k);
		else if (k == "+" || k == "-")
		{
			
				while (1)
				{
					std::string t = L2->pop(); //Переносчик элементов из списка 2 в список 1
					if (t == "*" || t == "/") L1->push(t);
					else if (t == "ERROR") break;
					else {L2->push(t); break;}
				}
			L2->push(k);
		}
		else L1->push(k);
	}
	while (L2->root != nullptr)
	{
		std::string t = L2->pop();
		L1->push(t);
	}
	return *L1;
	delete[] L2;
}