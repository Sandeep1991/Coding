/*GalaxyAZ uses its very own numeric system. Instead of using certain integers (base 1-10) as well as certain letters (A-F for base 16, for example), they use letters to label different bases.

Base Z is base 1
Base Y is base 2
Base X is base 3
...
Base B is base 25
Base A is base 26
They also use a different numbering for bases greater than 10: 'Z' equals 10, 'Y' equals 11, and so on.

Given a number in base10 and a base (letter), return the value of number in base without leading zeroes.

Example

For number = 10 and base = 'A', the output should be
GalaxyAZ(number, base) = "Z".

Input/Output

[time limit] 500ms (cpp)
[input] integer number

An integer.

Constraints:
4 ≤ number ≤ 109.

[input] char base

An uppercase English letter ('A' - 'Y').

[output] string

The value of number in the given base.
*/


#include <iostream>
#include <bits/stdc++.h>

using namespace std;

std::string GalaxyAZ(int number, char base) {
    std::map<char,int>alp;
    int no = number;
    char ch = base;
    int val=1;
	for(char i='Z';i>='A';i--)
		alp[i]=val++;
    std::string rem;
    while(no>=alp[ch]){
        int q = no % alp[ch];
        if(q > 9)
        {
            rem = char(90+(10-q)) + rem;
        }
        else
        {   
            rem = std::to_string(q) + rem;
            
        }
        no = no / alp[ch];
    }
    if(no>9 && no<alp[ch])
        rem = char(90+(10-no));
    else
		rem = std::to_string(no) + rem;
    
	return rem;
}


int main()
{
	cout<<GalaxyAZ(4,'Y')<<endl;	
	cout<<GalaxyAZ(10,'A')<<endl;
	cout<<GalaxyAZ(3049032,'P')<<endl;
}
