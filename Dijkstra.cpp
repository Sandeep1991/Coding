#ifdef MAC
#include <stdc++.h>
#else
#include <bits/stdc++.h>
#endif

#include <unordered_map>

using namespace std;

typedef vector<int> vi;
typedef pair<int,int> pii;
typedef vector< pii > vii;
#define INF 0x3f3f3f3f
 
vector<vii>G;   // Graph
vi Dist;  // for storing the distance of every other node from source.
/*==========================================*/
void Dijkstra(int source, int N) {
    priority_queue<pii, vector<pii>, greater<pii> > Q;   // min heap
    Dist.assign(N,INF);
    Dist[source] = 0;
    Q.push({0,source});
    while(!Q.empty()){
        int u = Q.top().second;
        Q.pop();
        for(auto &c : G[u]){
            int v = c.first;
            int w = c.second;
            if(Dist[v] > Dist[u]+w){
                Dist[v] = Dist[u]+w;
                Q.push({Dist[v],v});
            }
        }
    }
}

int main()
{
	int n,m;
	cin>>n>>m;
	//G = new vii[n+1];
	G.resize(n+1);
	int u,v,w,s;
	for (int i=0;i<m;i++)
	{
		cin>>u>>v>>w;
		G[u].push_back({v,w});
		G[v].push_back({u,w});
	}
	s = 1;
	Dijkstra(s,n+1);
	for (int i=2;i<=n;i++)
	{
		cout<<Dist[i]<<" ";
	}
	cout<<endl;
	return 0;
}
