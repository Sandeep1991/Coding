//Hackerrank Algorithms Stick problem

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> arr(n);
    for(int arr_i = 0;arr_i < n;arr_i++){
       cin >> arr[arr_i];
    }
    int min = arr[0];
    cout<<n<<endl;
    while(n>0)
    {
		int cnt = 0;
		for(unsigned int i = 0; i < arr.size(); i++)
		
			if(arr[i] < min && arr[i] > 0) min = arr[i];
		for(unsigned int i=0; i < arr.size(); i++)
		{
			arr[i] = arr[i] - min;
			if (arr[i] > 0)
				cnt++;
					
		}
		min = 65536;
		if (cnt == 0) break;
		if (cnt == 1){
			cout<<cnt<<endl;
			break;
		}
		cout<<cnt<<endl;
	}			
    return 0;
}
