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
bool isIdentical(Node *root1, Node *root2)
{
     if(root1==NULL && root2==NULL)
      return true;
    if(root1==NULL || root2==NULL)
      return false;

    if(root1->data==root2->data)
    {
      if(isIdentical(root1->left,root2->left) && isIdentical(root1->right,root2->right))
        return true;
    }
    return false;
}
int main()
{
  Node * root1=CreateTree();
  Node * root2=CreateTree();
  cout<<isIdentical(root1,root2);
}
