#include<iostream>
#include<cmath>
#include<bits/stdc++.h>

using namespace std;

void SieveOfEr(int n)
{
	bool prime[n+1];
	memset(prime, true, sizeof(prime));
	for(int p=2; p*p<=n; p++)
	{
		if(prime[p] == true)
		{
			for(int i = p * 2; i<=n;i+=p)
				prime[i] = false;
		}
	}
	for(int p=2; p<=n;p++)
	
		if(prime[p])
			cout<<p<<" ";
}

int main()
{
	int n=30;
	cout<<"Following are the prime no less than n"<<endl;
	SieveOfEr(n);
	return 0;
}
	
