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
vector<int> findSpiral(Node *root)
{
   vector<int>ans;
   if(root==NULL)
   return ans;
   stack<Node*>mstk,cstk;//main stk and child stack;
   int level=0;
   mstk.push(root);
   while(!mstk.empty())
   {
     if(level%2!=0)
     {
       if(mstk.top()->left!=NULL)
       cstk.push(mstk.top()->left);
       if(mstk.top()->right!=NULL)
       cstk.push(mstk.top()->right);
       ans.push_back(mstk.top()->data);
     }
     else
     {
       if(mstk.top()->right!=NULL)
       cstk.push(mstk.top()->right);
       if(mstk.top()->left!=NULL)
       cstk.push(mstk.top()->left);
       ans.push_back(mstk.top()->data);
     }
     mstk.pop();
     if(mstk.empty())
     {
       mstk=cstk;
       while(!cstk.empty())
       cstk.pop();
       level++;
     }
   }
   return ans;
}
int main()
{
  Node * root=CreateTree();
  for(auto e: findSpiral(root))
    cout<<e<<" ";
}
