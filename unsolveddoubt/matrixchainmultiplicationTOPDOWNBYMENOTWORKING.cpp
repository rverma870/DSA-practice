#include<bits/stdc++.h>
using namespace std;

int matrixMultiplication(int N, int arr[])
{
   int t[N][N],temp;
   memset(t,-1,sizeof(t));
   for(int i=1;i<N;i++)
       t[i][i]=0;
   for(int i=2;i<N;i++)//coloum
   {
       for(int j=i-1;j>0;j--)//row
       {
           temp=INT_MAX;
           for(int k=j;k<=i-1;k++)//j<k<i
           {
               temp=min(temp,t[j][k]+t[k+1][i]+arr[j-1]*arr[k]*arr[i]);
            //   cout<<t[k+1][i]<<endl;
           }
           t[j][i]=temp;
       }
   }
   for(int i=0;i<N;i++)
   {
     for(int j=0;j<N;j++)
      cout<<t[i][j]<<" ";
      cout<<endl;
   }
   return t[1][N-1];

}
int main()
{
  int n;
  cin>>n;
  int arr[n];
  for(int i=0;i<n;i++)
    cin>>arr[n];
  cout<<matrixMultiplication(n,arr)<<endl;
}
