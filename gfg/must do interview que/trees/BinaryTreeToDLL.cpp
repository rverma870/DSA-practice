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
void inOrder(Node* root,vector<Node*>&ans)
{
   if(root==NULL)
    return;
   inOrder(root->left,ans);
   ans.push_back(root);
   inOrder(root->right,ans);
}

Node * bToDLL(Node *root)
{
  vector<Node*>in;
  inOrder(root,in);
  int n=in.size();
  if(n==1)
  {
    in[0]->right=NULL;
    in[0]->left=NULL;
  }
  else
  {
    for(int i=0;i<n;i++)
    {
      if(i!=n-1 && i!=0)
      {
        in[i]->right=in[i+1];
        in[i]->left=in[i-1];
      }
      else if(i==0 && i+1!=n)
      {
        in[i]->right=in[i+1];
        in[i]->left=NULL;
      }
      else if(i==n-1)
      {
        in[i]->right=NULL;
        in[i]->left=in[i-1];
      }
    }
  }
  return in[0];
}

int main()
{
  Node * root=CreateTree();
  display(root);
}
