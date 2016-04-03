#include<iostream>
#include<cstring>
#include<string>
using namespace std;

int main()
{
	int c;
	cin>>c;
	while(c--)
	{
		string a,b;
		cin>>a;
		cin>>b;
		int cnt=0;
		for(int i=0;i<a.length();i++)
		{
			if(a[i]==b[0])
			{
				int k = i;
				cnt = cnt+1;
				i++;
				for(int j=1;j<b.length();j++)
				{
					
					if(a[i] == b[j])
					{
					
					cnt = cnt + 1;
					i++;
					}
					//else 
					//{
						//cnt = 0;
						//i = k;
						//break;
					//}
				}
				if(cnt == b.length())
				{
					cout<<1<<endl;
					return 0;
				}
				else 
				{
					cnt = 0;
					i = k;
					//break;
				}
				
			}	
			
		}
		
		cout<<0<<endl;
		return 0;
	}
}
