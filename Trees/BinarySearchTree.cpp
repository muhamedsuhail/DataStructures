// Binary Search Tree Implementation in C++

#include<iostream>
#include<queue>
using namespace std;

class Node
{
	private:
		int data;
	public:
		Node *left,*right;

		Node(int x)
		{
			data = x;
			left = right = NULL;
		}

		int getData()
		{
			return data;
		}
};

class BST
{
public:
	Node* root;

	// Function Prototypes
	BST();

	Node* InsertRecursive(int x, Node* rootptr);
	void InsertIterative(int x);	
	
	void SearchRecursive(int x, Node* rootptr);
	void SearchIterative(int x);
	
	int MinMaxIterative(bool flag);
	int MinMaxRecursive(Node* rootptr, bool flag);
	
	int Height(Node* rootptr);
	
	// BFS
	void LevelOrderTraversal();
	
	// DFS
	void PreOrder(Node* rootptr);
	void InOrder(Node* rootptr);
	void PostOrder(Node* rootptr);
};

int main()
{
	BST T;
	int key,temp;
	while(1)
	{
		cout<<
			"Option:1-Insert (Recursive)\n"
			"Option:2-Insert (Iterative)\n"
			"Option:3-Search (Recursive)\n"
			"Option:4-Search (Iterative)\n"
			"Option:5-Minimum Element (Recursive)\n"
			"Option:6-Minimum Element (Iterative)\n"
			"Option:7-Maximum Element (Recursive)\n"
			"Option:8-Maximum Element (Iterative)\n"
			"Option:9-Height of the BST\n"
			"Option:10-BFS-Level Order Traversal\n"
			"Option:11-DFS-PreOrder Traversal\n"
			"Option:12-DFS-InOrder Traversal\n"
			"Option:13-DFS-PostOrder Traversal\n"
			"Option:14-Exit\n\n"
			"Select an Option: "
		;

		cin>>key;
		switch(key)
		{
			case 1:
				cout<<"\nEnter the element to be inserted: ";
				cin>>temp;
				T.root = T.InsertRecursive(temp,T.root);
				break;
			case 2:
				cout<<"\nEnter the element to be inserted: ";
				cin>>temp;
				T.InsertIterative(temp);
				break;
			case 3:
				cout<<"\nEnter the element to be searched: ";
				cin>>temp;
				T.SearchRecursive(temp,T.root);
				break;
			case 4:
				cout<<"\nEnter the element to be searched: ";
				cin>>temp;
				T.SearchIterative(temp);
				break;
			case 5:
				cout<<"\nMinimum Element - "<<T.MinMaxRecursive(T.root,0);
				break;
			case 6:
				cout<<"\nMinimum Element - "<<T.MinMaxIterative(0);
				break;
			case 7:
				cout<<"\nMaximum Element - "<<T.MinMaxRecursive(T.root,1);
				break;
			case 8:
				cout<<"\nMaximum Element - "<<T.MinMaxIterative(1);
				break;
			case 9:
				cout<<"\nHeight of the BST - "<<T.Height(T.root);
				break;
			case 10:
				cout<<"\nLevel Order Traversal: ";
				T.LevelOrderTraversal();
				break;
			case 11:
				cout<<"\nPreOrder Traversal: ";
				T.PreOrder(T.root);
				break;
			case 12:
				cout<<"\nInOrder Traversal: ";
				T.InOrder(T.root);
				break;
			case 13:
				cout<<"\nPostOrder Traversal: ";
				T.PostOrder(T.root);
				break;
			case 14:
				return 0;
		}
		cout<<"\n\n";
	}
}

BST::BST()
{
	root = NULL;
}

Node* BST::InsertRecursive(int x, Node* rootptr)
{
	if(rootptr == NULL)
	{
		// If the Tree is Empty
		// Or
		// When the funcion hits base condition(lead node) -> 
		// where the value to be inserted fits into the BST
		Node* newNode = new Node(x);
		rootptr = newNode;
		return rootptr;
	}
	// Passing root of left/right subtree as parameter
	else if(x <= rootptr->getData())
	{	
		rootptr->left = InsertRecursive(x,rootptr->left);
	}
	else
	{
		rootptr->right = InsertRecursive(x,rootptr->right);
	}

	return rootptr;
}

void BST::InsertIterative(int x)
{
	Node* newNode = new Node(x);
	Node* current = root;

	if(root == NULL)
	{
		// Tree is empty
		root = newNode;
		return;
	}

	while(1)
	{
		// Executes until the funciton reaches the desired leaf node
		if(x <= current->getData())
		{
			if(current->left == NULL)
			{
				current->left = newNode;
				return;
			}
			current = current->left;
		}
		else
		{
			if(current->right == NULL)
			{
				current->right = newNode;
				return;
			}
			current = current->right;
		}
	}
	cout<<endl;
}

void BST::SearchRecursive(int x, Node* rootptr)
{
	if(rootptr==NULL)
	{
		// Tree is Empty
		// Or
		// When the funcion hits base condition(lead node - END of BST)
		cout<<"Not Found\n";
		return;
	}
	else if(rootptr->getData() == x)
	{
		cout<<"Found\n";
	}
	// Passing root of left/right subtree as parameter
	else if(x <= rootptr->getData())
	{

		SearchRecursive(x,rootptr->left);
	}
	else
	{
		SearchRecursive(x,rootptr->right);
	}
}

void BST::SearchIterative(int x)
{
	Node* current = root;
	if(root == NULL)
	{
		cout<<"Not Found\n";
		return;
	}
	// Executes until the function reaches the desired leaf node 
	do
	{
		if(current->getData() == x)
		{
			cout<<"Found\n";
			return;
		}

		else if(x < current->getData())
		{
			if(current->left == NULL)
			{
				break;
			}
			current = current->left;
		}
		else
		{
			if(current->right == NULL)
			{
				break;
			}
			current = current->right;
		}
	}
	while(current->left != NULL || current->right != NULL);
	
	cout<<"Not Found\n";
}

int BST::MinMaxIterative(bool flag)
{
	// Setting flag
	// flag = 0 - Find Min element
	// flag = 1 - Find Max element

	Node* current = root;
	if(root == NULL)
	{
		cout<<"ERROR: Tree is Empty\n";
		return -1;
	}

	if(flag)
	{
		while(current->right != NULL)
		{
			current = current->right;
		}
		return current->getData();
	}

	while(current->left != NULL)
	{
		current = current->left;
	}
	return current->getData();
}

int BST::MinMaxRecursive(Node* rootptr, bool flag)
{
	// Setting flag
	// flag = 0 - Find Min element
	// flag = 1 - Find Max element

	if(rootptr == NULL)
	{
		cout<<"ERROR: Tree is Empty\n";
		return -1;
	}

	if(flag)
	{
		if(rootptr->right == NULL)
		{
			return rootptr->getData();
		}
		return MinMaxRecursive(rootptr->right,flag);
	}
	else
	{
		if(rootptr->left == NULL)
		{
			return rootptr->getData();
		}
		return MinMaxRecursive(rootptr->left,flag);
	}
}

// Utility Function
int max(int A, int B)
{
	return (A>B)?(A):(B);
}

int BST::Height(Node* rootptr)
{
	if(rootptr == NULL)
	{
		return -1;
	}
	return max(Height(rootptr->right),Height(rootptr->left))+1;
}

void BST::LevelOrderTraversal()
{
	// Time Complexity - O(n)
	// Space Complexity - O(n)
	// Can also be implemented without queue(Ref C implementaion of BST)
	Node* rootptr = root;
	if(rootptr == NULL) return;
	queue<Node*> Q;
	Q.push(rootptr);
	while(!Q.empty())
	{
		Node* current = Q.front();
		cout<<current->getData()<<" ";
		if(current->left != NULL) Q.push(current->left);
		if(current->right != NULL) Q.push(current->right);
		Q.pop();
	}
	cout<<"\n";
}

void BST::PreOrder(Node* rootptr)
{
	if(rootptr == NULL) return;
	cout<<rootptr->getData()<<" ";
	PreOrder(rootptr->left);
	PreOrder(rootptr->right);
}

void BST::InOrder(Node* rootptr)
{
	if(rootptr == NULL) return;
	InOrder(rootptr->left);
	cout<<rootptr->getData()<<" ";
	InOrder(rootptr->right);
}

void BST::PostOrder(Node* rootptr)
{
	if(rootptr == NULL) return;
	PostOrder(rootptr->left);
	PostOrder(rootptr->right);
	cout<<rootptr->getData()<<" ";
}