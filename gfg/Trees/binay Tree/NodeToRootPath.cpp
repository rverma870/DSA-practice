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

vector<int>node_path;
bool NodeToRootPath(Node * root,int n)
{
  if(root==NULL)
  return false;

  if(root->data==n)
  {
    node_path.push_back(root->data);
    return true;
  }
  if(NodeToRootPath(root->left,n))
  {
    node_path.push_back(root->data);
    return true;
  }
  if(NodeToRootPath(root->right,n))
  {
    node_path.push_back(root->data);
    return true;
  }
  return false;
}

int main()
{
  Node * root=CreateTree();
  for(auto e:node_path)
  cout<<e<<" ";
}
