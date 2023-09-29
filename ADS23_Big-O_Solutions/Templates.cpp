#include "Templates.h"
template <class T>
T greaterThan(T x, T y)
{
	return x > y ? x : y;
}

void templateMain_q1()
{
	int x, y;
	x = 5;
	y = 10;

	cout << "The largest int is " << greaterThan(x, y) << endl;

	double z, w;
	z = 9.65;
	w = 3.1415986548;
	cout << "The largest double is " << greaterThan(z, w) << endl;
}


template <class T>
T lessThan(T x, T y)
{
	return x < y ? x : y;
}
void templateMain_q2()
{
	int x, y;
	x = 5;
	y = 10;

	cout << "The smallest int is " << lessThan(x, y) << endl;

	double z, w;
	z = 9.65;
	w = 3.1415986548;
	cout << "The smallest double is " << lessThan(z, w) << endl;
}




template <class T>
void print(const list<T>& items)
{
	typename list<T>::const_iterator iter;
	cout << "[";
	for (iter = items.begin(); iter != items.end();iter++)
	{
		if (iter != items.begin())
			cout << ", ";
		cout << *iter;

	}
	cout << "]";
}
void templateMain_q3()
{
	list<string> strs = {"we", "are", "going", "to", "catch", "a"};
	list<int> nums = {1,2,3,5,8,9,7,5,3};

	print(strs);
	print(nums);
}

void templateMain_q4()
{
	Pair<int, string> p1(1, "We're going on a bear hunt");
	cout << p1;
	Pair<float, long> p2(3.14f, 3.14159);
	cout << p2;

}

void templateMain_q5()
{
	DynamicArray<char> arr(5);
	for (int i = 65; i < 91; i++)
	{
		arr.add(i);
	}
	cout << "[";
	for (int i = 0; i < arr.size(); i++)
	{
		if (i != 0)
			cout << ", ";
		cout << arr.get(i);
	}
	cout << "]" << endl;
	for (int i = 0; i < arr.size(); i++)
	{
		if (arr.get(i) == 'A' || arr.get(i) == 'E' || arr.get(i) == 'I' || arr.get(i) == 'O' || arr.get(i) == 'U')
		{
			arr.remove(i);
			i--;
		}

	}
	cout << "[";
	for (int i = 0; i < arr.size(); i++)
	{
		if (i != 0)
			cout << ", ";
		cout << arr.get(i);
	}
	cout << "]" << endl;
}