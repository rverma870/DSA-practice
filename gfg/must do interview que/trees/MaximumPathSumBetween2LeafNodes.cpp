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
  string data;
  cin>>data;

  if(data=="N")
  return NULL;

  root =new Node(stoi(data));

  //cout<<" enter left:"<<endl;
  root->left=CreateTree();

  //cout<<" enter rigth:"<<endl;
  root->right=CreateTree();

  return root;
}

int solve(Node *root,int& ans)
{
  int sum=0;
  if(root==NULL)
  return 0;
  if(root->left==NULL && root->right==NULL)
    return root->data;

  int l=solve(root->left,ans);
  int r=solve(root->right,ans);
  if(root->left && root->right)
  {
    ans=max(ans,l+r+root->data);
    return max(l,r)+root->data ;
  }
  return (root->left)?root->data+l:root->data+r;
}

int maxPathSum(Node* root)
{
  int ans=-10000;
  int val=solve(root,ans);
  if(ans==-10000)
  return val;
  return ans;
}

int main()
{
  Node * root=CreateTree();
  cout<<maxPathSum(root);
}
