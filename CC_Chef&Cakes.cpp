//www.codechef.com/problems/EGRCAKE

#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;

int gcd(ll a, ll b)
{
	if(a>b) swap(a,b);
	if(a==0) return b;
	return gcd(a,b%a);
}

int main()
{
	ios_base::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--)
	{
		ll m,n;
		cin>>n>>m;
		ll d = n / gcd(n,m);
		if(d==n) cout<<"Yes"<<endl;
		else cout<<"No "<<d<<endl;
	}
	return 0;
}
			
			
