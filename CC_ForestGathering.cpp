//Code Chef Forest Gathering May 2016 Long contest challenge
//https://www.codechef.com/MAY16/problems/FORESTGA
#include <iostream>
#include<bits/stdc++.h>
#define ll long long int
using namespace std;

int main()
{
	ll N, W, L,a,b;
	vector<pair<ll,ll> > T;
	pair<ll,ll> temp;
	
	cin>>N>>W>>L;
	for(ll i=0;i<N;i++)
	{
		
		cin>>a;
		cin>>b;
		temp.first = a;
		temp.second = b;
		T.push_back(temp);
	}
	//ll count = 0;
	//sort(T.rbegin(),T.rend());
	int x=0,sim=0;
	for(int j=1; j<W;j++ )
	{
		sim = 0;
	for(int i=0; i<N;i++)
	{	
		x = T[i].first + T[i].second * j;
		if(x>=L)
			sim += x;
		//cout<<sim<<endl;
		if(sim >= W)
		{
			cout<<j<<endl;
			return 0;
		}
	}
	}
	cout<<sim<<endl;
	/*for(ll i=0,n=1; i < N,n<L; i ++,n++)
	{
		//cout<<T[i].first<<" "<<T[i].second<<endl;
		ll x=0,count=0;
		if(T[i].first+T[i].second*n >= L)
			x = T[i].first+T[i].second * n;
		if(x>=W)
		{
			cout<<count + x<<endl;
			cout<<n<<endl;
			return 0;
		}
		if(i==2) {
		count=0;
		i=0;
		}
	} */
}
