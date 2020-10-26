// Program to reverse a string or linked list
// Time Complexity - O(n)
// Space Complexity - O(n)

#include<iostream>
#include<string.h>
#include<stack>

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

class Linked_List
{
	private:
		Node* head;
		stack<Node*> S;
	public:
		Linked_List()
		{
			head = NULL;
		}

		void Print()
		{
			Node* temp = head;
			while(temp != NULL)
			{
				cout<<temp->data<<" ";
				temp = temp->next;
			}
			cout<<"\n";
		}

		void Insert(int x)
		{
			Node* newNode = new Node(x);
			newNode->next = head;
			head = newNode;
		}

		void Reverse()
		{
			Node* current = head;
			while(current != NULL)
			{
				S.push(current);
				current = current->next;
			}
			
			current = S.top();
			head = current;
			S.pop();
			while(!S.empty())
			{
				current->next = S.top();
				S.pop();
				current = current->next;
			}
			current->next = NULL;
		}
	
};

void StringReverse(char* C, int n)
{
	stack<char> S;
	
	for(int i=0;i<n;i++)
	{
		S.push(C[i]);
	}
	for(int i=0;i<n;i++)
	{
		C[i] = S.top();
		S.pop();
	}
}

int main()
{
	int key,n,temp;
	cout<<
		   "Option:1-Reverse String\n"
		   "Option:2-Reverse Linked List\n"
		   "Option:3-Exit\n";
	cin>>key;
	switch(key)
	{
		case 1:
		{
			scanf("%d",&n);
			char A[n];
			scanf("%s",A);
			StringReverse(A,strlen(A));
			printf("%s\n",A);
			break;
		}
		case 2:
		{
			Linked_List l;
			cout<<"Enter the number of elements to be inserted: ";
			cin>>n;
			cout<<"\nEnter the elements: ";
			for(int i=0;i<n;i++)
			{
				cin>>temp;
				l.Insert(temp);
			}
			cout<<"\nBefore Reversing: ";
			l.Print();
			l.Reverse();
			cout<<"After Reversing: ";
			l.Print();
			break;
		}
		case 3:
			return 0;
		default:
			cout<<"Select a valid option";
			break;
	}
	return 0;
}