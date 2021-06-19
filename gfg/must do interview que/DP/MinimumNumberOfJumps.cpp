#include<bits/stdc++.h>
using namespace std;

int minimumJumps(int arr[], int n)
{
  int maxR=arr[0],step=arr[0],jump=1;
  int dp[n];
  if(n==1)
   return 0;
  else if(arr[0]==0)
   return -1;
  for(int i=1;i<n;i++)
  {
    if(i==n-1)
     return jump;
    maxR=max(maxR,arr[i]+i);
    step--;
    if(step==0)
    {
      jump++;
      if(i>=maxR)
          return -1;
      step=maxR-i;
    }
  }
}

int main()
{
  int n,i,j;
  cin>>n;
  int arr[n];
  for(int i=0; i<n; i++)
      cin>>arr[i];
  cout<<minimumJumps(arr, n)<<endl;
}
