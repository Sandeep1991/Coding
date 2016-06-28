//Codefights challenge 
//Game of 15 https://codefights.com/challenge/DRDeYmmEGQMQNsJyb/main

#include<iostream>
#include<bits/stdc++.h>

using namespace std;

bool fifteen_game(std::vector<std::vector<int>> gameboard) {
    int cnt = 0,row;   
    std::vector<int>v;
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
        	if(gameboard[i][j]==0)
        		row = i;
            v.push_back(gameboard[i][j]);
        }
    }
    for(int i=0;i<v.size();i++)
    	cout<<v[i]<<" ";
    cout<<endl;
    cout<<row<<endl;
    for(int i=0;i<v.size();i++)
    {
       // int maxim =v[i];
        for(int j=i+1;j<v.size();j++)
        {
            if(v[i]>v[j] && v[j] != 0)
                cnt++;
        }
    }
    //cnt  = cnt - 1;
    cout<<cnt<<endl;
    if(cnt%2==0 && row % 2 == 0) return false;
    else if(cnt%2!=0 && row % 2 != 0) return false;
    else return true;
}
int main() {
	vector<vector<int>>a(4,vector<int>(4));
	for(int i=0;i<4;i++)
	{
		for(int j=0;j<4;j++)
		{
			int b;
			cin>>b;
			a[i][j] = b;
		}
	}
	cout<<fifteen_game(a);
	return 0;
}
