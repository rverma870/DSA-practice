#include<bits/stdc++.h>
using namespace std;

int eggDrop(int n, int k)
{
  int dp[n+1][k+1];
  for(int i=1;i<=n;i++)
  {
    dp[i][0]=0;
    dp[i][1]=1;
  }
  for(int i=1;i<=k;i++)
  {
    dp[1][i]=i;
  }
  for(int i=2;i<=n;i++)
  {
    for(int j=2;j<=k;j++)
    {
      dp[i][j]=INT_MAX;
      for(int l=1;l<=k;l++)
      {
        dp[i][j]=min(dp[i][j],1+max(dp[i-1][l-1],dp[i][j-l]));
      }
    }
  }
  return dp[n][k];
}

int main()
{
  int n,k;
  cin>>n>>k;
  cout<<eggDrop(n,k);
}
