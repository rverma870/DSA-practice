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

vector<Node*>node_path;
bool NodeToRootPath(Node * root,int n)
{
  if(root==NULL)
  return false;

  if(root->data==n)
  {
    node_path.push_back(root);
    return true;
  }
  if(NodeToRootPath(root->left,n))
  {
    node_path.push_back(root);
    return true;
  }
  if(NodeToRootPath(root->right,n))
  {
    node_path.push_back(root);
    return true;
  }
  return false;
}

vector<int>kLevel_element;
void kLevelDown(Node * root ,int k,Node* blocker)
{
  if(root==NULL || k<0 || root==blocker)
   return;
  if(k==0)
  kLevel_element.push_back(root->data);
  kLevelDown(root->left,k-1,blocker);
  kLevelDown(root->right,k-1,blocker);
}

vector <int> KDistanceNodes(Node* root, int target , int k)
{
  vector<int>ans;
  NodeToRootPath(root,target);
  for(int i=0;i<node_path.size();i++)
  {
    kLevelDown(node_path[i], k-i, (i==0)?NULL:node_path[i-1]);
  }
  ans=kLevel_element;
  kLevel_element.clear();
  node_path.clear();
  sort(ans.begin(),ans.end());
  return ans;
}

int main()
{
  Node * root=CreateTree();
  int target,k;
  cin>>target>>k;
  for(auto e:KDistanceNodes(root,target,k))
  cout<<e<<" ";
}
