#include<bits/stdc++.h>
using namespace std;

int main()
{
  string s;
  cin>>s;
  int n=s.length();
  if(s[0]=='0')
    cout<<0;
  else
  {
    int dp[n+1];
    dp[0]=1;
    dp[1]=1;
    for(int i=2;i<=n;i++)
    {
      if(s[i-2]=='0' && s[i-1]=='0')
        dp[i]=0;
      else if(s[i-2]=='0' && s[i-1]!='0')
        dp[i]=dp[i-1];
      else if(s[i-2]!='0' && s[i-1]=='0')
      {
        if(s.substr(i-2,2)>"26")
          dp[i]=0;
        else
          dp[i]=dp[i-2];
      }
      else
      {
        if(s.substr(i-2,2)>"26")
          dp[i]=dp[i-1];
        else
          dp[i]=dp[i-2]+dp[i-1];
      }
    }
    cout<<dp[n];
  }
}
