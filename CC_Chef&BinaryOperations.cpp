//https://www.codechef.com/JUNE16/problems/BINOP

#include <iostream>
#include <bits/stdc++.h>
typedef long long int ll;

using namespace std;

int main()
{
	ll t;
	cin>>t;
	cin.ignore();
	while(t--)
	{
		std::string a,b;
		getline(cin,a);
		getline(cin,b);
		ll c0 = 0, c1 = 0,d1=0,d0=0;
		ll f0=0, f1=0,cnt=0,bflag=0;
		if(a.length() != b.length())
		{
			cout<<"Unlucky Chef"<<endl;
			bflag = 1;
		}
		if(!bflag)
		{
		
			for(ll i=0;i<b.length();i++)
			{
				if(a[i] == '1')
					c1++;
				else
					c0++;
				if(b[i] == '1')
					d1++;
				else
					d0++;	
				if(a[i]=='0' && b[i] =='1')
				{
					f0++;
					if(f1>0)
					{
						f1--;
						f0--;
						cnt++;
					}
				}
				if(a[i]=='1' &&b[i] =='0')
				{
					f1++;
					if(f0>0)
					{
						f1--;
						f0--;
						cnt++;
					}
				}
			}
			cnt = cnt + f0 + f1;
			//cout<<c1;
			if((a.length() == c1 && c1 != d1) || (a.length() == c0 && c0 != d0))
				cout<<"Unlucky Chef"<<endl;
			else
				{
					cout<<"Lucky Chef"<<endl;
					cout<<cnt<<endl;
				}
		}
	}
}
