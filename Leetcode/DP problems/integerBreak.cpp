#include<bits/stdc++.h>
using namespace std;


int main()
{
  int n;
  cin>>n;
  int dp[n][n+1];
  for(int i=0;i<=n;i++)
    dp[0][i]=0;
  for(int i=0;i<n;i++)
  {
    dp[i][0]=0;
    dp[i][1]=0;
  }
  for(int i=1;i<n;i++)
  {
    for(int j=2;j<=n;j++)
    {
      if(j>i)
      dp[i][j]=max(i*(j-i) ,max(i*dp[i][j-i],dp[i-1][j]));
      else
      dp[i][j]=dp[i-1][j];
    }
  }
  cout<<dp[n-1][n];




}
