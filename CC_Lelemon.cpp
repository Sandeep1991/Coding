//https://www.codechef.com/problems/LELEMON

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int v[10000][10000] = {0};
int c[10000] = {0};
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,m;
		cin>>n>>m;
		vector<int>p(m);
		fill(p.begin(),p.end(),0);
		for(int i=0;i<m;i++)
		{
			int a;
			cin>>a;
			p[a]++;
		}
		for(int i=0;i<n;i++)
		{
			cin>>c[i];
			for(int j=0;j<c[i];j++)
			{
				cin>>v[i][j];
			}
			sort(v[i],v[i]+c[i]);
			reverse(v[i],v[i]+c[i]);
		}
		int res=0;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<min(c[i],p[i]);j++)
			{
				res += v[i][j];
			}
		}
		cout<<res<<endl;
	}
	return 0;
} 
		
		
