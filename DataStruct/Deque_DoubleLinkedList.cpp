#include<iostream>
using namespace std;

template<typename T>
struct Node
{
	T value;
	Node* before;
	Node* next;
	Node(T input)
	{
		value = input;
		before = nullptr;
		next = nullptr;
	}
};

template<typename T>
class Deque
{
private:
	Node<T>* First;
	Node<T>* End;

public:
	Deque()
	{
		First = nullptr;
		End = nullptr;
	}
	void push_front(T value);
	void push_back(T value);
	void pop_front();
	void pop_back();
	bool empty();
	T& front();
	T& back();
	unsigned int size();
	void clear();

};

template<typename T>
void Deque<T>::push_front(T value)
{
	Node<T>* NewNode = new Node<T>(value);
	if (empty())
	{
		First = NewNode;
		End = NewNode;
	}
	else
	{
		NewNode->next = First;
		First->before = NewNode;
		First = NewNode;
	}
}
template<typename T>
void Deque<T>::push_back(T value)
{
	Node<T>* NewNode = new Node<T>(value);
	if (empty())
	{
		First = NewNode;
		End = NewNode;
	}
	else
	{
		NewNode->before = End;
		End->next = NewNode;
		End = NewNode;
	}
}
template<typename T>
void Deque<T>::pop_front()
{
	Node<T>* temp;
	temp = First;
	First = First->next;
	delete temp;
}
template<typename T>
void Deque<T>::pop_back()
{
	Node<T>* temp;
	temp = End;
	End = End->before;
	delete end;
}
template<typename T>
bool Deque<T>::empty()
{
	return (First == nullptr);
}
template<typename T>
T& Deque<T>::front()
{
	return First->value;
}
template<typename T>
T& Deque<T>::back()
{
	return End->value;
}
template<typename T>
unsigned int Deque<T>::size()
{
	int count = 0;
	Node<T>* temp = nullptr;
	while (temp != nullptr)
	{
		temp = temp->next;
		count++;
	}
	return count;
}
template<typename T>
void Deque<T>::clear()
{
	Node<T>* temp = nullptr;
	while (temp != nullptr)
	{
		temp = First->next;
		First = temp;
		delete First;
	}
}
