/* Given a string in the modified balanced ternary notation, make a valid equation.
What does balanced ternary mean? This Wikipedia page can help you get the general idea.

In this challenge, we will use a modified balanced ternary notation. Instead of using -, +, and 0, or T, 1, and 0, we will use -, 1, and 0. However, the same rules apply.

For this challenge, convert a base10 integer value to balanced ternary notation.

Example

For num = 10, the output should be
BalancedTernary(num) = "101".

101 in balanced ternary is 10 in base10, because (performing conversion from right to left): 1 * 30 + 0 * 31 + 1 * 32 = 1 + 0 + 9 = 10.

For num = 42, the output should be
BalancedTernary(num) = "1---0".

1---0 in balanced ternary is 42 in base10 because 0 * 30 + (-1) * 31 + (-1) * 32 + (-1) * 33 + 1 * 34 = 0 + (-3) + (-9) + (-27) + 81 = 42.

For num = 1024, the output should be
BalancedTernary(num) = "111-0-1". */

std::string BalancedTernary(int num) {
    std::string s;
    long long int n = num,rem;
    int f=0;
    if(n==0) return "0";
    if(n>0)
        f =0;
    else
        f = 1;
    n = abs(n);
    while(n>0)
    {
        rem = n % 3;
        n = n/3;
        if(rem==2)
        {
            rem = -1;
            n++;
        }
        s= (rem==0?'0':(rem==1)?'1':'-') + s;
    }
    if(!f)
        return s;
    else
    {
        for(int i=0;i<=s.length();i++)
        {
            if(s[i] == '1') s[i] = '-';
            else if(s[i] == '-') s[i] = '1';
        }
        return s;
    }
}

