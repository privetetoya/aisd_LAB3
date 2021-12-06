#pragma once

#include <iostream>
#include "Stack.h"
#include "Queue.h"
#include "Iterator.h"



class BinaryHeap {
private:
	Node* root_of_heap;

public:
	int hight_of_heap, quantity_Last_el;
	Iterator* constructor_DFT() {
		return new DFT_iterator(root_of_heap);
	}

	Iterator* constructor_BFT() {
		BFT_iterator* new_bft_iterator = new BFT_iterator(root_of_heap);
		new_bft_iterator->queue->enqueue(root_of_heap);
		return new_bft_iterator;
	}

	class DFT_iterator : public Iterator
	{
	public:

		friend class Heap;

		DFT_iterator(Node*);

		~DFT_iterator();

		bool has_next() override;

		int next() override;




		Stack* stack;

		Node* cur;
	};

	class BFT_iterator : public Iterator
	{
	public:
		friend class Heap;

		BFT_iterator(Node*);

		~BFT_iterator();

		bool has_next() override;

		int next() override;





		Queue* queue;
		Node* cur;

	};


	BinaryHeap() { // Making an empty list
		this->root_of_heap = NULL;

	}

	BinaryHeap(int data) { // Making a list with values
		Node* Element = new Node(data);
		this->root_of_heap = Element;//the root of the heap
		hight_of_heap = 1; //heap height
		quantity_Last_el = 1;//number of elements on the last level

	}

	Node* parent_search(int tmp) {

		Node* ending_parent = root_of_heap;

		int tmp_lay = tmp;
		int tmp_Last = this->quantity_Last_el;

		if (this->quantity_Last_el > tmp) {
			tmp_lay = tmp_lay * 2;
		}

		while (tmp_lay != 2) {
			if (tmp_Last <= (tmp_lay / 2)) {

				ending_parent = ending_parent->left_node;
				tmp_lay = tmp_lay / 2;
			}
			else {
				ending_parent = ending_parent->right_node;
				tmp_Last = tmp_Last - tmp_lay / 2;
				tmp_lay = tmp_lay / 2;
			}
		}

		return ending_parent;
	}

	Node* findElem(int data) {
		Node* Elem = NULL;

		DFT_iterator* new_It;
		new_It = new DFT_iterator(root_of_heap);

		while (new_It->has_next()) {
			Elem = new_It->cur;
			if (new_It->next() == data) {
				delete new_It;
				return Elem;
			}
		}


		delete new_It;
		throw std::invalid_argument("error not found");
	}

	void siftDown(Node* tmp) {

		Node* wrong = tmp;


		if ((tmp->left_node != NULL) && (tmp->right_node != NULL))

			if ((tmp->data < tmp->right_node->data) || (tmp->data < tmp->left_node->data)) {

				if ((tmp->left_node->data) > (tmp->right_node->data))
					wrong = tmp->left_node;
				else
					wrong = tmp->right_node;
				std::swap(tmp->data, wrong->data);
				siftDown(wrong);
			}

			else {
				if ((tmp->right_node == NULL) && (tmp->left_node != NULL) && tmp->data < tmp->left_node->data) {
					wrong = tmp->left_node;
					std::swap(tmp->data, wrong->data);
					siftDown(wrong);
				}
			}

	}


	void siftUp(Node* tmp) {
		if (tmp->parent == NULL) {
			return;
		}
		else {
			if (tmp->data > tmp->parent->data) {
				std::swap(tmp->data, tmp->parent->data);
				siftUp(tmp->parent);
			}
			else {
				return;
			}
		}
	}


	void Heapify(Node* tmp) {
		if (tmp->parent == NULL)
			siftDown(tmp);
		else
			if ((tmp->data) > (tmp->parent->data))
				siftUp(tmp);
			else
				siftDown(tmp);
	}

	void insert(int key)
	{

		if (root_of_heap == NULL) { //++if the heap is empty, then the root is assigned the insertion value
			Node* elem = new Node(key);
			this->root_of_heap = elem;
			this->quantity_Last_el = 1;
			this->hight_of_heap = 1;

		}
		else {
			Node* tmp = new Node(key);
			Node* cur = root_of_heap;

			int last_layer = 1;
			this->quantity_Last_el++;

			for (int index = 0; index < hight_of_heap - 1; index++) {
				last_layer = last_layer * 2;
			}

			if (last_layer < this->quantity_Last_el) {
				this->quantity_Last_el = 1;
				this->hight_of_heap++;
				last_layer = last_layer * 2;
			}

			cur = parent_search(last_layer);

			if (cur->left_node == NULL) {
				cur->left_node = tmp;
				tmp->parent = cur;
			}
			else {
				cur->right_node = tmp;
				tmp->parent = cur;
			}

			Heapify(tmp);
		}
	}

	void remove(int key) {

		Node* delete_elem = findElem(key);


		if (root_of_heap->left_node == NULL && root_of_heap->right_node == NULL) {
			delete root_of_heap;
			root_of_heap = NULL;
			hight_of_heap = 0; quantity_Last_el = 0;
		}

		int last_layer = 1;

		for (int index = 0; index < hight_of_heap - 1; index++) {
			last_layer = last_layer * 2;
		}

		Node* last_elem = parent_search(last_layer);

		if (last_elem->right_node != NULL) {
			last_elem = last_elem->right_node;
			last_elem->parent->right_node = NULL;
			quantity_Last_el--;
		}
		else {
			last_elem = last_elem->left_node;
			last_elem->parent->left_node = NULL;
			quantity_Last_el--;
		}




		if (quantity_Last_el == 0) {
			quantity_Last_el = 1;
			hight_of_heap--;
			for (int index = 0; index < hight_of_heap - 1; index++) {
				quantity_Last_el = quantity_Last_el * 2;
			}

		}
		if (delete_elem == last_elem) { delete last_elem; }
		else {


			std::swap(last_elem->data, delete_elem->data);
			delete last_elem;
			Heapify(delete_elem);
		}

	}

	bool contains(int data) {
		try {
			findElem(data);
			return true;
		}
		catch (std::invalid_argument) {
			return false;
		}
	}
};


BinaryHeap::DFT_iterator::DFT_iterator(Node* root_of_heap) {
	cur = root_of_heap;
	stack = new Stack();
}
bool BinaryHeap::DFT_iterator::has_next() {
	return cur != NULL;
}

int BinaryHeap::DFT_iterator::next() {
	if (!has_next()) {
		throw std::out_of_range("error not found");
	}

	int tmp = cur->data;

	if (cur->right_node != NULL) {
		stack->Stack_push(cur->right_node);
	}

	if (cur->left_node != NULL) {
		cur = cur->left_node;
	}
	else {
		try {
			cur = stack->peek();
			stack->Stack_pop();
		}
		catch (std::out_of_range) {
			cur = NULL;
		}
	}

	return tmp;
}

BinaryHeap::DFT_iterator::~DFT_iterator() {
	delete stack;
}

BinaryHeap::BFT_iterator::BFT_iterator(Node* root_of_heap) {
	cur = root_of_heap;
	queue = new Queue();
}

bool BinaryHeap::BFT_iterator::has_next() {
	return cur != NULL;
}

int BinaryHeap::BFT_iterator::next() {
	if (!has_next()) {
		throw std::out_of_range("error not found");
	}

	int tmp = cur->data;

	if (cur->left_node != NULL) {
		queue->enqueue(cur->left_node);
	}

	if (cur->right_node != NULL) {
		queue->enqueue(cur->right_node);
	}

	queue->dequeue();

	try {
		cur = queue->front();


	}
	catch (std::out_of_range) {
		cur = NULL;
	}

	return tmp;
}

BinaryHeap::BFT_iterator::~BFT_iterator() {
	delete queue;
}