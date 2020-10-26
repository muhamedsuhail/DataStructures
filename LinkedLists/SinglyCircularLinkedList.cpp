// Singly Circular Liked List Implementation in C++

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

class SCLL
{

public:
	Node* tail;
	SCLL()
	{
		tail = NULL;
	}

	void Print()
	{
		if(tail == NULL)
		{
			cout<<"Empty List\n";
			return;	
		}

		Node* head = tail->next;
		do
		{
			cout<<head->getData()<<" ";
			head = head->next;
		}
		while(head != tail->next);
		
		cout<<"\n";
	}

	void Insert(int x)
	{
		// Insert at head
		Node* newNode = new Node(x);
		if(tail == NULL)
		{
			tail = newNode;
			tail->next = tail;	
			return;
		}
		newNode->next = tail->next;
		tail->next = newNode;
	}

	void Insert_At_Tail(int x)
	{
		Insert(x);
		tail = tail->next;
	}

	// Function Overloading 
	void Insert(int x,int y,string flag)
	{
		Node* head = tail->next;
		if(tail == NULL)
		{
			cout<<"ERROR:The List is Empty\n";
			return;	
		}

		if(flag == "Before")
		{
			if(head->getData() == y)
			{ 
				Insert(x);
				return; 
			}

			Node* newNode = new Node(x);
			do
			{
				if(head->next->getData() == y)
				{
					newNode->next = head->next;
					head->next = newNode;
					return;
				}
				head = head->next;
			}
			while(head!=tail->next);
		}
		else
		{
			if(tail->getData() == y)
			{ 
				Insert_At_Tail(x);
				return; 
			}
			Node* newNode = new Node(x);
			do
			{
				if(head->getData() == y)
				{
					newNode->next = head->next;
					head->next = newNode;
					return;
				}
				head = head->next;
			}
			while(head!=tail->next);
		}
	}

	void Delete(int x)
	{
		if(tail == NULL)
		{
			cout<<"ERROR:The List is Empty\n";
			return;
		}

		Node *head = tail->next, *nodeToDelete;
		if(head->getData() == x)
		{
			if(head == tail)
			{
				tail = NULL;
				delete head;
				return;
			}

			tail->next = tail->next->next;
			delete head;
			return;
		}
		
		do
		{
			if(head->next->getData() == x)
			{
				if(head->next == tail)
				{
					tail = head;
				}
				nodeToDelete = head->next;
				head->next = nodeToDelete->next;
				delete nodeToDelete;
				return;
			}
			head = head->next;
		}
		while(head!=tail);

		cout<<"\nElement not Found\n";
	}	
};

int main()
{
	int key,temp,temp1,n;
	SCLL ll;
	while(1)
	{
		cout<<"\nSingly Circular Linked List: ";
		ll.Print();
		cout<<
			"\nOption:1-Insert at Head\n"
			"Option:2-Insert at Tail\n"
			"Option:3-Insert after\n"
			"Option:4-Insert before\n"
			"Option:5-Delete\n"
			"Option:6-Exit\n"
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
					ll.Insert(temp);
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
				cout<<"\nEnter the element to be inserted followed by the previous element ";
				cin>>temp1>>temp;
				ll.Insert(temp1,temp,"After");
				break;
			case 4:
				cout<<"\nEnter the element to be inserted followed by the next element ";
				cin>>temp1>>temp;
				ll.Insert(temp1,temp,"Before");
				break;
			case 5:
				cout<<"\nEnter the element to delete\n";
				cin>>temp;
				ll.Delete(temp);
				break;
			case 6:
				return 0;
			default:
				cout<<"Select a valid Option";
				break;
		}
		cout<<"\n";
	}		
	return 0;
}