#include <bits/stdc++.h>

using namespace std;

class Person{
	public:
		string name;
		int age;
		
};

int main()
{
	int n; //no of persons
	cin>>n;
	vector<Person>vp(n);
	for(int i=0;i<n;i++)
	{
		cin>>vp[i].name;
		cin>>vp[i].age;
	}
	for(int i=0;i<n;i++)
	{
		cout<<vp[i].name<<"->"<<vp[i].age<<endl;
	}
	sort(vp.begin(),vp.begin()+n,[](const Person& lhs, const Person& rhs){return lhs.age > rhs.age; });
	for(int i=0;i<n;i++)
	{
		cout<<vp[i].name<<"->"<<vp[i].age<<endl;
	}
	return 0;
}
