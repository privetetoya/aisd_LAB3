#pragma once

#include <iostream>
#include "Node.h"


/*  ++Stack()
	++push(item)
	++pop()
	++peek()
	++isEmpty()
	++size(
	*/


class Stack {
private:

	class Stack_For_elements {
	private:
		Node* data;
		Stack_For_elements* next;
	public:
		Stack_For_elements(Node* data = 0, Stack_For_elements* next = NULL) : next(next), data(data)
		{ }
		~Stack_For_elements() = default;
		void NewNext(Stack_For_elements* newnext) {
			this->next = newnext;
		}

		void NewData(Node* newdata) {
			this->data = newdata;
		}

		Stack_For_elements* getNext() {
			return this->next;
		}

		Node* getElemdata() {
			return this->data;
		}

		Node* getNextdata() {
			if (this->next == NULL) {
				return 0;
			}
			else
				return this->next->data;
		}

		Stack_For_elements* toNULL() {
			return this->next = NULL;
		}

	};

	Stack_For_elements* head, * last;

public:

	Stack() {
		head = NULL;
	}
	~Stack() {
		while (!Stack_isEmpty()) {
			Stack_pop();
		}
	}
	void Stack_pop() {
		if (head == NULL) {
			throw std::runtime_error("The list NULL\n");
		}
		else {
			Stack_For_elements* cur = head;
			head = head->getNext();
			delete cur;
		}
	};;
	void Stack_push(Node* data) {
		if (head == NULL) {

			Stack_For_elements* cur = new Stack_For_elements(data);
			head = cur;
			last = head;

		}
		else {
			Stack_For_elements* tmp = new Stack_For_elements(data);
			Stack_For_elements* cur = head;
			this->head = tmp;
			this->head->NewNext(cur);
		}
	};
	bool Stack_isEmpty() { //CHECKING THE LIST FOR EMPTINESS
		if (head == NULL) { //IF THE LIST IS EMPTY
			return 1;
		}
		else {
			return 0;
		}
	}
	Node* peek() {

		if (Stack_isEmpty()) {
			throw std::out_of_range("error not found");
		}
		else {
			return head->getElemdata();
		}

	}
};