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

int ans_node=0;
int mxsum=-10000000;
int maximumsubtreesum(Node* root)
{
  int sum=0;
  for(auto e:root->child)
  {
    sum+=maximumsubtreesum(e);
  }
  sum+=root->data;
  if(sum>mxsum)
  {
    mxsum=sum;
    ans_node=root->data;
  }
  return sum;
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
  maximumsubtreesum(root);
  cout<<ans_node<<" "<<mxsum<<endl;
}
