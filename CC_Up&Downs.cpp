//Codechef https://www.codechef.com/problems/ANUUND
// O(N) solution -

#include <iostream>
#include <bits/stdc++.h>
#include <string.h>
#include <cstring>

typedef long long int ll;
using namespace std;


int main()
{
	ll t;
	cin>>t;
	while(t--)
	{
		ll n;
		cin>>n;
		int v[100001] = {};
		for(ll i=1;i<=n;i++)
		{
			ll a;
			cin>>a;
			v[i] = a;
		}
		if(n==2) 
		{
			if(v[1] > v[2]) swap(v[1],v[2]);
		}
		for(ll i=1;i<=n-2;i=i+1) // b>= a && b >= c 
		{
			ll a = v[i]; ll b = v[i+1]; ll c= v[i+2];
			if(i%2!=0)
			{
				if(b<a) swap(v[i+1],v[i]);
				if(b<c) swap(v[i+1],v[i+2]);
			}
			if(i%2==0)
			{
				if(a<b) swap(v[i+1],v[i]);
				if(b>c) swap(v[i+1],v[i+2]);
			}
		}
		for(ll i=1;i<=n;i++)
			cout<<v[i]<<" ";
		cout<<endl;
	}
	return 0;
}
