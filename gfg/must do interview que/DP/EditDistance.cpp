#include <bits/stdc++.h>
using namespace std;

int editDistance(string s, string t)
{
  int x=s.length(),y=t.length();
  int dp[x+1][y+1];
  for(int i=0;i<=y;i++)
    dp[0][i]=i;
  for(int i=1;i<=x;i++)
    dp[i][0]=i;
  for(int i=1;i<=x;i++)
  {
    for(int j=1;j<=y;j++)
    {
      if(s[i-1]==t[j-1])
        dp[i][j]=dp[i-1][j-1];
      else
        dp[i][j]=1+min(dp[i][j-1],min(dp[i-1][j],dp[i-1][j-1]));
    }
  }
  return dp[x][y];
}

int main()
{
  string s, t;
  cin >> s >> t;
  int ans = editDistance(s, t);
  cout<<ans;
}
