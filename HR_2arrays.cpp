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
        int n,k,l;
        cin>>n>>k;
        vector<int> a;
        vector<int> b;
        for(int i=0;i<n;i++)
        {
            cin>>l;
            a.push_back(l);
        }
        for(int j=0; j<n; j++)
        {
			cin>>l;
            b.push_back(l);
        }
        sort(a.begin(),a.end());
        sort(b.rbegin(),b.rend());
        int cnt=0;
        for(int i=0;i<n;i++)
         {
            if(a[i]+b[i] == k)
                cnt++;
            
        }
        if(cnt == n) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
    return 0;
}
