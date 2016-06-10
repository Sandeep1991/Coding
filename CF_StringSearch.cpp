#include <stdio.h>
#include <conio.h>
#include <string.h>

int row=4,col=5;

int occur(char a[][5],int x,int y,char targ[],int index,int n)
{
	if(x<0||y<0||x>=row||y>=col)
		return 0;
	if(index>n)
		return 0;
	if(a[x][y]!=targ[index])
	{
			return 0;
	}
	if(index==strlen(targ)-1)
	{
		return 1;
	}
	return (occur(a,x,y+1,targ,index+1,n)	
		+occur(a,x+1,y,targ,index+1,n)
		+occur(a,x-1,y,targ,index+1,n)
		+occur(a,x,y-1,targ,index+1,n));
		
}
int count(char a[][5],char targ[])
{
	int d=0;
	for(int i=0;i<row;i++)
	{
		for(int j=0;j<col;j++)
		{
			if(a[i][j]=='S')
				d+=occur(a,i,j,targ,0,strlen(targ)-1);
		}
	}
	return d;
}

int main()
{
	char a[][5]={{'S','N','B','S','N'},{'B','A','K','E','A'},{'B','K','B','B','K'},{'S','E','B','S','E'}};
	char c[]={"SNAKES"};
	printf("No of occurences are %d ",count(a,c));

}
