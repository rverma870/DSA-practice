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

Node* getMiddle(Node *head)
{
  Node * fast=head;
  Node * slow =head;
  while(fast->next!=NULL )
  {

    if(fast->next->next==NULL)
      break;
    fast=fast->next->next;
    slow=slow->next;
  }
  return slow;
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

bool isPalindrome(Node *head)
{
  Node * mid = getMiddle(head);
  Node * rev= reverseList(mid->next);
  Node * it1 =head, * it2 =rev;
  while(it2!=NULL)
  {
    if(it1->data != it2->data)
      return false;
    it1=it1->next;
    it2=it2->next;
  }
  return true;
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
  cout<<isPalindrome(head);
}
