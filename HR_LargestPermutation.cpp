//O(N) solution

#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long int

using namespace std;

int main()
{
	ll n,k;
	vector<ll> v;
	vector<ll> pos;
	cin>>n>>k;
	for(ll i =0; i<n;i++)
		pos.push_back(0);
	for(ll i=0; i<n; i++)
	{
		ll l;
		cin>>l;
		v.push_back(l);
		pos[v[i]]=i;
	}
	
	//while(k)
	//{
		
		
	for(ll i=0; i<n && k>0  ;i++)
	{
		
		if(v[i] == n-i) {
			continue;
		}
		v[pos[n-i]] = v[i];
		pos[v[i]] = pos[n-i];
		v[i] = n - i;
		pos[n-i] = i;
		k--;
	
	}
	for(ll i=0; i<n ;i++)
	{
		cout<<v[i]<<" ";
	}
	cout<<endl;
	return 0;
}	


//O(kN) solution:
#include <iostream>
#include <vector>
#include <algorithm>
#define ll long long int

using namespace std;

int main()
{
	ll n,k;
	vector<ll> v;
	cin>>n>>k;
	for(ll i=0; i<n; i++)
	{
		ll l;
		cin>>l;
		v.push_back(l);
	}
	ll m=0;
	while(k)
	{
		ll max = v[m],pos=0,flag=0;
		for(ll i=m; i<=n ;i++)
		{
			if(v[i] > max){
				max = v[i];
				pos = i;
				flag = 1;
			}
		}
		if(flag){
		swap(v[pos],v[m]);
		m++;
		k = k -1;
		flag = 0;
		}
		else if (m+1 <=n) m=m+1;
		else k=0;
	
	}
	for(ll i=0; i<n ;i++)
	{
		cout<<v[i]<<" ";
	}
	cout<<endl;
	return 0;
}	


