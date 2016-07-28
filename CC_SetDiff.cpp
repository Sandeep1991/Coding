//https://www.codechef.com/problems/SETDIFF
#include <iostream>
#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;

ll mod = 1e9+7;
int main()
{
	ll t;
	cin>>t;
	while(t--)
	{
		ll n;
		cin>>n;
		vector<ll>v(n);
		for(ll i=0;i<n;i++)
		{
			ll a;
			cin>>a;
			v[i]=a;
		}
		sort(v.begin(),v.end());
		ll p=0, q=0;
		for(ll i=0;i<n;i++)
		{
			p = (2*p+v[i])%mod;
			q = (2*q+v[n-i-1])%mod;
		}
		cout<<(q+mod-p) % mod<<endl;
	} 
	return 0;
}
