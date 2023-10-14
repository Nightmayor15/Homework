#pragma once
#include <iostream>

template <typename data>
struct Node
{
	std::string key, data;
	Node* left = nullptr;
	Node* right = nullptr;
	void del();
	void attach(Node* n);
	Node* search(std::string key);
};

template <typename T>
class BinTree
{
	Node<T>* root = nullptr;
	//void push(std::string key, std::string data);
	Node<T>* search(std::string key);
public:
	~BinTree();
	T& operator[](std::string key);

};
