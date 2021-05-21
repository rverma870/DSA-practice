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
  Node()
  {
    next=NULL;
  }
};

int getNthFromLast(Node *head, int n)
{
  Node * start=new Node();
  start->next=head;
  Node * fast =start;
  Node * slow =start;
  int count=0;
  while(count<n && fast->next!=NULL)
  {
    fast=fast->next;
    count++;
  }

  if(count!=n)
    return -1;
    
  while(fast->next!=NULL)
  {
    fast=fast->next;
    slow=slow->next;
  }
  return slow->next->data;
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
  int n,x;
  cin>>n>>x;
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
  cout<<getNthFromLast(head,x);
}
