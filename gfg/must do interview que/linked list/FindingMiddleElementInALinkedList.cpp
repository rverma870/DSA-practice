#include<bits/stdc++.h>
using namespace std;

struct Node
{
  int data;
  Node * next;
  Node(int x)
  {
    data=x;
    next=NULL;
  }
};

int getMiddle(Node *head)
{
  Node * fast=head;
  Node * slow =head;
  while(fast->next!=NULL )
  {

    if(fast->next->next==NULL)
    {
      return slow->next->data;
    }
    fast=fast->next->next;
    slow=slow->next;
  }
  return slow->data;
}

void print_linked_list(Node * head)
{
  Node * temp=head;
  while(temp!=NULL)
  {
    cout<<temp->data<<" ";
    temp=temp->next;
  }
}

int main()
{
  int n;
  cin>>n;
  Node * head=NULL, * tail=NULL;
  int first_data,l;
  cin>>first_data;

  head=new Node(first_data);
  tail=head;

  for(int i=0;i<n-1;i++)
  {
    cin>>l;
    tail->next=new Node(l);
    tail=tail->next;
  }
  print_linked_list(head);
  cout<<endl;
  cout<<getMiddle(head);
}
