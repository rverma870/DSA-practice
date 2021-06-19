#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define M 1000000007
vector<ll> solve(int u, int n, vector<ll>prev)
{
  if(u==n)
  return prev;
  vector<ll>next;
  next.push_back(1);
  for(int i=1;i<prev.size();i++)
    next.push_back( (prev[i-1]%M + prev[i]%M )%M);
  next.push_back(1);
  return solve(u+1,n,next);
}
vector<ll> nthRowOfPascalTriangle(int n)
{
  vector<ll>prev;
  prev.push_back(1);
  if(n==1)
  return prev;
  return solve(1,n,prev);
}
int main()
{
  int n;
  cin>>n;
  for(auto e:nthRowOfPascalTriangle(n))
  cout<<e<<" ";
}
