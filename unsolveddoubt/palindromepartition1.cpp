#include<bits/stdc++.h>
using namespace std;
int dp[1000][1000];
bool palin(string s,int q,int w)
{
  for(int i=q;i<=w;i++,w--)
  {
      if(s[i]!=s[w])
      return false;
  }
  return true;
}
int solve(string s,int dp[][1000],int i,int j)
{
  if(i>=j)
  return 0;
  if(palin(s,i,j))
  return 0;
  if(dp[i][j]!=-1)
  return 0;
  int ans=INT_MAX;
  for(int k=0;k<j;k++)
  {
      ans= min(ans,solve(s,dp,i,k)+solve(s,dp,k+1,j)+1);
  }

  return dp[i][j]=ans;

}
// int palindromicPartition(string str)
// {
//   int dp[1000][1000];
//   memset(dp,-1,sizeof(dp));
//   int n=str.length();
//   return solve(str,dp,0,n-1);
// }
int main()
{
  memset(dp,-1,sizeof(dp));
  string s;
  cin>>s;
  cout<<solve(s,dp,0,s.length()-1);
}
