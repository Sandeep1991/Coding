//Hacker Rank Greedy florist

/* Sample program illustrating input/output */
#include<iostream>
#include<algorithm>
using namespace std;
int main(void){

 

//Helpers for input and output

   int N, K;
   cin >> N >> K;
    int C[N];
   for(int i = 0; i < N; i++){
      cin >> C[i];
   }
   int sum = 0; 
   if(N==K)
   {
       for(int i=0;i<N;i++)
       {
           sum += C[i];
       }
   }
   else
   {
       sort(C,C+N,greater<int>());
       for(int i=0; i<K; i++)
       {
           sum = sum + C[i];
       }
       int x = 2;
       int ctr = 0;
       for(int i=K; i<N;i++)
       {
           sum = sum + x * C[i];
           ctr ++;
           if(ctr % K == 0) x++;
           
          
           
       }
   }
   int result;
   result = sum;
   cout << result << "\n";
   
   return 0;
}
