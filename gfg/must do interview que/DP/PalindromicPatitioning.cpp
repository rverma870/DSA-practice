#include <bits/stdc++.h>
using namespace std;

int palindromicPartition(string str)
{
  int n=str.length();
  int dp[n];
  bool p[n][n];

  for(int gap=0;gap<n;gap++)
  {
    for(int i=0,j=gap;j<n;i++,j++)
    {
      if(gap==0)
        p[i][j]=true;
      else if(gap==1)
        p[i][j]=(str[i]==str[j]);
      else
        p[i][j]=(str[i]==str[j] && p[i+1][j-1]);
    }
  }
  for(int i=0;i<n;i++)
  {
    if(p[0][i]==true)
      dp[i]=0;
    else
    {
      dp[i]=INT_MAX;
      for(int j=0;j<i;j++)
      {
        if(p[j+1][i]==true && dp[j]+1<dp[i])
          dp[i]=dp[j]+1;
      }
    }
  }
  return dp[n-1];
}

int main()
{
  string str;
  cin>>str;
  cout<<palindromicPartition(str)<<"\n";
}
