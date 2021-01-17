// Singly Liked List Implementation in C++

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

		// Encapsulation
		void setData(int x)
		{
			data = x;
		}

		int getData()
		{
			return data;
		}
};

class SLL
{

public:
	Node* head;
	SLL()
	{
		head = NULL;
	}
	void Print()
	{
		Node* temp = head;

		while(temp!=NULL)
		{
			cout<<temp->getData()<<" ";
			temp = temp->next;
		}
		cout<<"\n";
	}

	void Insert_At_Head(int x)
	{
		Node* newNode = new Node(x);
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
		Node* newNode = new Node(x);
		Node* current = head;
		
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
			cout<<"ERROR:Enter a valid Index\n";
			return;	
		}

		Node* newNode = new Node(x);		
		Node* current = head;
		for(int i=0;i<n-2;i++)
		{
			if(current->next == NULL)
			{
				cout<<"ERROR:Enter a valid Index\n";
				return;
			}
			current = current->next;
		}
		
		newNode->next = current->next;
		current->next = newNode;
		
	}

	void Delete(int n)
	{
		if(head == NULL)
		{
			cout<<"ERROR:The List is Empty\n";
			return;
		}

		Node* current = head;
		if(n==1)
		{
			head = current->next;
			delete current;
			return;
		}
		
		for(int i=0;i<n-2;i++)
		{
			if(current->next == NULL)
			{
				printf("\nEnter a valid Index\n");
				return;
			}
			// Iterate till we reach the (n-1)th node
			current = current->next;
		}
		
		Node* nodeToDelete = current->next;
		current->next = nodeToDelete->next;
		delete nodeToDelete;
	}

	void ReversePrint(Node* current,bool flag)
	{
		if(current == NULL)
		{
			return;
		}
		if(flag)
		{
			// Reverse print if flag is set to True
			ReversePrint(current->next,flag);
			cout<<current->getData()<<" ";
		}
		else
		{
			// Print Linked List in original order recursively if flag is set to False
			cout<<current->getData()<<" ";
			ReversePrint(current->next,flag);
		}
	}

	void ReverseIterative()
	{
		Node *current,*prev,*next;
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

	void ReverseRecursive(Node* current)
	{
		if(current->next==NULL)
		{
			head = current;
			return;
		}

		ReverseRecursive(current->next);

		// When the recursion hits the base case the below code  
		// will start executing for each call
		Node* temp = current->next;
		temp->next = current;
		current->next = NULL;
	}	
};

int main()
{
	int key,temp,n;
	SLL ll;
	while(1)
	{
		cout<<"Singly Linked List: ";
		ll.Print();
		cout<<
			"\nOption:1-Insert at Head\n"
			"Option:2-Insert at Tail\n"
			"Option:3-Insert at n\n"
			"Option:4-Delete at n\n"
			"Option:5-Print Reversed List\n"
			"Option:6-Reverse List Iteratively\n"
			"Option:7-Reverse List Recursively\n"
			"Option:8-Exit\n"
			"Enter an Option: ";
		cin>>key;
		switch(key)
		{				
			case 1:
				cout<<"\nEnter the number of elements to be Inserted: ";
				cin>>n;
				cout<<"\nEnter the elements to be inserted: ";
				for(int i=0;i<n;i++)
				{
					cin>>temp;
					ll.Insert_At_Head(temp);
				}
				break;
			case 2:
				cout<<"\nEnter the number of elements to be Inserted: ";
				cin>>n;
				cout<<"\nEnter the elements to be inserted: ";
				for(int i=0;i<n;i++)
				{
					cin>>temp;
					ll.Insert_At_Tail(temp);
				}
				break;
			case 3:
				cout<<"\nEnter the element and index to insert: ";
				cin>>temp;
				cin>>n;
				ll.Insert(temp,n);
				break;
			case 4:
				cout<<"\nEnter the index to delete\n";
				cin>>n;
				ll.Delete(n);
				break;
			case 5:
				cout<<"\nReverse Printed List: ";
				ll.ReversePrint(ll.head,1);
				cout<<"\n";
				break;
			case 6:
				cout<<"\nIteratively Reversed List: ";
				ll.ReverseIterative();
				cout<<"\n";
				break;
			case 7:
				cout<<"\nRecursively Reversed List: ";
				ll.ReverseRecursive(ll.head);
				cout<<"\n";
				break;		
			case 8:
				return 0;
			default:
				cout<<"Select a valid Option";
				break;
		}
		cout<<"\n";
	}		
	return 0;
}