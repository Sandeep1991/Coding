#ifdef MAC
#include <stdc++.h>
#else
#include <bits/stdc++.h>
#endif

using namespace std;
typedef long long ll;

vector<double>hp(1002,0);

/*
 * This is a famous probability problem known as coupon collectors problem
 * There is an approximation formula to do this:
 * E(x) = n ln n + n * 0.577216 + 0.5
 * It gives right answer for n >= 5
 * My approach is DP somewhat similar to Fibonacci calculation
 */ 

void extend(int m, int n)
{
	for (int i=m+1;i<=n;i++)
	{
		double rat = 1.0/i;
		hp[i] = hp[i-1] + rat;
	}
}

int main()
{
	int t,pk=1;
	cin>>t;
	hp[0] = 0;
	hp[1] = 1;
	while(t--)
	{
		int k;
		cin>>k;
		if (pk<k)
		{
			extend(pk,k);
			pk = k;
		}
		double ans = k * hp[k];
		printf("%0.2f\n",ans);
	}
	return 0;
}
		
		
