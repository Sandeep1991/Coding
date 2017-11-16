#include <stdc++.h>

using namespace std;

int BIT[16]={0},arr[10] = {0},n;



void update(int pos, int val)
{
	for(;pos<=n;pos +=(pos & -pos))
		BIT[pos] += val;
}
int query(int pos)
{
	int sum =0;
	for(;pos>0;pos -=(pos & -pos))
		sum +=  BIT[pos];
	return sum;
}

int main()
{
	cin>>n;
	for(int i=1;i<n;i++)
	{
			cin>>arr[i];
			update(i,arr[i]);
	}
	update(2,5);
	for(int i=0;i<16;i++)
		cout<<BIT[i]<<" ";
	cout<<endl;
	cout<<query(10)<<endl;
	cout<<query(10)-query(5)<<endl;
	return 0;
}
