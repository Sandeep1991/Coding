//Hacker Rank maximum subarray
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,val;
		cin>>n;
		vector<int> a;
		for(int i=0;i<n;i++)
		{
			cin>>val;
			a.push_back(val);
		}
		int sum1 =0,max_now=0, max_prev=0;
		for(int i=0; i<n ;i++)
		{
			if(a[i] > 0)
			{
				sum1 = sum1 + a[i];
			}
			max_now = max_now + a[i];
			if(max_now<0)
			max_now = 0;
			else if(max_prev < max_now)
			max_prev = max_now;
		}
		if(sum1==0){
		sort(a.begin(), a.end(), greater<int>());
		sum1 = a[0];
		max_prev = a[0];
	}
		cout<<max_prev<<" "<<sum1<<endl;
	}		
	return 0;
}

