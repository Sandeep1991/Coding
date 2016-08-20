//Hacker earth Unreachable nodes

#include <bits/stdc++.h>

using namespace std;


vector<int>adj[100001];
bool visited[100001];

void dfs(int s)
{
	visited[s] =true;
	for(int i=0;i<(int)adj[s].size();i++)
	{
		if(visited[adj[s][i]]==false)
			dfs(adj[s][i]);
	}
}

void initialize()
{
	for(int i=0;i<10;i++)
	{
		visited[i]=false;
	}
}
	
int main()
{
	int nodes,edges,x,y;//,connectedComponents=0;
	cin>>nodes>>edges;
	for(int i=0;i<edges;i++)
	{
		cin>>x>>y;
		adj[x].push_back(y);
		adj[y].push_back(x);
	}
	initialize();
	int s;
	cin>>s;
	dfs(s);
	int cnt=0;
	for(int i=1;i<=nodes;i++)
	{
		if(visited[i]==false) cnt++;
	}
	cout<<cnt<<endl;
	/*for(int i=1;i<=nodes;i++)
	{
		if(visited[i]==false)
		{
			dfs(i);
			connectedComponents++;
		}
	}
	cout<<connectedComponents<<endl;
	*/
	return 0;
}
