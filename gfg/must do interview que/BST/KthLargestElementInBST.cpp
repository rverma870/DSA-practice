#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

Node * CreateTree()
{
  Node * root=NULL;
  //cout<<"enterData"<<endl;
  int data;
  cin>>data;

  if(data==-1)
  return NULL;

  root =new Node(data);

  //cout<<" enter left:"<<endl;
  root->left=CreateTree();

  //cout<<" enter rigth:"<<endl;
  root->right=CreateTree();

  return root;
}
int ans;
int cnt=1;
void solve(Node *root,int k)
{
  if(root==NULL)
  return;
  solve(root->right,k);
  if(cnt==k)
  {
    ans=root->data;
    cnt++;
  }
  else
  cnt++;
  solve(root->left,k);
}
int kthLargest(Node *root, int K)
{
  solve(root,K);
  return ans;
}
int main()
{
  Node * root=CreateTree();
  int k;
  cin>>k;
  cout<<kthLargest(root,k);
}
