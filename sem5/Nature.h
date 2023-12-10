#pragma once
#include <iostream>

/// @brief Элемент дерева
/// @tparam 
template <typename T>
struct Node
{
	std::string key; //Ключ
	T data; //Значение
	Node* left = nullptr;
	Node* right = nullptr;
	void del();
	void attach(Node* n);
	Node* search(std::string key);
};

/// @brief Двоичное дерево, его корень
/// @tparam 
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

/// @brief Удаление потомков элемента
/// @tparam 
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

/// @brief Деструктор
/// @tparam
template <typename T>
BinTree<T>::~BinTree()
{
	if (root != nullptr)
	{
		root->del();
		delete root;
	}
}

/// @brief Поиск по дереву по ключу
/// @tparam 
/// @param key Ключ (строка)
/// @return Указатель на элемент дерева
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

/// @brief Поиск по элементу дерева и по его потомкам
/// @tparam 
/// @param keyy Ключ (строка)
/// @return Указатель на элемент дерева
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

/// @brief Присоединение элемента к дереву (к элементу)
/// @tparam 
/// @param n Указатель на присоединяемый элемент
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

/// @brief Вывод элемента по его ключу (или создание элемента)
/// @tparam
/// @param key Ключ (строка)
/// @return Информацию элемента списка
template <typename T>
T& BinTree<T>::operator[](std::string key)
{
	Node<T>* b = BinTree<T>::search(key);
	return b->data;
}

