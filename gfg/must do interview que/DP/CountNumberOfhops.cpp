#include <bits/stdc++.h>
using namespace std;

long long countWays(int n)
{
  long long M=1000000007,dp[n+1];
  memset(dp,0,sizeof(dp));
  dp[0]=1;
  for(int i=1;i<=n;i++)//sum
  {
    for(int j=1;j<=3;j++)//from 1 2 3
    {
      if(i>=j)
      dp[i]=(dp[i]%M+dp[i-j]%M)%M;
    }
  }
  return dp[n];
}

int main()
{
   int n;
   cin>>n;
   cout << countWays(n);
}
