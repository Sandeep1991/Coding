//Quick sort using random pivot

#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;


ll partition ( vector<ll>&v,ll start ,ll end) {
    ll i = start + 1;
    ll piv = v[start] ;            //make the first element as pivot element.
    for(ll j =start + 1; j <= end ; j++ )  {
    //rearrange the array by putting elements which are less than pivot
       on one side and which are greater that on other. 

          if ( v[ j ] < piv) {
                 swap (v[ i ],v [ j ]);
            i += 1;
        }
   }
   swap ( v[ start ] ,v[ i-1 ] ) ;  //put the pivot element in its proper place.
   return i-1;                      //return the position of the pivot
}

ll rand_partition ( vector<ll>&v , ll start , ll end ) {
    //chooses position of pivot randomly by using rand() function .
     ll random = start + rand( )%(end-start +1 ) ;

      swap ( v[random] , v[start]) ;        //swap pivot with 1st element.
     return partition(v,start ,end) ;       //call the above partition function
}



void quick_sort(vector<ll>&v,ll s,ll e)
{
	if(s<e)
	{
		ll p = rand_partition(v,s,e);
		quick_sort(v,0,p-1);
		quick_sort(v,p+1,e);
	}
}



int main()
{
    ll n;
    cin>>n;
    vector<int>v(n);
    for(ll i=0;i<n;i++)
    {
    	cin>>v[i];
    }
    quick_sort(v,0,n-1);
    //sort(v.begin(),v.end());
    for(ll i=0;i<n;i++)
    	cout<<v[i]<<" ";
    cout<<endl;
    return 0;
}
