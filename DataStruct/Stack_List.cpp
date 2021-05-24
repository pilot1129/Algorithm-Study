#include<iostream>
using namespace std;

template<typename T> class Stack
{
private :
	unsigned int Stack_size;
	unsigned int Count;
	T* values;

public :
	Stack()
	{
		Stack_size = 5;
		values = new T[Stack_size];
		Count = 0;
	}
	~Stack()
	{
		delete[] values;
	}

	void push(T value);
	void pop();
	T& top();
	bool empty();
	unsigned int size();
	void Check();
};

template<typename T>
void Stack<T>::push(T value)
{
	Check();
	values[Count] = value;
	Count = (Count+1);
}
template<typename T>
void Stack<T>::pop()
{
	if (Count != 0)
		Count = Count - 1;
	else
		cout << "error" << endl;
}
template<typename T>
T& Stack<T>::top()
{
	return values[Count-1];
}
template<typename T>
bool Stack<T>::empty()
{
	return (Count == 0 ? true : false);
}
template<typename T>
unsigned int Stack<T>::size()
{
	return Count;
}
template<typename T>
void Stack<T>::Check()
{
	if (Count == Stack_size)
	{
		int Before_Stack_size = Stack_size;
		Stack_size *= 2;
		T* Temp = new T[Stack_size];
		for (auto a = 0; a < Before_Stack_size; ++a)
		{
			Temp[a] = values[a];
		}
		delete[] values;
		values = Temp;
		Temp = nullptr;
	}
}
