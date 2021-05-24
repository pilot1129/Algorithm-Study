#include<iostream>
using namespace std;

template<typename T>
struct Node
{
	T value;
	Node* next;
	Node(T input)
	{
		value = input;
		next = NULL;
	}
};

template<typename T>
class Queue
{
private :
	Node<T>* First;
	
public :
	Queue()
	{
		First = NULL;
	}
	~Queue() {}
	void push(T value);
	void pop();
	bool empty();
	unsigned int size();
	T& front();
	T& back();
	// C++ 11 AIEA
	//emplace
	//swap
};

template<typename T>
void Queue<T>::push(T value)
{
	Node<T>* Input = new Node<T>(value);
	if (empty())
		First = Input;
	else
	{
		Node<T>* temp = NULL;
		temp = First;
		while (temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->next = Input;
	}
}
template<typename T>
void Queue<T>::pop()
{
	Node<T>* temp = First;
	First = First->next;
	delete temp;
}
template<typename T>
bool Queue<T>::empty()
{
	return (First == NULL);
}
template<typename T>
unsigned int Queue<T>::size()
{
	int Count = 0;
	Node<T>* temp = First;
	while (temp!= NULL)
	{
		temp = temp->next;
		Count++;
	}
	return Count;
}
template<typename T>
T& Queue<T>::front()
{
	return First->value;
}
template<typename T>
T& Queue<T>::back()
{
	Node<T>* Temp = First;
	while (Temp->next != NULL)
	{
		Temp = Temp->next;
	}
	return Temp->value;
}
