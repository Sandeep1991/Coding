#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int t;
    cin >> t;
    for(int a0 = 0; a0 < t; a0++){
        int n;
        int c;
        int m;
        cin >> n >> c >> m;
        int wrap, rem_wrap, choc,choc_extra;
        choc = n/c;
        wrap = choc;
        do{
            rem_wrap = wrap % m;
            choc_extra = wrap / m;
            choc = choc + choc_extra;
            wrap = rem_wrap + choc_extra;
        } while(wrap>=m);
        cout<<choc<<endl;
    }
    return 0;
}
