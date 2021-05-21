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

int state=0;
int pred=-1,succ=-1;

void PredAndSucc(Node *root,int x)
{
  if(state==0)
  {
    if(root->data==x)
    state=1;
    else
    pred=root->data;
  }
  else if(state==1)
  {
    succ=root->data;
    state=2;
  }
  for(auto e:root->child)
    PredAndSucc(e,x);
}
int main()
{
  int n,x;
  cin>>n>>x;
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
  PredAndSucc(root,x);
  cout<<pred<<" "<<succ<<endl;
}
