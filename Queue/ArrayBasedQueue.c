// Array Based Implementation of Queue 

#include<stdio.h>
#include<stdbool.h>
#define MAX 10

int Queue[MAX],front = -1,rear = -1;

bool IsEmpty()
{
	if(front == -1 && rear == -1) return true;
	return false;
}

bool IsFull()
{
	if((rear+1) % MAX == front) return true;
	return false;
}

int Front()
{
	if(IsEmpty())
	{
		printf("\nThe Queue is Empty\n");
		return -1;
	}
	return Queue[front];
}

void Print()
{
	printf("\nQueue: ");
	if(IsEmpty())
	{
		printf("Empty Queue\n");
		return;
	}
	for(int i=front;i<=rear;i++)
	{
		printf("%d ",Queue[i]);
	}
	printf("\n");
}

void Enqueue(int x)
{
	if(IsEmpty())
	{
		Queue[++front] = x;
		++rear;	
	}
	else if(IsFull())
	{
		printf("\nERROR: Enqueue Failed - The Queue is Full\n");
	}
	else
	{
		rear = (rear+1) % MAX;
		Queue[rear] = x;
	}
}

int Dequeue()
{
	if(IsEmpty())
	{
		printf("\nERROR: Dequeue Failed - The Queue is Empty\n");
		return -1;
	}

	int data = Queue[front];
	
	if(front == rear)
	{
		front = rear = -1;
	}
	else
	{
		front = (front+1)%MAX;
	}

	return data ;
}

int main()
{
	int key,temp;
	while(true)
	{
		Print();
		printf(
			  "\nOption:1-Enqueue\n"
			  "Option:2-Dequeue\n"
			  "Option:3-Front\n"
			  "Option:4-IsEmpty\n"
			  "Option:5-IsFull\n"
			  "Option:6-Exit\n"
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
				printf("\n%s\n",(IsFull())?("YES"):("NO"));
				break;
			case 6:
				return 0;
			default:
				printf("\nSelect a valid option\n");
				break;
		}
	}
	return 0;
}