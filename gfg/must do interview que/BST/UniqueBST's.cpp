#include<bits/stdc++.h>
using namespace std;

long long numTrees(int N)
{
  const unsigned int M = 1000000007;
  long long dp[N+1];
  dp[0]=1;
  for(int i=1;i<=N;i++)
  {
    long long sum=0;
    for(int j=1;j<=i;j++)
    {
         sum= (sum+ (dp[j-1]*dp[i-j])%M)%M;
    }
    dp[i]=sum;
  }
  return dp[N];
}
int main()
{
  int n;
  cin>>n;
  cout<<numTrees(n);
}
