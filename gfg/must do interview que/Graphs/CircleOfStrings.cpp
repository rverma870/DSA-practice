#include<bits/stdc++.h>
using namespace std;

void DFS(int u,vector<int>adj[],vector<bool>&vis)
{
  vis[u]=true;
  for(auto e:adj[u])
  {
    if(!vis[e])
    DFS(e,adj,vis);
  }
}

bool connected(int V, vector<int>adj[])
{
  int node=-1;//initial node for DFS to Start
  vector<bool>vis(V,false);
  for(int i=0;i<V;i++)
  {
    if(adj[i].size()>0)
    {
      node=i;
    }
  }
  if(node==-1)
  return false;//means no starting edge is found and every node has degree 0 or 1
              //therefore it is EULER circuit
  DFS(node,adj,vis);

  for(int i=0;i<V;i++)
  {
    if(!vis[i] && adj[i].size()>0)//checking for unvisited // nd unconnected egdes in all component with greater degree greater than 0
    return false;
  }
  return true;
}

int findEuler(int V, vector<int>adj[])
{
  if(!connected(V,adj))//checking if all the edges are present in one component only and if not its component must have degree 0;
    return 0;
  int inDegree[V]={0},outDegree[V]={0};//number of nodes having odd degree
  for(int i=0;i<V;i++)
  {
    for(auto e:adj[i])
    {
      inDegree[e]+=1;
      outDegree[i]+=1;
    }
  }
  for(int i=0;i<V;i++)
  {
    if(inDegree[i]!=outDegree[i])
      return 0;
  }
  return 1;
}

int isCircle(int N, vector<string> A)
{
  vector<int>adj[26];
  for(int i=0;i<N;i++)
  {
    int u=A[i][0]-97;
    int v=A[i][A[i].size()-1]-97;
    adj[u].push_back(v);
  }
  return findEuler(26,adj);
}

int main()
{
  int n;
  cin>>n;
  vector<string>A(n);
  for(int i=0;i<n;i++)
    cin>>A[i];

  cout<<isCircle(n,A);
}
