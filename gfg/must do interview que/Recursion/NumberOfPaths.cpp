#include<bits/stdc++.h>
using namespace std;
void solve(int i,int j,int m,int n,long long &ans)
{
  if(i<0 || i>=m || j<0 || j>=n)
  return;
  if(i==(m-1) && j==(n-1))
    ans+=1;
  solve(i+1,j,m,n,ans);
  solve(i,j+1,m,n,ans);
}
long long numberOfPaths(int m, int n)
{
  long long ans=0;
  solve(0,0,m,n,ans);
  return ans;
}

int main()
{
  int m,n;
  cin>>m>>n;
  cout<<numberOfPaths(m,n);
}
