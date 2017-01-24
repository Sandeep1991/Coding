/*
The below code computes fibonacci sequence for very large numbers. As tested works till 5000 as input.
Makes use of string based addition of numbers
*/

#include<bits/stdc++.h>
using namespace std;
string stringAdd(string s1, string s2)
{
  int n1 = s1.length();
  int n2 = s2.length();
  vector<int>num1(n1),num2(n2);
  for (int l1 = 0; l1<n1; l1++)
	num1[l1] = s1[l1] - '0';

  for (int l2 = 0; l2<n2; l2++)
	num2[l2] = s2[l2] - '0';
    
    int n = n1 >= n2 ? n1 : n2;
    vector<int>sum(n);
    int carry = 0;
    int k = 0;
	int i = n1 - 1;
	int j = n2 - 1;
	for (; i >= 0 && j >= 0; i--, j--, k++) {
		sum[k] = (num1[i] + num2[j] + carry) % 10;
		carry = (num1[i] + num2[j] + carry) / 10;
	}
	if (n1 > n2) {

		while (i >= 0) {
			sum[k++] = (num1[i] + carry) % 10;
			carry = (num1[i--] + carry) / 10;
		}

	} else if (n1 < n2) {
		while (j >= 0) {
			sum[k++] = (num2[j] + carry) % 10;
			carry = (num2[j--] + carry) / 10;		
		}
	} else {
		if (carry > 0)
			sum[k++] = carry;
		}
	string ans="";
	for(int i=0;i<k;i++)
	{
		ans = char(sum[i] + '0') + ans;
	}
	return ans;
}
int main()
{
      int n; // size of the array
      cin>>n;
      vector<string>f(n+1);
      if(n==0)
      {
      	cout<<0<<endl;
      	return 0;
	  }
	  if(n==1)
	  {
	  	cout<<1<<endl;
	  	return 0;
	  }
	  n=n+1;
       f[0]="0"; f[1]="1";
      for(int i=2;i<n;i++)
       {
            f[i]=stringAdd(f[i-1] , f[i-2]);
        }
      //Outputting the result
       cout<<f[n-1]<<endl;
        return 0;
}       
