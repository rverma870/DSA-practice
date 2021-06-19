#include<bits/stdc++.h>
using namespace std;

bool is_Possible(vector<vector<int>>& grid)
{
  queue<pair<int,int>>q;
  int n=grid.size();
  pair<int,int> source=make_pair(-1,-1);
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<n;j++)
    {
      if(grid[i][j]==1)
      source=make_pair(i,j);
    }
  }
  if(source.first==-1 and source.second==-1)
    return false;
  q.push(source);

  while(!q.empty())
  {
    int i=q.front().first , j= q.front().second;
    q.pop();

    if(i<0 || i>=n || j<0 || j>=n)
    continue;

    if(grid[i][j]==0)
    continue;

    if(grid[i][j]==2)
    return true;

    grid[i][j]=0;

    int row[]={-1,0,0,1};
    int col[]={0,-1,1,0};

    for(int k=0;k<4;k++)
      q.push({i+row[k], j+col[k]});
  }
  return false;
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

  cout<<is_Possible(graph);
}
