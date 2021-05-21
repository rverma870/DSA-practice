#include<bits/stdc++.h>
using namespace std;

struct Node
{
  int data;
  vector<Node*>child;
  Node(int x)
  {
    data=x;
  }
};

void display(Node * root)
{
  cout<<root->data<<"-> ";
  for(auto e:root->child)
    cout<<e->data<<", ";
  cout<<"."<<endl;
  for(auto e:root->child)
    display(e);
}
int dia=0;
int cal_Dia_ReturnHeight(Node * root)// according to egde calculation
{
  int hmax=-1 , sechmax=-1;

  for(auto e:root->child)
  {
    int temp=cal_Dia_ReturnHeight(e);
    if(temp>hmax)
    {
      sechmax=hmax;
      hmax=temp;
    }
    else if(temp>sechmax)
      sechmax=temp;
  }
  if(hmax+sechmax+2>dia)
    dia=hmax+sechmax+2;
  hmax+=1;
  return hmax;
}
int main()
{
  int n;
  cin>>n;
  int arr[n];
  for(int i=0;i<n;i++)
    cin>>arr[i];
  stack<Node *>stk;
  Node * root=NULL;
  for(int i=0;i<n;i++)
  {
    if(stk.empty() && arr[i]!=-1)
    {
      root =new Node(arr[i]);
      stk.push(root);
    }
    else
    {
      if(arr[i]!=-1)
      {
        Node * t= new Node(arr[i]);
        stk.top()->child.push_back(t);
        stk.push(t);
      }
      else
      {
        stk.pop();
      }
    }

  }
  cal_Dia_ReturnHeight(root);
  cout<<dia;
}
