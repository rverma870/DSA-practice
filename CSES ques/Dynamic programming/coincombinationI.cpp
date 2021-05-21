#include <bits/stdc++.h>
using namespace std;
#define M 1000000007

int main()
{
  int n,sum;
  cin>>n>>sum;
  vector<int> a;
  for(int i=0;i<n;i++)
  {
    int x;
    cin>>x;
    a.push_back(x);
  }
  vector<int> dp(sum+1,0);
  dp[0]=1;
  for(int i=1;i<=sum;i++)
  {
    for(int j=0;j<n;j++)
    {
      if(a[j]<=i)
      dp[i]=(dp[i]%M+dp[i-a[j]]%M)%M;
    }
  }
  cout<<dp[sum];
}
