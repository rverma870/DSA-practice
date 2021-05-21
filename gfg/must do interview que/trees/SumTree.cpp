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
bool flag=true;
int sum(Node* root)
{
  if(root==NULL)
    return 0;
  if(root->left==NULL && root->right==NULL)
    return root->data;
  int lsum=sum(root->left);
  int rsum=sum(root->right);

  if(lsum+rsum != root->data)
    flag=false;
  return lsum + rsum + root->data;
}

bool isSumTree(Node* root)
{
  sum(root);
  return flag;
}
int main()
{
  Node * root=CreateTree();
  cout<<isSumTree(root);
}
