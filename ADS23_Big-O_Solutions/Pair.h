#pragma once
#include <iostream>

using namespace std;

template <class T, class U>
class Pair
{
	T first;
	U second;
public:
	Pair(T first, U second);
	T getFirst();
	U getSecond();
	void setFirst(T first);
	void setSecond(U second);
	template <class T, class U>
	friend ostream& operator<<(ostream& out, Pair<T, U>& pair);
};
template <class T, class U>
ostream& operator<<(ostream& out, Pair<T, U>& pair)
{
	out << pair.getFirst() << " -> " << pair.getSecond() << endl;
	return out;
}
template <class T, class U>
Pair<T, U>::Pair(T first, U second)
{
	this->first = first;
	this->second = second;
}
template <class T, class U>
T Pair<T, U>::getFirst()
{
	return first;
}
template <class T, class U>
U Pair<T, U>::getSecond()
{
	return second;
}
template <class T, class U>
void Pair<T, U>::setFirst(T first)
{
	this->first = first;
}
template <class T, class U>
void Pair<T,U>::setSecond(U second)
{
	this->second = second;
}
