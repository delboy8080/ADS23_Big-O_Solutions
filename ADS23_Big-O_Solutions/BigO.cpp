/*****************************************************************//**
 * \file   BigO.cpp
 * \brief  Provides timing function used to measure performance of a function.
 * This file also contains some common algorithm (search, sort, factorial)
 * implementations which you can use the measureTime function with.
 *
 * \author DF
 * \date   October 2020
 *********************************************************************/
#include <iostream>
#include <list>
#include <chrono>
#include "Templates.h"

using namespace std;

template <typename FuncType>
double measureTime(FuncType &func);
template <typename T>
int binarySearch(T* list, int size, T target); // O(log N)
template <typename T>
int linearSearch(T* list, int size, T value); // O(N)
void printFirstItem(int arrayOfItems[]); // O(1)
void bubbleSort(int arr[], int size); // O(N^2)
void factorial(int i); // O(N^2)

struct BSFunctor
{
	int size;
	int* arr;
	int searchValue;

	BSFunctor(int size)
	{
		this->size = size;
		arr = new int[size];
		for (int i = 1; i <= size; i++)
		{
			arr[i - 1] = i;
		}
	}
	void operator()()
	{
		int result = binarySearch(arr, size, searchValue);
		cout << searchValue << " Found at position " << result << " using binary search." << endl;
	}
	~BSFunctor()
	{
		delete[] arr;
		arr = nullptr;
	}
};
struct LSFunctor
{
	int size;
	int* arr;
	int searchValue;

	LSFunctor(int size)
	{
		this->size = size;
		arr = new int[size];
		for (int i = 1; i <= size; i++)
		{
			arr[i - 1] = i;
		}
		searchValue = 0;
	}
	void operator()()
	{
		int result = linearSearch(arr, size, searchValue);
		cout << searchValue << " Found at position " << result << " using binary search." << endl;
	}
	~LSFunctor()
	{
		delete[] arr;
		arr = nullptr;
	}
};

void main_BigO()
{
	std::cout << "Code to use BigO functions...." << endl;
	int nums[4] = { 1000, 10000, 100000, 1000000 };

	for (int i = 0; i < 4; i++)
	{
		BSFunctor bsf(nums[i]);
		LSFunctor lsf(nums[i]);

		bsf.searchValue = -1;
		lsf.searchValue = -1;

		cout << "Binary search of " << nums[i] << " elements: " << measureTime(bsf) << endl;
		cout << "Linear search of " << nums[i] << " elements: " << measureTime(lsf) << endl;

	}
}

int main()
{
	 main_BigO();
	//templateMain_q1();
	//templateMain_q2();
	//templateMain_q3();
	//templateMain_q4();
	templateMain_q5();
}


template <typename FuncType>
double measureTime(FuncType &func)
{
	std::chrono::time_point<std::chrono::high_resolution_clock> st = std::chrono::high_resolution_clock::now();
	func();
	std::chrono::time_point<std::chrono::high_resolution_clock> end = std::chrono::high_resolution_clock::now();
	return (end - st) / std::chrono::nanoseconds(1);

}

template <typename T>
int binarySearch(T* list, int size, T target)
{
	int min = 0, max = size - 1, mid = 0;
	bool found = false;
	while (!found && min <= max)
	{
		mid = (min + max) / 2; // (integer div!)
		if (list[mid] == target)
			found = true;
		else if (target < list[mid])
			max = mid - 1;
		else min = mid + 1;
	}
	if (found) return mid;
	else return -1;
}
template <typename T>
int linearSearch(T* list, int size, T value)
{
	for (int x = 0; x < size; x++)
		if (list[x] == value) return x;

	return -1;
}

void printFirstItem(int arrayOfItems[])
{
	cout << arrayOfItems[0] << endl;
}

void bubbleSort(int arr[], int size)
{
	int n = size;
	int tmp = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < (n - i - 1); j++) {
			if (arr[j] > arr[j + 1]) {
				tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
		}
	}
}

void factorial(int i)
{
	int sum = 0;
	for (int x = i; x > 0; x--)
	{
		sum += x;
	}
	cout << sum << endl;

	if (i > 0)
		factorial(i - 1);
	else
		return;
}
