// Linked List Based Implementation of Stack
#include<iostream>
using namespace std;

class Node
{
	public:
		int data;
		Node* next;
		Node(int x)
		{
			data = x;
			next = NULL;
		}	
};
class Linked_List_Stack
{
	private:
		Node* top;
	public:
		Linked_List_Stack()
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
				cout<<"ERROR : Can't Pop. Stack is Empty";
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
				return top->data;
			}
			cout<<"ERROR : Stack is Empty ";
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
			cout<<"Stack : ";
			Node* temp = top;
			while(temp !=NULL )
			{
				cout<<temp->data<<" ";
				temp = temp->next;
			}
			cout<<"\n";
		}
};
int main()
{
	Linked_List_Stack stack;
	stack.Pop();
	cout<<(stack.IsEmpty()?"\nStack is Empty\n":"\nStack is Not Empty\n");
	stack.Push(5); stack.Print();
	stack.Push(4); stack.Print();
	stack.Push(3); stack.Print();
	stack.Push(2); stack.Print();
	stack.Push(1); stack.Print();
	stack.Pop();   stack.Print();
	stack.Pop();
	stack.Pop();
	stack.Pop();
	stack.Pop();
	stack.Print();
	int top = stack.Top();
	if(top)
	{
		cout<<top;
	}
	cout<<(stack.IsEmpty()?"\nStack is Empty\n":"\nStack is Not Empty\n");
	return 0;

}