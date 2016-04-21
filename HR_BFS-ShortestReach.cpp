//Hacker Rank BFS Shortest reach challenge
#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

vector<int> adj[1000];
int dis[1000];
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int vertices, edges;
		cin>>vertices>>edges;
		for(int i=0; i <edges ; i++)
		{
			int v1, v2;
			cin>>v1>>v2;
			v1--; v2--;
			adj[v1].push_back(v2);
			adj[v2].push_back(v1);
		}
		int start;
		cin>>start;
		start--;
		queue<int> q;
		q.push(start);
		memset(dis, -1, sizeof(dis));
		dis[start] = 0;
		while(!q.empty())
		{
			int u = q.front(); 
			q.pop();
			for(unsigned int i=0; i <adj[u].size(); i++)
			{
				int v = adj[u][i];
				if(dis[v] == -1)
				{
					dis[v] = dis[u] + 1;
					q.push(v);
				}
			}
		}
		for(int i=0; i<vertices; i++)
		{
			if(i==start) continue;
			else if(dis[i]==-1) cout<<dis[i]<<" ";
			else cout<<dis[i] * 6<<" ";
		}
		cout<<endl;
		for(int i=0; i<vertices; i++)
		{
			adj[i].clear();
		}
	}
	return 0;
}
