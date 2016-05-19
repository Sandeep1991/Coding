//https://www.codechef.com/problems/TWTCLOSE
#include <iostream>
#include <cstring>
#include <bits/stdc++.h>
 
using namespace std;
 
int main()
{
	int n,k;
	cin>>n>>k;
	//cin.ignore();
	vector<int> v(n);
	for(int i=0;i<n;i++)
		v[i]=0;
	for(int i=0;i<k;i++)
	{
		string s;
		cin>>s;
		int num;
		if(s.compare("CLICK") == 0)
		{
			{
				cin>>num;
			}
			num = num -1;
			v[num] ^= 1;
			int cnt=0;
			for(int i=0; i < n;i++)
			{
				if(v[i]==1) cnt++;
			}
			cout<<cnt<<endl;
		 }
		 else if(s.compare("CLOSEALL") == 0)
		 {
			 for(int i=0;i<n;i++)
				v[i]=0;
			cout<<"0"<<endl;
		  }
	}
	return 0;
}

