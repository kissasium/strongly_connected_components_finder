// **********************************************************
// **********************************************************

/*                  GROUP MEMBERS                     */
/*
 
            Aliza Ibrahim    i21-0470
            Faiza Rehman     i21-0836
            Kalsoom Tariq    i21-2487
            Kissa Zahra      i21-0572
 
 */
// **********************************************************
// **********************************************************

#ifndef Header_h
#define Header_h

#include <iostream>
#include <cstdlib>
#include <list>
#include <iterator>
#include <stack>
#include <map>
using namespace std;

class Undirected_Graph
{
    // map object to know the status of node
    map<int,bool>visited;
    // map object containing Adjacency list
    map<int,list<int>> Adjacency_list;

    // Performs DFS and fills the stack in a given order
    void FillStack_inOrder(int , stack<int>&);
    // A recursive function to find the size of each SCC
    int SCC_Size(int&,int);
  
    // Returns an object containing Transpose of graph
    Undirected_Graph Transpose();

public:
    
     //The Function to be called from main to invoke code
      void Size_of_LargestSCC();
    
    // Adding Edges in Graph between nodes
    void addEdge(int,int);
 
};

// **********************************************************
// **********************************************************

/*                  FUNCTION DEFINITIONS                      */

// **********************************************************
// **********************************************************

void Undirected_Graph::addEdge(int a, int b)
{
    Adjacency_list[a].push_back(b);
}

// The Function to print the size of largest SCC
void Undirected_Graph::Size_of_LargestSCC()
{
    // Initialize a stack object
    stack<int> Stack;
 
    // Making a status variable array for each Vertex
    // Initialize them to false in order to apply the DFS technique
    //bool *visited = new bool[Vertices];
    for(auto i : Adjacency_list)
    {
        visited[i.first] = false;
    }
       
 
    // Filling Adjacent nodes in stack in Post-order Traversal
    for(auto i : Adjacency_list)
    {
        // Check to avoid running DFS for nodes
        //already visited in previous DFS traversals
        if(visited[i.first] == false)
        {
            FillStack_inOrder(i.first , Stack);
        }
            
    }
       
 
    // Making a Transpose Adjacency list
    // The logic here is to change the edge Direction
    // in order to detect SCC in second DFS
    
    Undirected_Graph Transpose_graph = Transpose();
 
    // Mark all the vertices as not visited (For second DFS)
    for(auto i : Adjacency_list)
    {
        visited[i.first] = false;
    }
        
    int max=0;
    int count=0;
    // Now process all vertices in order defined by Stack
    while (Stack.empty() == false)
    {
        count = 0;
        // Pop a vertex from stack
        int V = Stack.top();
        Stack.pop();

        // Find Size of each SCC
        if (visited[V] == false)
        {
            Transpose_graph.SCC_Size(count, V);

            // Compare size and update Maximum
            if (count > max)
            {
                max = count;
            }
        }
    }
    
    cout<<max<<endl;
}

// Kosaraju Algorithm
void Undirected_Graph::FillStack_inOrder(int vertex, stack<int> &Stack)
{
    //Update Status Flag of Current Node
    
    visited[vertex] = true;
 
   //Recursive code for all adjacent vertices
    list<int>::iterator i;
    
    for(i = Adjacency_list[vertex].begin(); i != Adjacency_list[vertex].end(); ++i)
    {
        if(!(visited[(*i)]))
        {
            FillStack_inOrder(*i, Stack);
        }
           
    }
    //Fill Stack on return
    Stack.push(vertex);
}

Undirected_Graph Undirected_Graph::Transpose()
{
    // Creating a temporary object of Undirected_Graph class
    // in order to store the transpose List
    Undirected_Graph g;
    
    // Start Loop from 0 to no of vertices in adjacency list
    for (auto V : this->Adjacency_list)
    {
        // Initialize an iterator for list
        list<int>::iterator i;
        for(i = Adjacency_list[V.first].begin(); i != Adjacency_list[V.first].end(); ++i)
        {
            //Copying vertex in (y,x) fashion
            g.Adjacency_list[*i].push_back(V.first);
        }
    }
    
    return g;
}

int Undirected_Graph::SCC_Size(int& count, int V)
{
    // update visited Status
    visited[V] = true;
    // Increment Count
    count++;
    
    // Recursion for SCC
    list<int>::iterator i;
    for (i = Adjacency_list[V].begin(); i != Adjacency_list[V].end(); ++i)
    {
        if (!visited[*i])
        {
            SCC_Size(count,*i);
        }
           
    }
    return count;
}



#endif /* Header_h */
