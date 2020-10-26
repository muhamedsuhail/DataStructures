// Linked List Based Implementation of Queue

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

class Queue
{
	public:
		Node *front,*rear;
		
		Queue()
		{
			front = rear = NULL;	
		}

		bool IsEmpty()
		{
			if(front == NULL && rear == NULL) return true;
			return false;
		}	

		int Front()
		{
			return ((IsEmpty())?-1:front->getData());
		}

		void Print()
		{
			cout<<"\nQueue: ";
			if(IsEmpty())
			{
				cout<<"Empty Queue\n";
				return;
			}

			Node* current = front;
			while(current != NULL)
			{
				cout<<current->getData()<<" ";
				current = current->next;
			}
			cout<<"\n";
		}

		void Enqueue(int x)
		{
			Node* newNode = new Node(x);
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
				cout<<"\nERROR: Dequeue Failed - Queue is Empty\n";
				return -1;
			}
			
			Node* temp = front;
			int data = temp->getData();

			if(front == rear)
			{
				front = rear = NULL;
			}
			else
			{
				front = front->next;
			}
			delete temp;
			return data;
		}
};

int main()
{
	int key,temp;
	Queue q;
	while(true)
	{
		q.Print();
		cout<<
			  "\nOption:1-Enqueue\n"
			  "Option:2-Dequeue\n"
			  "Option:3-Front\n"
			  "Option:4-IsEmpty\n"
			  "Option:5-Exit\n"
			  "Select an Option: ";
		cin>>key;
		switch(key)
		{
			case 1:
				cout<<"\nEnter a number to Enqueue ";
				cin>>temp;
				q.Enqueue(temp);
				break;
			case 2:
				q.Dequeue();
				break;
			case 3:
				cout<<"\nFront Element : "<<q.Front()<<"\n";
				break;
			case 4:
				cout<<"\n"<<((q.IsEmpty())?("YES"):("NO"))<<"\n";
				break;
			case 5:
				return 0;
			default:
				cout<<"\nSelect a valid option\n";
				break;
		}
	}
	return 0;
}