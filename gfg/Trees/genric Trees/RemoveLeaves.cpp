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
void removeleaves(Node * root)
{
  for(int i=root->child.size()-1; i>=0; i--)
  {
    if(root->child[i]->child.size()==0)
    {
      root->child.erase(root->child.begin()+i);
    }
  }
  for(auto e:root->child)
  {
    removeleaves(e);
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
  removeleaves(root);
  display(root);
}
