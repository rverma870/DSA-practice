#include<bits/stdc++.h>
using namespace std;

void dfs(int v, vector<bool>& visited, vector<int>&ans ,vector<int>adj[])
{
    visited[v] = true;
    for (auto i:adj[v])
    {
        if (!visited[i])
          dfs(i, visited, ans, adj);
    }
    ans.push_back(v);
}

vector<int>topoOrder(int V, vector<int>adj[])
{
  vector<bool>visited(V,false);
  vector<int>ans;
    for (int u = 0; u < V; u++)
    {
        if (!visited[u])
          dfs(u, visited, ans, adj);
    }
    reverse(ans.begin(), ans.end());
    return ans;
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
string findOrder(string dict[], int N, int K)
{
    vector<int>adj[K];
    vector<int>topo;
    for(int i=0;i<N-1;i++)
    {
      string a=dict[i];
      string b=dict[i+1];
      for(int j=0; j < min(a.length(),b.length()) ; j++)
      {
        if(a[j]!=b[j])
        {
          adj[a[j] - 'a'].push_back(b[j]-'a');
          break;
        }
      }
    }
    topo=topoOrder(K,adj);
    int l=topo.size();
    string ans;
    for(int i=0;i<l;i++)
    {
      ans.push_back((char)(topo[i]+97));
    }
    return ans;
}

int main()
{
  int n,k;
  cin>>n>>k;
  string dict[n];
  for(int i=0;i<n;i++)
  cin>>dict[i];
  cout<<findOrder(dict,n,k);
}
