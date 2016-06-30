/* 
Vasya faced a serious problem: he has to work with a bunch of numbers. Since he has to print them out, he wants to use as little paper as possible. And that is why he came up with the following idea: convert array of numbers into a string by the following rule.

Converted each number to the base 26. To write a number, Vasya will use lowercase letters of Latin alphabet: 'a' = 0, 'b' = 1, ..., 'z' = 25;
Find the longest of the strings obtained by the conversion;
Turn all obtained strings of the same length by appending symbols 'a' in front of the strings that are shorter than the longest one;
Combine the strings into one. The first symbol of the resulting string is the length of the each string as a letter ('a' for 1, 'b' for 2, ..., 'z' for 26). After that all strings are written one by one in the order the numbers they were converted from appear in the array.
Check out examples for better understanding.

Your task is to convert the given array a to a string as Vasya suggests.

Example

For a = [1, 28, 55], the output should be
conversion(a) = "babbccd".

Here's how the numbers are converted:

1 = "b";
28 = "bc";
55 = "cd".
Since the longest string is of length 2, number 1 should be turned into "ab".

The final answer is "babbccd", where:

the first letter 'b' stands for the length of the longest string;
the next two letters "ab" stand for the first number;
the following two letters "bc" stand for the second number;
the last two letters "cd" stand for the last number.
Input/Output

[time limit] 500ms (cpp)
[input] array.integer a

Array of integers.

Constraints:
1 ≤ a.length ≤ 100,
1 ≤ a[i] ≤ 109.

[output] string

A string into which a is converted.
*/
std::string conversion(std::vector<int> a) {
    std::string s;
    int ml = 0;
    std::vector<std::string>v;
    for(int i=0;i<a.size();i++)
    {
        int n = a[i];
        s = "";
        while(n)
        {
            int a = n % 26;
            n = n/26;
            s = char(a+'a') + s;
        }
        //cout<<s<<" ";
        int l = s.length();
        if(ml<l) ml = l;
        v.push_back(s);
    }
    std::string fs;
    fs = "";
    //ml = ml;
    fs += char(ml+'a'-1);
    //cout<<fs<<endl;
    for(int i=0;i<v.size();i++)
    {
    	std::string tmp = "";
    	int x = ml-v[i].length();
    	//cout<<x<<" ";
        for(int i=0; i<x;i++)
            tmp += 'a'; 
        fs += tmp + v[i];
    }
    return fs;
}
int main()
{
	vector<int>v;
	v.push_back(9546);
	v.push_back(3594);
	v.push_back(5244);
	vector<int>v1;
	v1.push_back(1);
	v1.push_back(28);
	v1.push_back(55);
	cout<<conversion(v)<<endl;
	cout<<conversion(v1)<<endl;
}



