#include <bits/stdc++.h>
using namespace std;

long long maximumAmount(int arr[], int n)
{
  long long dp[n][n];
  for(int gap=0;gap<n;gap++)
  {
    for(int i=0,j=gap;j<n;i++,j++)
    {
      if(gap==0)
      dp[i][j]=arr[i];
      else if(gap==1)
      dp[i][j]=max(arr[i],arr[j]);
      else
      dp[i][j]=max(arr[i]+min(dp[i+2][j], dp[i+1][j-1]), arr[j]+min(dp[i][j-2], dp[i+1][j-1]));
    }
  }
  return dp[0][n-1];
}

int main()
{
  int N;
  cin>>N;
  int A[N];
  for(int i=0;i<N;i++)
  cin>>A[i];
  cout<<maximumAmount(A,N)<<endl;
}
