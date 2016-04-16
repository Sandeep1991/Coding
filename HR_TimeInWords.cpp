//Hacker Rank Time in words using hash map.

#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;


int main(){
    int h;
    cin >> h;
    int m;
    cin >> m;
    map<int, string> hour_map;
    map<int, string> minutes_map; 
    hour_map[1]="one";
	hour_map[2]="two";
	hour_map[3]="three";
	hour_map[4]="four";
	hour_map[5]="five";
	hour_map[6]="six";
	hour_map[7]="seven";
	hour_map[8]="eight";
	hour_map[9]="nine";
	hour_map[10]="ten";
	hour_map[11]="eleven";
	hour_map[12]="twelve";
	
	
	minutes_map[1]="one minute";
	minutes_map[2]="two minutes";
	minutes_map[3]="three minutes";
	minutes_map[4]="four minutes";
	minutes_map[5]="five minutes";
	minutes_map[6]="six minutes";
	minutes_map[7]="seven minutes";
	minutes_map[8]="eight minutes";
	minutes_map[9]="nine minutes";
	minutes_map[10]="ten minutes";
	minutes_map[11]="eleven minutes";
	minutes_map[12]="twelve minutes";
	minutes_map[13]="thirteen minutes";
	minutes_map[14]="fourteen minutes";
	minutes_map[15]="quarter";
	minutes_map[16]="sixteen minutes";
	minutes_map[17]="seventeen minutes";
	minutes_map[18]="eighteen minutes";
	minutes_map[19]="nineteen minutes";
	minutes_map[20]="twenty minutes";
	minutes_map[21]="twenty one minutes";
	minutes_map[22]="twenty two minutes";
	minutes_map[23]="twenty three minutes";
	minutes_map[24]="twenty four minutes";
	minutes_map[25]="twenty five minutes";
	minutes_map[26]="twenty six minutes";
	minutes_map[27]="twenty seven minutes";
	minutes_map[28]="twenty eight minutes";
	minutes_map[29]="twenty nine minutes";
	minutes_map[30]="half";
	
	
	if(m==0)
	//cout<<hour_map[10]<<minutes_map[28];
	cout<<hour_map[h]<<" o' clock"<<endl;
	else if(m<=30)
	cout<<minutes_map[m]<<" past "<<hour_map[h]<<endl;
	//else if(m==30)
	//cout<<minutes_map[m]<<" past "<<hour_map[h]<<endl;
	/*else
	{
		if(h+1>12){
		int k = (h+1) % 12; 
		cout<<minutes_map[60-m]<<" to "<<hour_map[k]<<endl;
		}
		else
		cout<<minutes_map[60-m]<<" to "<<hour_map[h+1]<<endl;
		
	
	}*/
	else
		cout<<minutes_map[60-m]<<" to "<<hour_map[h+1]<<endl;
	
    return 0;
}
