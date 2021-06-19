//this algorithm use to detect negativr loop in weighted graph and to
//find shortest distance;
#include<bits/stdc++.h>
using namespace std;
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
void BellmanFord(int V,vector<Node>edge)
{
  vector<int>parent(V,-1);
  vector<int>value(V,INT_MAX);
  value[0]=0;
  bool update;
  for(int i=0;i<V-1;i++)
  {
    update=false;
    for(auto e:edge)
    {
        if(value[e.u]!=INT_MAX && value[e.u]+e.w < value[e.v])
        {
          update=true;
          value[e.v]=value[e.u] + e.w;
          parent[e.v]=e.u;
        }
    }
    if(!update)
      break;
  }

  if(update)
  {
    for(auto e:edge)
    {
      if(value[e.u]!=INT_MAX && value[e.u]+e.w < value[e.v])
      {
        cout<<"negative edge found";
        return;
      }
    }
  }
  //shortest dist;
  for(int i=0;i<V;i++)
  {
    cout<<"u->v : "<<parent[i]<<" "<<i<<" "<<" cost to reach : "<<value[i]<<endl;
  }
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

  BellmanFord(V,edge);
}
