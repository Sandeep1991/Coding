#include <stdc++.h>

using namespace std;

struct coord{
	int x;
	int y;
};
/*
0 1 0 1 0       1 0 1 0 1     0 0 0 0 0
1 0 0 0 1       0 1 1 1 0     0 1 0 1 0
0 0 K 0 0   -   1 1 Q 1 1  -  0 0 P 0 0  
1 0 0 0 1       0 1 1 1 0     0 0 0 0 0
0 1 0 1 0       1 0 1 0 1     0 0 0 0 0
*/ 
#define check_range(x,y,m,n) ((x>=0 && x<m && y>=0 && y<n) ? 1 : 0)          
void Queen(vector<vector<int> >&board, int x, int y, int m, int n)
{
	//Queen movements
	//[i][j+1], [i][j-1], [i+1][j+1], [i+1][j-1], [i+1][j], [i-1][j+1], [i-1][j], [i-1][j-1]
    int i=x,j=y;
    //cout<<"Queen"<<endl;
    /*for (int i=0;i<m;i++)
	{
		for (int j=0;j<n;j++)
			cout<<board[i][j]<<" ";
		cout<<endl;
	}*/
	//cout<<x<<" "<<y<<endl;
	j = y+1;
    while (check_range(i,j,m,n) && board[i][j] < 2) //i,j+1 1
    {
		//cout<<board[i][j]<<" ";
		//if (board[i][j]<2)
			board[i][j++] = 1;
		//else
		//	break;
		//j++;
	}
	i=x+1;j= y;
	while (check_range(i,j,m,n) && board[i][j] < 2) //i+1,j 2
    {
		//if (board[i][j]<2)
			board[i++][j] = 1;
		//else
		//	break;
		//i++;
	}
	i=x+1;j=y+1;
	while (check_range(i,j,m,n) && board[i][j] < 2) //i+1,j+1 3
    {
		//if (board[i][j]<2)
			board[i++][j++] = 1;
		//else
		//	break;
		//i++;j++;
	}
	i=x;j=y-1;
	while (check_range(i,j,m,n) && board[i][j] < 2) //i,j-1 4
    {
		//if (board[i][j]<2)
			board[i][j--] = 1;
		//else
		//	break;
		//j--;
	}
	i=x-1;j=y;
	while (check_range(i,j,m,n) && board[i][j] < 2) //i-1,j 5
    {
		//cout<<board[i][j]<<" ";
		//if (board[i][j]<2)
			board[i--][j] = 1;
		//else
		//	break;
		//i--;
	}
	i=x-1;j=y-1;
	while (check_range(i,j,m,n) && board[i][j] < 2) //i-1,j-1 6
    {
		//if (board[i][j]<2)
			board[i--][j--] = 1;
		//else
		//	break;
		//i--;j++;
	}
	i=x-1;j=y+1;
	while (check_range(i,j,m,n) && board[i][j] < 2) //i-1,j+1 7
    {
		//if (board[i][j]<2)
			board[i--][j++] = 1;
		
		//i--;j++;
	}
	i=x+1;j=y-1;
	while (check_range(i,j,m,n) && board[i][j] < 2) //i+1,j-1 8
    {
		//if (board[i][j]<2)
			board[i++][j--] = 1;
		//else
		//	break;
		//i++;j--;
	}
	/*i=x;j=y;
	for (int i=0;i<m;i++)
	{
		for (int j=0;j<n;j++)
			cout<<board[i][j]<<" ";
		cout<<endl;
	}*/
}
void Knight(vector<vector<int> >&board, int i, int j, int m, int n)
{
	//[i-2][j+1] [i+2][j+1] [i+2][j-1] [i-2][j-1] [i+1][j+2] [i-1][j+2] [i+1][j-2] [i-1][j-2]
	//cout<<"Knight"<<endl;
	if (check_range(i-2,j+1,m,n) && board[i-2][j+1] < 2)
		board[i-2][j+1] = 1;
	if (check_range(i+2,j+1,m,n) && board[i+2][j+1] < 2)
		board[i+2][j+1] = 1;
	if (check_range(i+2,j-1,m,n) && board[i+2][j-1] < 2)
		board[i+2][j-1] = 1;
	if (check_range(i-2,j-1,m,n) && board[i-2][j-1] < 2)
		board[i-2][j-1] = 1;
	if (check_range(i+1,j+2,m,n) && board[i+1][j+2] < 2)
		board[i+1][j+2] = 1;
	if (check_range(i-1,j+2,m,n) && board[i-1][j+2] < 2)
		board[i-1][j+2] = 1;
	if (check_range(i+1,j-2,m,n) && board[i+1][j-2] < 2)
		board[i+1][j-2] = 1;
	if (check_range(i-1,j-2,m,n) && board[i-1][j-2] < 2)
		board[i-1][j-2] = 1;
}

int main()
{
	int m,n; //m rows and n cols
	int trial = 0;
	while(1)
	{
		scanf("%d %d",&m,&n);
		if (m==0 && n==0)
			break;
		trial++;
		int t;
		cin>>t;
		vector<vector<int> >board(m,vector<int>(n,0));
		vector<coord>vq(t);
		for (int i=0;i<t;i++)
		{
			cin>>vq[i].x>>vq[i].y;
			vq[i].x = vq[i].x-1;vq[i].y = vq[i].y-1;
			board[vq[i].x][vq[i].y] = 2;
			
		}
		cin>>t;
		vector<coord>vk(t);
		for (int i=0;i<t;i++)
		{
			cin>>vk[i].x>>vk[i].y;
			vk[i].x = vk[i].x-1;vk[i].y = vk[i].y-1;
			board[vk[i].x][vk[i].y] = 3;
		}
		cin>>t;
		vector<coord>vp(t);
		for (int i=0;i<t;i++)
		{
			cin>>vp[i].x>>vp[i].y;
			vp[i].x = vp[i].x-1;vp[i].y = vp[i].y-1;
			board[vp[i].x][vp[i].y] = 4;
		}
		
		for (int pq=0; pq < vq.size(); pq++)
		{
			//for (int i=v[pq].x;i<m;i++)
			//{
			Queen(board,vq[pq].x,vq[pq].y,m,n);
		}
		for (int pk=0; pk < vk.size(); pk++)
		{
			Knight(board,vk[pk].x,vk[pk].y,m,n);
		}
		/*for (int pp=0; pp < vp.size(); pp++)
		{
			if(check_range(vp[pp].x-1, vp[pp].y-1, m, n) && board[vp[pp].x-1][vp[pp].y-1] < 2)
				board[vp[pp].x-1][vp[pp].y-1] = 1;
			if(check_range(vp[pp].x-1, vp[pp].y+1, m, n) && board[vp[pp].x-1][vp[pp].y+1] < 2)
				board[vp[pp].x-1][vp[pp].y+1] = 1;
		}*/
		int cnt = 0;
		for (int i=0;i<m;i++)
		{
			for (int j=0;j<n;j++)
			{
				if (!board[i][j])
				{
					//cout<<i<<" "<<j<<endl;
						cnt++;
				}
			}
		}
		/*for (int i=0;i<14;i++)
		{
			for (int j=0;j<14;j++)
				cout<<board[i][j]<<" ";
		cout<<endl;
		}*/
		printf("Board %d has %d safe squares.\n", trial, cnt);	
					
	}
	return 0;
}
		
