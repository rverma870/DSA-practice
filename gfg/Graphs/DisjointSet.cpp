#include<bits/stdc++.h>
using namespace std;
//this data structure helps to find weather two node belong to same component of graph or not;
int parent[1000];
int rnk[1000];// rank shows how many nodes are attach below it ie, height of that node;

void makeSet(int V)
{
  for(int i=0 ;i<V ;i++)
  {
    parent[i]=i;
    rnk[i]=0;
  }
}

int findparent(int node)//find parent
{
  if(node==parent[node])
    return node;
  return parent[node]=findparent(parent[node]);
}

void uion(int u, int v)
{
  u=findparent(u);
  v=findparent(v);

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

int main()
{
  int V;
  cin>>V;
  makeSet(V);
  int m;
  cin>>m;
  while(m--)
  {
    int u,v;
    cin>>u>>v;
    uion(u,v);
  }
  //to check weather a and b belong to same component
  int a,b;
  cin>>a>>b;
  if(findparent(a)!=findparent(b))
  cout<<"different component";
  else
  cout<<"same component";
}
