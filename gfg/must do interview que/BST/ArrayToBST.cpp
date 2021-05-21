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

Node* CreateTree(vector<int> arr,int lb,int ub)
{
  if(lb>ub)
  return NULL;
  int mid=(lb+ub)/2;
  int val=arr[mid];
  Node * node=new Node(val);
  node->left=CreateTree(arr,lb,mid-1);
  node->right=CreateTree(arr,mid+1,ub);
  return node;
}
void pre(Node* root,vector<int>&ans)
{
   if(root==NULL)
    return;
   ans.push_back(root->data);
   pre(root->left,ans);
   pre(root->right,ans);
}

vector<int> preOrder(Node* root)
{
    vector<int>ans;
    pre(root,ans);
    return ans;
}

vector<int> sortedArrayToBST(vector<int>& nums)
{
  Node*root=CreateTree(nums,0,nums.size()-1);
  vector<int>ans=preOrder(root);
  return ans;
}

int main()
{
  int n;
  cin>>n;
  vector<int> arr(n);
  for(int i=0;i<n;i++)
  cin>>arr[i];
  for(auto e:sortedArrayToBST(arr))
  cout<<e<<" ";

}
