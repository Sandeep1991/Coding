#Hacker Rank Lisa's workbook


#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


int main() {
    int n,k;
    cin>>n>>k;
    int a[n]={};
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    int pg=1,cnt=0,prcnt=0,flag=0;
    for(int l=0;l<n;l++){
		//cout<<a[l]<<" ";
    for(int i=1;i<=a[l];i++)
    {
    	flag = 0;
		//cout<<pg<<" ";
        if(i==pg) cnt++;
        //if(i%k==0) pg++; 
        prcnt++;
        if(prcnt == k)
		{
		
        	pg++;
        	flag = 1;
        	prcnt = 0;
    	}
    }
    if(!flag){
	prcnt = 0;
    pg++;
	}
    
    //cout<<cnt<<endl;
}
    cout<<cnt<<endl;
    return 0;
}
