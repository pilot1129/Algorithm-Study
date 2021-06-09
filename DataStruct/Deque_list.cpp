#include<iostream>
using namespace std;

template<typename T> class Deque
{
private:
	unsigned int index_front;
	unsigned int index_back;
	T* values;
	unsigned int Deque_size;
public:
	Deque()
	{
		Deque_size = 40;
		values = new T[Deque_size];
		index_front = 20;
		index_back = 20;
	}
	~Deque()
	{
		delete[] values;
	}

	void push_front(T value);
	void push_back(T value);
	void pop_front(T value);
	void pop_back(T value);
	bool empty();
	T& front();
	T& back();
	unsigned int size();
	void clear();
};

template<typename T>
void Deque<T>::push_front(T value)
{
	values[index_front - 1] = T;
	Deque_size++;
}
template<typename T>
void Deque<T>::push_back(T value)
{
	values[index_back + 1] = T;
	Deque_size++;
}
template<typename T>
void Deque<T>::pop_front(T value)
{
	index_front = index_front + 1;
	Deque_size--;
}
template<typename T>
void Deque<T>::pop_back(T value)
{
	index_back = index_back - 1;
	Deque_size--;
}
template<typename T>
bool Deque<T>::empty()
{
	return (index_front == index_back) ? true : false;
}
template<typename T>
T& Deque<T>::front()
{
	return value[index_front];
}
template<typename T>
T& Deque<T>::back()
{
	return value[index_back];
}
template<typename T>
unsigned int Deque<T>::size()
{
	return Deque_size;
}
template<typename T>
void Deque<T>::clear()
{
	index_front = 20;
	index_back = 20;
	Deque_size = 0;
}