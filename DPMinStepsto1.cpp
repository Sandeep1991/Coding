#include<iostream>
using namespace std;
int mem[10]={-1,-1,-1,-1,-1,-1,-1,-1,-1,-1};

int getminsteps(int n)
{
	if(n==1) return 0;
	//cout<<n;
	if(mem[n]!=-1) return mem[n]; 
	int r = 1 + getminsteps(n-1);
	if (n%2==0) r = min(r,1 + getminsteps(n/2));
	if (n%3==0) r = min(r,1 + getminsteps(n/3));
	mem[n] = r;
	return r;
}
int main()
{
	cout<<getminsteps(9)<<endl;
}
