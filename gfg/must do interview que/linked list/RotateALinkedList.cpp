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

void print_linked_list(Node * head)
{
  Node * temp=head;
  while(temp!=NULL)
  {
    cout<<temp->data<<" ";
    temp=temp->next;
  }
}
Node* rotate(Node* head, int k)
{
  int count=1;
  Node * it=head;
  while(it->next!=NULL)
  {
    it=it->next;
    count++;
  }
  int rotation = k%count;
  if(rotation==0)
    return head;

  it->next=head;

  Node* dummy=new Node(-1);
  dummy->next=head;

  Node * new_head=NULL;

  while(rotation--)
    dummy=dummy->next;

  new_head=dummy->next;
  dummy->next=NULL;
  return new_head;
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
  int k;
  cin>>k;
  print_linked_list(rotate(head,k));
}
