//https://www.codechef.com/problems/KNPSK


#include <iostream>
#include <bits/stdc++.h>

// Using priority queues as this greedy algo requires us to use the bigges amongst the given elements
typedef long long int ll;
using namespace std;
priority_queue<ll> odd, even,taken_odd, taken_even;
ll sumC = 0,currW=0;

int main()
{
	ll n;
	cin>>n;
	int w;
	ll c;
	ll m=0;
	for(ll i=0;i<n;i++)
	{
		cin>>w>>c;
		if(w%2!=0) odd.push(c);
		else even.push(c);
		m += w;
	}
	for(ll w=1;w<=m;w++)
	{   
 		while(currW+1<=w && odd.size() > 0) //Given odd weights equals only one or nothing
		{
			ll c = odd.top(); odd.pop();
			taken_odd.push(-c);
			sumC += c;
			currW += 1;
		}
		while(currW+2<=w && even.size() > 0) //Given even weights equals only two or nothing
		{
			ll c = even.top();even.pop();
			taken_even.push(-c);
			sumC += c;
			currW += 2;
		}
		while(true)
		{
			if(taken_odd.size()<1)break;
			if(even.size()<1) break;
			if(currW + 1 > w) break;
			ll a = -taken_odd.top(); taken_odd.pop();
			ll b = even.top();even.pop();
			if(a<b)
			{
				taken_even.push(-b);
				odd.push(a);
				sumC += b - a;
				currW += 1;
			}
			else
			{
				taken_odd.push(-a);
				even.push(b);
				break;
			}
		}
		while(1)
		{
			if(taken_odd.size()<2) break;
			if(even.size()<1) break;
			ll a = -taken_odd.top(); taken_odd.pop();
			ll b = -taken_odd.top(); taken_odd.pop();
			ll c = even.top(); even.pop();
			if(a+b<c)
			{
				taken_even.push(-c);
				odd.push(a);
				odd.push(b);
				sumC += c - (a+b);
			}
			else
			{
				taken_odd.push(-a);
				taken_odd.push(-b);
				even.push(c);
				break;
			}
		}
		cout<<sumC<<" ";
	}
	return 0;
}
