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
       int a,b;
       cin>>a>>b;
       int d,e;
        d = ceil(sqrt(a));
        e = sqrt(b);
        cout<<e-d+1<<endl;
    }
    return 0;
}
