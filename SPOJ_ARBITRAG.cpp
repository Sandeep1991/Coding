#ifdef MAC
#include <stdc++.h>
#else
#include <bits/stdc++.h>
#endif

#include <unordered_map>

using namespace std;

typedef long long int ll;

bool floyd_warshall(vector<vector<double> >&mat)
{
	int n = mat.size();
	for (int k=0;k<n;k++)
	{
		for (int i=0;i<n;i++)
		{
			for (int j=0;j<n;j++)
			{
				if (mat[i][k] * mat[k][j] > mat[i][j])
					mat[i][j] = mat[i][k] * mat[k][j];
			}
		}
	}
	for (int i=0;i<n;i++)
		if (mat[i][i] > 1.0)
			return true;
	return false;
}


int main()
{
	int cse = 1;
	while(1)
	{
		int k;
		cin>>k;
		if (k==0)
			break;
		map<string,int>m;
		vector<vector<double> > mat(k,vector<double>(k)); //stores the exchange value between currencies
		for (int i=0;i<k;i++)
		{
			string s;
			cin>>s;
			m[s] = i;
		}
		int edg;
		cin>>edg;
		for (int j=0;j<edg;j++)
		{
			string a,c;
			double b;
			cin>>a>>b>>c;
			mat[m[a]][m[c]] = b;
		}
		bool f = floyd_warshall(mat);
		cout<<"Case "<<cse<<": ";
		if (f)
			cout<<"Yes\n";
		else
			cout<<"No\n";
		cse++;
	}
	return 0;
}
	
