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
int solve(string s, int i, int j, int dp[][1000])
{
    if(i>=j)
    return 0;

    if(palin(s,i,j))
    return 0;

    if(dp[i][j]!=-1)
    return dp[i][j];

    int ans=INT_MAX,left,right;
    for(int k=i;k<j;k++)
    {
        if(dp[i][k]!=-1)
          left=dp[i][k];
        else
        {
          left=solve(s,i,k,dp);
          dp[i][k]=left;
        }

        if(dp[k+1][j]!=-1)
          right=dp[k+1][j];
        else
        {
          right=solve(s,k+1,j,dp);
          dp[k+1][j]=right;
        }

        ans=min(ans,left+right+1);
    }
    return dp[i][j]=ans;
}
// int matrixMultiplication(int N, int arr[])
// {
//     int t[1000][1000];
//     memset(t,-1,sizeof(t));
//     return solve(N,arr,1,N-1,t);
// }

int main()
{
  memset(dp,-1,sizeof(dp));
  string s;
  cin>>s;
  cout<<solve(s,0,s.length()-1,dp);
}
