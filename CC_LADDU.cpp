//CodeChef May 2016 Long contest LADDU challenge
//https://www.codechef.com/MAY16/problems/LADDU

#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int act,rank,bf,LAD=0;
		bool tc;
		string nation,nat[2];
		cin>>act;
		cin>>nation;
		//cin.ignore();
		//cin.ignore();
		
		for(int i=0;i<act;i++)
		{
			
			for(int j=0;j<2;j++)
			{
				cin>>nat[j];
				if(strcmp(nat[j].c_str(),"TOP_CONTRIBUTOR")==0)
				{
					LAD = LAD + 300;
					//cout<<LAD<<endl;					
					j =2;
				}
				else if(strcmp(nat[j].c_str(),"CONTEST_HOSTED")==0)
				{
					LAD = LAD + 50;
					//cout<<LAD<<endl;
					j = 2;
				}
				else if(strcmp(nat[j].c_str(),"CONTEST_WON")==0)
				{
					j=1;
					if(j==1) {
					cin>>nat[j];
					rank = atoi(nat[j].c_str());
					//cout<<rank<<endl;
					if(rank < 20) LAD = LAD + 300 +20 - rank;
					else LAD = LAD +300;
					//cout<<LAD<<endl;
					}
				}
				else if(strcmp(nat[j].c_str(),"BUG_FOUND")==0)
				{
					j++;
					if(j==1) {
					cin>>nat[j];
					bf = atoi(nat[j].c_str());
					LAD = LAD + bf;
					//cout<<LAD<<endl;
					}
				}
				
			}			
		}
		//cout<<LAD<<endl;
		if(strcmp(nation.c_str(),"INDIAN")==0)
			cout<<LAD/200<<endl;
		else
			cout<<LAD/400<<endl;
	}
	return 0;
}
	
