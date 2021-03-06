//Codechef palindrome https://www.codechef.com/problems/DPC206 
#include <iostream>
#include <bits/stdc++.h>
 
using namespace std;
 
int RN(int n)
{
	int a = 0;
	while(n)
	{
		a = a * 10 + n % 10;
		n = n/10;
	}
	return a;
}
bool palin(int n)
{
	if(n==RN(n)) return true;
	else return false;
}
void compute(int n)
{
	int cnt = 0;
	while(palin(n)==false)
	{
		cnt++;
		n = n + RN(n);
	}
	cout<<cnt<<" "<<n;
}
 
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int a;
		cin>>a;
		compute(a);
		cout<<endl;
	}
	return 0;
}
		
