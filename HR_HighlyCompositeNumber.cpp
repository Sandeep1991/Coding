//HR Highly composite number
//Also termed as Anti-prime number

#include <iostream>
#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;

ll answer(ll n)
{
    ll anti[] = {1, 2, 4, 6, 12, 24, 36, 48, 60, 120}; 
	ll anti11[]= {180, 240, 360, 720, 840, 1260, 1680, 2520, 5040,7560, 10080};
	ll anti1[] = {15120, 20160, 25200, 27720, 45360, 50400, 55440, 83160, 110880, 166320, 221760};
	 ll anti2[] = {277200,332640, 498960, 554400, 665280, 720720, 1081080, 1441440, 2162160,2882880};
	 ll anti3[]={3603600,4324320,6486480,7207200,8648640,10810800,14414400,17297280,21621600}; 
	ll anti4[] = {32432400,36756720,43243200,61261200,73513440,110270160,122522400,147026880,183783600};
	if(n<=120)
	{
		for(ll i=0;i<10;i++)
		{
			if(anti[i]>=n) return anti[i];
		}
	}
	else if(n>21&&n<=10080)
	{
		for(ll i=0;i<11;i++)
		{
			if(anti11[i]>=n) return anti11[i];
		}
	}
	//
	else if(n>10080&&n<=221760)
	{
		for(ll i=0;i<11;i++)
		{
			if(anti1[i]>=n) return anti1[i];
		}
	}
	else if(n>221760&&n<=2882880)
	{
		for(ll i=0;i<10;i++)
		{
			if(anti2[i]>=n) return anti2[i];
		}
	}
	else if(n>2882880&&n<=21621600)
	{
		for(ll i=0;i<9;i++)
		{
			if(anti3[i]>=n) return anti3[i];
		}
	}
	else
	{
		for(ll i=0;i<9;i++)
		{
			if(anti4[i]>=n) return anti4[i];
		}
	}
	
	return -1;
}

	
	
int main()
{
	std::ios::sync_with_stdio(false);
	ll q;
	cin>>q;
	while(q--)
	{
		ll n;
		cin>>n;
		cout<<answer(n)<<endl;
	}
	return 0;
}
