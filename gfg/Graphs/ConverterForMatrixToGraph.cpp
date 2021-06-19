#include<bits/stdc++.h>
using namespace std;

bool issafe(int i,int j ,int n,int m, vector<vector<int>>graph)
{
  if(i<0 || i>n-1 || j<0 || j>m-1 || graph[i][j]==0)
  return false;
  return true;
}

void convert(vector<vector<int>>graph, vector<int>adj[])
{
  int row[]={-1,0,0,1};//up,left,right,down;
  int col[]={0,-1,1,0};
  int n=graph.size(),m=graph[0].size() ,count=-1;
  for(int i=0;i<n;i++)
  {
    for(int j=0;j<m;j++)
    {
      count+=1;
      for(int k=0;k<4;k++)
      {
        if( graph[i][j] && issafe(i+row[k],j+col[k],n,m,graph) )
        {
          if(k==0)
          adj[count].push_back(count-m);
          else if(k==1)
          adj[count].push_back(count-1);
          else if(k==2)
          adj[count].push_back(count+1);
          else
          adj[count].push_back(count+m);
        }
      }
    }
  }
}
void printGraph(vector<int> adj[], int nodes)
{
  for(int i=0;i<nodes;i++)
  {
    cout<<i<<" -> ";
    for(int j=0;j<adj[i].size();j++)
    cout<<adj[i][j]<<" ";
    cout<<endl;
  }
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
  vector<int>adj[n*n];
  convert(graph,adj);
  printGraph(adj,n*n);
}
