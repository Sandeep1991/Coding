// Hacker rank Caesar cipher challenge

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    int k;
    cin >> k;
    if(k>26) k = k % 26;
    for(int i=0;i<n;i++)
    {
    	if(s[i]>=65&&s[i]<=90 || s[i]>=97 && s[i]<=122)
    	{
    		if(s[i]>=65&&s[i]<=90 && (int(s[i])+k) > 90)
    			s[i] = char(int(s[i]) + k - 90 + 64);	
    		else if (s[i]>=97 && s[i]<=122 && (int(s[i])+k) > 122)
    			s[i] = char(int(s[i]) + k - 122 + 96);
    		else
				s[i] = char(int(s[i]) + k);
    		
		}
    		
		else
			s[i] = s[i];
	}
    cout<<s<<endl;
    return 0;
}
