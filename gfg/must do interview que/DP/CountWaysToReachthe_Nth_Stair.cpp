#include<bits/stdc++.h>
using namespace std;

int countWays(int m)
{
  int dp[m+1];
  int M=1000000007;
	memset(dp,0,sizeof(dp));
	dp[0]=1;
	dp[1]=1;
	dp[2]=2;
	for(int i=3;i<=m;i++)
    dp[i]=(dp[i-1]%M+dp[i-2]%M)%M;
	 return dp[m];
}

int main()
{
  int m;
  cin>>m;
  cout<<countWays(m)<<endl;
}
