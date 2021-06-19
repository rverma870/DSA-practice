#include <bits/stdc++.h>
using namespace std;

bool findPartition(int a[], int n)
{
  int sum=0;
  for(int i=0;i<n;i++)
      sum+=a[i];
  if(sum%2!=0)
      return false;
  else
  {
    sum=sum/2;
    bool dp[n+1][sum+1];
    for(int i=0;i<=n;i++)
        dp[i][0]=1;
    for(int i=1;i<=sum;i++)
        dp[0][i]=0;
    for(int i=1;i<=n;i++)
    {
      for(int j=1;j<=sum;j++)
      {
        if(j>=a[i-1])
         dp[i][j]=dp[i-1][j-a[i-1]] || dp[i-1][j];
        else
        dp[i][j]=dp[i-1][j];
    }
    }
    return dp[n][sum];
  }
}

int main()
{
  int n, i;
  cin >> n;
  int a[n];
  for (i = 0; i < n; i++)
  cin >> a[i];
  if (findPartition(a, n))
      printf("YES\n");
  else
      printf("NO\n");
}
