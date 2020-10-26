// Linked List Based Implementation of Queue

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct Node
{
	int data;
	struct Node* next;
};

struct Node *front,*rear;

struct Node* createNewNode(int x)
{
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node*));
	newNode->data = x;
	newNode->next = NULL;
	return newNode;
}

bool IsEmpty()
{
	if(front == NULL && rear == NULL) return true;
	return false;
}

int Front()
{
	return ((IsEmpty())?-1:front->data);
}

void Print()
{
	printf("\nQueue: ");
	if(IsEmpty())
	{
		printf("Empty Queue\n");
		return;
	}

	struct Node* current = front;
	while(current != NULL)
	{
		printf("%d ",current->data);
		current = current->next;
	}
	printf("\n");
}

void Enqueue(int x)
{
	struct Node* newNode = createNewNode(x);
	if(IsEmpty()) 
	{
		front = rear = newNode;
		return;
	}
	rear->next = newNode;  
	rear = newNode;
}

int Dequeue()
{
	if(IsEmpty()) 
	{
		printf("\nERROR: Dequeue Failed - Queue is Empty\n");
		return -1;
	}
	
	struct Node* temp = front;
	int data = temp->data;

	if(front == rear)
	{
		front = rear = NULL;
	}
	else
	{
		front = front->next;
	}
	free(temp);
	return data;
}


int main()
{
	front = rear = NULL;

	int key,temp;
	while(true)
	{
		Print();
		printf(
			  "\nOption:1-Enqueue\n"
			  "Option:2-Dequeue\n"
			  "Option:3-Front\n"
			  "Option:4-IsEmpty\n"
			  "Option:5-Exit\n"
			  "Select an Option: "
		);
		scanf("%d",&key);
		switch(key)
		{
			case 1:
				printf("\nEnter a number to Enqueue\n");
				scanf("%d",&temp);
				Enqueue(temp);
				break;
			case 2:
				Dequeue();
				break;
			case 3:
				printf("\nFront Element : %d\n",Front());
				break;
			case 4:
				printf("\n%s\n",(IsEmpty())?("YES"):("NO"));
				break;
			case 5:
				return 0;
			default:
				printf("\nSelect a valid option\n");
				break;
		}
	}
	return 0;
}