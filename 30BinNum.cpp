//HR-https://www.hackerrank.com/challenges/30-binary-numbers
//The challenge was to get number of adjacent set bits('1')
#include <iostream>
#include <cstring>
#include <string>
#include <bits/stdc++.h>

using namespace std;

/* binary(int n)
{
	string bin("");
	if(n <= 1)
	{
		string res;
		ostringstream convert;
		convert << 1;
		res = convert.str();
		bin = res+bin;
		return bin;
	}
	string res;
	ostringstream convert;
	convert << n%2;
	res = convert.str();
	bin = res+bin;
	n = n/2;
		
}*/

int main()
{
	long long int n;
	cin>>n;
	string a = bitset<32>(n).to_string();
	long long int cnt=0,max=0;
	//cout<<a<<endl;
	for(long long int i=0;i<a.length();i++)
	{
		//cout<<a[i]<<" ";
		if(a[i]=='1')
		{
			//cout<<"Hello";
			cnt = cnt + 1;
			if(max<cnt)max=cnt;
			//cout<<cnt<<endl;
		}
		
		else 
		{
			cnt=0;
		}
	}
	cout<<max<<endl;
}
