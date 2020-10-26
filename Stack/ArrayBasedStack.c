// Array based Implementation of Stack

#include<stdio.h>
#include<stdbool.h>
#define MAX_SIZE 100

int stack[MAX_SIZE] , top = -1;

void Print()
{
	if(top==-1)
	{
		printf("Stack : Empty\n");
		return;	
	}
	printf("Stack : ");
	for(int i=0;i<=top;i++)
	{
		printf("%d ",stack[i]);
	}
	printf("\n");
}

void Push(int x)
{
	if(top == MAX_SIZE-1)
	{
		printf("Stack overflow\n");
		return;
	}
	stack[++top] = x;
}

void Pop()
{
	if(top == -1)
	{
		printf("Stack is Empty\n");
		return;
	}
	top--;
}

int Top()
{
	return stack[top];
}

bool IsEmpty()
{
	if(top==-1) return true;
	return false;
}

int main()
{
	int temp,key,n;
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
				printf("\nEnter the number of elements to Push\n");
				scanf("%d",&n);
				printf("\nEnter the elements to be pushed:\n");
				for(int i=0;i<n;i++)
				{
					scanf("%d",&temp);
					Push(temp);
				}
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