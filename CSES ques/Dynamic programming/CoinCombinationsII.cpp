#include<bits/stdc++.h>
using namespace std;
#define M 1000000007
int main()
{
  int n,x;
  cin>>n>>x;
  int a[n];
  for(int i=0;i<n;i++)
    cin>>a[i];
  int dp[n+1][x+1];
  for(int i=0;i<n+1;i++)
      dp[i][0]=1;
  for(int i=1;i<x+1;i++)
      dp[0][i]=0;
  for(int i=1;i<n+1;i++)
  {
    for(int j=1;j<x+1;j++)
    {
      if(a[i-1]<=j)
      dp[i][j]=(dp[i-1][j]%M + dp[i][j-a[i-1]]%M)%M;
      else
      dp[i][j]=dp[i-1][j]%M;
    }
  }
  cout<<dp[n][x];
}
