#include <iostream>
using namespace std;

void merge(int A[],int start,int mid,int end)
{
	int p =start, q = mid+1;
	int Arr[end-start+1],k=0;

	for(int i = start ;i <= end ;i++) {
    	if(p > mid)      //checks if first part comes to an end or not .
       		Arr[ k++ ] = A[ q++] ;

   		else if ( q > end)   //checks if second part comes to an end or not
       		Arr[ k++ ] = A[ p++ ];

   		else if( A[ p ] < A[ q ])     //checks which part has smaller element.
      		Arr[ k++ ] = A[ p++ ];

   		else
      		Arr[ k++ ] = A[ q++];
 	}
  	for (int p=0 ; p< k ;p ++) {
   	/* Now the real array has elements in sorted manner including both 
        parts.*/
    	 A[ start++ ] = Arr[ p ] ;                          
  	}
}


void merge_sort(int A[], int s, int e)
{
	if(s<e)
	{
		int m = (s+e)/2;
		merge_sort(A,s,m);
		merge_sort(A,m+1,e);
		merge(A,s,m,e);
	}
}
int main()
{
    int n;
    cin>>n;
    int A[n];
    for(int i=0;i<n;i++)
    	cin>>A[i];
    merge_sort(A,0,n);
    for(int i=0;i<n;i++)
    	cout<<A[i]<<" ";
    cout<<endl;
    return 0;
}
