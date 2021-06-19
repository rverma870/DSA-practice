//This algorithm is used to find SCC(Strongly Connected Component) in a Directed Graph.
//summary - we traverse through DFS and at any node we find a backEdge to a node means
//that is the head of SCC and that small component is itself SCC.
//Now in the whole traversal we find this small component which are strongly connected.
//and we will get all SCC in the Graph.
//the key is to check weather the found backedge is backEdge or CrossEdge or TreeEdge
//if it is CrossEdge then we will not consider it and move ahead.
//Now if reach to a node wehere no further nodes are available then we check that node
// for SCC as each node itself is SCC .
//So basically we divide the whole graph in each single node which itself is SCC. and then
//join them to check if they form SCC.

#include<bits/stdc++.h>
using namespace std;

void GraphInput(int edge,vector<int>adj[])
{
  for(int i=0; i<edge ; i++)
  {
    int u,v;
    cin>>u>>v;
    adj[u].push_back(v);
    //adj[v].push_back(u);
  }
}

void DFS(int v, vector<int>adj[], vector<int>&disc, vector<int>&low, vector<bool>&instack, stack<int>&stk, vector<vector<int>>&ans)
{
  static int time=0;
  disc[v]=low[v]=time;
  time++;
  stk.push(v);
  instack[v]=true;

  for(auto e:adj[v])
  {
    if(disc[e]==-1)
    {
      DFS(e,adj,disc,low,instack,stk,ans);
      low[v]=min(low[v],low[e]);
    }
    else if(instack[e])//to check for cross Edges in the graph
      low[v]=min(low[v],disc[e]);
  }

  //checking if it is SCC
  if(low[v]==disc[v])
  {
    vector<int>temp;
    while(stk.top()!=v)
    {
      temp.push_back(stk.top());
      instack[stk.top()]=false;
      stk.pop();
    }
    temp.push_back(stk.top());
    stk.pop();
    instack[v]=false;
    ans.push_back(temp);
  }
}

vector<vector<int>> tarjans(int V, vector<int> adj[])
{
  vector<int>disc(V,-1);//discovery Time;
  vector<int>low(V,-1);//Lowest discovery node available;
  vector<bool>instack(V,false);//elements present in stack;
  stack<int>stk;
  vector<vector<int>>ans;
  for(int i=0;i<V;i++)
  {
    if(disc[i]==-1)
    DFS(i,adj,disc,low,instack,stk,ans);
  }
  return ans;
}

int main()
{
  int nodes,edge;
  cin>>nodes>>edge;
  vector<int>adj[nodes];
  GraphInput(edge,adj);
  vector<vector<int>>ans=tarjans(nodes,adj);
  for(auto e:ans)
  {
    for(auto x:e)
    cout<<x<<" ";
  }
}
