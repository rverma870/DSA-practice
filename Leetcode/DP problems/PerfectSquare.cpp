#include<bits/stdc++.h>
using namespace std;

int numSquares(int n)
{
  int r=sqrt(n);
  int dp[r+1][n+1];
  for(int i=0;i<=r;i++)
    dp[i][0]=0;
  for(int i=1;i<=n;i++)
  {
    dp[0][i]=0;
    dp[1][i]=i;
  }
  int ans=n;
  for(int i=2;i<=r;i++)
  {
    for(int j=1;j<=n;j++)
    {
      if(j>=i*i)
        dp[i][j]=min(dp[i][j-i*i]+1,dp[i-1][j]);
      else
        dp[i][j]=dp[i-1][j];

      if(j==n)
      ans=min(ans,dp[i][j]);
    }
  }
  for(int i=0;i<=r;i++)
  {
    for(int j=0;j<=n;j++)
    cout<<dp[i][j]<<" ";
    cout<<endl;
  }
  return dp[r][n];
}

int main()
{
  int n;
  cin>>n;
  cout<<numSquares(n);
}
