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
Node* removekeys(Node* root, int l, int r)
{
  if(root==NULL)
  return NULL;
  if(root->data >= l && root->data <= r)
  {
    root->left=removekeys(root->left,l ,r);
    root->right=removekeys(root->right,l,r);
  }
  else
  {
    if(root->data < l )
    {
      Node*temp=root->right;
      while(temp!=NULL)
      {
        if(temp->data >= l && temp->data <= r)
          break;
        else if(temp->data < l)
          temp=temp->right;
        else
          temp=temp->left;
      }
      if(temp!=NULL)
      {
        temp->left=removekeys(temp->left,l,r);
        temp->right=removekeys(temp->right,l,r);
      }
      return temp;
    }
    else
    {
      Node*temp=root->left;
      while(temp!=NULL)
      {
        if(temp->data >= l && temp->data <= r)
          break;
        else if(temp->data < l)
          temp=temp->right;
        else
          temp=temp->left;
      }
      if(temp!=NULL)
      {
        temp->left=removekeys(temp->left,l,r);
        temp->right=removekeys(temp->right,l,r);
      }
      return temp;
    }
  }
  return root;
}
int main()
{
  Node * root=CreateTree();
  int l,r;
  cin>>l>>r;
  display(removekeys(root,l,r));
}
