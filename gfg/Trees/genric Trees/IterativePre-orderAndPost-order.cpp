#include<bits/stdc++.h>
using namespace std;

struct Node
{
  int data;
  vector<Node*>child;
  Node(int x)
  {
    data=x;
  }
};

void iterate(Node * root)
{
  vector<int>pre;
  vector<int>post;
  stack<pair<Node *,int>> stk;
  stk.push(make_pair(root,-1));
  while(!stk.empty())
  {
    if(stk.top().second==-1)
    {
      pre.push_back(stk.top().first->data);
      pair<Node *,int>p;
      p=stk.top();
      stk.pop();
      stk.push(make_pair(p.first,p.second+1));
    }
    else if(stk.top().second == stk.top().first->child.size())
    {
      post.push_back(stk.top().first->data);
      stk.pop();
    }
    else
    {
      pair<Node *,int>p=stk.top();
      stk.pop();
      stk.push(make_pair(p.first,p.second+1));
      stk.push(make_pair(stk.top().first->child[p.second] ,-1));
    }
  }
  for(auto e:pre)
  cout<<e<<" ";
  cout<<endl;
  for(auto e:post)
  cout<<e<<" ";
}

int main()
{
  int n;
  cin>>n;
  int arr[n];
  for(int i=0;i<n;i++)
    cin>>arr[i];
  stack<Node *>stk;
  Node * root=NULL;
  for(int i=0;i<n;i++)
  {
    if(stk.empty() && arr[i]!=-1)
    {
      root =new Node(arr[i]);
      stk.push(root);
    }
    else
    {
      if(arr[i]!=-1)
      {
        Node * t= new Node(arr[i]);
        stk.top()->child.push_back(t);
        stk.push(t);
      }
      else
      {
        stk.pop();
      }
    }
  }
  iterate(root);
}
