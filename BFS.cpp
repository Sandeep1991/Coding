//This is a simple BFS program using list stl.
#include<iostream>
#include<list>

using namespace std;

class Graph
{
  int V; //No of vertices
  list<int> *adj; //Pointer to array containing adjacency list
public:
  Graph int V; //Constructor
  void addEdge(int v, int w); //function to add an edge to graph
  void BFS(int s); //function to print a BFS from starting edge s
}

Graph::Graph(int V)
{
  this->V = V;
  adj = new list<int>[V]
  }

void Graph::addEdge(int v, int w)
{
  adj[v].push_back(w); //add w to v's list
}

void Graph::BFS(int s)
{
  bool *visited = new bool[V];
  for(int i=0; i<V; i++)
    visited[i] = false;
  //Create a queue for BFS
  list<int> queue;
  
  //Mark the current node as visited and enqueue it
  visited[s] = true;
  queue.push_back(s);
  //i will be used to get all the adjacent vertices of s
  list<int>::iterator i;
  while(!queue.empty())
  {
    s = queue.front();
    cout<< s <<" ";
    queue.pop_front();
    
    //Get all adjacent vertices of the dequeued vertex s
    //If an adjacent vertex has not been visisted, then mark it visited 
    //and enqueue it
    
    for(i=adj[s].begin(); i!=adj[s].end();i++)
    {
      if(!visited[*i])
      {
        visited[*i] = true;
        queue.push_back(*i);
      }
    }
  }
}

//Driver program to test methods of given class
int main()
{
  //Create a graph given in the above diagram
  Graph g(4);
  g.addEdge(0,1);
  g.addEdge(0,2);
  g.addEdge(1,2);
  g.addEdge(2,0);
  g.addEdge(2,3);
  g.addEdge(3,3);
  cout<<"Following is the BFS starting from the start node 2\n"
  g.BFS(2)
  cout<<endl;
  
  return(0);
}

  
  
    
    
  
