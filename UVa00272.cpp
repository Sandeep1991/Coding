#include <bits/stdc++.h>

/*HN
*UVa00272
 * This is MagicWish :)
 */
using namespace std;

int main()
{
	string s;
	int f=0;
	while(getline(cin,s))
	{
		string t;
		for(int i=0;i<(int)s.length();i++)
		{
			if(s[i]=='"' && !f)
			{	t+='`'; t+='`';f=1; }
				
			else if(s[i] =='"' && f)
			{	t +='\''; t+='\''; f=0;}
			else
				t += s[i];
		}
		cout<<t<<endl;
	}
	return 0;
}
