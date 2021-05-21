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

vector<int>NodeToRoot(Node * root,int x)
{
  vector<int>ans;
  if(root->data==x)
  {
    ans.push_back(root->data);
    return ans;
  }

  for(auto e: root->child)
  {
    vector<int>temp=NodeToRoot(e,x);
    if(temp.size())
    {
      temp.push_back(root->data);
      return temp;
    }
  }
  return ans;
}

int lowestCommonAncestor(Node * root,int x,int y)
{
  vector<int>v1=NodeToRoot(root,x);
  vector<int>v2=NodeToRoot(root,y);
  int i=v1.size()-1, j=v2.size()-1;
  while(i>=0 && j>=0 && v1[i]==v2[j])
  {
    i--;
    j--;
  }
  i++;
  return v1[i];
}

int main()
{
  int n,x,y;
  cin>>n>>x>>y;
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
  cout<<lowestCommonAncestor(root,x,y);
}
