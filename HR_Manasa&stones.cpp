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
    	int n,a,b,gt,lw;
    	cin>>n; //no. of stones
    	cin>>a;
    	cin>>b;
    	if(a>b)
    	{
    		gt = a;
    		lw = b;
		}
		else 
		{
			gt = b;
			lw = a;
		}
		int ans = lw * (n-1);
		n--;
		int diff = gt - lw;
		cout<<ans<<" ";
		if(diff>0)
		{
			while(n--)
			{
				ans += diff;
				cout<<ans<<" ";
			}
		}
		cout<<endl;
		
	}
    return 0;
}
