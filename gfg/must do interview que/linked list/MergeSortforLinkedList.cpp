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
Node* getMiddle(Node *head , Node *tail)
{
  Node * fast=head;
  Node * slow =head;
  while(fast!=tail && fast->next!=tail)
  {
    fast=fast->next->next;
    slow=slow->next;
  }
  return slow;
}

Node* sortedMerge(Node* head1, Node* head2)
{
	Node * temp = new Node(-1);
	Node * res =temp;
	while(head1!=NULL && head2!=NULL)
	{
			if(head1->data <=head2->data)
			{
					temp->next=head1;
					temp=temp->next;
					head1=head1->next;
			}
			else
			{
					temp->next=head2;
					temp=temp->next;
					head2=head2->next;
			}
	}
	if(head1!=NULL)
			temp->next=head1;
	else
			temp->next=head2;
	return res->next;
}
Node* mergesort_linklist(Node* head,Node* tail)
{
  if(head==tail)
  {
    Node * tmp = new Node(head->data);
    return tmp;
  }
  Node * mid =getMiddle(head,tail);
  Node * left=mergesort_linklist(head,mid);
  Node * right=mergesort_linklist(mid->next,tail);
  return sortedMerge(left,right);
}

Node* mergeSort(Node* head)
{
  Node * tail=head;
  while(tail->next!=NULL)
    tail=tail->next;
  return mergesort_linklist(head,tail);
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
  print_linked_list(mergeSort(head));
}
