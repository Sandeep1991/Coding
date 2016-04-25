//HR DP problem
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

int main()
{
	long long int n;
	cin>>n;
	if(n==0) {
        cout<<"0"<<endl;
        return 0;
    }
	vector<long long int> OPT;
	for(long long int i=0; i<n; i++)
		OPT.push_back(1);
	vector<long long int> v;
	for(long long int i=0; i<n; i++)
	{
		long long int l;
		cin>>l;
		v.push_back(l);
	}
    //cout<<OPT[0]<<" ";
    long long int cnt = 0;
    //memset(OPT, 1, n+1);
    for(long long int i=1; i<n ;i++)
    {
		if(v[i] > v[i-1])
		OPT[i] = OPT[i-1] + 1;
		//cnt = cnt + OPT[i];
		//cout<<OPT[i]<<" ";
	}
	for(long long int j=n-1; j>0; j--)
	{
		if(v[j-1] > v[j]){
		OPT[j-1] = max(OPT[j-1], OPT[j] + 1);
		}
		//cnt = cnt + OPT[j-1];
		
	}
	for(long long int i=0; i<n ;i ++)
	 {
	 //cout<<OPT[i]<<" ";
	 cnt = cnt + OPT[i];
	}
	cout<<cnt<<endl;
	return 0;
}

