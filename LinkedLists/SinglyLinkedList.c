// Singly Liked List Implementation in C++

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct Node
{
	int data;
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

	while(current!=NULL)
	{
		printf("%d ",current->data); // current->data  is similar to *(current).data
		current = current->next;
	}
	printf("\n");
}

void Delete(int n)
{
	struct Node* current = head;
	
	if(n == 1)
	{
		head = current->next;
		free(current); // frees the heap memory captured by the node at 1.
		return;
	}
	
	for(int i=0;i<n-2;i++)
	{
		if(current->next->next == NULL)
		{
			printf("\nEnter a valid Index\n");
			return;
		}
		current = current->next;
	}
	
	struct Node* nodeToDelete = current->next;
	current->next = nodeToDelete->next;
	free(nodeToDelete); // frees the heap memory captured by the node at n. 
}

struct Node* createNewNode(int x)
{
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->data = x;
	newNode->next = NULL;	
}

void Insert_At_Head(int x)
{
	struct Node* newNode = createNewNode(x);
	if(head == NULL)
	{
		head = newNode;	
		return;
	}
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
	current->next = newNode;
}

void ReverseIterative()
{
	struct Node *current,*prev,*next;
	current = head;
	prev = NULL;
	
	while(current != NULL)
	{
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}	
	head = prev;
}

void ReverseRecursive(struct Node* p)
{
	if(p->next==NULL)
	{
		head = p;
		return;
	}

	ReverseRecursive(p->next);
	
	// When the recursion hits the base case the below code  
	// will start executing for each call
	struct Node* q = p->next;
	q->next = p;
	p->next = NULL;
}
  
void ReversePrint(struct Node* p,bool flag)
{
	if(p == NULL)
	{
		return;
	}
	if(flag)
	{
		// Reverse print if flag is set to True
		ReversePrint(p->next,flag);
		printf("%d ",p->data);
	}
	else
	{
		// Print Linked List in original order recursively if flag is set to False
		printf("%d ",p->data);
		ReversePrint(p->next,flag);
	}
}

int main()
{
	int key,temp,n;
	while(1)
	{
		printf("Singly Linked List: ");
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
				ReversePrint(head,1);
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

// int main()
// {
// 	int key,temp,n;
// 	head = NULL;
// 	while(1)
// 	{
// 		printf("Singly Linked List: ");
// 		printList();
// 		printf("\n"
// 			"Option:1-Insert at Head\n"
// 			"Option:2-Insert at Tail\n"
// 			"Option:3-Insert at n\n"
// 			"Option:4-Delete\n"
// 			"Option:5-Print Reversed List\n"
// 			"Option:6-Reverse List Iteratively\n"
// 			"Option:7-Reverse List Recursively\n"
// 			"Option:8-Exit\n"
// 			"Enter an Option: "
// 		);
// 		scanf("%d",&key);
// 		switch(key)
// 		{
// 			case 1:
// 				printf("How many elements to insert? ");
// 				scanf("%d",&n);
// 				printf("Enter the elements to be inserted:\n");
// 				for(int i=0;i<n;i++)
// 				{
// 					scanf("%d",&temp);
// 					Insert(temp,1);
// 				}
// 				break;
// 			case 2:
// 				printf("Enter the index to delete\n");
// 				scanf("%d",&n);
// 				Delete(n);
// 				break;
// 			case 3:
// 				printf("Reverse Printed List: ");
// 				ReversePrint(head,1);
// 				printf("\n");
// 				break;
// 			case 4:
// 				printf("Iteratively Reversed List: ");
// 				ReverseIterative();
// 				break;
// 			case 5:
// 				printf("Recursively Reversed List: ");
// 				ReverseRecursive(head);
// 				printf("\n");
// 				break;		
// 			case 6:
// 				return 0;
// 			default:
// 				printf("Select a valid Option");
// 				break;
// 		}
// 		printf("\n");
// 	}		
// 	return 0;
// }