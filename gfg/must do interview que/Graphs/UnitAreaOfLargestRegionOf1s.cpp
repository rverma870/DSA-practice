#include<bits/stdc++.h>
using namespace std;

bool issafe(int i,int j ,int n,int m, vector<vector<int>>&graph)
{
  if(i<0 || i>n-1 || j<0 || j>m-1 || graph[i][j]==0)
  return false;
  return true;
}

void DFS(int u,int v,vector<vector<int>> &grid,int n,int m,vector<vector<bool>>&vis, int& temp)
{
  static int row[]={-1,0,0,1,-1,-1,1,1 };//up,left,right,down, upper left, upper, right, lower left, lower right;
  static int col[]={0,-1,1,0,-1,1,-1,1 };
  vis[u][v]=true;
  temp+=1;
  for(int k=0;k<8;k++)
  {
    if(issafe(u+row[k],v+col[k],n,m,grid) && !vis[u+row[k]][v+col[k]] )
      DFS(u+row[k],v+col[k],grid,n,m,vis,temp);
  }
}

int findMaxArea(vector<vector<int>>& grid)
{
  int n=grid.size();
  int m=grid[0].size();
  vector<vector<bool>> vis(n,vector<bool>(m,false));
  int ans=0,temp=0;
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<m;j++)
    {
      temp=0;
      if(!vis[i][j] && grid[i][j])
      {
        DFS(i,j,grid,n,m,vis,temp);
      }
      ans=max(ans,temp);
    }
  }
  return ans;
}

int main()
{
  int n,m;
  cin>>n>>m;
  vector<vector<int>>graph(n);
  for(int i=0;i<n;i++)
  {
    vector<int>temp(m);
    for(int j=0;j<m;j++)
      cin>>temp[j];
    graph[i]=temp;
  }
  cout<<findMaxArea(graph);
}
