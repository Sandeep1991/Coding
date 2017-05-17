#include <bits/stdc++.h>

using namespace std;

class Person{
	public:
		string name;
		int age;		
};
class less_than{
	public:
		inline bool operator()(const Person& p1,const Person& p2)
		{
			return (p1.age<p2.age);
		}
};
	
class Collection{
	private:
		vector<Person>vp;
	public:
		void AddPerson(Person p)
		{
			vp.push_back(p);
		}
		void PrintPerson()
		{
			vector<Person>::iterator it;
			for(it=vp.begin();it!=vp.end();it++)
			{
				cout<<it->name<<"->"<<it->age<<endl;
			}
			cout<<endl;
		}
		void Sorted()
		{
			sort(vp.begin(),vp.end(),less_than());
			vector<Person>::iterator it;
			for(it=vp.begin();it!=vp.end();it++)
			{
				cout<<it->name<<"->"<<it->age<<endl;
			}
			cout<<endl;
		} 
};

int main()
{
	int n; //no of persons
	cin>>n;
	Person p;
	//vector<Person>vp(n);
	string s; int a;
	Collection col;
	for(int i=0;i<n;i++)
	{
		cin>>s;
		cin>>a;
		p.name=s;
		p.age=a;
		//col.AddPerson(a);
		col.AddPerson(p);
	}
	col.PrintPerson();
	col.Sorted();
	return 0;
}
