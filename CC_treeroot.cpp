//https://www.codechef.com/problems/TREEROOT
//The task was to find the candidate nodes which can become the root given the sum of their children.
#include <iostream>
#include <bits/stdc++.h>
 
using namespace std;
 
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		vector<int>id(n);
		vector<int>sum(n);
		for(int i=0;i<n;i++)
		{
			cin>>id[i];
			cin>>sum[i];
		}
		int total=0;
		for(int i=0;i<n;i++)
		{
			total -= sum[i];
		}
		for(int i=0;i<n;i++)
		{
			total += id[i];
		}
		cout<<total<<endl;
	}
	return 0;
} 
