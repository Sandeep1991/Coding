#include <bits/stdc++.h>

using namespace std;


map<string,int>m;
map<string,int>::iterator it;
map<string,int> permute(string s, int l, int r)
{
	//int i;
	
	if(l==r)
		m[s]++;
	else
	{
		for(int i=l;i<=r;i++)
		{
			swap(s[l],s[i]);
			permute(s,l+1,r);
			swap(s[l],s[i]);
		}
	}
	//for(it=m.begin();it!=m.end();it++)
		//cout<<it->first<<" ";
	//cout<<endl;
	return m;
}


int main()
{
	string s = "aab";
	int n = s.length();
	map<string,int>v;
	map<string,int>::iterator it;
	v=permute(s,0,n-1);
	//for(int i=0;i<(int)v.size();i++)
		//cout<<v[i]<<" ";
	for(it=v.begin();it!=v.end();it++)
			cout<<it->first<<" ";
	cout<<endl;
	return 0;
}
