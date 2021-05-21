#include<bits/stdc++.h>
using namespace std;

int main()
{
  int N;
  cin>>N;
  vector<vector<int>>obstacleGrid;
  for(int i=0;i<N;i++)
  {
    vector<int>col;
    for(int j=0;j<N;j++)
    {
      int t;
      cin>>t;
      col.push_back(t);
    }
    obstacleGrid.push_back(col);
  }
  int M=obstacleGrid[0].size();
  int dp[N][M];
  bool b=true;
  for(int i=0;i<N;i++)
  {
    if(obstacleGrid[i][0]==0 && b==true)
    dp[i][0]=1;
    else
    {
      b=false;
      dp[i][0]=0;
    }
  }
  b=true;
  for(int i=0;i<M;i++)
  {
    if(obstacleGrid[0][i]==0 && b==true)
    dp[0][i]=1;
    else
    {
      b=false;
      dp[0][i]=0;
    }
  }
  for(int i=1;i<N;i++)
  {
    for(int j=1;j<M;j++)
    {
      if(obstacleGrid[i][j]==0)
      dp[i][j]=dp[i-1][j]+dp[i][j-1];
      else
      dp[i][j]=0;
    }
  }
  cout<<dp[N-1][M-1];
}
