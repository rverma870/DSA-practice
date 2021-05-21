#include<bits/stdc++.h>
using namespace std;

void BFS(int s,vector<int>adj[],bool visited[],int N)
{
  queue<int>q;
  q.push(s);

  while(!q.empty())
  {
    int curr=q.front();
    q.pop();
    cout<<curr<<" ";
    for(int i=0;i<adj[curr].size();i++)
    {
      if(visited[adj[curr][i]]==false)
      {
        q.push(adj[curr][i]);
        visited[adj[curr][i]]=true;
      }
    }
  }
}

int main()
{
  int N,E;//nodes and edges
  cin>>N>>E;
  vector<int>adj[N];
  bool visited[N]={0};
  for(int i=0;i<E;i++)
  {
    int u,v;
    cin>>u>>v;
    adj[u].push_back(v);
  }
  BFS(0,adj,visited,N);
}
