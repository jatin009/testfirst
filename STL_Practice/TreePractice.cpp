
#include <iostream>
#include <string>
#include <memory>

#define PTR(x) x.get()

struct Node
{
	int data;
	std::unique_ptr<Node> next = nullptr;
	Node(int d)
		: data(d) {}
};

class LinkedList
{
public:
	void Create(int* arr, size_t sz)
	{
		Node* curr, *prev;
		for (size_t i = 0; i < sz; i++)
		{
			curr = new Node(arr[i]);
			if (head == nullptr)
				head.reset(curr);
			else
				prev->next.reset(curr);
			prev = curr;
		}
	}
	void Print()
	{
		Node* temp = PTR(head);
		while (temp != nullptr)
		{
			std::cout << temp->data << " -> ";
			temp = PTR(temp->next);
		}
		std::cout << "NULL\n";
	}
	void Search(int elem)
	{
		Node* temp = PTR(head);
		int idx = 0;
		while (temp != nullptr)
		{
			if (temp->data == elem)
				break;
			temp = PTR(temp->next);
			idx++;
		}
		if (temp != nullptr)
			std::cout << "Elem " << elem << " is located at index: " << idx << "\n";
		else
			std::cout << "Elem " << elem << " not found.\n";
	}
	void Replace(int src, int dest)
	{
		Node* temp = GetNode(src);
		if (temp == nullptr)
			std::cout << "Elem " << src << " not found.\n";
		else
			temp->data = dest;
	}
	void Delete(int elem)
	{
		Node* temp = PTR(head);
		Node* prev = temp;
		while (temp != nullptr)
		{
			if (temp->data == elem)
				break;
			prev = temp;
			temp = PTR(temp->next);
		}
		if (temp == nullptr)
			std::cout << "Elem " << elem << " not found.\n";
		else
		{
			if (temp == PTR(head))
			{
				head = std::move(head->next);
				head.reset(nullptr);
			}
			else
			{
				prev->next = std::move(temp->next);
			}
		}
	}
	void InsertAfter(int elem, int after)
	{
		Node* temp = GetNode(after);
		if (temp == nullptr)
			std::cout << "Elem " << elem << " not found.\n";
		else
		{
			Node* newNode = new Node(elem);
			newNode->next = std::move(temp->next);
			temp->next.reset(newNode);
		}
	}
	Node* GetNode(int elem)
	{
		Node* temp = PTR(head);
		while (temp != nullptr)
		{
			if (temp->data == elem)
				break;
			temp = PTR(temp->next);
		}
		return temp;
	}
private:
	std::unique_ptr<Node> head = nullptr;
};

template<typename T>
class UPtr
{
public:
	UPtr() = default;
	UPtr(int val)
		: ptr(new T(val)) {}
	UPtr(T* other)
		:ptr(std::move(other))
	{}
	UPtr(const UPtr& other) = delete;
	UPtr& operator=(const UPtr& other) = delete;
	//UPtr(UPtr&& other)
	//{
	//	if (other.ptr != nullptr)
	//		ptr = std::move(other.ptr);
	//}
	~UPtr()
	{
		if (ptr != nullptr)
		{
			delete ptr;
			ptr = nullptr;
		}
	}
	T* get() const { return ptr; }
	operator bool()
	{
		return ptr != nullptr;
	}
	bool operator==(T* other)
	{
		return ptr == other;
	}
	UPtr& operator=(UPtr&& other)
	{
		if (other.ptr != nullptr)
		{
			delete ptr;
			ptr = std::move(other.ptr);
		}
		return *this;
	}
private:
	T* ptr = nullptr;
};

struct TreeNode
{
	int data;
	std::unique_ptr<TreeNode> left = nullptr;
	std::unique_ptr<TreeNode> right = nullptr;
	TreeNode(int d)
		: data(d) {}
};

class BinarySearchTree
{
public:
	typedef std::unique_ptr<TreeNode> UPtr_TreeNode;
	enum ORDER
	{
		IN_ORDER,
		PRE_ORDER,
		POST_ORDER
	};
	void Create(int* arr, size_t sz)
	{
		for (size_t i = 0; i < sz; i++)
		{
			int val = arr[i];
			if (root == nullptr)
				root = std::make_unique<TreeNode>(val);
			else
				Insert(val, PTR(root));
		}
	}
	void Insert(int elem, TreeNode* opNode = nullptr)	//recursive
	{
		if (opNode == nullptr)
			opNode = PTR(root);
		if (elem < opNode->data)
		{
			if (!opNode->left)
			{
				opNode->left = std::make_unique<TreeNode>(elem);
				return;
			}
			opNode = PTR(opNode->left);
			Insert(elem, opNode);
		}
		else if (elem > opNode->data)
		{
			if (!opNode->right)
			{
				opNode->right = std::make_unique<TreeNode>(elem);
				return;
			}
			opNode = PTR(opNode->right);
			Insert(elem, opNode);
		}
	}
	void Print(ORDER order)	//recursive
	{
		TreeNode* temp = PTR(root);
		if (order == IN_ORDER)
			InOrder(temp);
		else if (order == PRE_ORDER)
			PreOrder(temp);
		else if (order == POST_ORDER)
			PostOrder(temp);
		std::cout << "\n";
	}
	void Search(int elem)	//recursive
	{
		std::cout << "Element Found: " << (Search(PTR(root), elem) != nullptr) << "\n";
	}
	void Delete(int elem)
	{
		if (root == nullptr)
			return;
		UPtr_TreeNode& delNode = Search(root, PTR(root), elem);
		if (delNode == nullptr)
		{
			std::cout << "Element " << elem << " not found\n";
			return;
		}
		else
		{
			if (delNode->right == nullptr && delNode->left == nullptr)	// leaf node
			{
				delNode.reset(nullptr);
			}
			else
			{
				if (delNode->left != nullptr)
				{
					std::pair<TreeNode*, TreeNode*> maxPair =
						FindMaxPair(PTR(delNode->left), PTR(delNode));
					TreeNode* replacingNode = maxPair.first;
					TreeNode* parentOfReplNode = maxPair.second;
					int val = replacingNode->data;
					parentOfReplNode->left = std::move(replacingNode->left);
					delNode->data = val;
				}
				else if (delNode->right != nullptr)
				{
					std::pair<TreeNode*, TreeNode*> maxPair =
						FindMinPair(PTR(delNode->right), PTR(delNode));
					TreeNode* replacingNode = maxPair.first;
					TreeNode* parentOfReplNode = maxPair.second;
					int val = replacingNode->data;
					parentOfReplNode->right = std::move(replacingNode->right);
					delNode->data = val;
				}
			}
		}
	}
	void FindMin()
	{
		TreeNode* temp = PTR(root);
		while (temp->left != nullptr)
		{
			temp = PTR(temp->left);
		}
		std::cout << "Min : " << temp->data << "\n";
	}
	void FindMax()
	{
		TreeNode* temp = PTR(root);
		while (temp->right != nullptr)
		{
			temp = PTR(temp->right);
		}
		std::cout << "Max : " << temp->data << "\n";
	}

private:
	std::unique_ptr<TreeNode> root;

	// methods
	void InOrder(TreeNode* temp)
	{
		if (temp)
		{
			InOrder(PTR(temp->left));
			std::cout << temp->data << " ";
			InOrder(PTR(temp->right));
		}
	}
	void PreOrder(TreeNode* temp)
	{
		if (temp)
		{
			std::cout << temp->data << " ";
			PreOrder(PTR(temp->left));
			PreOrder(PTR(temp->right));
		}
	}
	void PostOrder(TreeNode* temp)
	{
		if (temp)
		{
			PostOrder(PTR(temp->left));
			PostOrder(PTR(temp->right));
			std::cout << temp->data << " ";
		}
	}
	TreeNode* Search(TreeNode* temp, int elem)
	{
		if (temp)
		{
			if (temp->data == elem)
				return temp;
			else if (temp->data < elem)
				return Search(PTR(temp->right), elem);
			else if (temp->data > elem)
				return Search(PTR(temp->left), elem);
		}
		return nullptr;
	}
	UPtr_TreeNode& Search(UPtr_TreeNode& curr, TreeNode* parent, int elem)
	{
		if (curr)
		{
			if (curr->data == elem)
				return curr;
			else if (curr->data < elem)
				return Search(curr->right, PTR(curr), elem);
			else if (curr->data > elem)
				return Search(curr->left, PTR(curr), elem);
		}
		return std::unique_ptr<TreeNode>(nullptr);
	}
	std::pair<TreeNode*, TreeNode*> FindMaxPair(TreeNode* temp, TreeNode* parent)
	{
		while (temp->right != nullptr)
		{
			parent = temp;
			temp = PTR(temp->right);
		}
		return std::pair<TreeNode*, TreeNode*>(temp, parent);
	}
	std::pair<TreeNode*, TreeNode*> FindMinPair(TreeNode* temp, TreeNode* parent)
	{
		while (temp->left != nullptr)
		{
			parent = temp;
			temp = PTR(temp->left);
		}
		return std::pair<TreeNode*, TreeNode*>(temp, parent);
	}
};

void TreeOperations()
{
	int arr[] = { 34, 22, 45, 25, 67, 21, 50, 80, 14 };
	BinarySearchTree tree;
	tree.Create(arr, 9);
	tree.Print(BinarySearchTree::IN_ORDER);
	tree.Print(BinarySearchTree::PRE_ORDER);
	tree.Print(BinarySearchTree::POST_ORDER);
	tree.Search(67);
	tree.Insert(123);
	tree.Insert(48);
	tree.Insert(54);
	tree.Insert(46);
	tree.Insert(57);
	tree.Search(123);
	tree.Delete(123);
	tree.FindMin();
	tree.FindMax();
	tree.Delete(54);
	tree.Print(BinarySearchTree::IN_ORDER);
}

void ListOperations()
{
	int arr[] = { 1, 34, 22, 45, 25, 67, 21 };
	LinkedList lst;
	lst.Create(arr, 7);
	lst.Print();
	lst.Search(145);
	lst.Replace(122, 99);
	lst.Print();
	lst.Delete(34);
	lst.Delete(21);
	lst.Print();
	lst.InsertAfter(36, 45);
	lst.InsertAfter(90, 67);
	lst.Print();
}

int main()
{
	//ListOperations();
	TreeOperations();
	std::cin.get();
	return 0;
}