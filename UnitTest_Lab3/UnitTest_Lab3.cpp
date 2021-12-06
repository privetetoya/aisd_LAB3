#include "pch.h"
#include "CppUnitTest.h"
#include "../АиСД. Лабораторная работа 3. new thing/BinaryHeap.h"
#include "../АиСД. Лабораторная работа 3. new thing/Iterator.h"
#include "../АиСД. Лабораторная работа 3. new thing/Queue.h"
#include "../АиСД. Лабораторная работа 3. new thing/Stack.h"
using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace UnitTestForLab3
{
	TEST_CLASS(UnitTest)
	{
	public:
		TEST_METHOD(STACK)
		{
			Stack stack;
			stack.Stack_push(new Node(100));
			stack.Stack_pop();

			bool check = true;
			for (int i = 1; i < 5; i++) {
				stack.Stack_push(new Node(i));
			}
			Assert::IsFalse(stack.Stack_isEmpty());
			for (int i = 4; i >= 1; i--) {
				stack.Stack_pop();
			}
			Assert::IsTrue(stack.Stack_isEmpty());
		}

		TEST_METHOD(QUEUE) {

			Queue queue;
			queue.enqueue(new Node(100));
			queue.dequeue();
			bool check = true;
			for (int i = 1; i < 5; i++) {
				queue.enqueue(new Node(i));
			}
			Assert::IsFalse(queue.Queue_isEmpty());
			for (int i = 4; i >= 1; i--) {
				Assert::AreEqual(5 - i, queue.front()->data);
				queue.dequeue();
			}
			Assert::IsTrue(queue.Queue_isEmpty());
		}
		TEST_METHOD(INSERT_REMOVE_CONTAINS) {

			BinaryHeap Heap(11);
			Heap.insert(10);
			Heap.insert(9);
			Heap.insert(8);
			Heap.insert(7);
			Heap.insert(6);
			Heap.insert(5);
			Heap.insert(4);
			Heap.insert(3);
			Assert::IsFalse(Heap.contains(22));
		}

		TEST_METHOD(DFT_BFT_Iterators) {
			BinaryHeap Heap(11);
			Iterator* dft;
			Heap.insert(10);
			Heap.insert(9);
			Heap.insert(8);
			Heap.insert(7);
			Heap.insert(6);
			Heap.insert(5);
			Heap.insert(4);
			Heap.insert(3);
			int arr1[9], i = 0;//FOR DFT
			dft = Heap.constructor_DFT();

			if (dft->has_next()) {
				while (dft->has_next()) { arr1[i++] = dft->next(); }
			}

			Assert::AreEqual(11, arr1[0]);
			Assert::AreEqual(10, arr1[1]);
			Assert::AreEqual(8, arr1[2]);
			Assert::AreEqual(4, arr1[3]);
			Assert::AreEqual(3, arr1[4]);
			Assert::AreEqual(7, arr1[5]);
			Assert::AreEqual(9, arr1[6]);
			Assert::AreEqual(6, arr1[7]);
			Assert::AreEqual(5, arr1[8]);
			delete dft;
		}
	};
}

