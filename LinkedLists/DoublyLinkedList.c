// Doubly Liked List Implementation in C

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct Node
{
	int data;
	struct Node* prev;
	struct Node* next;
};

struct Node* head;

void Print()
{
	if(head == NULL)
	{
		printf("Empty List");
	}

	struct Node* current = head;

	while(current != NULL)
	{
		printf("%d ",current->data);
		current = current->next;
	}
	printf("\n");
}

struct Node* createNewNode(int x)
{
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	
	newNode->data = x;
	newNode->prev = NULL;
	newNode->next = NULL;
	
	return newNode;
}

void Insert_At_Head(int x)
{	
	struct Node* newNode = createNewNode(x);
	if(head == NULL)
	{
		head = newNode;	
		return;
	}
	
	head->prev = newNode;
	newNode->next = head;
	head = newNode;
}

void Insert_At_Tail(int x)
{
	struct Node* newNode = createNewNode(x);
	struct Node* current = head;
	
	if(head == NULL)
	{
		head = newNode;
		return;
	}	
	
	while(current->next != NULL)
	{
		current = current->next;
	}
	
	current->next = newNode;
	newNode->prev = current;
}

void Insert(int x,int n)
{
	if(n==1)
	{ 
		Insert_At_Head(x);
		return; 
	}

	if(head == NULL && n>1)
	{
		printf("ERROR:Enter a valid Index\n");
		return;	
	}
	
	struct Node* newNode = createNewNode(x);
	struct Node* current = head;

	for(int i=0;i<n-2;i++)
	{
		if(current->next == NULL)
		{
			printf("Enter a valid Index\n");
			return;
		}
		current = current->next;
	}

	newNode->next = current->next;
	newNode->prev = current;
	if(current->next != NULL)
	{
		current->next->prev = newNode;
	}
	current->next = newNode;
}

void Delete(int n)
{
	struct Node* current = head;

	if(head == NULL || n == 0)
	{
		printf("ERROR:Enter a valid Index\n");
		return;
	}
	if(n==1)
	{
		// If the node to be deleted is the head node
		if(current->next == NULL)
		{
			head = NULL;
		}
		else
		{
			current->next->prev = NULL;
			head = current->next;
		}
		free(current);
		return;
	}

	for(int i=0;i<n-2;i++)
	{
		if(current->next->next == NULL)
		{
			printf("Enter a valid Index\n");
			return;
		}
		current = current->next;
	}
	
	struct Node* nodeToDelete = current->next; 
	current->next = nodeToDelete->next;
	current->next->prev = current;
	
	free(nodeToDelete);
}

void ReverseIterative()
{
	if(head == NULL)
	{
		printf("The list is Empty");
		return;
	}
	struct Node *current = head,*temp;
	
	while(current != NULL)
	{
		temp = current->prev;
		current->prev = current->next;
		current->next = temp; 
	
		current = current->prev;
	}

	if(temp != NULL)
	{
		head = temp->prev;
	}
}

void ReverseRecursive(struct Node* current)
{
	if(head == NULL)
	{
		printf("The list is Empty");
		return;
	}
	if(current->next==NULL)
	{
		head = current;

		struct Node* temp;
		temp = current->prev;
		current->prev = current->next;
		current->next = temp;
		
		return;
	}
	ReverseRecursive(current->next);
	
	struct Node* temp;
	temp = current->prev;
	current->prev = current->next;
	current->next = temp;
}

void ReversePrint(struct Node* current)
{
	if(current == NULL)
	{
		return;
	}
	ReversePrint(current->next);
	printf("%d ",current->data);

}

int main()
{
	int key,temp,n;
	while(1)
	{
		printf("Doubly Linked List: ");
		Print();
		printf("\n");
		printf(
			"Option:1-Insert at Head\n"
			"Option:2-Insert at Tail\n"
			"Option:3-Insert at n\n"
			"Option:4-Delete at n\n"
			"Option:5-Print Reversed List\n"
			"Option:6-Reverse List Iteratively\n"
			"Option:7-Reverse List Recursively\n"
			"Option:8-Exit\n"
			"Enter an Option: "
		);
		scanf("%d",&key);
		switch(key)
		{				
			case 1:
				printf("Enter the number of elements to be Inserted: ");
				scanf("%d",&n);
				for(int i=0;i<n;i++)
				{
					scanf("%d",&temp);
					Insert_At_Head(temp);
				}	
				break;
			case 2:
				printf("\nEnter the number of elements to be Inserted: ");
				scanf("%d",&n);
				printf("\nEnter the elements to be Inserted:");
				for(int i=0;i<n;i++)
				{
					scanf("%d",&temp);
					Insert_At_Tail(temp);
				}
				break;
			case 3:
				printf("\nEnter the element and index to insert: ");
				scanf("%d",&temp);
				scanf("%d",&n);
				Insert(temp,n);
				break;
			case 4:
				printf("\nEnter the index to delete: ");
				scanf("%d",&n);
				Delete(n);
				break;
			case 5:
				printf("\nReverse Printed List: ");
				ReversePrint(head);
				printf("\n");
				break;
			case 6:
				printf("\nIteratively Reversed List: ");
				ReverseIterative();
				printf("\n");
				break;
			case 7:
				printf("\nRecursively Reversed List: ");
				ReverseRecursive(head);
				printf("\n");
				break;		
			case 8:
				return 0;
			default:
				printf("Select a valid Option");
				break;
		}
		printf("\n");
	}		
	return 0;
}