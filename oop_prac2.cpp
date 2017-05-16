#include <bits/stdc++.h>

using namespace std;

class Person{
	public:
		string name;
		int age;
		vector<Person>vp;
		//void AddPerson(Person person)
		//void PrintPerson(vector<Person>vp)
		void PrintPerson();
		
};
void Person::PrintPerson()
{
	cout<<name<<"->"<<age<<endl;
}

int main()
{
	int n; //no of persons
	cin>>n;
	Person p;
	//vector<Person>vp(n);
	string s; int a;
	for(int i=0;i<n;i++)
	{
		cin>>s;
		cin>>a;
		p.name=s;
		p.age=a;
		p.PrintPerson();
		//Person::AddPerson(Person(p));
	}
	return 0;
}
