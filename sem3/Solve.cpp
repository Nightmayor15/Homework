#include "Solve.h"
#include <iostream>	

void LinkedList::push(int n)
{
	Node* r;
	r = new Node;
	r->data = n;
	r->next = this->root;
	this->root = r;
}

int LinkedList::pop()
{
	Node* n = this->root;
	int a = this->root->data;
	this->root = this->root->next;
	delete n;
	return a;
}


void LinkedList_s::push(std::string n)
{
	Node_s* r;
	r = new Node_s;
	r->data = n;
	r->next = this->root;
	this->root = r;
}

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


LinkedList_s Polska()
{
	LinkedList_s* L1 = new LinkedList_s;
	LinkedList_s* L2 = new LinkedList_s;
	std::string k;
	while (1)
	{
		std::string c = "_";
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
					std::string t = L2->pop();
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