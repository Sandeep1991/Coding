//HR Absolute permuation
//https://www.hackerrank.com/challenges/absolute-permutation


#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,k;
		cin>>n>>k;
		vector<int>a(n+1),b(n+1);
		for(int i=1;i<=n;i++)
            b[i] = 0;
		for(int i=1;i<=n;i++)
		{
			a[i]=i;
		}
		int f = 0;
		if(k==0) f = 1;
		if(!f && n%k!=0){cout<<-1<<endl; continue;}
		if(k==0)
		{
			for(int i=1;i<=n;i++)
			cout<<a[i]<<" ";
			cout<<endl; continue;
		}
		for(int i=1;i<=n;i++)
		{
			if(i+k<=n&&a[i]==abs(a[i+k]-k)&&b[i]==0)
			{
				b[i]=a[i+k];
				b[i+k]=a[i];
			}
		}
		
		for(int i=1;i<=n;i++)
		{
			cout<<b[i]<<" ";
		}
		cout<<endl;
		
	}
	return 0;
}
