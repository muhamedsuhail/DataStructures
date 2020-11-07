#include<iostream>
#include<vector>
using namespace std;

class Node
{
public:
	int data; // To store indices of connected nodes
	int weight; // To store weight of the corresponding edge
	Node* next;
	Node(int x,int w)
	{
		data = x;
		weight = w;
		next = NULL;
	}
};

class LinkedList
{
public:
	Node* head;
	LinkedList()
	{
		head = NULL;
	}
	
	void Insert(int data, int weight)
	{
		Node* newNode = new Node(data, weight);
		newNode->next = head;
		head = newNode;
	}
};

// Declaring a Dynamic array to store the vertices and pointer to linked list(Adjacency List)
vector<string> vertices;
vector<LinkedList*> edges;

// Function for creating a new Edge
void CreateEdge(string vertexLabel1, string vertexLabel2, int tempWeight);

// Function to find the Index of a vertex in the array
int GetIndex(string vertexLabel);

// Function to find adjacent nodes of a node(vertex)
vector<string> FindAdjacentNodes(string vertexLabel);

// Function to check if two nodes are connected 
bool IsConnected(string vertexLabel1, string vertexLabel2);

int main()
{	
	int key;
	
	// Declaring temp variables to use inside loop
	int tempWeight, tempStart, tempEnd;
	string tempS, tempLabel, tempLabel1;
	vector<string> AdjacentVertices;
	LinkedList* tempLL;

	while(1)
	{
		cout<<
			"\nOption:1-Create a Vertex\n"
			"Option:2-Create an Edge(Connect two vertices)\n"
			"Option:3-Find Adjacent Nodes of a vertex\n"
			"Option:4-Check if two nodes are connected\n"
			"Option:5-Exit\n"
			"Select an Option: ";
		cin>>key;
		cout<<"\n";
		switch(key)
		{
			case 1:
				cout<<"\nEnter a string to represent the vertex: ";
				cin>>tempLabel;
				vertices.push_back(tempLabel);
				tempLL = new LinkedList;
				edges.push_back(tempLL); 
				break;

			case 2:
				cout<<"\nEnter the labels of vertices to connect: ";
				cin>>tempLabel>>tempLabel1;
				cout<<"\nDo you want to add weight to the edge? [y/n] ";
				cin>>tempS;
				if(tempS == "y")
				{
					cout<<"\nEnter the weight of the Edge: ";
					cin>>tempWeight;
				}
				else
				{
					tempWeight = 0;
				}

				CreateEdge(tempLabel,tempLabel1,tempWeight);
				break;

			case 3:
				cout<<"\nEnter a node label to find it's adjacent nodes: ";
				cin>>tempLabel;
				AdjacentVertices = FindAdjacentNodes(tempLabel);

				if(AdjacentVertices.size() == 0)
				{
					cout<<"\nNo Adjacent Nodes";
					break;
				}
				
				// Print the Adjacent Nodes
				cout<<"\nAdjacent Nodes - ";
				for(int i = 0;i < AdjacentVertices.size();i++)
				{
					cout<<AdjacentVertices[i]<<" ";
				}
				break;

			case 4:
				cout<<"\nEnter any two node labels to check if they are connected: ";
				cin>>tempLabel>>tempLabel1;

				cout<<(IsConnected(tempLabel,tempLabel1)?"\nYes":"\nNo");
				break;

			case 5:
				return 0;
		}
		cout<<"\n";
	}
	return 0;
}

// Function to find the Index of a vertex in the array
int GetIndex(string vertexLabel)
{
	// Fetching index of a node takes O(n) in worst case 
	// This can be reduced by passing the index of the vertex directly

	for(int i = 0;i < vertices.size();i++)
	{
		if(vertices[i] == vertexLabel)
		{
			return i;
		}
	}
	return -1;
}

void CreateEdge(string vertexLabel1, string vertexLabel2, int tempWeight)
{
	int start = GetIndex(vertexLabel1);
	int end = GetIndex(vertexLabel2);
	if(start == -1 || end == -1)
	{
		cout<<"\nERROR:Invalid vertex";
		return;
	}

	// Inserting the edge to the Adjacency List
	// Since we are implementing an undirected graph update both the vertices
	edges[start]->Insert(end,tempWeight);
	edges[end]->Insert(start,tempWeight);	
}

// Function to find adjacent nodes of a node(vertex)
vector<string> FindAdjacentNodes(string vertexLabel)
{
	// Array to store adjacent vertices
	vector<string> AdjacentVertices;
	
	// Fetch the index of the node(As we store index of vertex as Edge terminals)  
	int index = GetIndex(vertexLabel);
	int NodeIndex;panni sonna kelu paakala
	Node* current = edges[index]->head;
	while(current != NULL)
	{
		NodeIndex = current->data;
		AdjacentVertices.push_back(vertices[NodeIndex]);
		current = current->next;
	}

	return AdjacentVertices;
}

// Function to check if two nodes are connected 
bool IsConnected(string vertexLabel1, string vertexLabel2)
{
	// Fetch the index of the node(As we store index of vertex as Edge terminals)  
	int start = GetIndex(vertexLabel1);
	int end = GetIndex(vertexLabel2);
	

	if(start == -1 || end == -1)
	{
		cout<<"\nERROR:Invalid vertices";
		return false;
	}

	// Iterate through the Adjacency List of start Index searching for end Index  
	// Or 
	// Iterate through the Adjacency List of end Index searching for start Index  
	
	Node* current = edges[start]->head;
	while(current != NULL)
	{
		if(current->data == end)
		{
			return true;
		}
		current = current->next;
	}

	return false;
}
