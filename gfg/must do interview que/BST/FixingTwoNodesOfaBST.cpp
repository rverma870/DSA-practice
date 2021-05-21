#include<bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int data)
    {
        data = data;
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

bool flag =true;
pair<int,Node* > arr[2];
int curr_data = INT_MIN;
Node* curr_add =NULL;

void solve(Node*root)
{
  if(root==NULL)
  return;

  solve(root->left);

  if(root->data >= curr_data )
  {
    curr_data = root->data;
    curr_add = root;
  }
  else
  {
    if(flag)
    {
      arr[0] = make_pair(curr_data, curr_add);
      arr[1] = make_pair(root->data , root);
      curr_data = root->data;
      curr_add = root;
      flag=false;
    }
    else
    {
      arr[1] = make_pair(root->data , root);
      curr_data = root->data;
      curr_add = root;
    }
  }
  solve(root->right);
}

Node * correctBST(Node* root )
{
  solve(root);
  if(arr[0].second!=NULL)
  arr[0].second->data = arr[1].first;
  if(arr[1].second!=NULL)
  arr[1].second->data = arr[0].first;
  return root;
}

int main()
{
  Node * root=CreateTree();
  display(correctBST(root));
}
