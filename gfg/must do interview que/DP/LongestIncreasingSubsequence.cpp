#include<bits/stdc++.h>
using namespace std;

int longestSubsequence(int n, int a[])
{
  int dp[n+1];
  for(int i=1;i<=n;i++)
      dp[i]=INT_MAX;
  dp[0]=INT_MIN;
  for(int i=0;i<n;i++)
  {
      int idx=upper_bound(dp,dp+n+1,a[i])-dp;
      if(a[i]>dp[idx-1] && a[i]<dp[idx])
          dp[idx]=a[i];
  }
  int ans=0;
  for(int i=n;i>=0;i--)
  {
      if(dp[i]!=INT_MAX)
      {
          ans=i;
          break;
      }
  }
  return ans;
}

int main()
{
  int n;
  cin>>n;
  int a[n];
  for(int i=0;i<n;i++)
      cin>>a[i];
  cout<<longestSubsequence(n, a);
}
