#include<iostream>
using namespace std;

template<typename T> class Queue
{
private:
	unsigned int index_front; // 
	unsigned  int index_back;
	T* values;
	unsigned int Queue_size;
public:
	Queue()
	{
		Queue_size = 5; // ¨öCA| size ¢¥A 4¡Æ¢® ¥ìE
		values = new T[Queue_size];
		index_front = 0;
		index_back = 0;
	}
	~Queue()
	{
		delete[] values;
	}

	void push(T value);
	void pop();
	bool empty();
	int size();
	T& front();
	T& back();
	void Check();
	// c++ 11 AIEA
	// emplace
	// swap
};

template<typename T>
void Queue<T>::push(T value)
{
	Check();
	values[index_back] = value;
	index_back = (index_back + 1) % Queue_size;
}
template<typename T>
void Queue<T>::pop()
{
	index_front = (index_front+1) % Queue_size;
}
template<typename T>
bool Queue<T>::empty()
{
	return index_front == index_back;
}
template<typename T>
int Queue<T>::size()
{
	return(index_back - index_front + Queue_size) % Queue_size;
}
template<typename T>
T& Queue<T>::front()
{
	return values[(index_front) % Queue_size];
}
template<typename T>
T& Queue<T>::back()
{
	return values[index_back-1];
}

template<typename T>
void Queue<T>::Check()
{
	if (((index_back+1)%Queue_size)== index_front)
	{
		int before_Q_size = Queue_size;
		Queue_size *= 2;
		T* Temp = new T[Queue_size];
		for (auto a = 0; a < before_Q_size - 1; ++a)
		{
			Temp[a] = values[(index_front + a) % before_Q_size];
		}
		delete[] values;
		values = Temp;
		Temp = nullptr;
		index_front = 0;
		index_back = before_Q_size - 1;
	}
}