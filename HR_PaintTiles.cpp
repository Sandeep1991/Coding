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
//#include <unordered_map>

using namespace std;


int main(){
    int N,cnt=1;
    cin >> N;
    string C;
    cin >> C;
    for(unsigned int i=1;i<C.length();i++)
    {
		if(C[i] != C[i-1])
			cnt++;
	}
	cout<<cnt;
    return 0;
}
