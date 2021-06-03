#include<iostream>
using namespace std;

template<typename T_key, typename T_value>
struct Node// Key, value로 이루어진 Node
{
	Node* left;
	Node* right;
	Node* parent;
	T_key key;
	T_value value;
	Node() : left(nullptr), right(nullptr), parent(nullptr), key(NULL), value(NULL) {}
};

template<typename T_key, typename T_value>
class Map 
{
private:
	struct Node<T_key, T_value>* Root;
	int count;
	//Tree
	void DeleteLeaf(struct Node<T_key, T_value>* CurNode);
	void DeleteLeft(struct Node<T_key, T_value>* CurNode);
	void DeleteRight(struct Node<T_key, T_value>* CurNode);
	void DeleteBoth(struct Node<T_key, T_value>* CurNode);
	void DeleteNode(T_key key);
	// Balanced Tree
	int height(struct Node<T_key, T_value>* root);
	int difference(struct Node<T_key, T_value>* node);
	Node<T_key, T_value>* LL_Rotation(struct Node<T_key, T_value>* node);
	Node<T_key, T_value>* LR_Rotation(struct Node<T_key, T_value>* node);
	Node<T_key, T_value>* RL_Rotation(struct Node<T_key, T_value>* node);
	Node<T_key, T_value>* RR_Rotation(struct Node<T_key, T_value>* node);
	Node<T_key, T_value>* balance(struct Node<T_key, T_value>* node);
	//Insert
	void Insert(T_key key, T_value value);
public:
	Map() : Root(nullptr), count(0) {}
	template<typename T_key, typename T_value>
	class iterator 
	{
	private:
		struct Node<T_key, T_value>* Cur;
		void Increase() 
		{
			struct Node<T_key, T_value>* temp = Cur; // 명시적 선언
			if (Cur->right) // 오른쪽이 존재한다면 오른쪽중 제일 작은것(바로 다음것) 출력
			{
				Cur = Cur->right;
				while (Cur->left) 
				{
					Cur = Cur->left;
				}
			}
			else // 오른쪽이 없으면 부모로 올라가서 다음것을 찾음
			{
				struct Node<T_key, T_value>* Parent_temp = Cur->parent;
				while (Parent_temp && (Cur == Parent_temp->right)) // 자신이 제일 오른쪽이 아닐때까지
				{
					Cur = Parent_temp;
					Parent_temp = Parent_temp->parent;
				}
				Cur = Parent_temp;
			}
		}
		void Decrease() 
		{
			if (Cur->left) // 왼쪽이 존재한다면 왼족중 제일 큰것(바로 전것) 출력
			{
				Cur = Cur->left;
				while (Cur->right) 
				{
					Cur = Cur->right;
				}
			}
			else // 왼쪽이 없으면 부모로 올라가서 전것을 찾음
			{
				struct Node<T_key, T_value>* Parent_temp = Cur->parent;
				while (Parent_temp && (Cur == Parent_temp->left)) {
					Cur = Parent_temp;
					Parent_temp = Parent_temp->parent;
				}
				Cur = Parent_temp;
			}
		}
	public:
		iterator& operator++() 
		{
			Increase();
			return *this;
		}
		iterator& operator--() 
		{
			Decrease();
			return *this;
		}
		bool operator!=(const iterator& i) 
		{
			return(i.Cur != Cur);
		}
		bool operator==(const iterator& i) 
		{
			return(i.Cur == Cur);
		}
		T_key key() 
		{
			if (Cur)
				return Cur->key;
			else
				return NULL;
		}
		T_value value() 
		{
			if (Cur)
				return Cur->value;
			else
				return NULL;
		}
		void SetCur(struct Node<T_key, T_value>* node)
		{
			this->Cur = node;
		}
		Node<T_key, T_value>* ReturnCur()
		{
			return Cur;
		}
	};

	void insert(pair<T_key, T_value> p);
	void erase(T_key key);
	void clear();
	bool empty();
	int size();
	iterator<T_key, T_value> insert(T_key key, T_value value);
	iterator<T_key, T_value> find(T_key key);
	iterator<T_key, T_value> begin();
	iterator<T_key, T_value> end();
	iterator<T_key, T_value> upper_bound(T_key key);
	iterator<T_key, T_value> lower_bound(T_key key);
};
template<typename T_key, typename T_value>
void Map<T_key, T_value>::DeleteLeaf(struct Node<T_key, T_value>* CurNode)
{
	struct Node<T_key, T_value>*BefNode = CurNode->parent;
	if (CurNode->key == Root->key) // 삭제하고자 하는 것이 Root 인 경우
		Root = nullptr;
	else if (BefNode->key > CurNode->key) // 삭제하고자 하는 Node가 상위 Node의 좌측에 있을 경우
		BefNode->left = nullptr;
	else // 삭제하고자 하는 Node가 상위 Node의 우측에 있을 경우
		BefNode->right = nullptr;
	delete CurNode;
}
template<typename T_key, typename T_value>
void Map<T_key, T_value>::DeleteLeft(struct Node<T_key, T_value>* CurNode)
{
	struct Node<T_key, T_value>*BefNode = CurNode->parent;
	if (CurNode->key == Root->key) // 삭제하고자 하는 것이 Root인 경우
	{
		Root = CurNode->right;
		Root->parent = nullptr;
	}
	else if (BefNode->key > CurNode->key) // 삭제하고자 하는 Node가 상위 Node의 좌측에 있을 경우
		BefNode->left = CurNode->left;
	else // 삭제하고자 하는 Node가 상위 Node의 우측에 있을 경우
		BefNode->right = CurNode->left;
	delete CurNode;
}
template<typename T_key, typename T_value>
void Map<T_key, T_value>::DeleteRight(struct Node<T_key, T_value>* CurNode)
{
	struct Node<T_key, T_value>*BefNode = CurNode->parent;
	if (CurNode->key == Root->key) // 삭제하고자 하는 것이 Root인 경우
		Root = CurNode->right;
	else if (BefNode->key > CurNode->key) // 삭제하고자 하는 Node가 상위 Node의 좌측에 있을 경우
		BefNode->left = CurNode->right;
	else // 삭제하고자 하는 Node가 상위 Node의 우측에 있을 경우
		BefNode->right = CurNode->right;
	delete CurNode;
}
template<typename T_key, typename T_value>
void Map<T_key, T_value>::DeleteBoth(struct Node<T_key, T_value>* CurNode)
{
	struct Node<T_key, T_value>* BefNode = CurNode->parent;
	struct Node<T_key, T_value>* TempNode = CurNode->right;
	T_key key;
	T_value value;
	while (TempNode->left != nullptr) // 우측 중 가장 작은 값을 찾음
	{
		TempNode = TempNode->left;
	}
	key = TempNode->key;
	value = TempNode->value;
	DeleteNode(TempNode->key); // TempNode에 해당하는 값 삭제 
	CurNode->value = value;// 우측중 제일 작은 값을 복사하여 현재값에 삽입
	CurNode->key = key;// 우측중 제일 작은 값을 복사하여 현재값에 삽입
}
template<typename T_key, typename T_value>
void Map<T_key, T_value>::DeleteNode(T_key key)
{
	if (Root == nullptr)
		return;
	else
	{
		iterator<T_key, T_value> it = find(key);
		struct Node<T_key, T_value>* DNode = it.ReturnCur();
		if (DNode == nullptr)
			return;
		else
		{
			if (DNode->left == nullptr && DNode->right == nullptr) // leaf 일 경우
				DeleteLeaf(DNode);
			else if (DNode->left == nullptr && DNode->right != nullptr) // 우측자식만 있을 경우
				DeleteRight(DNode);
			else if (DNode->left != nullptr && DNode->right == nullptr) // 좌측자식만 있을 경우
				DeleteLeft(DNode);
			else // 자식이 양쪽 다 있을 경우
				DeleteBoth(DNode);
		}
	}
}
template<typename T_key, typename T_value>
int Map<T_key, T_value>::height(struct Node<T_key, T_value>* root) 
{
	int h = 0;
	if (root != nullptr) {
		int l = height(root->left);
		int r = height(root->right);
		int m = 0;
		if (l > r)
			h = l + 1;
		else
			h = r+1;
	}
	return h;
}
template<typename T_key, typename T_value>
int Map<T_key, T_value>::difference(struct Node<T_key, T_value>* node) 
{
	int l = height(node->left);
	int r = height(node->right);
	int dif = l - r;
	return dif;
}
template<typename T_key, typename T_value>
struct Node<T_key, T_value>* Map<T_key, T_value>::LL_Rotation(struct Node<T_key, T_value>* node) 
{
	struct Node<T_key, T_value>* parent;
	struct Node<T_key, T_value>* temp;
	struct Node<T_key, T_value>* temp2;
	parent = node;
	temp = parent->left;
	temp2 = parent->parent;
	//move 1
	parent->left = temp->right;
	if(temp->right != nullptr)
		temp->right->parent = parent;
	//move 2
	temp->right = parent;
	parent->parent = temp;
	if (node == Root)
	{
		temp->parent = nullptr;
		Root = temp;
	}
	else
	{
		temp->parent = temp2;
		if (temp2->left == parent)
			temp2->left = temp;
		else
			temp2->right = temp;
	}
	return temp;
}
template<typename T_key, typename T_value>
struct Node<T_key, T_value>* Map<T_key, T_value>::LR_Rotation(struct Node<T_key, T_value>* node) 
{
	struct Node<T_key, T_value>* parent;
	struct Node<T_key, T_value>* temp;
	struct Node<T_key, T_value>* temp2;
	struct Node<T_key, T_value>* temp3;
	parent = node;
	temp = parent->left;
	temp2 = parent->left->right;
	temp3 = parent->parent;
	//move 1
	parent->left = temp2->right;
	if (temp2->right != nullptr)
		temp2->right->parent = parent;
	temp2->right = parent;
	parent->parent = temp2;
	//move 2
	temp->parent = temp2;
	temp->right = temp2->left;
	if(temp2->left != nullptr)
		temp2->left->parent = temp;
	temp2->left = temp;

	if (node == Root)
	{
		temp2->parent = nullptr;
		Root = temp2;
	}
	else
	{
		temp2->parent = temp3;
		if (temp3->left == parent)
			temp3->left = temp;
		else
			temp3->right = temp;
	}
	return temp2;
}
template<typename T_key, typename T_value>
struct Node<T_key, T_value>* Map<T_key, T_value>::RL_Rotation(struct Node<T_key, T_value>* node) 
{
	struct Node<T_key, T_value>* parent;
	struct Node<T_key, T_value>* temp;
	struct Node<T_key, T_value>* temp2;
	struct Node<T_key, T_value>* temp3;
	parent = node;
	temp = parent->right;
	temp2 = parent->right->left;
	temp3 = parent->parent;
	//move 1
	parent->right = temp2->left;
	if (temp2->left != nullptr)
		temp2->left->parent = parent;
	temp2->left = parent;
	parent->parent = temp2;
	//move 2
	temp->parent = temp2;
	temp->left = temp2->right;
	if (temp2->right != nullptr)
		temp2->right->parent = temp;
	temp2->right = temp;

	if (node == Root)
	{
		temp2->parent = nullptr;
		Root = temp2;
	}
	else
	{
		temp2->parent = temp3;
		if (temp3->left == parent)
			temp3->left = temp;
		else
			temp3->right = temp;
	}
	return temp2;
}
template<typename T_key, typename T_value>
struct Node<T_key, T_value>* Map<T_key, T_value>::RR_Rotation(struct Node<T_key, T_value>* node) 
{
	struct Node<T_key, T_value>* parent;
	struct Node<T_key, T_value>* temp;
	struct Node<T_key, T_value>* temp2;
	parent = node;
	temp = parent->right;
	temp2 = parent->parent;
	//move 1
	parent->right = temp->left;
	if (temp->left != nullptr)
		temp->left->parent = parent;
	//move 2
	temp->left = parent;
	parent->parent = temp;
	if (node == Root)
	{
		temp->parent = nullptr;
		Root = temp;
	}
	else
	{
		temp->parent = temp2;
		if (temp2->left == parent)
			temp2->left = temp;
		else
			temp2->right = temp;
	}
		
	return temp;
}
template<typename T_key, typename T_value>
struct Node<T_key, T_value>* Map<T_key, T_value>::balance(struct Node<T_key, T_value>* node) 
{
	struct Node<T_key, T_value>* temp = node;
	int dif = difference(temp);
	if (dif > 1) // 왼쪽이 과히 크면
	{
		if (difference(temp->left) > 0) // 큰쪽의 좌우 확인
			temp = LL_Rotation(temp);
		else
			temp = LR_Rotation(temp);
	}
	else if (dif < -1) // 오른쪽이 과히 크면
	{
		if (difference(temp->right) > 0)
			temp = RL_Rotation(temp);
		else
			temp = RR_Rotation(temp);
	}
	return temp;
}
template<typename T_key, typename T_value>
void Map<T_key, T_value>::Insert(T_key key, T_value value)
{
	struct Node<T_key, T_value>* CurNode = Root;
	struct Node<T_key, T_value>* ParentNode = nullptr;
	struct Node<T_key, T_value>* newNode = new Node<T_key, T_value>;
	bool LR = false; // 좌 우 구분용[Left(true) / Right(false)]
	newNode->key = key;
	newNode->value = value;
	count++;

	while (1)
	{
		if (CurNode == nullptr)
		{
			if (Root == nullptr) // 빈 Map에 삽입하였을 경우
				Root = newNode;
			else // 빈 Map이 아닌 경우
			{
				newNode->parent = ParentNode;
				if (LR)
					ParentNode->left = newNode;
				else
					ParentNode->right = newNode;
			}
			break;
		}
		else if (CurNode->key > key)
		{
			ParentNode = CurNode;
			CurNode = CurNode->left;
			LR = true; // 왼쪽임
		}
		else if (CurNode->key < key)
		{
			ParentNode = CurNode;
			CurNode = CurNode->right;
			LR = false; // 오른쪽임
		}
	}
	balance(Root);
}
template<typename T_key, typename T_value>
void Map<T_key, T_value>::insert(pair<T_key, T_value> p)
{
	Insert(p.first, p.second);	
}
template<typename T_key, typename T_value>
void Map<T_key, T_value>::erase(T_key key) 
{
	DeleteNode(key);
	count--;
	balance(Root);
}
template<typename T_key, typename T_value>
void Map<T_key, T_value>::clear() 
{
	if (empty())
		return;
	while (Root != nullptr) {
		erase(Root->key);
	}
}
template<typename T_key, typename T_value>
bool Map<T_key, T_value>::empty()
{
	return (count == 0);
}
template<typename T_key, typename T_value>
int Map<T_key, T_value>::size() 
{
	return count;
}
template<typename T_key, typename T_value>
Map<T_key, T_value>::iterator<T_key, T_value> Map<T_key, T_value>::insert(T_key key, T_value value) 
{
	Insert(key, value);
	return find(key);
}
template<typename T_key, typename T_value>
Map<T_key, T_value>::iterator<T_key, T_value> Map<T_key, T_value>::find(T_key key) 
{
	iterator<T_key, T_value> it;
	struct Node<T_key, T_value>* result = nullptr;
	struct Node<T_key, T_value>* findkey = Root;
	while (findkey != nullptr)
	{
		if (findkey->key > key)
			findkey = findkey->left;
		else if (findkey->key == key)
		{
			result = findkey;
			break;
		}
		else
			findkey = findkey->right;
	}
	it.SetCur(result);
	return it;
}
template<typename T_key, typename T_value>
Map<T_key, T_value>::iterator<T_key, T_value> Map<T_key, T_value>::begin() 
{
	iterator<T_key, T_value> it;
	struct Node<T_key, T_value>* First = nullptr;
	First = Root;
	while (First->left != nullptr)
	{
		First = First->left;
	}
	it.Cur = First;
	return it;
}
template<typename T_key, typename T_value>
Map<T_key, T_value>::iterator<T_key, T_value> Map<T_key, T_value>::end() 
{
	iterator<T_key, T_value> it;
	it.Cur = nullptr;
	return it;
}
template<typename T_key, typename T_value>
Map<T_key, T_value>::iterator<T_key, T_value> Map<T_key, T_value>::upper_bound(T_key key) 
{
	struct Node<T_key, T_value>* result = nullptr;
	struct Node<T_key, T_value>* findkey = Root;
	iterator<T_key, T_value> it;
	while (findkey != nullptr)
	{
		if (findkey->key > key)
		{
			result = findkey;
			findkey = findkey->left;
		}
		else
			findkey = findkey->right;
	}
	it.Cur = result;
	return it;
}
template<typename T_key, typename T_value>
Map<T_key, T_value>::iterator<T_key, T_value> Map<T_key, T_value>::lower_bound(T_key key) 
{
	struct Node<T_key, T_value>* result = nullptr;
	struct Node<T_key, T_value>* findkey = Root;
	iterator<T_key, T_value> it;
	while (findkey != nullptr) 
	{
		if (findkey->key > key) 
		{
			result = findkey;
			findkey = findkey->left;
		}
		else if (findkey->key == key) 
		{
			result = findkey;
			break;
		}
		else
			findkey = findkey->right;
	}
	it.Cur = result;
	return it;
}
