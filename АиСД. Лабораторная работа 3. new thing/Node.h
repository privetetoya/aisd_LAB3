#pragma once
#include <iostream>
class Node {
public:
	int data;
	Node* left_node, * right_node, * parent;
	Node(int data = 0, Node* left_node = NULL, Node* right_node = NULL, Node* parent = NULL) {
		this->data = data;
		this->left_node = left_node;
		this->right_node = right_node;
		this->parent = parent;
	}
};sfs