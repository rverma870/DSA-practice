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

void display(Node * root)
{
  cout<<root->data<<"-> ";
  for(auto e:root->child)
  {
    cout<<e->data<<", ";
  }
  cout<<"."<<endl;
  for(auto e:root->child)
    display(e);
}

void zigzag(Node * root)
{
  stack<Node *>ms,cs;//main stack , child stack;
  ms.push(root);
  int level=1;
  while(!ms.empty())
  {
    cout<<ms.top()->data<<endl;
    if(level%2!=0)
    {
      for(auto e:ms.top()->child)
        cs.push(e);
    }
    else
    {
      for(int i=ms.top()->child.size()-1 ; i>=0 ; i--)
        cs.push(ms.top()->child[i]);
    }
    ms.pop();
    if(ms.empty())
    {
      ms=cs;
      while(!cs.empty())
        cs.pop();
      level++;
    }
  }
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
  zigzag(root);
}
