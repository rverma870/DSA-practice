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
  Node * ans=sortedMerge(head1,head2);
  print_linked_list(ans);
}
