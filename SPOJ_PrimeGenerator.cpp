/*
PRIME1 - Prime Generator
#number-theory
Peter wants to generate some prime numbers for his cryptosystem. Help him! Your task is to generate all prime numbers between two given numbers!

Input

The input begins with the number t of test cases in a single line (t<=10). In each of the next t lines there are two numbers m and n (1 <= m <= n <= 1000000000, n-m<=100000) separated by a space.

Output

For every test case print all prime numbers p such that m <= p <= n, one number per line, test cases separated by an empty line.

Example

Input:
2
1 10
3 5

Output:
2
3
5
7

3
5
Warning: large Input/Output data, be careful with certain languages (though most should be OK if the algorithm is well designed)
Information

After cluster change, please consider PRINT as a more challenging problem

*/


#include<iostream>
#include<cmath>
using namespace std;

int prime(int n)
{
	bool prime = true;
	//int a[100] = {0};
	if(n%2==0)
	{
		prime = false;
		return 0;
		//exit;
	}
	else for(int i=3;i<=sqrt(n);i++)
	{
	
		if(n%i==0){
		
			prime = false;
			//exit;
			return 0;
		}
	}
	if (prime == true)
	return n;
}
int main()
{
	int c;
	cin>>c;
	while(c--)
	{
		int a,b,d[100]={0},i,j,k;
		cin>>a;
		cin>>b;
		
		k = b - a;
		for(i =a;i<=b;i++)
		{
			if(i==1);
			//d[i] = 0;
			else if(i==2)
			cout<<i<<endl;
			else{
			
			d[i]=prime(i);
			if(d[i]!=0)
			cout<<d[i]<<endl;
		}
		}
	}
}
