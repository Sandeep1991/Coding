//Hacker Earth MST Prim's Algorithm O((V+E)log(V))

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int MAX = 1e4+5;
typedef pair<ll,int> PII;
vector<PII>adj[MAX];
bool marked[MAX];

ll prim(int x)
{
	priority_queue<PII,vector<PII>,greater<PII> >Q;
	int y;
	ll minimumCost = 0;
	PII p;
	Q.push(make_pair(0,x));
	while(!Q.empty())
	{
		//Select the edge with min weight
		p = Q.top();
		Q.pop();
		x = p.second;
		//Cycle check
		if(marked[x] == true)
			continue;
		minimumCost += p.first;
		marked[x] = true;
		for(int i=0;i<(int)adj[x].size();i++)
		{
			y=adj[x][i].second;
			if(marked[y]==false)
				Q.push(adj[x][i]);
		}
	}
	return minimumCost;
}

int main()
{
	int nodes,edges,x,y;
	ll weight, minimumCost;
	cin>>nodes>>edges;
	for(int i=0;i<edges;i++)
	{
		cin>>x>>y>>weight;
		adj[x].push_back(make_pair(weight,y));
		adj[y].push_back(make_pair(weight,x));
	}
	//Selecting 1 as the starting node
	minimumCost = prim(1);
	cout<<minimumCost<<endl;
	return 0;
}

