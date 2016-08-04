//https://www.hackerrank.com/challenges/gem-stones


#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;
int main()
{
	int n;
	cin>>n;
	map<char,int>m;
	map<char,int>::iterator itr;
	int k = n;
	while(n--)
	{
		string s;
		cin>>s;
		set<char>st;
		set<char>::iterator it;
		
		for(int i=0;i<(int)s.length();i++)
		{
			st.insert(s[i]);
		}
		for(it=st.begin();it!=st.end();it++)
		{
			m[*it]++;
		}
	}
	int cnt = 0;
	for(itr=m.begin();itr!=m.end();itr++)
	{
		if(itr->second == k)
			cnt++;
	}
	cout<<cnt<<endl;
	return 0;
}
