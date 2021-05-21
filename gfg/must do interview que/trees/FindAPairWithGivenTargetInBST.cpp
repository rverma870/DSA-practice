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
bool find(Node*root,int x)
{
  if(root==NULL)
  return false;
  if(x < root->data)
  find(root->left,x);
  else if(x > root->data)
  find(root->right,x);
  else
    return true;
}

bool flag=false;

void solve(Node* root,Node * node,int target)
{
  if(node==NULL)
  return;
  solve(root,node->left,target);

  int temp = target - node->data;
  if(node->data < temp)
  {
    if(find(root,temp))
      flag=true;
  }

  solve(root,node->right,target);
}

int isPairPresent(Node *root, int target)
{
  solve(root,root,target);
  return flag;
}

int main()
{
  Node * root=CreateTree();
  int target;
  cin>>target;
  cout<<isPairPresent(root,target);
  //cout<<flag;
}
