#include<bits/stdc++.h>
using namespace std;
//this algoritm is used to find minimum Spannig tree and
//it is based on disjoint set data structure;

struct Node
{
  int w,u,v;
  Node(int u,int v,int w)
  {
    this->w=w;
    this->u=u;
    this->v=v;
  }
};

int findparent(int node ,vector<int> &parent)//find parent
{
  if(node==parent[node])
    return node;
  return parent[node]=findparent(parent[node],parent);
}

void yunion(int u, int v,vector<int> &parent,vector<int> &rnk)
{
  u=findparent(u,parent);
  v=findparent(v,parent);

  if(rnk[u]<rnk[v])
    parent[u]=v;
  else if(rnk[v] < rnk[u])
    parent[v]=u;
  else
  {
    parent[v]=u;
    rnk[u]++;
  }
}

bool cmp(Node a, Node b)
{
  if(a.w > b.w)
  return false;
  else
  true;
}

int main()
{
  int V,m;
  cin>>V>>m;
  vector<Node>edge;
  while(m--)
  {
    int u,v,w;
    cin>>u>>v>>w;
    edge.push_back(Node(u,v,w));
  }
  sort(edge.begin(),edge.end(),cmp);//to have minimum weight edge firts;

  vector<int> parent(V);
  vector<int> rnk(V);
  for(int i=0 ;i<V ;i++)
  {
    parent[i]=i;//every one is its own parent;
    rnk[i]=0;//rank is 0 for every node;
  }
  vector<pair<int,int>>mst;
  int cost=0;
  for(auto e:edge)
  {
    if(findparent(e.u,parent) != findparent(e.v,parent))
    {
      cost+=e.w;
      mst.push_back({e.u,e.v});
      yunion(e.u,e.v,parent,rnk);
    }
  }
  cout<<"Total Cost = "<<cost<<endl;
  for(auto e:mst)
    cout<<e.first<<" "<<e.second<<endl;
}
