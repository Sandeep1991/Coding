#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;

/* Program by MagicWish :)
CC contest 01/06/2017 */


int main()
{
	cin.sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--)
	{
		ll cat,dog,legs;
		cin>>cat>>dog>>legs;
		ll k = cat - 2 * dog;
		k = k > 0 ? k : 0;
		if((cat>0 || dog>0)&&legs<4)
			cout<<"no"<<endl;
		else if(legs%4==0 && legs >= (dog + k) * 4 && legs <= (dog + cat) * 4)
			cout<<"yes"<<endl;
		else
			cout<<"no"<<endl;
	}
	return 0;
}
