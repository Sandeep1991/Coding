//Hacker rank grid challenge

#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		string a[100] = {};
		
		for(int i=0;i<n;i++)
		{
			cin>>a[i]; 
			sort(a[i].begin(),a[i].end());
		}
		int flag = 0;
	for(int i=1;i<n;i++)
    {
        for(int j=0; j<n; j++)
		{
			if(a[i][j] < a[i-1][j])
				flag = 1;
		}
    }
        
		if(!flag) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
    
	}
	return 0;
}
