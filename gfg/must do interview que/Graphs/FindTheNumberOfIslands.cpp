#include <bits/stdc++.h>
using namespace std;

bool issafe(int i,int j ,int n,int m, vector<vector<char>>&graph)
{
  if(i<0 || i>n-1 || j<0 || j>m-1 || graph[i][j]=='0')
  return false;
  return true;
}

void DFS(int u,int v, vector<vector<char>>& grid,int n,int m,vector<vector<int>>& vis)
{
  static int row[]={-1,0,0,1,-1,-1,1,1 };//up,left,right,down, upper left, upper, right, lower left, lower right;
  static int col[]={0,-1,1,0,-1,1,-1,1 };
  vis[u][v]=1;
  for(int k=0;k<8;k++)
  {
    if(issafe(u+row[k],v+col[k],n,m,grid) && !vis[u+row[k]][v+col[k]] )
    {
      DFS(u+row[k], v+col[k], grid, n, m, vis);
    }
  }
}

int numIslands(vector<vector<char>>& grid)
{
  int n=grid.size(),m=grid[0].size();
  vector<vector<int>>vis(n,vector<int>(m,0));
  int ans=0;
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<m;j++)
    {
      if(vis[i][j]==0 && grid[i][j]!='0')
      {
        DFS(i,j,grid,n,m,vis);
        ans++;
      }
    }
  }
  return ans;
}

int main()
{
  int n,m;
  cin>>n>>m;
  vector<vector<char>>graph(n);
  for(int i=0;i<n;i++)
  {
    vector<char>temp(m);
    for(int j=0;j<m;j++)
      cin>>temp[j];
    graph[i]=temp;
  }
  cout<<numIslands(graph);
}
