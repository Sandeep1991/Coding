//This code works unmodified for both LASTDIG and LASTDIG2
#ifdef MAC
#include <stdc++.h>
#else
#include <bits/stdc++.h>
#endif

using namespace std;
typedef unsigned long long ll;

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		//ll d,e;
		//scanf("%llu %llu",&d,&e);
		string d;
		ll e;
		cin>>d>>e;
		//int u = d % 10;
		int u = d[d.length()-1] - '0';
		int rep[] = {-0,-1,4,4,2,-5,-6,4,4,2};
		int ans,k;
		if (rep[u]>0 && e!=0)
		{
			k = e % rep[u];
			k = k==0 ? rep[u] : k;
			ans = pow(u,k);
			ans = ans % 10;
		}
		else if (e == 0)
			ans = 1;
		else
			ans = abs(rep[u]);
		printf("%d\n",ans);
	}
	return 0;
}
		
		
