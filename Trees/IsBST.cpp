// Program to check if the given Binary Tree is a BST

#include<iostream>
#include<limits.h>
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

class BTree
{
public:
	Node* root;

	BTree()
	{
		root = NULL;
	}

	void Insert(int x)
	{
		Node* rootptr = root;
		Node* newNode = new Node(x);
		if(rootptr == NULL) 
		{
			root = newNode;
			return;
		}
		
		// Do a BFS until a leaf node is reached
		// (Traverse until an empty place is found)
		queue<Node*> Q;
		Q.push(rootptr);

		while(!Q.empty())
		{
			Node* current = Q.front();
			Q.pop();
			if(current->left != NULL)
			{
				Q.push(current->left);
			}
			else
			{
				current->left = newNode;
				return;
			}

			if(current->right != NULL)
			{
				Q.push(current->right);
			}
			else
			{
				current->right = newNode;
				return;
			}
		}		
	}
};

// Approach #1
// Compare each and every nodes with it's corresponding root node
// Time Complexity - O(n^2)
// Space Complexity - Implicit(Stack Overflow may occur)
bool IsSubtreeLesser(Node* rootptr, int value)
{
	if(rootptr == NULL) return true;
	if(rootptr->getData() <= value
		&&IsSubtreeLesser(rootptr->left,value)
		&&IsSubtreeLesser(rootptr->right,value))
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool IsSubtreeGreater(Node* rootptr, int value)
{
	if(rootptr == NULL) return true;
	if(rootptr->getData() >= value
		&&IsSubtreeGreater(rootptr->left,value)
		&&IsSubtreeGreater(rootptr->right,value))
	{
		return true;
	}
	else
	{
		return false;
	}

}

bool IsBST(Node* rootptr)
{
	if(rootptr == NULL) return true;
	if(IsSubtreeLesser(rootptr->left,rootptr->getData())
		&&IsSubtreeGreater(rootptr->right,rootptr->getData())
		&&IsBST(rootptr->left)
		&&IsBST(rootptr->right))
	{
		return true;
	}

	return false;
}

// Approach #2 - Efficient Algorithm
// Setting up a range starting from the root node so that 
// each node will be compared only once with it's corresponding min and max values
// Time Complexity - O(n)
bool IsBinarySearchTree(Node* rootptr, int min, int max)
{
	if(rootptr == NULL) return true;
	if(rootptr->getData() > min && rootptr->getData() <= max
		&&IsBinarySearchTree(rootptr->left,min,rootptr->getData())
		&&IsBinarySearchTree(rootptr->right,rootptr->getData(),max))
	{
		return true;
	}
	return false;
}

bool IsBST1(Node* rootptr)
{
	return IsBinarySearchTree(rootptr,INT_MIN,INT_MAX);
}

int main()
{
	BTree T;
	T.Insert(15);
	T.Insert(10);
	T.Insert(20);
	T.Insert(8);
	T.Insert(12);
	T.Insert(18);
	T.Insert(25);
	// cout<<(IsBST(T.root)?"YES":"NO");
	cout<<(IsBST1(T.root)?"YES":"NO");
	return 0;
}