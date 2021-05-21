#include <bits/stdc++.h>
using namespace std;
#define MX 10000000;
bool isvalid(int r , int c,int N)
{
  if(r<0 or r>N-1)
    return false ;
  else if( c<0 or c>N-1)
    return false ;
	return true;
}
int solve(int i,int j,vector<vector<int>>grid,int N,bool b[][501],int dp[][501])
{
  if(i==N-1 && j==N-1)
  {
    dp[N-1][N-1] = grid[N-1][N-1];
    return dp[N-1][N-1];
  }
  if(dp[i][j]!=-1)
      return dp[i][j];
  b[i][j]=true;
  int l=0,r=0,u=0,d=0;
  if(isvalid(i,j-1,N) && b[i][j-1]==false)
  	 l=solve(i,j-1,grid,N,b,dp);
  else
     l=MX;

  if(isvalid(i,j+1,N) && b[i][j+1]==false)
     r=solve(i,j+1,grid,N,b,dp);
  else
     r=MX;

  if(isvalid(i-1,j,N) && b[i-1][j]==false)
     u=solve(i-1,j,grid,N,b,dp);
  else
     u=MX;

  if(isvalid(i+1,j,N) && b[i+1][j]==false)
     d=solve(i+1,j,grid,N,b,dp);
  else
     d=MX;

  dp[i][j]=grid[i][j]+min(min(l,r),min(u,d));
  b[i][j]=false;
  return	dp[i][j];
}
int main()
{
	int N;
  cin>>N;
  vector<vector<int>>grid;
  for(int i=0;i<N;i++)
  {
    vector<int>col;
    for(int j=0;j<N;j++)
    {
      int t;
      cin>>t;
      col.push_back(t);
    }
    grid.push_back(col);
  }
	bool b[N][501];
	memset(b,false,sizeof(b));
	int dp[N][501];
	memset(dp,-1,sizeof(dp));
	cout<<solve(0,0,grid,N,b,dp);
}
