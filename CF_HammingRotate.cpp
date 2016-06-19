//8.3 Generate all subsets of a given set

#include <iostream>
#include <bits/stdc++.h>

using namespace std;
std::string rightrot(std::string s)
{
    std::string t; 
    int n = s.length()-1;
    t = s[n];
    s.erase(n);
    return (t+s);
}

int Hamming_Rotate(std::string a, std::string b) {
    int n = a.length();
    int cret = 0;
    int min = 9876;
    int rot=0;
    if(b.compare(a)==0)
        return 0;
    int cnt =0;
    for(int i=0;i<n;i++)
        {
            if(a[i]!=b[i])
                cnt++;
        }
    min = cnt;
    cret = 0;
    std::string temp = a;
    a = rightrot(a);
    while(temp.compare(a)!=0)
    {
        rot++;
        int cnt=0;
        for(int i=0;i<n;i++)
        {
            if(a[i]!=b[i])
                cnt++;
        }
        
        if(min>cnt) 
        {
            min = cnt;
            cret = rot;
        }
        a = rightrot(a);
        cout<<a<<endl;
    }
    return cret;
    
}


int main()
{
	string a,b;
	cin>>a>>b;
	//cout<<Hamming_Rotate("10010011","00100101")<<endl;
	//cout<<Hamming_Rotate("010","101")<<endl;	
	//cout<<Hamming_Rotate("1","0")<<endl;
	//cout<<Hamming_Rotate("11","11")<<endl;
	cout<<Hamming_Rotate(a,b)<<endl;
	return 0;
}
