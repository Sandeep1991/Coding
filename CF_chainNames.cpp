/*
You're given an array of names, where each name is given as a string. Your task is to link these names into a chain, so that the ith name starts with the same letter the (i - th)th name ends, and return this chain as a list.

All names should be used. It is guaranteed that each name starts with a unique letter. It is also guaranteed that there is only one solution.

Example

For

names = ["Raymond",  "Nora", "Daniel", 
         "Louie", "Peter", "Esteban"]
the output should be

chainNames(names) = ["Peter", "Raymond", "Daniel", 
                     "Louie", "Esteban", "Nora"]
Input/Output

[time limit] 500ms (cpp)
[input] array.string names

Array of names, where each name starts with a unique letter.

Constraints:
1 ≤ names.length ≤ 15,
1 ≤ names[i].length ≤ 10.

[output] array.string

Array of chained names.


Sub optimal solution with time complexity O(n^2)
It can be solved in O(n+m) using DFS approach
*/
std::vector<std::string> chainNames(std::vector<std::string> names) {
int n = names.size();    

//std::fill(b.begin(),b.end(),0);
std::vector<std::string>ans(n);    
std::map<char,std::string>m;
    
for(int i=0;i<n;i++)
{
    //int a = names[i].length()-1;
    char s = names[i][0]-'A'+'a';
    //cout<<s<<endl;
    m[s] = names[i];
}
std::map<char,std::string>::iterator it;
//for(it=m.begin();it!=m.end();it++)
	//cout<<it->first<<"-"<<it->second<<" ";
for(int i=0;i<n;i++)
{
    std::vector<std::string>ans(n);
    std::vector<bool>b(n);
    std::fill(b.begin(),b.end(),0);
    ans[0] = names[i];
    //int z = ans[0].length()-1;
    //b[ans[0][z]]=1;
    int c = 1;
    for(int j=1;j<n;j++)
    {
        int t = ans[j-1].length()-1;
        char next = ans[j-1][t];
        int z = ans[j].length()-1;
        //if(b[ans[j][z]]) break;
        //else b[ans[j][z]]=1;
        //ans[j] = m[next];
        if(m[next]!=""&&find(ans.begin(),ans.end(),m[next])==ans.end())
        {
			ans[j] = m[next];
            c++;
		}
    }
    if(c==n) 
    {
    //for(int i=0;i<(int)ans.size();i++)
		//cout<<ans[i]<<" ";
    return ans;}
}
return ans;
}
int main()
{
	vector<string>n;
	n.push_back("Raymond");n.push_back("Nora");
	n.push_back("Daniel");n.push_back("Louie");
	n.push_back("Peter");n.push_back("Esteban");
	chainNames(n);
	return 0;
}

