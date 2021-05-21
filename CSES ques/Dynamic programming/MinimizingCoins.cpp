#include<bits/stdc++.h>
using namespace std;

int main()
{
  int n,sum;
  cin>>n>>sum;
  int a[n];
  for(int i=0;i<n;i++)
    cin>>a[i];
  int dp[n+1][sum+1];
  for(int i=0;i<=n;i++)
    dp[i][0]=0;
  for(int i=1;i<=sum;i++)
    dp[0][i]=10000000;
  for(int i=1;i<=n;i++)
  {
    for(int j=1;j<=sum;j++)
    {
      if(a[i-1]<=j)
        dp[i][j]=min(1+dp[i][j-a[i-1]],dp[i-1][j]);
      else
        dp[i][j]=dp[i-1][j];
    }
  }
  if(dp[n][sum]==10000000)
    cout<<-1;
  else
  cout<<dp[n][sum];
}
