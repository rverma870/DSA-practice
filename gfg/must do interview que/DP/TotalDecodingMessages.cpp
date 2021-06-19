#include<bits/stdc++.h>
using namespace std;

int CountWays(string str)
{
  int x=str.length(),M=1000000007;
  int dp[x];
  dp[0]=1;
  if(str[0]=='0')
    return 0;
  for(int i=1;i<x;i++)
  {
    if(str[i-1]=='0' && str[i]=='0')
      dp[i]=0;
    else if(str[i-1]!='0' && str[i]=='0')
    {
      if(str[i-1]=='1' || str[i-1]=='2')
      {
        int q=(i>=2)?dp[i-2]%M:1;
        dp[i]=q;
      }
      else
      dp[i]=0;
    }
    else if(str[i-1]=='0' && str[i]!='0')
       dp[i]=dp[i-1];
    else
    {
      if(str[i-1]=='1' || str[i-1]=='2'&&str[i]<'7')
      {
        int t=(i>=2)?dp[i-2]%M:1;
        dp[i]=(dp[i-1]%M+t)%M;
      }
      else
      dp[i]=dp[i-1];
    }
  }
  return dp[x-1];
}
int main()
{
		string str;
		cin >> str;
		cout<<CountWays(str);
}
