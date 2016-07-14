//Codechef Little Elephant https://www.codechef.com/problems/SUBMIN

#include <iostream>
#include <bits/stdc++.h>
#include <limits.h>
typedef long long int ll;
using namespace std;

ll A[51] = {0};

int main()
{
	//int t;
	//cin>>t;
	//while(t--)
	//{
		int n;
		cin>>n;
		for(int i=0;i<n;i++)
		{
			int a;
			cin>>a;
			A[i]=a;
		}
		int nq;
		cin>>nq;
		for(int k=0;k<nq;k++)
		{
			ll q;
			cin>>q;
			int cnt = 0,lcnt=0;
			for(int i=0;i<n;i++)
			{
				int f=0,m;
				for(int j=i;j<n;j++) //moving right
				{
					if(!f && A[i] == q)
					{
						m=i;
						cnt++;
						f = 1;
						while(A[--m] > q) lcnt++; //moving left
						continue;
					}
					if(f && A[j]>=q)
						{cnt++;continue;}
					if(f && A[j]<q)
						{f=0;break;}
				}
			}
			ll ans = lcnt * cnt + cnt;
			cout<<ans<<endl;
		}	
	//}
	return 0;
}
