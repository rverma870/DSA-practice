#include<bits/stdc++.h>
using namespace std;
#define M 1000000007

int main()
{
  int sum;
  cin>>sum;
  long long int dp[sum+1];
  memset(dp,0,sizeof(dp));
  dp[0]=1;
  for(int i=1;i<=sum;i++)
  {
    for(int j=1 ; j<=6 && i-j>=0 ; j++)
      dp[i]=(dp[i]%M+dp[i-j]%M)%M;
  }
  cout<<dp[sum];

}
