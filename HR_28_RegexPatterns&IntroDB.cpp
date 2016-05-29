//Day 28: RegEx, Patterns, and Intro to Databases
#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <unordered_map>

using namespace std;


int main(){
    int N;
    cin >> N;
    vector<string>v;
    vector<string>::iterator it;
    for(int a0 = 0; a0 < N; a0++){
        string firstName;
        string emailID;
        cin >> firstName >> emailID;
        int pos = emailID.find("@gmail.com");
        if(pos != emailID.npos)
        {
            v.push_back(firstName);
        }
            
    }
    sort(v.begin(),v.end());
    for(it = v.begin();it!=v.end();it++)
    {
        cout<<*it<<endl;
    }
    
    return 0;
}
