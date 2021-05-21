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

//METHOD 1 NORMAL APPROCH FOR BINARY TREE;

// bool flag=false;
// Node * ans=NULL;
// void solve(Node *root,Node *x)
// {
//   if(root==NULL)
//   return ;
//
//   solve(root->left,x);
//   if(root==x)
//   {
//     flag=true;
//   }
//   else if(flag)
//   {
//     ans=root;
//     flag=false;
//   }
//   solve(root->right,x);
// }
//
// Node * inOrderSuccessor(Node *root, Node *x)
// {
//   solve(root,x);
//   return ans;
// }

//METHOD 2 EFFICIENT FOR BINARY SEARCH TREE;
Node * inOrderSuccessor(Node *root, Node *x)
{
  if(x->right!=NULL)
  {
    Node*temp=x->right;
    Node* ans=NULL;
    while(temp!==NULL)
    {
      ans=temp;
      temp=temp->left;
    }
    return ans;
  }
  else
  {
    Node * ans=NULL;
    while(root!=x)
    {
      if(x->data <= root->data)
      {
        ans=root;
        root=root->left;
      }
      else
        root=root->right;
    }
    return ans;
  }
}

int main()
{
  Node * root=CreateTree();
}
