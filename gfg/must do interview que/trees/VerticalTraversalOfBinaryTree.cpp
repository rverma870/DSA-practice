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

vector<int> verticalOrder(Node *root)
{
  queue<pair<Node*,int>>q;//int->shows vertical positions of node
  map<int,vector<int>>mp;
  vector<int>ans;
  q.push(make_pair(root,0));
  while(!q.empty())
  {
    mp[q.front().second].push_back(q.front().first->data);
    if(q.front().first->left!=NULL)
    q.push(make_pair(q.front().first->left , q.front().second-1));
    if(q.front().first->right!=NULL)
    q.push(make_pair(q.front().first->right , q.front().second+1));
    q.pop();
  }

  for(auto e:mp)
  {
    for(auto q:e.second)
    ans.push_back(q);
  }
  return ans;
}

int main()
{
  Node * root=CreateTree();
  for(auto e:verticalOrder(root))
  {
    cout<<e<<" ";
  }

}
