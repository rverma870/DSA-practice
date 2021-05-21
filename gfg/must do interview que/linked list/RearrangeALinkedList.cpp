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
Node *rearrangeEvenOdd(Node *head)
{
  if(head->next==NULL || head->next->next==NULL)
      return head;
  Node * odd_head=head,* even_head=head->next,* odd_it=head,* even_it=head->next,* it=even_head->next;
  bool flag=false;
  while(it!=NULL)
  {
    if(flag==false)
    {
      flag=true;
      odd_it->next=it;
      odd_it=odd_it->next;
      it=it->next;
    }
    else
    {
      flag=false;
      even_it->next=it;
      even_it=even_it->next;
      it=it->next;
    }
  }
  odd_it->next=even_head;
  even_it->next=NULL;
  return odd_head;
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
  print_linked_list(rearrangeEvenOdd(head));
}
