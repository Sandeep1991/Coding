#include <iostream>

using namespace std;


int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string ch;
		int cnt=0;
		cin>>ch;
		for(unsigned int i=1; i<ch.size() ; i++)
		{
			if(ch[i] == ch[i-1])
				cnt++;
		}
	cout<<cnt<<endl;
	}
	return 0;
}
