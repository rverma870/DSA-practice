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
Node* addTwoLists(struct Node* head1, struct Node* head2)
{
  head1=reverseList(head1);
  head2=reverseList(head2);
  int carry=0,sum=0;
  Node * res_head=NULL , * tail=NULL;
  sum = head1->data + head2->data;
  head1=head1->next;
  head2=head2->next;
  res_head=new Node(sum%10);
  carry=sum/10;
  tail=res_head;
  sum=0;
  while(carry!=0 || head1!=NULL || head2!=NULL)
  {
    if(head1!=NULL && head2!=NULL)
    {
      sum=head1->data+head2->data+carry;
      head1=head1->next;
      head2=head2->next;
    }
    else if(head1==NULL && head2!=NULL)
    {
      sum=head2->data+carry;
      head2=head2->next;
    }
    else if(head1!=NULL && head2==NULL)
    {
      sum=head1->data+carry;
      head1=head1->next;
    }
    else
      sum=carry;

    tail->next = new Node(sum%10);
    tail=tail->next;
    carry =sum/10;
    sum=0;
  }
  return reverseList(res_head);
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
  int n,m;
  cin>>n>>m;
  Node * head1=NULL, * tail1=NULL,* head2=NULL, * tail2=NULL ;
  int first_data1,first_data2,l;
  cin>>first_data1;

  head1=new Node(first_data1);
  tail1=head1;


  for(int i=0;i<n-1;i++)
  {
    cin>>l;
    tail1->next=new Node(l);
    tail1=tail1->next;
  }

  cin>>first_data2;

  head2=new Node(first_data2);
  tail2=head2;

  for(int i=0;i<m-1;i++)
  {
    cin>>l;
    tail2->next=new Node(l);
    tail2=tail2->next;
  }
  Node * ans=addTwoLists(head1,head2);
  print_linked_list(ans);
}
