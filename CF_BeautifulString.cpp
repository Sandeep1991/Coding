/* Codefights

We say that a string s is a Binary string, if it consists of only A and B characters, i.e. for each valid i s[i]='A' or s[i]='B'.

A Binary string is a Beautiful Binary string, if it is possible to connect pairs of equal letter with lines above the string so that no two lines intersect and each character is connected to exactly one other character.

Now that you do remember, solve the following task: how many beautiful binary strings of length n are there?

Example

For n = 2, the output should be beautifulbinstr(n) = 2.

There are 2 Beautiful Binary strings of length 2: "AA" and "BB" */
long long int fact(int x)
{
    if(x<=0) return 1;
    long long int t;
    t = x * fact(x-1);
    return t;
}
int beautifulbinstr(int n) {
    if(n%2!=0)
        return 0;
    else
        return (fact(n)/pow(fact(n/2),2));
}
