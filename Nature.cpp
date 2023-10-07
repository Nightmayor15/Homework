#include <iostream>
#include "Nature.h"


void Node::del()
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

BinTree::~BinTree()
{
	if (root != nullptr)
	{
		root->del();
		delete root;
	}
}

Node* BinTree::search(std::string key)
{
	if (this->root != nullptr)
	{
		return this->root->search(key);
	}
	else
	{
		Node* n = new Node();
		this->root = n;
		n->key = key;
		return n;
	}

}

Node* Node::search(std::string keyy)
{
	if (keyy == this->key) return this;
	else if (keyy < this->key)
	{
		if (this->left != nullptr) {
			return this->left->search(keyy);
		}
		else
		{
			Node* n = new Node();
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
			Node* n = new Node();
			n->key = keyy;
			this->right = n;
			return n;
		}
	}
}

void Node::attach(Node* n)
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

/*void BinTree::push(std::string key, std::string data)
{
	Node* n;
	n = new Node;
	n->data = data;
	n->key = key;

	if (root == nullptr) root = n;
	else root->attach(n);
}*/

std::string& BinTree::operator[](std::string key)
{
	Node* b = BinTree::search(key);
	return b->data;
}

