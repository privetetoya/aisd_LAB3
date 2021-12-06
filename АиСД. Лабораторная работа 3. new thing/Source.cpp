#include <iostream>
#include "Stack.h"
#include "Queue.h"
#include "BinaryHeap.h"
using namespace std;

int main()
{
	BinaryHeap Heap(10);
	Iterator* dft;
	Heap.insert(9);
	Heap.insert(8);
	Heap.insert(7);
	Heap.insert(6);
	Heap.insert(5);
	Heap.insert(4);
	Heap.insert(3);
	Heap.insert(2);
	Heap.insert(1);
	int firstheap[10], i = 0;//FOR DFT
	dft = Heap.constructor_DFT();
	cout << "First heap " << endl;
	if (dft->has_next()) {
		while (dft->has_next()) { firstheap[i++] = dft->next(); }
	}
	for (i = 0; i < 10; i++) {
		cout << firstheap[i] << " ";
	}
	cout << endl << "Second Heap without 1 element" << endl;
	BinaryHeap heap(10);
	Iterator* bft;
	heap.insert(9);
	heap.insert(8);
	heap.insert(7);
	heap.insert(6);
	heap.insert(5);
	heap.insert(4);
	heap.insert(3);
	heap.insert(2);
	heap.insert(1);
	heap.remove(5);
	heap.contains(5);
	int secondheap[9]; i = 0;
	bft = heap.constructor_BFT();
	if (bft->has_next()) {
		while (bft->has_next()) {
			secondheap[i++] = bft->next();
		}
	}
	for (i = 0; i < 9; i++) {
		cout << secondheap[i] << " ";

	}
	return 0;
}

