#include <iostream>
#include <bits/stdc++.h>
using namespace std;


#define ll long long
long long hashMap(std::vector<std::string> queryType, std::vector<std::vector<int>> query) {
    map<ll,ll>m;
    int i = 0;
    vector<int>vm;
    for (;i<queryType.size();i++)
    {
        string s = queryType[i];
        if (s=="insert")
        {
            m[query[i][0]] = query[i][1];
            vm.push_back(query[i][0]);
        }
        else if (s=="get")
        {
            return m[query[i][0]];
        }
        else if (s=="addToKey")
        {
            //map<ll,ll>t;
            //vector<ll>kdel;
            for (auto it=vm.begin();it!=vm.end();it++)
            {
                m[*it+query[i][0]] = m[*it];
                //auto z = m.find(it->first);
                //m.erase(z);
                //kdel.push_back(it->first);
            }
            
        }
        else if (s=="addToValue")
        {
            //map<ll,ll>t;
            for (auto it=m.begin();it!=m.end();it++)
            {
                m[it->first] = it->second + query[i][0];
            }
            
        }
        //i++;
    }
    return 0;
}

int main() {
	// your code goes here
	vector<string>r ={"insert", "insert", "addToValue", "addToKey","get"};
	vector<vector<int> > m = {{1, 2}, {2, 3}, {2}, {1},{3}};
	cout<<hashMap(r,m)<<endl;
	
	return 0;
}
