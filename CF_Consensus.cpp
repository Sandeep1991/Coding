/* A number of candidates are running for office. Each one has official positions on many issues, and these positions are given as a string, where the ith character is a position on the ith issue. A position can be Yes ('Y'), No ('N'), or undecided ('?').

A consensus position is one where all candidates either agree or are undecided. While candidates can be undecided, a consensus position cannot be (i.e. it can't contain a '?' position on any issue).

Given positions of the candidates, your job is to figure out in how many ways the candidates can reach consensus.

Example

For candidate_positions = ["Y??", "??N"], the output should be
Consensus(candidate_positions) = 2.
There're two consensus positions: "YYN" and "YNN".

For candidate_positions = ["Y", "N"], the output should be
Consensus(candidate_positions) = 0.
It's impossible to reach consensus in this example.

Input/Output

[time limit] 500ms (cpp)
[input] array.string candidate_positions

Array of strings of the same length. Each string contain only characters 'Y', 'N' or '?'.

Constraints:
1 ≤ candidate_positions.length ≤ 16,
1 ≤ candidate_positions[i] ≤ 16.

[output] integer

The number of the position sets that all candidates can agree upon.*/




#include<iostream>
#include<bits/stdc++.h>

using namespace std;

int Consensus(std::vector<std::string> candidate_positions) {
    std::string s;
 for(int i=0;i<candidate_positions[0].length();i++)
     s += '?';
 cout<<s<<endl;
    for(int i=0;i<candidate_positions.size();i++)
 {
     for(int j=0;j<s.length();j++)
     {
         char a = candidate_positions[i][j];
         if(s[j]=='?')
             s[j] = a;
         else if(s[j] == 'Y' && a == 'N')
             return 0;
         else if(s[j] == 'N' && a == 'Y')
             return 0;
         else
             s[j] = 'a';
     }
 }
int cnt=0;
 for(int i=0;i<s.length();i++)
 {
     if(s[i] == '?')
         cnt++;
 }
    return pow(2,cnt);
}


int main()
{
	vector<string>v;
	v.push_back("Y");
	v.push_back("N");
	cout<<Consensus(v)<<endl;
}
