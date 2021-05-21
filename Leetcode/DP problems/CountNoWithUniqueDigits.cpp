#include<bits/stdc++.h>
using namespace std;

int main()
{
  int n;
  cin>>n;
  int dp[n+1],D=0,ans=1;//no. of duplicates D;
  dp[0]=1;//0 has no duplicates;
  for(int i=1;i<=n;i++)
  {
    D = D*10+(i-1)*dp[i-1];
    dp[i]=pow(10,i) - pow(10,i-1)-D;
    ans+=dp[i];
  }
  cout<<ans;
}
