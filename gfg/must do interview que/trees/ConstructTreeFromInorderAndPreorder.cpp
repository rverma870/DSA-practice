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
int search(int in[],int x,int lb,int ub)
{
  if(lb>ub)
  return -1;
  for(int i=lb;i<=ub;i++)
  {
    if(in[i]==x)
    return i;
  }
}
int idx=0;
Node* solve(int in[],int pre[],int lb, int ub,int n)
{
  if(idx==n)
  return NULL;
  Node* res=new Node(pre[idx]);
  int temp = search(in,pre[idx],lb,ub);
  idx++;
  if(temp!=lb)
  res->left = solve(in,pre,lb,temp-1,n);
  if(temp!=ub)
  res->right = solve(in,pre,temp+1,ub,n);
  return res;
}
Node* buildTree(int in[],int pre[], int n)
{
  return solve(in,pre,0,n-1,n);
}
int main()
{
  int n;
  cin>>n;
  int in[n],pre[n];
  for(int i=0;i<n;i++)
  cin>>in[i];
  for(int i=0;i<n;i++)
  cin>>pre[i];

  display(buildTree(in,pre,n));
}
