#pragma once
#include <iostream>

/// @brief Элемент связного списка с int
struct Node
{
	int data;
	Node* next = nullptr;
};

/// @brief Связный список (его корень) с int
struct LinkedList 
{
	Node* root = nullptr;
	void push(int n);
	int pop();
};

/// @brief Элемент связного списка с std::string
struct Node_s
{
	std::string data;
	Node_s* next = nullptr;
};

/// @brief Связный список (его корень) с std::string
struct LinkedList_s 
{
	Node_s* root = nullptr;
	void push(std::string n);
	std::string pop();
};
LinkedList_s Polska();