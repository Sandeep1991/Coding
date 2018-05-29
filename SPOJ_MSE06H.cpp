/*
Good example of how BIT comes in handy!
*/

#ifdef MAC
#include <stdc++.h>
#else
#include <bits/stdc++.h>
#endif

using namespace std;
typedef long long ll;

ll bit[1001];

struct eg{
	int e;
	int w;
};

typedef struct eg edg;
edg edge[1000000];

bool comp(edg e1, edg e2)
{
	if (e1.e == e2.e) return e1.w < e2.w;
	return e1.e<e2.e;
}

void update(int x, int val)
{
	for(;x<=val;x+=x&-x)
		bit[x] ++;
}

ll query(int x)
{
	ll sum = 0;
	for (;x>0;x -= x &-x)
		sum += bit[x];
	return sum;
}

int main()
{
	int t,cas=0;
	scanf("%d",&t);
	ll ans = 0;
	while(t--)
	{
		cas ++;
		int n,m,k;
		scanf("%d %d %d",&n,&m,&k);
		for (int i=1;i<=m;i++) bit[i] = 0;
		for (int i=0;i<k;i++)
			scanf("%d %d",&edge[i].e, &edge[i].w);
		sort(edge, edge+k, comp);
		ans = 0;
		for (int i=0;i<k;i++){
			ans += query(m-edge[i].w);
			update(m-edge[i].w+1,m);
		}
		printf("Test case %d: %lld\n",cas,ans);
	}
	return 0;
}
		
