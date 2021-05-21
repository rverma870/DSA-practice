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

void display(Node * root)
{
  cout<<root->data<<"-> ";
  if(root->left!=NULL && root->right!=NULL)
    cout<<root->left->data<<", "<<root->right->data<<"."<<endl;
  else if(root->left!=NULL && root->right==NULL)
    cout<<root->left->data<<"."<<endl;
  else if(root->left==NULL && root->right!=NULL)
    cout<<root->right->data<<"."<<endl;
  else
  cout<<endl;

  if(root->left!=NULL)
  display(root->left);
  if(root->right!=NULL)
  display(root->right);
}

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

void left(Node* root,vector<int>&v)
{
  if(root==NULL)
    return;

  if(root->left==NULL && root->right==NULL)
    return;

  if(root->left!=NULL)
    left(root->left,v);
  else
    left(root->right,v);

  v.push_back(root->data);
  return;
}

void bottom(Node * root ,vector<int>&v)
{
  if(root==NULL)
    return;

  if(root->left==NULL && root->right==NULL)
  {
    v.push_back(root->data);
    return;
  }

  bottom(root->left,v);
  bottom(root->right,v);

  return;
}

void right(Node* root,vector<int>&v)
{
  if(root==NULL)
    return;

  if(root->left==NULL && root->right==NULL)
    return;

  if(root->right!=NULL)
    right(root->right,v);
  else
    right(root->left,v);

  v.push_back(root->data);
  return;
}

vector <int> printBoundary(Node *root)
{
  vector<int>l,r,b,ans;
  if(root->left!=NULL)
    left(root->left,l);
  if(root->right!=NULL)
    right(root->right,r);
  bottom(root,b);
  ans.push_back(root->data);

  for(int i=l.size()-1;i>=0;i--)
    ans.push_back(l[i]);
  for(int i=0;i<b.size();i++)
    ans.push_back(b[i]);
  for(int i=0;i<r.size();i++)
    ans.push_back(r[i]);

  return ans;
}

int main()
{
  Node * root=CreateTree();

  for(auto e:printBoundary(root))
  cout<<e<<" ";
}
