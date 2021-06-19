#include<bits/stdc++.h> 
using namespace std;

bool is1winner(int N,int arr[])
{
  int dp[N][N],sum=0;
  memset(dp,0,sizeof(dp));
  for(int gap=0;gap<N;gap++)
  {
    for(int i=0,j=gap;j<N;i++,j++)
    {
      if(gap==0)
      {
        sum+=arr[i];
        dp[i][j]=arr[i];
      }
      else if(gap==1)
      dp[i][j]=max(arr[i],arr[j]);
      else
      {
        dp[i][j]=max(arr[i]+min(dp[i+2][j],dp[i+1][j-1]),arr[j]+min(dp[i][j-2],dp[i+1][j-1]));
      }
    }
  }
  if(sum-dp[0][N-1]>dp[0][N-1])
  return false;
  else
  return true;
}

int main()
{
  int N, X;
  cin >> N;
  int arr[N];
  for(int i = 0; i < N; i++)
      cin >> arr[i];
  cout<<is1winner(N, arr) << endl;
}
