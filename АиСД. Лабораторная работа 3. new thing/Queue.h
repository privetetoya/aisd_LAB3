#pragma once
#include <iostream>
#include "Node.h"
class Queue {
private:
	class Queue_For_elements {
	public:
		Node* data;;
		Queue_For_elements* next;
		Queue_For_elements* head, * last;
		Queue_For_elements(Node* data = 0, Queue_For_elements* next = NULL, Queue_For_elements* last = NULL, Queue_For_elements* head = NULL) : next(next), data(data), last(last), head(head)
		{ }
		~Queue_For_elements() = default;

		void NewNext(Queue_For_elements* newnext) {
			this->next = newnext;
		}

		void NewData(Node* newdata) {
			this->data = newdata;
		}


		Queue_For_elements* getNext() {
			return this->next;
		}


		Node* getdata() {
			return this->data;
		}

		Node* getNextdata() {
			if (this->next == NULL) {
				return 0;
			}
			else
				return this->next->data;
		}

		Queue_For_elements* toNULL() {
			return this->next = NULL;
		}

		Node* haveHead() {

			return head->data;
		}




	};
	Queue_For_elements* head, * last;

public:


	Queue() {
		head = NULL;
		last = NULL;
	};

	~Queue() {
		while (!Queue_isEmpty()) {
			dequeue();
		}
	};

	void dequeue() {
		if (head == NULL) {
			throw std::runtime_error("The list NULL\n");
		}
		else {
			Queue_For_elements* cur = head;
			head = head->next;
			delete cur;
		}
	};

	void enqueue(Node* data) {
		if (head == NULL) {
			Queue_For_elements* cur = new Queue_For_elements(data);
			head = cur;
			last = head;
		}
		else {
			Queue_For_elements* cur = new Queue_For_elements(data);
			last->next = cur;
			last = cur;
		}
	};

	bool Queue_isEmpty() { //CHECKING THE LIST FOR EMPTINESS
		if (head == NULL) { //IF THE LIST IS EMPTY
			return 1;
		}
		else {
			return 0;
		}
	};

	Node* front() {
		if (Queue_isEmpty()) {
			throw std::out_of_range("The list NULL\n");
		}
		else {
			//Queue_For_elements* haveHead();
			return head->data;
		};

	}

};