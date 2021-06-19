#include<bits/stdc++.h>
using namespace std;

int wildCard(string pattern,string str)
{
  int x=pattern.length(),y=str.length(),
  dp[x+1][y+1];
  dp[0][0]=1;
  for(int i=1;i<=x;i++)
  {
    if(pattern[i-1]=='*')
    dp[i][0]=dp[i-1][0];
    else
    dp[i][0]=0;
  }
  for(int i=1;i<=y;i++)
    dp[0][i]=0;
  for(int i=1;i<=x;i++)
  {
    for(int j=1;j<=y;j++)
    {
      if(pattern[i-1]=='*')
      {
        dp[i][j]= dp[i-1][j] or dp[i][j-1];
      }
      else if(pattern[i-1]=='?' or pattern[i-1]==str[j-1])
      dp[i][j]= dp[i-1][j-1];
      else
      dp[i][j]=0;
    }
  }
  return dp[x][y];
}

int main()
{
  string pattern ,str;
  cin>>pattern>>str;
  cout<< wildCard(pattern , str);
}
