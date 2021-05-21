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

int BSTMAX(Node*root)
{
  if(root->right!=NULL)
    BSTMAX(root->right);
  else
    return root->data;
}
Node *deleteNode(Node *root,  int X)
{
   if(root==NULL)
   return NULL;

   if(X > root->data)
     root->right=deleteNode(root->right ,X);
   else if(X < root->data)
     root->left=deleteNode(root->left , X);
   else
   {
     if(root->left!=NULL && root->right!=NULL)
     {
       int lmax=BSTMAX(root->left);
       root->data=lmax;
       root->left=deleteNode(root->left,lmax);
       return root;
     }
     else if(root->left!=NULL)
       return root->left;
     else if(root->right!=NULL)
       return root->right;
     else
       return NULL;
   }
   return root;
}
int main()
{
  Node * root=CreateTree();
  int x;
  cin>>x;
  display(deleteNode(root,x));
}
