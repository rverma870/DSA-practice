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

vector<int> levelOrder(Node* root)
{
    vector<int>ans;
    queue<Node *>q;
    q.push(root);
    while(!q.empty())
    {
      ans.push_back(q.front()->data);
      if(q.front()->left!=NULL)
      q.push(q.front()->left);
      if(q.front()->right!=NULL)
      q.push(q.front()->right);
      q.pop();
    }
    return ans;
}

int main()
{
  Node * root=CreateTree();
  display(root);
  vector<int>ans=levelOrder(root);
  for(auto e:ans)
  cout<<e<<" ";
}
