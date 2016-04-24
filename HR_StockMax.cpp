//HR DP Stock maximisation problem

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int t;
    cin>>t;
    while(t--)
    {
		long long int n;
		cin>>n;
		vector<long long int> v;
		for(int i=0; i<n; i++)
		{
			long long int l;
			cin>>l;
			v.push_back(l);
		}
		long long int MCFP=0, P=0;
		for(int i=n-1;i>=0;i--)
		{
			MCFP = max(MCFP, v[i]);
			P += MCFP - v[i];
		}
		cout<<P<<endl;
	}
    return 0;
}
