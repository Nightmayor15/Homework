#pragma once
#include <iostream>

template <typename T>
struct Node
{
	std::string key;
	T data;
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


template <typename T>
void Node<T>::del()
{
	if (left != nullptr)
	{
		left->del();
		delete left;
	}
	if (right != nullptr)
	{
		right->del();
		delete right;
	}
}

template <typename T>
BinTree<T>::~BinTree()
{
	if (root != nullptr)
	{
		root->del();
		delete root;
	}
}

template <typename T>
Node<T>* BinTree<T>::search(std::string key)
{
	if (this->root != nullptr)
	{
		return this->root->search(key);
	}
	else
	{
		Node<T>* n = new Node<T>();
		this->root = n;
		n->key = key;
		return n;
	}

}

template <typename T>
Node<T>* Node<T>::search(std::string keyy)
{
	if (keyy == this->key) return this;
	else if (keyy < this->key)
	{
		if (this->left != nullptr) {
			return this->left->search(keyy);
		}
		else
		{
			Node<T>* n = new Node<T>();
			n->key = keyy;
			this->left = n;
			return n;
		}
	}
	else // key > this->key
	{
		if (this->right != nullptr)
			return this->right->search(keyy);
		else
		{
			Node<T>* n = new Node<T>();
			n->key = keyy;
			this->right = n;
			return n;
		}
	}
}

template <typename T>
void Node<T>::attach(Node<T>* n)
{
	if (n->key == this->key)
	{
		this->data = n->data;
		delete n;
	}
	if (n->key < this->key)
	{
		if (this->left == nullptr) this->left = n;
		else this->left->attach(n);
	}
	if (n->key > this->key)
	{
		if (this->right == nullptr) this->right = n;
		else this->right->attach(n);
	}
}

/*void BinTree<T>::push(std::string key, std::string data)
{
	Node<T>* n;
	n = new Node<T>;
	n->data = data;
	n->key = key;

	if (root == nullptr) root = n;
	else root->attach(n);
}*/

template <typename T>
T& BinTree<T>::operator[](std::string key)
{
	Node<T>* b = BinTree<T>::search(key);
	return b->data;
}

