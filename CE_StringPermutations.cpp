//All Permutations of a given string iterative approach
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int fact(int n)
{
    return (n<=1)? 1 : n*fact(n-1);
}
void permute(string s)
{
    int n = s.length();
    std::vector<std::string>v;
	if(n==2)
	{
		v.push_back(s);
		swap(s[0],s[1]);
		v.push_back(s);	
	} 
	else if(n==1||n==0)
	{
		v.push_back(s);
	}
	else
	{
		int fc = fact(n);
	    int j = 1;
	    int m = 0;
	 	
	    for (int perm_c = 0; perm_c < fc; )
	    {
	        string perm = s;
	        int k = 0;
	        while (k != fc/n)
	        {
	            while (j != n-1)
	            {
	                v.push_back(perm);
	 
	                swap(perm[j], perm[j+1]);
	                k++;
	                perm_c++;
	                j++;
	            }
	            j = 1;
	        }
	        m++;
	        if (m == n)
	           break;
	        swap(s[0], s[m]);
	    }
	}
    sort(v.begin(),v.end());
    cout<<v[0];
    for(int i=1;i<v.size();i++)
    	cout<<","<<v[i];
    cout<<endl;
}

int main()
{
	string line = "2DR@";
	permute(line);
	//print()
}
