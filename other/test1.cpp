#include<bits/stdc++.h>
using namespace std;
long long dp[76];
long long solve(int curr,int buf,int n, int N)
{
  if(dp[n]!=0)
    return dp[n];
  if(n==N)
    return curr;
  long long left=0,right=0;
  if(N-n>2)
    left = solve(2*curr,curr,n+3,N);
  else
    left = curr;

  if(buf!=0)
    right= solve(curr+buf,buf,n+1,N);
  else
    right = solve(curr+1,1,n+1,N);
  return dp[n]=max(left , right);
}

long long int optimalKeys(int N)
{
  long long ans=0;
  ans=max(ans,solve(0,0,0,N));
  for(auto e:dp)
  cout<<e<<" ";
  cout<<endl;
  return ans;
}

int main()
{
  int n;
  cin>>n;
  memset(dp,0,sizeof(dp));
  cout<<optimalKeys(n);
}
