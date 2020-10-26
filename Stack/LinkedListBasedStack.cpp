// Linked List Based Implementation of Stack

#include<iostream>
using namespace std;

class Node
{
	private:
		int data;
	public:
		Node* next;
		Node(int x)
		{
			data = x;
			next = NULL;
		}

		int getData()
		{
			return data;
		}
};

class Stack
{
	private:
		Node* top;
	public:
		Stack()
		{
			top = NULL;
		}
		void Push(int x)
		{
			Node* temp = top;
			Node* newNode = new Node(x);
			newNode->next = temp;
			top = newNode;
		}
		
		void Pop()
		{
			if(top == NULL)
			{
				cout<<"\nERROR : Pop Failed - Stack is Empty\n";
				return;
			}
			Node* temp = top;
			top = temp->next;
			delete temp;
		}
		
		int Top()
		{
			if(top!=NULL)
			{
				return top->getData();
			}
			cout<<"\nERROR : Stack is Empty\n";
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
		void Print()
		{
			cout<<"\nStack : ";
			Node* temp = top;
			while(temp !=NULL )
			{
				cout<<temp->getData()<<" ";
				temp = temp->next;
			}
			cout<<"\n";
		}
};

int main()
{
	Stack S;
	int key,temp;
	while(1)
	{
		S.Print();
		cout<<
			"\nOption:1-Push\n"
			"Option:2-Pop\n"
			"Option:3-IsEmpty\n"
			"Option:4-Get Top Element\n"
			"Option:5-Exit\n"
			"Select an Option: "
		;

		cin>>key;
		switch(key)
		{
			case 1:
				cout<<"\nEnter the element to be pushed:\n";
				cin>>temp;
				S.Push(temp);
				break;
			case 2:
				S.Pop();
				break;
			case 3:
				if(S.IsEmpty())
				{
					cout<<"\nYes\n";
					break;
				}
				cout<<"\nNo\n";
				break;
			case 4:
				cout<<"\nTop Element: "<<S.Top()<<"\n";
			 	break;
			case 5:
				return 0;
			default:
				cout<<"\nSelect a valid option\n";
		}
	}
	return 0;
}