#include <stdc++.h>

using namespace std;
//flood-fill and connected components
int mx = 1001;

int cc=0;

vector<vector<char> >mat(mx,vector<char>(mx));
vector<vector<int> >vis(mx,vector<int>(mx,0));

bool in_range(int i, int j, int m, int n)
{
	if (i >= 0 && i < m && j >= 0 && j < n)
		return 1;
	return 0;
}

void dfs(int i, int j, int m, int n)
{
	if (in_range(i,j,m,n))
	{
		if (vis[i][j])
		{
			cc = vis[i][j];
			return;
		}
		vis[i][j] = cc;
		char k = mat[i][j];
		if (k=='S')
			dfs(i+1,j,m,n);
		if (k=='N')
			dfs(i-1,j,m,n);
		if (k=='E')
			dfs(i,j+1,m,n);
		if (k=='W')
			dfs(i,j-1,m,n);
		vis[i][j] = cc;
	}
}



void initialize(int m,int n)
{
	mat = vector<vector<char> >(m, vector<char>(n));
	vis = vector<vector<int> >(m, vector<int>(n,0));
}


			
int main()
{
	int m,n;
	cin>>m>>n;
	initialize(m,n);
	vector<string>vs(m);
	for (int i=0;i<m;i++)
		cin>>vs[i];
	for (int i=0;i<m;i++)
	{
		for (int j=0;j<n;j++)
			mat[i][j] = vs[i][j];
	}
	int last = 0;
	for (int i=0;i<m;i++)
	{
		for (int j=0;j<n;j++)
		{
			if (!vis[i][j])
			{
				cc = last + 1;
				//cout<<i<<" "<<j<<" "<<mat[i][j]<<endl;
				//check if it is part of some chain
					dfs(i,j,m,n);
					if (cc > last) last++;
			}
		}
	}
	cout<<last<<endl;
	return 0;
}
	
