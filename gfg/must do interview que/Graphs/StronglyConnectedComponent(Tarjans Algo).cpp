#include<bits/stdc++.h>
using namespace std;

void GraphInput(int edge,vector<int>adj[])
{
  for(int i=0; i<edge ; i++)
  {
    int u,v;
    cin>>u>>v;
    adj[u].push_back(v);
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
    if(disc[e]==-1 && low[e]==-1)
    {
      DFS(e,adj,disc,low,instack,stk,ans);
      low[v]=min(low[v],low[e]);
    }
    else if(instack[e])//checking for cross edge;
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
    sort(temp.begin(),temp.end());
    ans.push_back(temp);
  }
}

bool static sortFunc( vector<int> p1, vector<int> p2 )
{
  if(p1[0] < p2[0])
    return true;
  else
    return false;
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
    sort(ans.begin(), ans.end(),sortFunc);
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
