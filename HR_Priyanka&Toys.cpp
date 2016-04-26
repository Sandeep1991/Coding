//Hacker Rank Priyanka and toys challenge Greedy!!


#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

#define ll long long int
using namespace std;


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */    
    //int t;
    //cin>>t;
    //while(t--)
    //{
        ll n;
        cin>>n;
        if(n==0) {
			cout<<"0"<<endl;
			return 0;}
        vector<ll> v;
        for(ll i =0; i < n ; i++)
         {
            ll l;
            cin>>l;
            v.push_back(l);
        }
        ll cnt = 0;
        
        sort(v.begin(),v.end());
        ll k = v[0];
        for(ll i=0; i <n; i++)
        {
            if(v[i]<=k+4);
            else{
                cnt++;
                k = v[i];
			}
        }    
        cnt++;
        cout<<cnt<<endl;
    //}
    return 0;
}
