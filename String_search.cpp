//This is an alternative approach to finding the substring in linear time compared to KMP but at the cost of extra space.
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
	string s1,s2;
	cin>>s2;
	cin>>s1;
	map<string,int>m;
	m[s2]++;
	//int cnt=0;
	//int j=0;
	char c = s2[0];
	int len = (int)s1.length()-(int)s2.length();
	int s2l = (int)s2.length();
	for(int i=0;i<=len;i++)
	{
		if(s1[i]==c)
		{
			string k = s1.substr(i,s2l);
			//cout<<k<<endl;
			m[k]++;
		}
	}
	cout<<m[s2]-1<<endl;
    return 0;
}
