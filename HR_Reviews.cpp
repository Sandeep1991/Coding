//Hacker Rank Reviews challenge
//https://www.hackerrank.com/contests/booking-passions-hacked-backend/challenges/reviews

#include <bits/stdc++.h>
#include <regex>

using namespace std;
typedef long long int ll;

int wordCount(string s)
{
	int cnt = 0;
	for(int i=0;i<s.length();i++)
	{
		if(s[i]==' ') cnt++;
	}
	return (cnt+1);
}
int date(ll d)
{
	if(d>=1465948800 && d<=1468540800)
		return 20;
//	else if(d<1465948800)
//		return 10;
	else return 0;
}

struct comment{
	ll r,d;  //id and time of comment
	string s; // comment string
	//int count = wordCount(s);
	//int dt = date(d);
	vector<int>points;
};
// 15 th june 2016 GMT is 1465948800
// 15 th july 2016 GMT is 1468540800

int main()
{
	int n,m;
	cin>>n>>m;
	vector<regex>v(n);
	for(int i=0;i<n;i++)
	{
		string s1; //word we are searching in comments
		cin>>s1;
		int l = s1.length();
		string rep; rep += '[';
		rep += s1[0]; rep += s1[0] - 'A' + 'a'; rep += ']';
		rep += s1.substr(1,l-1);
		v[i] = rep;
	}
	vector<comment>c(m);
	for(int i=0;i<m;i++)
	{
		cin>>c[i].r>>c[i].d;
		cin.ignore();
		getline(cin,c[i].s);
	}
	//Calculate the points for each person and each word
	smatch mat;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			if(regex_search(c[j].s,mat,v[i]))
			{
				int p = 10;
				if(wordCount(c[j].s)>= 100) p+=20; //change to 100
				p+=date(c[j].d);
				c[j].points.push_back(p); 
			}
			else c[j].points.push_back(0);
		}
	}
	/*for(int j=0;j<m;j++)    //m no of strings
	{
		for(int i=0;i<c[j].points.size();i++)
			cout<<c[j].points[i]<<" ";
		cout<<endl;
	}*/
	/*map<int,int>ma;
	for(int j=0;j<n;j++)
	{
		for(int i=0;i<m;i++)
		{
			m[c[i].r]+=c[i].points[j];
				
		}
	}*/
	
	
	//------
	for(int j=0;j<n;j++)
	{
		int mx=0, ans = -1;
		map<int,int>ma;
		map<int,int>::iterator it;
		for(int i=0;i<m;i++)
		{
			ma[c[i].r] += c[i].points[j];
		}
		for(it=ma.begin();it!=ma.end();it++)
		{
		//	cout<<it->first<<" "<<it->second;
		//	cout<<endl;
			if(it->second>mx)
			{
				mx = it->second;
				ans = it->first;
			}
			else if(it->second==mx)
			{
				if(ans>it->first)
					ans = it->first;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
//
//
