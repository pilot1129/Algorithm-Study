#include<iostream>
using namespace std;

/*
	* 해당 BST(Binary Search Tree)는 중복을 허용하는 Tree입니다
	* 중복의 경우 Count로 관리합니다.
	* Display의 경우 기본은 Inorder이나, 선택가능
*/

template<typename T>
struct Node
{
	Node* left;
	Node* right;
	int count;
	T value;
	Node(T v)
	{
		count = 1;
		value = v;
		left = nullptr;
		right = nullptr;
	}
};

template<typename T>
class BST
{
private:
	Node<T>* root;
	unsigned int size;

	Node<T>* SearchLeftMax(Node<T>* node);
	Node<T>* DeleteFunction(Node<T>* node, T value);
	void Destroy(Node<T>* node);
	void Preorder(Node<T>* node);
	void Inorder(Node<T>* node);
	void Postorder(Node<T>* node);

	
public:
	BST()
	{
		root = nullptr;
		size = 0;
	}
	~BST()
	{
		clear();
	}
	void AddNode(T value);
	Node<T>* SearchNode(T value);
	void DeleteNode(T value);
	void Display();
	unsigned int Treesize();
	void clear();
};

template<typename T>
Node<T>* BST<T>::SearchLeftMax(Node<T>* node)
{
	if (node == nullptr)
		return nullptr;
	while (node->right != nullptr)
		node = node->right;
	return node;
}

template<typename T>
Node<T>* BST<T>::DeleteFunction(Node<T>* node, T value)
{
	if (node == nullptr)
		return nullptr;
	else if (node->value > value)
		node->left = DeleteFunction(node->left, value);
	else if (node->value < value)
		node->right = DeleteFunction(node->right, value);
	else//찾은경우
	{
		Node<T>* temp = node;
		if (node->left == nullptr && node->right == nullptr) // 자식이 없을때
		{
			if (node == root)
				root = nullptr;
			delete node;
			node = nullptr;
		}
		else if (node->left == nullptr) // 자식이 우측 하나
		{
			if (node == root)
				root = node->right;
			node = node->right;
			delete temp;
		}
		else if (node->right == nullptr) // 자식이 좌측 하나
		{
			if (node == root)
				root = node->left;
			node = node->left;
			delete temp;
		}
		else // 자식이 둘
		{
			temp = SearchLeftMax(node->left);
			node->value = temp->value;
			node->count = temp->count;
			node->left = DeleteFunction(node->left, temp->value);
		}
	}
	return node;
}

template<typename T>
void BST<T>::AddNode(T value)
{
	Node<T>* NewNode = new Node<T>(value);
	if (root == nullptr)
		root = NewNode;
	else
	{
		Node<T>* temp = root;
		Node<T>* beforetemp = nullptr;
		while (temp != nullptr)
		{
			beforetemp = temp;
			if (temp->value > value) // 값이 작은 경우
				temp = temp->left;
			else if (temp->value < value) // 값이 큰 경우
				temp = temp->right;
			else // 값이 동일한 경우
				temp->count++;
		}
		if (value > beforetemp->value)
			beforetemp->right = NewNode;
		else if (value < beforetemp->value)
			beforetemp->left = NewNode;
	}
	++size;
}

template<typename T>
Node<T>* BST<T>::SearchNode(T value)
{
	Node<T>* cur = root;
	while (cur != nullptr)
	{
		if (cur->value > value)
			cur = cur->left;
		else if (cur->value < value)
			cur = cur->right;
		else
			return cur;
	}
	return nullptr;
}

template<typename T>
void BST<T>::DeleteNode(T value)
{
	Node<T>* temp = root;
	Node<T>* find = SearchNode(value);

	if (find != nullptr) // 값이 존재한다면
	{
		if (find->count > 1) // 중복값이 2개 이상이라면
			find->count--;
		else
			DeleteFunction(temp, value);
		size--;
	}
}

#pragma region Order
template<typename T>
void BST<T>::Preorder(Node<T>* node)
{
	if (node != nullptr)
	{
		cout << node->value << " ";
		Inorder(node->left);
		Inorder(node->right);
	}
}

template<typename T>
void BST<T>::Inorder(Node<T>* node)
{
	if (node != nullptr)
	{
		Inorder(node->left);
		cout << node->value << " ";
		Inorder(node->right);
	}
}

template<typename T>
void BST<T>::Postorder(Node<T>* node)
{
	if (node != nullptr)
	{
		Inorder(node->left);
		Inorder(node->right);
		cout << node->value << " ";
	}
}

#pragma endregion

template<typename T>
void BST<T>::Display()
{
	Inorder(root);
}

template<typename T>
unsigned int BST<T>::Treesize()
{
	return size;
}

template<typename T>
void BST<T>::Destroy(Node<T>* node)
{
	if (node == nullptr)
		return;
	Node<T>* left = node->left;
	Node<T>* right = node->right;

	delete node;
	Destroy(left);
	Destroy(right);
}

template<typename T>
void BST<T>::clear()
{
	Destroy(root);
	root = nullptr;
}

