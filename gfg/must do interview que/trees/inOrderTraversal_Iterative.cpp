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

vector<int> inOrder(Node* root)
{
    vector<int>ans;
    stack<pair<Node* , int>> stk;
    pair<Node*,int>p;
    p.first=root;
    p.second=0;
    stk.push(p);
    while(!stk.empty())
    {
      if(stk.top().second==0)
      {
        pair<Node*,int>temp=stk.top();
        stk.pop();
        stk.push(make_pair(temp.first,1));
        if(stk.top().first->left!=NULL)
          stk.push(make_pair(temp.first->left,0));
      }
      else if(stk.top().second==1)
      {
        pair<Node*,int>temp=stk.top();
        stk.pop();
        stk.push(make_pair(temp.first,2));
        ans.push_back(stk.top().first->data);
        if(stk.top().first->right!=NULL)
        {
          stk.push(make_pair(temp.first->right,0));
        }
      }
      else
        stk.pop();
    }
    return ans;
}

int main()
{
  Node * root=CreateTree();
  display(root);
  vector<int>ans=inOrder(root);
  for(auto e:ans)
  cout<<e<<" ";
}
