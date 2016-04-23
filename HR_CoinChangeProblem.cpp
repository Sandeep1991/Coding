//Hacker rank DP problem
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;


int main() {
    long int m,n;
    cin>>n>>m;
    long int arr[m];
    for(long int i=0;i<m;i++)
    {
        cin>>arr[i];
    }
    long int table[n+1];
    memset(table,0,sizeof(table));
    table[0] =1;
    for(long int i=0;i<m;i++)
    {
        for(long int j=arr[i];j<=n;j++)
            table[j] += table[j-arr[i]];
    }
    cout<<table[n]<<endl;
    return 0;
}

