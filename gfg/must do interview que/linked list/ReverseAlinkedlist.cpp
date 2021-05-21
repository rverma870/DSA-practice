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

Node* reverseList(struct Node *head)
{
  Node * new_head=NULL;
  while(head!=NULL)
  {
    Node * next=head->next;
    head->next=new_head;
    new_head=head;
    head=next;
  }
  return new_head;
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
  head=reverseList(head);
  print_linked_list(head);
}
