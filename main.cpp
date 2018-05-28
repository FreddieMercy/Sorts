#include "Vector.h"
#include "LinkedList.h"
#include "IndexedSorter.h"
#include "InsertionSorter.h"
#include "BubbleSorter.h"
#include "SelectionSorter.h"
#include "SortedBag.h"
#include "RandomNumberGenerator.h"
#include "DoubleLinkedList.h"
#include <iostream>
#include <Windows.h> //sorry *nix users :(
using namespace std;

template <typename T>
DWORD sortBenchmark(Indexed<T> &data, IndexedSorter<T> &sorter)
{
	DWORD start;
	DWORD end;
	start = GetTickCount();

	//sort data
	sorter.sort(data);

	end = GetTickCount();
	return end - start;
}

DWORD insertBenchmark(Bag<int> &data, int max_items)
{
	//placeholder benchmark code
	DWORD start;
	DWORD end;
	RandomNumberGenerator rng{};
	start = GetTickCount();

	//insert data
	for (int i = 0; i < max_items; i++)
	{
		data.addElement(rng.getRandomNumber(0, 100));
	}

	end = GetTickCount();
	return end - start;
}

DWORD insertBenchmark(Vector<int> &data, int max_items)
{
	//placeholder benchmark code
	DWORD start;
	DWORD end;
	RandomNumberGenerator rng{};
	start = GetTickCount();

	//insert data
	for (int i = 0; i < max_items; i++)
	{
		data.addElement(rng.getRandomNumber(0, 100));
	}

	end = GetTickCount();
	return end - start;
}

int main(void)
{
	LinkedList<int> ll_ints{};
	LinkedList<int> ll_insertion{};
	LinkedList<int> ll_selection{};
	
	DoubleLinkedList<int> double_ll{};
	DoubleLinkedList<int> double_insertion{};
	DoubleLinkedList<int> double_selection{};

	InsertionSorter<int> insertion_sorter{};
	BubbleSorter<int> bubble_sorter{};
	SelectionSorter<int> selection_sorter{};

	int insert_amount = 500;
	cout << "Insert benchmark (" << insert_amount << " items): " << endl;
	cout << "LL insert time: " << insertBenchmark(ll_ints, insert_amount) << endl;
	cout << "Double LL insert time: " << insertBenchmark(double_ll, insert_amount) << endl;
	insertBenchmark(ll_insertion, insert_amount);
	insertBenchmark(ll_selection, insert_amount);
	insertBenchmark(double_insertion, insert_amount);
	insertBenchmark(double_selection, insert_amount);
	
	//sort benchmarks
	cout << endl << "LL bubble sort time: " << sortBenchmark(ll_ints, bubble_sorter) << "ms" << endl;
	cout << "LL selection sort time: " << sortBenchmark(ll_ints, selection_sorter) << "ms" << endl;
	cout << "LL insertion sort time: " << sortBenchmark(ll_ints, insertion_sorter) << "ms" << endl;
	cout << "Double LL bubble sort time: " << sortBenchmark(double_ll, bubble_sorter) << "ms" << endl;
	cout << "Double LL selection sort time: " << sortBenchmark(double_ll, selection_sorter) << "ms" << endl;
	cout << "Double LL insertion sort time: " << sortBenchmark(double_ll, insertion_sorter) << "ms" << endl;

	return 0;
}