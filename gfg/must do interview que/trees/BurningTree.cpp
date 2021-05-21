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
unordered_map<int,int>mp;
int height(Node *root)
{
  if(root==NULL)
  return 0;
  int l=height(root->left);
  int r=height(root->right);
  mp[root->data]=max(l,r)+1;
  return max(l,r)+1;
}
int res=0;
int solve(Node*root,int target)
{
  if(root==NULL)
  return 0;
  if(root->data==target)
  return 1;

  int val=solve(root->left,target);
  if(val)
  {
    if(root->right)
    res=max(res,val+mp[root->right->data]);
    return val+1;
  }

  val=solve(root->right,target);
  if(val)
  {
    if(root->left)
    res=max(res,val+mp[root->left->data]);
    return val+1;
  }
}
int minTime(Node* root, int target)
{
  res=0;
  height(root);
  solve(root,target);
  mp.clear();
  return res;
}


int main()
{
  Node * root=CreateTree();
  int n;
  cin>>n;
  cout<<minTime(root,n);
}
