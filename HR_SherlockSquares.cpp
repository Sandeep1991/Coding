//Hackerrank Sherlock and squares challenge

#include <iostream>

using namespace std;

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int a;
		cin>>a;
		if(a==1 || a==2 ) cout<< -1<<endl;
		//if(a % 3 !=0 && a%5 !=0) cout<< -1<<endl;
		else if(a % 3 == 0){
			for(int i = 0; i <a; i++)
			cout<<5;
			cout<<endl;
		}
		else{
			
			int q;
			q = a / 3;
			int p;
			p = a - (3 * q);
			while(p % 5 != 0 )
			{
				q = q -1;
				p = a - (3 * q);
			}
			if(q<=0 && q % 5 != 0) cout<<-1<<endl; 
			else{
			for(int i=0; i<3*q; i++)
				cout<<5;
			for(int j=0; j<p;j++)
				cout<<3;
			cout<<endl;
		}
		}
	}
	return 0;
}

				
