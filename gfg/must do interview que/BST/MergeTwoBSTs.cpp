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

void mergeSortedArray(vector<int>x, vector<int>y, vector<int>&ans)
{
  int n1=x.size();
  int n2=y.size();
  int i=0,j=0;
  while(i<n1 && j<n2)
  {
    if(x[i]<=y[j])
    {
      ans.push_back(x[i]);
      i++;
    }
    else
    {
      ans.push_back(y[j]);
      j++;
    }
  }
  while(i<n1)
  {
    ans.push_back(x[i]);
    i++;
  }
  while(j<n2)
  {
    ans.push_back(y[j]);
    j++;
  }
}

void in(Node* root,vector<int>&ans)
{
   if(root==NULL)
    return;
   in(root->left,ans);
   ans.push_back(root->data);
   in(root->right,ans);
}

vector<int> inOrder(Node* root)
{
    vector<int>ans;
    in(root,ans);
    return ans;
}

vector<int> merge(Node *root1, Node *root2)
{
  vector<int>v1=inOrder(root1);
  vector<int>v2=inOrder(root2);
  vector<int>ans;
  mergeSortedArray(v1,v2,ans);
  return ans;
}

int main()
{
  Node* root1=CreateTree();
  Node* root2 =CreateTree();
  for(auto e:merge(root1,root2))
  cout<<e<<" ";
}
