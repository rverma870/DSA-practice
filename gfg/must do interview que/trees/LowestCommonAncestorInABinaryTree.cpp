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

bool NodeToRoot(Node* root,int x,vector<Node*>&v)
{
  if(root==NULL)
    return false;

  if(root->data==x)
  {
    v.push_back(root);
    return true;
  }

  if(NodeToRoot(root->left,x,v) || NodeToRoot(root->right,x,v))
  {
    v.push_back(root);
    return true;
  }
  return false;
}

Node* lca(Node* root ,int n1 ,int n2 )
{
   vector<Node*>dist1,dist2;
   NodeToRoot(root,n1,dist1);
   NodeToRoot(root,n2,dist2);
   int n=dist1.size()-1;
   int m=dist2.size()-1;
   while(n>=0 && m>=0)
   {
     if(dist1[n]->data!=dist2[m]->data)
      return dist1[n+1];
      n--;
      m--;
   }
   n++;
   m++;
   return dist1[n];
}
int main()
{
  Node * root=CreateTree();
  int n1,n2;
  cin>>n1>>n2;
  cout<<lca(root,n1,n2)->data;
}
