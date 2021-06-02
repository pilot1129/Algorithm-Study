#include<iostream>
using namespace std;

/*
	* 이 Tree의 경우 삭제시 양쪽 자식이 있을 경우 오른쪽 자식의 가장 작은 값을 옮기는 형태를 사용함

*/
template<typename T>
struct Node
{
	T value;
	Node* left;
	Node* right;
	Node(T value)
	{
		this->value = value;
		left = nullptr;
		right = nullptr;
	}
};

template<typename T>
class BST
{
private:
	Node<T>* Root;
	void Inorder(Node<T>* Find);
	void Preorder(Node<T>* Find);
	void Postorder(Node<T>* Find);
	Node<T>* SearchNodePoint(T value); // Value에 해당하는 값을 가진 Node Pointer 반환
	Node<T>* BeforeNodeFind(Node<T>* Find); // Find의 한단계 위 부모 Node Pointer 반환
	void DeleteLeaf(Node<T>* CurNode, Node<T>* BefNode);
	void DeleteLeft(Node<T>* CurNode, Node<T>* BefNode);
	void DeleteRight(Node<T>* CurNode, Node<T>* BefNode);
	void DeleteBoth(Node<T>* CurNode, Node<T>* BefNode);
public:
	BST()
	{
		Root = nullptr;
	}
	~BST()
	{
		while (Root != nullptr)
		{
			DeleteNode(Root->value);
		}
	}
	void AddNode(T value);
	void DeleteNode(T value);
	bool SearchNode(T value);
	void DisplayTree(int num);
};

template<typename T>
void BST<T>::Inorder(Node<T>* Find)
{
	if (Find != nullptr)
	{
		Inorder(Find->left);
		cout << Find->value << " ";
		Inorder(Find->right);
	}
}
template<typename T>
void BST<T>::Preorder(Node<T>* Find)
{
	if (Find != nullptr)
	{
		cout << Find->value << " ";
		Preorder(Find->left);
		Preorder(Find->right);
	}
}
template<typename T>
void BST<T>::Postorder(Node<T>* Find)
{
	if (Find != nullptr)
	{
		Postorder(Find->left);
		Postorder(Find->right);
		cout << Find->value << " ";
	}
}

template<typename T>
Node<T>* BST<T>::SearchNodePoint(T value)
{
	Node<T>* SNode = Root;
	while (SNode != nullptr)
	{
		if (SNode->value == value)
			return SNode; // Find
		else if (SNode->value > value)
			SNode = SNode->left;
		else
			SNode = SNode->right;
	}
	return nullptr; // Not Find
}
template<typename T>
Node<T>* BST<T>::BeforeNodeFind(Node<T>* Find)
{
	Node<T>* FindNode = nullptr;
	if (Root == nullptr || Root == Find)
		return nullptr;
	else
	{
		FindNode = Root;
		while (FindNode->left != Find && FindNode->right != Find)
		{
			if (Root->value > Find->value)
				FindNode = FindNode->left;
			else
				FindNode = FindNode->right;
		}
		return FindNode;
	}
}

template<typename T>
void BST<T>::DeleteLeaf(Node<T>* CurNode, Node<T>* BefNode)
{
	if (CurNode == Root) // 삭제하고자 하는 것이 Root 인 경우
		Root = nullptr;
	else if (BefNode->value > CurNode->value) // 삭제하고자 하는 Node가 상위 Node의 좌측에 있을 경우
		BefNode->left = nullptr;
	else // 삭제하고자 하는 Node가 상위 Node의 우측에 있을 경우
		BefNode->right = nullptr;
	delete CurNode;
}
template<typename T>
void BST<T>::DeleteLeft(Node<T>* CurNode, Node<T>* BefNode)
{
	if (CurNode == Root) // 삭제하고자 하는 것이 Root인 경우
		Root = CurNode->right;
	else if (BefNode->value > CurNode->value) // 삭제하고자 하는 Node가 상위 Node의 좌측에 있을 경우
		BefNode->left = CurNode->left;
	else // 삭제하고자 하는 Node가 상위 Node의 우측에 있을 경우
		BefNode->right = CurNode->left;
	delete CurNode;
}
template<typename T>
void BST<T>::DeleteRight(Node<T>* CurNode, Node<T>* BefNode)
{
	if (CurNode == Root) // 삭제하고자 하는 것이 Root인 경우
		Root = CurNode->right;
	else if (BefNode->value > CurNode->value) // 삭제하고자 하는 Node가 상위 Node의 좌측에 있을 경우
		BefNode->left = CurNode->right;
	else // 삭제하고자 하는 Node가 상위 Node의 우측에 있을 경우
		BefNode->right = CurNode->right;
	delete CurNode;
}
template<typename T>
void BST<T>::DeleteBoth(Node<T>* CurNode, Node<T>* BefNode)
{
	Node<T>* TempNode = CurNode->right;
	T value;
	while (TempNode->left != nullptr) // 우측 중 가장 작은 값을 찾음
	{
		TempNode = TempNode->left;
	}
	value = TempNode->value;
	DeleteNode(TempNode->value); // TempNode에 해당하는 값 삭제 
	CurNode->value = value;// 우측중 제일 작은 값을 복사하여 현재값에 삽입
}

template<typename T>
void BST<T>::AddNode(T value)
{
	Node<T>* newNode = new Node<T>(value);
	if (Root == nullptr) // IsEmpty
		Root = newNode;
	else
	{
		Node<T>* Temp = Root;
		Node<T>* BeforeTemp = nullptr;
		while (Temp != nullptr)
		{
			BeforeTemp = Temp;
			if (Temp->value > value)
				Temp = Temp->left;
			else
				Temp = Temp->right;
		}
		if (BeforeTemp->value > value)
			BeforeTemp->left = newNode;
		else
			BeforeTemp->right = newNode;
	}
}
template<typename T>
void BST<T>::DeleteNode(T value)
{
	if (Root == nullptr)
		cout << "Tree is empty!" << endl;
	else
	{
		Node<T>* DNode = SearchNodePoint(value);
		if (DNode == nullptr)
			cout << "Not Exist Value!" << endl;
		else
		{
			Node<T>* BNode = BeforeNodeFind(DNode);
			if (DNode->left == nullptr && DNode->right == nullptr) // leaf 일 경우
				DeleteLeaf(DNode, BNode);
			else if (DNode->left == nullptr && DNode->right != nullptr) // 우측자식만 있을 경우
				DeleteRight(DNode, BNode);
			else if (DNode->left != nullptr && DNode->right == nullptr) // 좌측자식만 있을 경우
				DeleteLeft(DNode, BNode);
			else // 자식이 양쪽 다 있을 경우
				DeleteBoth(DNode, BNode);
		}
	}
}
template<typename T>
bool BST<T>::SearchNode(T value)
{
	if (Root == nullptr)
	{
		cout << "Tree is empty!" << endl;
		return false;
	}
	else
	{
		Node<T>* NewNode = SearchNodePoint(value);
		if (NewNode == nullptr)
		{
			cout << "Do Not Exist!" << endl;
			return false;
		}
		else
		{
			cout << "Find!" << endl;
			return true;
		}
	}
}
template<typename T>
void BST<T>::DisplayTree(int num)
{
	if (Root == nullptr)
		cout << "Tree is empty!" << endl;
	else
	{
		switch (num)
		{
		case 1:
		{
			cout << "Preorder방식 : " << endl;
			Preorder(Root);
			break;
		}
		case 2:
		{
			cout << "Inorder방식 : " << endl;
			Inorder(Root);
			break;
		}
		case 3:
		{
			cout << "Postorder방식 : " << endl;
			Postorder(Root);
			break;
		}
		default:
			cout << "정상적인 숫자를 입력해주세요!" << endl;
			break;
		}
		cout << endl;
	}
}
