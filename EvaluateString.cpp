/*
Simplified question asking to evaluate a string containing valid arithmetic expression containing 
addition or subtraction (This is implemented using evaluate function)

As an extension the string can now contain parentheses. The pattern to recognize once again is that parentheses makes 
sense only when subtract sign appears before parentheses. We need to modify the sign within parentheses only during 
this condition!.

Remove the biases towards any particular containers like stack or queue. As there is no need for this simple case.
Space complexity is O(1) for evaluate and O(n) for finaleval
Time Complexity overall is O(n).
*/
#include <bits/stdc++.h>
using namespace std;

int evaluate(string s)
{
  int sum=0;
  string num;
  char prev_op = '+';
  int i=0;
  if (s[i]=='+'||s[i]=='-')
  {
    prev_op = s[i];
    i++;
  }

  for (;i<(int)s.length();i++)
  {
    if (s[i]=='+')
    {
      if (prev_op =='+')
      sum += stoi(num);
      else
        sum -= stoi(num);
      prev_op = '+';  
      num = "";
    }
    else if (s[i]=='-')
    {
      if (prev_op =='+')
      sum += stoi(num);
      else
        sum -= stoi(num);
      prev_op = '-';
      num = "";
    }
    else 
      num += s[i];
  }
  if (prev_op =='+')
  sum += stoi(num);
  else
    sum -= stoi(num);
  return sum;
}
int finaleval(string s)
{
  string ans;
  char sign_flag = '+'; 
  for (int i=0;i<s.length();i++)
  {  
    if (s[i]=='(' && (i==0 || s[i-1]=='+'))
        ;
    if (s[i]=='(' && (i!=0 && s[i-1]=='-'))
    {
        if (sign_flag == '+')
            sign_flag = '-';
        else
            sign_flag = '+';
    }
    /*if (s[i]>='0' && s[i]<='9' && s[i-1]=='(')
    {    
        ans += sign_flag;
    }*/
    if (s[i]>='0' && s[i]<='9')
        ans += s[i];
    if (s[i]=='+' && sign_flag=='-')
        ans += sign_flag;
    if (s[i]=='-' && sign_flag=='-')
        ans += '+';
    if ((s[i]=='+'||s[i]=='-') && sign_flag == '+')
        ans += s[i];
    if (s[i]==')')
        sign_flag = '+'; 
  }
  //cout<<ans<<endl; 
  return evaluate(ans);  
}
    
      

// To execute C++, please define "int main()"
int main() {
  string s = "2+3";
  
  cout<<evaluate(s)<<endl;
  s = "2-7+3";
  cout<<evaluate(s)<<endl;
  string s2 = "3-5";
  cout<<evaluate(s2)<<endl;
  s2 = "-5+2";
  cout<<evaluate(s2)<<endl;
  string s3 = "200-200+100-100+10-10+2-2+101";
  cout<<evaluate(s3)<<endl;
  s3 = "-3+2";
  cout<<evaluate(s3)<<endl;
  s3 = "(2+3)-(5+12)";
  cout<<finaleval(s3)<<endl;
  s3 = "-(9+9)";
  cout<<finaleval(s3)<<endl;
  s3 = "-(3-(4+5))";
  cout<<finaleval(s3)<<endl;
  s3 = "+(3-(4-(5-6)))";
  cout<<finaleval(s3)<<endl;
  return 0;
}
