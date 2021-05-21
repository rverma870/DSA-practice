#include<bits/stdc++.h>
using namespace std;

int solve(int e,int f)
{
  int dp[e+1][f+1];
  for(int i=1;i<=e;i++)
  {
    dp[i][0]=0;
    dp[i][1]=1;
  }
  for(int i=1;i<=f;i++)
  {
    dp[1][i]=i;
  }
  for(int i=2;i<=e;i++)
  {
    for(int j=2;j<=f;j++)
    {
      dp[i][j]=INT_MAX;
      for(int k=1;k<=f;k++)
      {
        dp[i][j]=min(dp[i][j],1+max(dp[i-1][k-1],dp[i][j-k]));
      }
    }
  }
  return dp[e][f];
}
int main()
{
  int e,f;
  cin>>e>>f;
  cout<<solve(e,f);
}
