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

void storeInorder(Node* root, char arr[], int& i)
{
	if (root == NULL) {
		arr[i++] = '$';
		return;
	}
	storeInorder(root->left, arr, i);
	arr[i++] = root->data;
	storeInorder(root->right, arr, i);
}

void storePreOrder(Node* root, char arr[], int& i)
{
	if (root == NULL) {
		arr[i++] = '$';
		return;
	}
	arr[i++] = root->data;
	storePreOrder(root->left, arr, i);
	storePreOrder(root->right, arr, i);
}

bool isSubtree(Node* T, Node* S)
{
	if (S == NULL)
		return true;
	if (T == NULL)
		return false;

	int m = 0, n = 0;
	char inT[100], inS[100];
	storeInorder(T, inT, m);
	storeInorder(S, inS, n);

	if (strstr(inT, inS) == NULL)
		return false;

	m = 0, n = 0;
	char preT[100], preS[100];
	storePreOrder(T, preT, m);
	storePreOrder(S, preS, n);

	return (strstr(preT, preS) != NULL);
}

int main()
{
  Node * root1=CreateTree();
  Node * root2=CreateTree();
  cout<<isSubtree(root1 , root2);
}
