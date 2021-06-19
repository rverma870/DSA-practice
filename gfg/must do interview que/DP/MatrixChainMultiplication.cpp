#include <bits/stdc++.h>
using namespace std;

int solve(int N, int arr[], int i, int j, int dp[][1000])
{
  if(i>=j)
  return 0;
  if(dp[i][j]!=-1)
  return dp[i][j];
  int ans=INT_MAX;
  for(int k=i;k<j;k++)
  {
      ans=min(ans,solve(N,arr,i,k,dp)+solve(N,arr,k+1,j,dp)+arr[i-1]*arr[k]*arr[j]);
  }
  return dp[i][j]=ans;
}

int matrixMultiplication(int N, int arr[])
{
  int t[1000][1000];
  memset(t,-1,sizeof(t));
  return solve(N,arr,1,N-1,t);
}

int main()
{
  int N;
  cin>>N;
  int arr[N];
  for(int i = 0;i < N;i++)
      cin>>arr[i];
  cout<<matrixMultiplication(N, arr)<<endl;

}
