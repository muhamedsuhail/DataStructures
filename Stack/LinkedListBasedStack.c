// Linked List Based Implementation of Stack

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct Node
{
	int data;
	struct Node* next;
};

struct Node* top;

void Print()
{
	if(top == NULL)
	{
		printf("Stack : Empty Stack\n");
		return;	
	}
	printf("Stack : ");
	struct Node* temp = top;
	while(temp !=NULL)
	{
		printf("%d ",temp->data);
		temp = temp->next;
	}
	printf("\n");
}

struct Node* createNewNode(int x)
{
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node*));
	newNode->data = x;
	newNode->next = NULL;
	return newNode;
}

void Push(int x)
{
	struct Node* temp = top;
	struct Node* newNode = createNewNode(x);
	newNode->next = temp;
	top = newNode;
}

void Pop()
{
	if(top == NULL)
	{
		printf("ERROR : Can't Pop. Stack is Empty");
		return;
	}

	struct Node* temp = top;
	top = temp->next;
	free(temp);
}

int Top()
{
	if(top!=NULL)
	{
		return top->data;
	}
	printf("ERROR : Stack is Empty ");
	return 0;
}

bool IsEmpty()
{
	if(top != NULL)
	{
		return false;
	}
	return true;
}

int main()
{
	top = NULL;
	int key,n,temp;
	while(1)
	{
		printf("\n");
		Print();
		printf(
			"\nOption:1-Push\n"
			"Option:2-Pop\n"
			"Option:3-IsEmpty\n"
			"Option:4-Get Top Element\n"
			"Option:5-Exit\n"
			"Select an Option: "
		);
		scanf("%d",&key);
		
		switch(key)
		{
			case 1:
				printf("\nEnter the element to be pushed:\n");
				scanf("%d",&temp);
				Push(temp);
				break;
			case 2:
				Pop();
				break;
			case 3:
				if(IsEmpty())
				{
					printf("\nYes\n");
					break;
				}
				printf("\nNo\n");
				break;
			case 4:
				printf("\nTop Element: %d\n",Top());
			 	break;
			case 5:
				return 0;
			default:
				printf("\nSelect a valid option\n");
		}
	}
	return 0;
}