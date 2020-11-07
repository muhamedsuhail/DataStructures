/*
  Adjacency Matrix Based Implementation of Graph

  If |V| is n then |E| will be atmost n^2

  Operation                       Time Complexity  

  Finding Adjacent Nodes  		    O(|V|) 
  
  Check if given Nodes              O(1)   - Constant time
  are connected

  where,
  	|E| - Number of Edges
  	|V| - Number of Vertices

  Time Complexity is reduced by using adjacency matrix

  But Adjacency Matrix is not efficient in terms of Space.
  Space Complexity - O(n^2)

  E.g: If our graph deals with 100 vertices,
  adjacency matrix will be vacant to store 10000 edges. Consider we have 10 edges in our graph.
  Then we will be storing weights for 10 edges along with a bunch of redundant information. 

  This can be avoided by using Adjacency List.

*/

#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;

// Declaring a Dynamic array to store the vertices
vector<string> vertices;

/* 
  Declaring a matrix to store whether vertices are connected(Adjacency Matrix)
  If two vertices are connected then the position in matrix corresponding
  to the vertices will be marked with the weight of the edge
*/
vector<vector<int>> edges; 

// Function to Create a new Vertex
void CreateVertex(string tempLabel)

// Function to Create a new Edge(Connect two vertices)
void CreateEdge(string vertexLabel1, string vertexLabel2, int weight);

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

				CreateVertex(tempLabel);

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

void CreateVertex(string vertexLabel)
{
	// Update the new vertex to the array of vertices
	vertices.push_back(vertexLabel);

	// Adding a row and column for the new vertex

	if(edges.size() != 0)
	{
		// Fill the new row with Infinity for all columns except for the newly created vertex
		// 
		// E.g: If there are 3 vertices before creating new vertex fill in the 
		// 4th row of adjacency matrix(newly created vertex) with infinity for 3 columns.
		edges.push_back(vector<int> (vertices.size()-1,INT_MAX));
	}
	else
	{
		// If there are no edges create an empty array for the new vertex
		edges.push_back(vector<int> ());
	}

	// Insert a new column for the new vertex and initialize it to infinity
	for(int i=0;i<edges.size();i++)
	{
		edges[i].push_back(INT_MAX);
	}
}

// Function to Create a new Edge(Connect two vertices)
void CreateEdge(string vertexLabel1, string vertexLabel2, int weight)
{
	int start = GetIndex(vertexLabel1);
	int end = GetIndex(vertexLabel2);
	if(start == -1 || end == -1)
	{
		cout<<"\nERROR:Invalid vertices";
		return;
	}

	// Mark the connected vertices in adjacency matrix
	// This is an undirected graph
	edges[start][end] = edges[end][start] = weight;
	
	// For directed graph
	// edges[start][end] = weight;
}

// Function to find adjacent nodes of a node(vertex)
vector<string> FindAdjacentNodes(string vertexLabel)
{
	// Array to store adjacent vertices
	vector<string> AdjacentVertices;
	
	// Fetch the index of the node(As we store index of vertex as Edge terminals)  
	int index = GetIndex(vertexLabel);
	
	for(int i = 0;i<edges[index].size();i++)
	{
		if(edges[index][i] != INT_MAX)
		{
			// Insert labels of all the nodes which are connected with the given node
			AdjacentVertices.push_back(vertices[i]);
		}
	}

	return AdjacentVertices;
}

// Function to check if two nodes are connected 
bool IsConnected(string vertexLabel1, string vertexLabel2)
{
	// Fetch the index of the node(As we store index of vertex as Edge terminals)  
	int Start = GetIndex(vertexLabel1);
	int End = GetIndex(vertexLabel2);

	if(Start == -1 || End == -1)
	{
		cout<<"\nERROR:Invalid vertices";
		return false;
	}

	// If the position at adjacency matrix is not infinity return true
	return ((edges[Start][End]!=INT_MAX)?true:false);
}