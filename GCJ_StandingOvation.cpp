#include <bits/stdc++.h>

using namespace std;

int main()
{
	cin.sync_with_stdio(false);
	int t;
	cin >> t;
	int i,j;
	for( i = 0; i < t; i++ )
	{
		int smax;
		cin >> smax;
		string input;
		cin >> input;
		int standing = 0;
		int need = 0;
		for( j = 0; j < smax+1; j++ )
		{
			if( input[j] != '0' )
			{
				if( standing < j )
				{
					need += j-standing;
					standing += j-standing;
				}
				standing += input[j]-'0';
			}
		}

		cout << "Case #" << (i+1) << ": " << need << endl;		
	}
	return 0;
}
