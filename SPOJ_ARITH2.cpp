#ifdef MAC
#include <stdc++.h>
#else
#include <bits/stdc++.h>
#endif

using namespace std;
typedef long long ll;

int main()
{
	int t;
	cin>>t;
	cin.ignore();
	while(t--)
	{
		string s,buf,ks;
		
		getline(cin,s);
		if (s.length() == 0) 
			getline(cin,s);
		stringstream ss(s);
		queue<string>vtok;
		while(ss>>buf)
			vtok.push(buf);
		ll ans = 0,opf=0, oper = 0;
		while (!vtok.empty())
		{
			ks = vtok.front();
			//cout<<ks<<" ";
			vtok.pop();
			if (ks == "+")
				opf = 0;
			else if (ks == "-")
				opf = 1;
			else if (ks == "*")
				opf = 2;
			else if (ks == "/")
				opf = 3;
			else if (ks == "=")
				opf = 4;
			else 
			{
				oper = stoi(ks);
				if (opf == 0)
					ans += oper;
				else if (opf == 1)
					ans -= oper;
				else if (opf == 2)
					ans *= oper;
				else if (opf == 3)
					ans /= oper;
			}
		}
		cout<<ans<<endl;	
	}
	return 0;
}
		
