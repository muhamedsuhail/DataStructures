// Binary Search Tree Implementation in C

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct Node
{
	int data;
	struct Node *left,*right;
};

struct Node* root;

// Function Prototypes

struct Node* CreateNewNode(int data);
int max(int A, int B);

struct Node* InsertRecursive(int data, struct Node* rootptr);
void InsertIterative(int data);

void SearchRecursive(int data, struct Node* rootptr);
void SearchIterative(int data);

int MinMaxIterative(bool flag);
int MinMaxRecursive(struct Node* rootptr, bool flag);

int Height(struct Node* rootptr);

// BFS
void LevelN(struct Node* rootptr, int level);
void LevelOrderTraversal(struct Node* rootptr);

// DFS
void PreOrder(struct Node* rootptr);
void InOrder(struct Node* rootptr);
void PostOrder(struct Node* rootptr);


int main()
{
	root = NULL;
	int key,temp;
	while(1)
	{
		printf(
			"\nOption:1-Insert (Recursive)\n"
			"Option:2-Insert (Iterative)\n"
			"Option:3-Search (Recursive)\n"
			"Option:4-Search (Iterative)\n"
			"Option:5-Minimum Element (Recursive)\n"
			"Option:6-Minimum Element (Iterative)\n"
			"Option:7-Maximum Element (Recursive)\n"
			"Option:8-Maximum Element (Iterative)\n"
			"Option:9-Height of the BST\n"
			"Option:10-Level Order Traversal\n"
			"Option:11-PreOrder Traversal\n"
			"Option:12-InOrder Traversal\n"
			"Option:13-PostOrder Traversal\n"
			"Option:14-Exit\n\n"
			"Select an Option: "
		);

		scanf("%d",&key);
		switch(key)
		{
			case 1:
				printf("\nEnter the element to be inserted: ");
				scanf("%d",&temp);
				root = InsertRecursive(temp,root);
				break;
			case 2:
				printf("\nEnter the element to be inserted: ");
				scanf("%d",&temp);
				InsertIterative(temp);
				break;
			case 3:
				printf("\nEnter the element to be searched: ");
				scanf("%d",&temp);
				SearchRecursive(temp,root);
				break;
			case 4:
				printf("\nEnter the element to be searched: ");
				scanf("%d",&temp);
				SearchIterative(temp);
				break;
			case 5:
				printf("\nMinimum Element - %d",MinMaxRecursive(root,0));
				break;
			case 6:
				printf("\nMinimum Element - %d",MinMaxIterative(0));
				break;
			case 7:
				printf("\nMaximum Element - %d",MinMaxRecursive(root,1));
				break;
			case 8:
				printf("\nMaximum Element - %d",MinMaxIterative(1));
				break;
			case 9:
				printf("\nHeight of the BST - %d",Height(root));
				break;
			case 10:
				printf("\nLevel Order Traversal: ");
				LevelOrderTraversal(root);
				break;
			case 11:
				printf("\nPreOrder Traversal: ");
				PreOrder(root);
				break;
			case 12:
				printf("\nInOrder Traversal: ");
				InOrder(root);
				break;
			case 13:
				printf("\nPostOrder Traversal: ");
				PostOrder(root);
				break;
			case 14:
				return 0;
		}
		printf("\n");
	}
}

struct Node* CreateNewNode(int data)
{
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node*));
	newNode->data = data;
	newNode->left = newNode->right = NULL;
	return newNode;
}

struct Node* InsertRecursive(int data, struct Node* rootptr)
{
	if(rootptr == NULL)
	{
		// If the Tree is Empty
		// Or
		// When the funcion hits base condition(lead node) -> 
		// where the value to be inserted fits into the BST
		struct Node* newNode = CreateNewNode(data);
		rootptr = newNode;
		return rootptr;
	}

	// Passing root of left/right subtree as parameter
	else if(data <= rootptr->data)
	{	
		rootptr->left = InsertRecursive(data,rootptr->left);
	}
	else
	{
		rootptr->right = InsertRecursive(data,rootptr->right);
	}

	return rootptr;
}

void InsertIterative(int data)
{
	struct Node* newNode = CreateNewNode(data);
	struct Node* current = root;

	if(root == NULL)
	{
		// Tree is empty
		root = newNode;
		return;
	}

	while(1)
	{
		// Executes until the funciton reaches the desired leaf node
		if(data <= current->data)
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
	printf("\n");
}	

void SearchRecursive(int data, struct Node* rootptr)
{
	if(rootptr==NULL)
	{
		// Tree is Empty
		// Or
		// When the funcion hits base condition(lead node - END of BST)
		printf("Not Found\n");
		return;
	}
	else if(rootptr->data == data)
	{
		printf("Found\n");
	}
	// Passing root of left/right subtree as parameter
	else if(data <= rootptr->data)
	{
		SearchRecursive(data,rootptr->left);
	}
	else
	{
		SearchRecursive(data,rootptr->right);
	}
}

void SearchIterative(int data)
{
	struct Node* current = root;
	if(root == NULL)
	{
		printf("Not Found\n");
		return;
	}

	// Executes until the function reaches the desired leaf node 
	do
	{
		if(current->data == data)
		{
			printf("Found\n");
			return;
		}

		else if(data < current->data)
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
	
	printf("Not Found\n");
}

int MinMaxIterative(bool flag)
{
	// Setting flag
	// flag = 0 - Find Min element
	// flag = 1 - Find Max element

	struct Node* current = root;
	if(root == NULL)
	{
		printf("ERROR: Tree is Empty\n");
		return -1;
	}

	if(flag)
	{
		while(current->right != NULL)
		{
			current = current->right;
		}
		return current->data;
	}

	while(current->left != NULL)
	{
		current = current->left;
	}
	return current->data;
}

int MinMaxRecursive(struct Node* rootptr, bool flag)
{
	// Setting flag
	// flag = 0 - Find Min element
	// flag = 1 - Find Max element

	if(rootptr == NULL)
	{
		printf("ERROR: Tree is Empty\n");
		return -1;
	}

	if(flag)
	{
		if(rootptr->right == NULL)
		{
			return rootptr->data;
		}
		return MinMaxRecursive(rootptr->right,flag);
	}
	else
	{
		if(rootptr->left == NULL)
		{
			return rootptr->data;
		}
		return MinMaxRecursive(rootptr->left,flag);
	}
}

// Utility Function
int max(int A, int B)
{
	return (A>B)?(A):(B);
}

int Height(struct Node* rootptr)
{
	if(rootptr == NULL) return -1;
	return max(Height(rootptr->right),Height(rootptr->left))+1;
}

void LevelN(struct Node* rootptr, int level)
{
	if(rootptr == NULL) return;
	if(level == 1) printf("%d ",rootptr->data);
	else if(level > 1)
	{
		LevelN(rootptr->left,level-1);
		LevelN(rootptr->right,level-1);
	}
}

void LevelOrderTraversal(struct Node* rootptr)
{
	// Time Complexity  - O(n^2)
	// Space Complexity - O(n)
	// Can be implemented effectively by using a Queue(Ref Cpp Implementation of BST)
	int h = Height(rootptr);
	for(int i=1;i<=h+1;i++)
	{
		LevelN(rootptr,i);
	}
}

void PreOrder(struct Node* rootptr)
{
	if(rootptr == NULL) return;
	printf("%d ",rootptr->data);
	PreOrder(rootptr->left);
	PreOrder(rootptr->right);
}

void InOrder(struct Node* rootptr)
{
	if(rootptr == NULL) return;
	InOrder(rootptr->left);
	printf("%d ",rootptr->data);
	InOrder(rootptr->right);
}

void PostOrder(struct Node* rootptr)
{
	if(rootptr == NULL) return;
	PostOrder(rootptr->left);
	PostOrder(rootptr->right);
	printf("%d ",rootptr->data);
}
