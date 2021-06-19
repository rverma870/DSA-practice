#include<bits/stdc++.h>
using namespace std;

bool issafe(int i,int j ,int n)
{
  if(i<0 || i>n-1 || j<0 || j>n-1)
  return false;
  return true;
}

int minimumCostPath(vector<vector<int>>& grid)
{
  int n=grid.size();
  vector<vector<int>>dis(n,vector<int>(n,INT_MAX));
  priority_queue< pair<int,pair<int,int>> ,vector<pair<int,pair<int,int>>> , greater<pair<int,pair<int,int>>> > q;
  q.push({grid[0][0], {0,0}});//distance,source;

  dis[0][0]=grid[0][0];

  int row[]={-1,0,0,1};//up,left,right,down;
  int col[]={0,-1,1,0};
  while(!q.empty())
  {
    int mindist=q.top().first;
    int u=q.top().second.first;
    int v=q.top().second.second;
    q.pop();
    for(int k=0;k<4;k++)
    {
      if(issafe(u+row[k], v+col[k], n) && (grid[u+row[k]][v+col[k]] + mindist < dis[u+row[k]][v+col[k]]) )
      {
        dis[u+row[k]][v+col[k]] = grid[u+row[k]][v+col[k]] + mindist;
        q.push({dis[u+row[k]][v+col[k]] ,{u+row[k], v+col[k]} });
      }
    }
  }
  return dis[n-1][n-1];
}
int main()
{
  int n;
  cin>>n;
  vector<vector<int>>graph(n);
  for(int i=0;i<n;i++)
  {
    vector<int>temp(n);
    for(int j=0;j<n;j++)
      cin>>temp[j];
    graph[i]=temp;
  }
  cout<<minimumCostPath(graph);
}
