//Hacker rank day 14 challenge
//https://www.hackerrank.com/challenges/30-scope

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Difference {
    private:
    vector<int> elements;
  
  	public:
	int maximumDifference;
  	Difference(vector<int>a)
        {
        elements = a;
    }
    int computeDifference()
    {
    int diff=0; 
    maximumDifference=-2147483648; 
    for(int j=0; j<elements.size();j++)
     {
    for(int i=0; i<elements.size() && i!=j; i++)
     {
        diff = abs(elements[j]-elements[i]);
        if(maximumDifference<diff) maximumDifference = diff;
      }
    } 
    return maximumDifference;
    }
    
    }; // End of Difference class

int main() {
    int N;
    cin >> N;
    
    vector<int> a;
    
    for (int i = 0; i < N; i++) {
        int e;
        cin >> e;
        
        a.push_back(e);
    }
    
    Difference d(a);
    
    d.computeDifference();
    
    cout << d.maximumDifference;
    
    return 0;
}
