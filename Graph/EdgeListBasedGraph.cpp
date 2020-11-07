/*
  Edge List Based Implementation of Graph

  If |V| is n then |E| will be atmost n^2

  Operation                       Time Complexity  

  Finding Adjacent Nodes     		   O(|E|) 
  
  Check if given Nodes                 O(|E|)
  are connected

  where,
  	|E| - Number of Edges
  	|V| - Number of Vertices

  If there are n vertices with n^2 edges, 
  Time Complexity will be O(n^2) since every Edge should be checked.
  We can overcome this by using Adjacency Matrix

*/

#include<iostream>
#include<vector>
using namespace std;

class Edge
{
	public:

		// Start and end indices of an Edge
		int start;
		int end;

		// Weight of an Edge
		int weight;

		// Constructor to initialize an Edge
		Edge(int startIndex, int endIndex,int data)
		{
			start = startIndex;
			end = endIndex;
			weight = data;
		}				
};

// Declaring Dynamic arrays to store the Edges and vertices
vector<Edge> edges;
vector<string> vertices;

// Function Prototypes

// Funtion to create an Edge
void CreateEdge(string vertexLabel1, string vertexLabel2, int weight);

// Function to find the index of a vertex in the array
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
	string tempLabel,tempLabel1;
	vector<string> AdjacentVertices;

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

		switch(key)
		{
			case 1:
				cout<<"\nEnter a string to represent the vertex: ";
				cin>>tempLabel;

				// Insert the vertex into the dynamic array
				vertices.push_back(tempLabel);

				break;

			case 2:
				cout<<"\nEnter the labels of vertices to connect: ";
				cin>>tempLabel>>tempLabel1;
				cout<<"\nEnter the weight of the Edge: ";
				cin>>tempWeight;

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
	// This can be reduced by passing the 
	// index of the vertex directly

	for(int i = 0;i < vertices.size();i++)
	{
		if(vertices[i] == vertexLabel)
		{
			return i;
		}
	}
	return -1;
}

// Funtion to create an Edge
void CreateEdge(string vertexLabel1, string vertexLabel2, int weight)
{
	// Fetch the index of the node(As we store index of vertex as Edge terminals)  
	int Start = GetIndex(vertexLabel1);
	int End = GetIndex(vertexLabel2);
	if(Start == -1 || End == -1)
	{
		cout<<"\nERROR:Invalid vertices";
		return;
	}
	// tempEdge is a pointer pointing to newly created Edge
	Edge* tempEdge = new Edge(Start, End, weight);

	// Insert the newly created edge to dynamic array
	edges.push_back(*tempEdge);
}

// Function to find adjacent nodes of a node(vertex) - O(|E|)
vector<string> FindAdjacentNodes(string vertexLabel)
{
	vector<string> AdjacentNodes;

	// Fetch the index of the node(As we store index of vertex as Edge terminals)  
	int index = GetIndex(vertexLabel);
	if(index == -1)
	{
		cout<<"\nERROR:Invalid vertices";
		return AdjacentNodes;
	}
	for(int i = 0;i < edges.size();i++)
	{
		if(vertices[edges[i].start] == vertices[index])
		{
			AdjacentNodes.push_back(vertices[edges[i].end]);
		}
		else if(vertices[edges[i].end] == vertices[index])
		{
			AdjacentNodes.push_back(vertices[edges[i].start]);	
		}
	}
	return AdjacentNodes;
}

// Function to check if two nodes are connected - O(|E|)
bool IsConnected(string vertexLabel1, string vertexLabel2)
{
	int Node1 = GetIndex(vertexLabel1);
	int Node2 = GetIndex(vertexLabel2);
	
	if(Node1 == -1 || Node2 == -1)
	{
		cout<<"\nERROR:Invalid vertices";
		return false;
	}

	for(int i = 0;i < edges.size();i++)
	{
		if((edges[i].start == Node1 && edges[i].end == Node2)
			|| (edges[i].start == Node2 && edges[i].end == Node1))
			return true;
	}
	return false;
}
