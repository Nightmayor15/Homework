#pragma once
#include <iostream>

struct Node
{
	std::string key, data;
	Node* left = nullptr;
	Node* right = nullptr;
	void del();
	void attach(Node* n);
	Node* search(std::string key);
};

class BinTree
{
	Node* root = nullptr;
	//void push(std::string key, std::string data);
	Node* search(std::string key);
public:
	~BinTree();
	std::string& operator[](std::string key);

};
