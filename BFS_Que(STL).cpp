//Basic BFS implementation in C++


#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>

using namespace std;


void bfs(vector<list<int> >adjList,int parent[], int level[], int start)
{
	list<int>::iterator itr;
	int lev;
	lev = 0;
	level[start] = lev;
	list<int>VQue;
	VQue.push_back(start);
	while(!VQue.empty())
	{
		int newVertex = VQue.front();
		itr = adjList[newVertex].begin();
		while(itr != adjList[newVertex].end())
		{
			if(level[*itr]==-1)
			{
				level[*itr] = lev + 1;
				parent[*itr] = newVertex;
				VQue.push_back(*itr);
			}
			++itr;
		}
		VQue.pop_front();
		++lev;
	}
}


int main()
{
    int vertices, edges, v1, v2, weight;
  
    printf("Enter the Number of Vertices -\n");
    cin>>vertices;
  
    printf("Enter the Number of Edges -\n");
    cin>>edges;
  
    // Adjacency List is a vector of lists.
    vector< list<int> > adjList(vertices + 1);
  
    printf("Enter the Edges V1 -> V2\n");
  
    for (int i = 1; i <= edges; ++i) {
        cin>>v1>>v2;
  
        // Adding Edge to the Directed Graph
        adjList[v1].push_back(v2);
    }
  
    cout<<"\nThe Adjacency List-\n";
    // Printing Adjacency List
    for (int i = 1; i < adjList.size(); ++i) {
        cout<<"adjacencyList "<< i;
  
        list<int>::iterator itr = adjList[i].begin();
  
        while (itr != adjList[i].end()) {
            cout<<"-> "<<*itr;
            ++itr;
        }
        cout<<endl;
    }
  
    int parent[vertices + 1];
    // Each element of Parent Array holds the Node value of its parent
    int level[vertices + 1];
    // Each element of Level Array holds the Level value of that node
  
    for (int i = 0; i <= vertices; ++i) {
        //Initialising our arrays
        parent[i] = 0;
        level[i] = -1;
    }
  
    cout<<"\nEnter the Starting Vertex -\n";
    cin>>v1;
  
    bfs(adjList, parent, level, v1);
  
    //Level Array
    cout<<"\nLevel and Parent Arrays -\n";
    for (int i = 1; i <= vertices; ++i) {
        cout<<"Level of Node " <<i <<"is " <<level[i] <<" Parent is " <<parent[i] <<endl;
    }
  
    return 0;
}
