// Doubly Linked List Implementation in C++

#include<iostream>
using namespace std;

class Node
{
	private:
		int data;
	public:
		Node* prev;
		Node* next;
		Node(int x)
		{
			data = x;
			prev = NULL;
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

class DLL
{
	public:
		Node* head;
		DLL()
		{
			head = NULL;
		}
		
		void Print()
		{
			if(head == NULL)
			{
				cout<<"Empty List";
			}

			Node* current = head;
			while(current != NULL)
			{
				cout<<current->getData()<<" ";
				current = current->next;
			}
			cout<<"\n\n";
		}

		void Insert_At_Head(int x)
		{	
			Node* newNode = new Node(x);
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
			newNode->prev = current;
			
			if(current->next != NULL)
			{
				current->next->prev = newNode;
			}
			
			current->next = newNode;
		}

		void Delete(int n)
		{
			Node* current = head;
			if(head == NULL)
			{
				cout<<"ERROR:The List is Empty\n";
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
				delete current;
				return;
			}

			for(int i=0;i<n-2;i++)
			{
				if(current->next->next == NULL)
				{
					cout<<"\nERROR:Enter a valid Index\n";
					return;
				}
				current = current->next;
			}
			
			Node* nodeToDelete = current->next; 
			current->next = nodeToDelete->next;
			current->next->prev = current;
			
			delete nodeToDelete;
		}

		void ReversePrint(Node* current)
		{
			if(current == NULL)
			{
				return;
			}
			ReversePrint(current->next);
			cout<<current->getData()<<" ";
		}

		void ReverseIterative()
		{
			if(head == NULL)
			{
				cout<<"The list is Empty";
				return;
			}
			Node *current = head,*temp;
			while(current != NULL)
			{
				// swapping next and previous pointers for each node
				temp = current->prev;
				current->prev = current->next;
				current->next = temp; 

				current = current->prev;
			}

			if(temp != NULL)
			{
				// make head point to last node 
				head = temp->prev;
			}
		}

		void ReverseRecursive(Node* current)
		{
			if(head == NULL)
			{
				cout<<"The list is Empty";
				return;
			}
			if(current->next==NULL)
			{
				head = current;

				Node* temp;
				temp = current->prev;
				current->prev = current->next;
				current->next = temp;

				return;
			}

			ReverseRecursive(current->next);
			// Modify links by swapping next and prev 
			Node* temp;

			temp = current->prev;
			current->prev = current->next;
			current->next = temp;
		}
};

int main()
{
	int key,temp,n;
	DLL ll;
	while(1)
	{
		cout<<"Doubly Linked List: ";
		ll.Print();
		cout<<
			"Option:1-Insert at Head\n"
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
				ll.ReversePrint(ll.head);
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