#pragma once
#include <iostream>

struct Node
{
	int data;
	Node* next = nullptr;
};
struct LinkedList
{
	Node* root = nullptr;
	void push(int n);
	int pop();
};
struct Node_s
{
	std::string data;
	Node_s* next = nullptr;
};

struct LinkedList_s
{
	Node_s* root = nullptr;
	void push(std::string n);
	std::string pop();
};
LinkedList_s Polska();