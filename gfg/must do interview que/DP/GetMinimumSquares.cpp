#include<bits/stdc++.h>
using namespace std;

int MinSquares(int n)
{
  int dp[n+1];
  memset(dp,0,sizeof(dp));
  dp[0]=1;
  dp[1]=1,dp[2]=2,dp[3]=3;

  for(int i=4;i<=n;i++)
  {
    dp[i]=INT_MAX;
    for(int j=1;j<=sqrt(i);j++)
    {
      if(i%(j*j)!=0)
      dp[i]=min(dp[i],dp[i%(j*j)]+i/(j*j));
      else
      dp[i]=min(dp[i],i/(j*j));
    }
  }
  return dp[n];
}
int main()
{
	int n;
	cin >> n;
	cout<<MinSquares(n);
} 
