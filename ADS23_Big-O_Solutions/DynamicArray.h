#pragma once
template <class T>
class DynamicArray
{
	T* arr;
	int mySize;
	int capacity;
	void grow();
public:
	DynamicArray(int capacity = 10);
	void add(T item);
	void remove(int index);
	int size();
	T get(int index);
};
template <class T>
void DynamicArray<T>::grow()
{
	int newSize = capacity * 2;
	T* temp = new T[newSize];
	for (int i = 0; i < capacity; i++)
	{
		temp[i] = arr[i];
	}
	delete[]arr;
	arr = temp;
	capacity = newSize;
}

template <class T>
DynamicArray<T>::DynamicArray(int capacity)
{
	arr = new T[capacity];
	this->capacity = capacity;
	mySize = 0;
}
template <class T>
void DynamicArray<T>::add(T item)
{
	if (mySize == capacity)
	{
		grow();
	}
	arr[mySize] = item;
	mySize++;
}
template <class T>
void DynamicArray<T>::remove(int index)
{
	for (int i = index; i < mySize - 1; i++)
	{
		arr[i] = arr[i + 1];
	}
	mySize--;
}
template <class T>
int DynamicArray<T>::size()
{
	return mySize;
}
template <class T>
T DynamicArray<T>::get(int index)
{
	if (index < mySize && index >= 0)
	{
		return arr[index];
	}
}