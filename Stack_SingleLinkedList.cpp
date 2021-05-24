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
		next = nullptr;
	}
};

template<typename T>
class Stack
{
private : 
	Node<T>* First;
	Node<T>* Tail;

public :
	Stack()
	{
		First = nullptr;
		Tail = nullptr;
	}
	~Stack() {}
	void push(T value);
	void pop();
	bool empty();
	unsigned int size();
	T& top();
	// C++ 11 AIEA
	//emplace
	//swap

};
template<typename T>
void Stack<T>::push(T value)
{
	Node<T>* Input = new Node<T>(value);
	if (empty())
		First = Input;
	else
		Tail->next = Input;
	Tail = Input;
}
template<typename T>
void Stack<T>::pop()
{
	Node<T>* temp = nullptr;
	temp = First;
	while (temp->next == Tail)
	{
		temp = temp->next;
	}
	temp->next = nullptr;
	delete Tail;
	Tail = temp;
}
template<typename T>
bool Stack<T>::empty()
{
	return Tail == nullptr ? true : false;
}
template<typename T>
unsigned int Stack<T>::size()
{
	Node<T>* temp = First;
	unsigned int Count = 0;
	while (temp != nullptr)
	{
		temp = temp->next;
		Count++;
	}
	return Count;
}
template<typename T>
T& Stack<T>::top()
{
	return Tail->value;
}