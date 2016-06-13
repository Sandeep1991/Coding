https://www.codechef.com/SNCKPB16/problems/ENTEXAM

#include <iostream>
#include <bits/stdc++.h>

typedef long long int ll;

using namespace std;

int main()
{
	ll t;
	cin>>t;
	while(t--)
	{
		ll k, n,m;
		ll e;
		cin>>n>>k>>e>>m;		
		vector<ll>sum(n-1);
		fill(sum.begin(),sum.end(),0);
		for(ll i=0;i<n-1;i++)
		{
			for(ll j=0;j<e;j++)
			{
				ll sc;
				cin>>sc;
				sum[i] += sc;
			}
		}
		ll iSum=0;
		for(ll i=0;i<e-1;i++)
		{
			ll iSC;
			cin>>iSC;
			iSum += iSC;
		}
		
		std::sort(sum.rbegin(),sum.rend());
	
		std::vector<ll>::iterator it = sum.begin();
		//for(;it!=sum.end();it++)
			//cout<<*it<<" ";
		//cout<<endl;
		ll diff;
		//if(n<=k) 
		//{
			//cout<<"0"<<endl;
			//continue;
		//}
		
		int ind = (int)k-1;
		ll no = sum[ind];
		//cout<<iSum<<" "<<no<<endl;
		diff = no - iSum;

		if(diff<0)
		{
			cout<<"0"<<endl;
			continue;
		}
		
		if((diff+1)<=m)
		cout<<(diff+1)<<endl;
		else
		cout<<"Impossible"<<endl;
		
		
	}
	return 0;
}
